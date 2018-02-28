// ITP 365 Spring 2017
// HW7 - IMDB Graph
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// IDMBData.cpp - Implements IMDBData interface

#include "IMDBData.h"
#include <fstream>
#include <iostream>
#include <queue>

// Do for Part 1
// Function: Default Constructor
// Purpose: Loads in the actor/movie file specified,
// and populates the data into the appropriate hash maps.
// Also constructs the graph with actor relationships.
// Input: Name of file to load (by reference)
// Returns: Nothing
IMDBData::IMDBData(const std::string& fileName)
{
	std::ifstream file(fileName);
	// open file
	if (file.is_open()){
		// go through file contents
		std::string actor = "";
		std::vector<std::string> movieVec;
		while (!file.eof()){
			std::string currLine;
			std::getline(file, currLine);
			
			if (currLine[0] != '|'){
				if (actor == ""){
					// update previous actor
					actor = currLine;
					// clear movie vector
					movieVec.clear();
				}
				else{
					// we have a previous actor that we have to push into bigger map
					mActorsToMoviesMap[actor] = movieVec;
					// update previous actor
					actor = currLine;
					// clear movie vector
					movieVec.clear();
				}
			}
			else{
				std::string movie = currLine.substr(1);
				movieVec.push_back(movie);
			}
		}
		file.close();
	}
	else{
		// Display error message
		std::cout << "Error: File " << fileName << " not available" << std::endl;
	}
	
	// Reverse map
	for (auto itr : mActorsToMoviesMap){
		reverseMap(itr.first, itr.second);
	}
}

// Do for Part 1
// Function: reverseMap
// Purpose: This is a helper function that is used to generate
// the reverse map (movies to actors)
// Input: Name of actor (by reference), vector of their movies (by reference)
// Returns: Nothing
void IMDBData::reverseMap(const std::string& actorName, const std::vector<std::string>& movies)
{
	// TODO for Part 1
	// TODO: Implement
	
	// go through movies
	for (int i = 0; i < movies.size(); i++){
		// 1. If mMovieToActorsMap already contains the movie in question, you need to add actorName to that movie’s associated vector
		if (mMoviesToActorsMap.find(movies[i]) != mMoviesToActorsMap.end()){
			// we found the movie in the big map, so we have to append the actorName to end of movie's actor vector
			mMoviesToActorsMap[movies[i]].push_back(actorName);
		}
		// 2. Otherwise, you need to add an entry in mMovieToActorsMap that associates the movie with a vector that, for now, only contains actorName
		else{
			std::vector<std::string> tempVec;
			tempVec.push_back(actorName);
			mMoviesToActorsMap[movies[i]] = tempVec;
		}
	}
}

// Do for Part 1
// Function: getMoviesFromActor
// Purpose: Given an actor's name, returns a vector containing their movies
// Input: Name of actor (by reference)
// Returns: Vector of movies (by reference)
std::vector<std::string>& IMDBData::getMoviesFromActor(const std::string& actorName)
{
	if (mActorsToMoviesMap.find(actorName) != mActorsToMoviesMap.end()){
		// actor name found in map -> return vector associated with it
		return mActorsToMoviesMap[actorName];
	}
	else{
		// actor name NOT found in map -> return empty vector
		return sEmptyVector;
	}
}

// Do for Part 1
// Function: getActorsFromMovie
// Purpose: Given a movie's name, returns the name of its actors
// Input: Name of movie (by reference)
// Returns: Vector of actors (by reference)
std::vector<std::string>& IMDBData::getActorsFromMovie(const std::string& movieName)
{
	// TODO for Part 1
	// TODO: Implement
	if (mMoviesToActorsMap.find(movieName) != mMoviesToActorsMap.end()){
		// movie name found in map -> return vector associated with it
		return mMoviesToActorsMap[movieName];
	}
	else{
		// movie name NOT found in map -> return empty vector
		return sEmptyVector;
	}
}

// Do for Part 2
// Function: findRelationship
// Purpose: Tries to find a relationship between two actors, using a BFS
// and outputs (to cout) the result of the search.
// Input: Name of two actors to check for a relationship
// Returns: Nothing
void IMDBData::findRelationship(const std::string& fromActor, const std::string& toActor)
{
	// Check if actors are even in graph, otherwise print error message
	if (!mGraph.containsActor(fromActor)){
		std::cout << "Error: " << fromActor << " is not in the graph. " << std::endl;
	}
	if (!mGraph.containsActor(toActor)){
		std::cout << "Error: " << toActor << " is not in the graph. " << std::endl;
	}
	
	// 1. Create a queue of ActorNode*, and enqueue the node we’re starting from…
	ActorNode* startNode = mGraph.getActorNode(fromActor);
	ActorNode* endNode = mGraph.getActorNode(toActor);
	
	std::queue<ActorNode*> myQueue;
	myQueue.push(startNode);

	bool pathFound = false;
	
	// 2. While the BFS queue is not empty…
	while (myQueue.size() != 0){
		// a) Dequeue the front ActorNode*, and save in currentNode
		ActorNode* currentNode;
		currentNode = myQueue.front();
		// dequeue front node
		myQueue.pop();
		// b) If currentNode == targetNode, we found a path!
		if (currentNode == endNode){
			pathFound = true;
			break;
		}
		// c) Otherwise if currentNode’s visited bool is false…
		else if (currentNode->mIsVisited == false){
			// 1. Visit currentNode
			// 2. Set currentNode visited to true
			currentNode->mIsVisited = true;
			// 3. Loop through currentNode’s adjacency list and if the visited flag is false…
			for (auto i : currentNode->mEdges){
				if (i->mOtherActor->mIsVisited == false){
					// a) enqueue the adjacent node
					myQueue.push(i->mOtherActor);
					// b) If the adjacent node path has a size of 0…
					if (i->mOtherActor->mPath.size() == 0){
						// a) Set the adjacent node’s path equal to currentNode’s path
						i->mOtherActor->mPath = currentNode->mPath;
						// b) Push_back adjacent nodes’s relevant path information (destination name and label in ITPPathInfo struct)
						PathPair temp(i->mMovieName, currentNode->mName);
						i->mOtherActor->mPath.push_back(temp);
					}
				}
			}
		}
	}
	// 3. If we made it here, we didn’t find a path
	if (pathFound){
		std::cout << "Found a path!" << " (" << endNode->mPath.size() << " hops)" << std::endl;
		// Range-based for loop to show path
		int counter = 0;
		for (auto i : endNode->mPath){
			if (counter == 0){
				std::cout << i.getActorName() << " was in..." << std::endl;
				std::cout << i.getMovieName() << " with ";
				if (endNode->mPath.size() == 1){
					std::cout << endNode->mName << std::endl;
				}
				counter++;
			}
			else{
				std::cout << i.getActorName() << " who was in..." << std::endl;
				std::cout << i.getMovieName() << " with ";
				counter++;
				if (counter == endNode->mPath.size()){
					std::cout << endNode->mName << std::endl;
				}
			}
		}
	}
	else{
		std::cout << "Didn't find a path :(" << std::endl;
	}
	
	// LEAVE THIS AT THE END OF THE FUNCTION
	mGraph.clearVisited();
}

// For Part 2
// Function: createGraph
// Purpose: This helper function constructs the IMDBGraph from the movie to actors map
// Input: None
// Returns: Nothing
void IMDBData::createGraph()
{
	// DO NOT EDIT THIS FUNCTION
	// For every movie in the actors map...
	for (auto& p : mMoviesToActorsMap)
	{
		const std::string& movieName = p.first;
		// Get the actors for this movie
		const std::vector<std::string>& actors = mMoviesToActorsMap[movieName];

		// Make n^2 edges between these actors
		for (size_t i = 0; i < actors.size(); i++)
		{
			ActorNode* firstActor = mGraph.getActorNode(actors[i]);
			for (size_t j = i + 1; j < actors.size(); j++)
			{
				ActorNode* secondActor = mGraph.getActorNode(actors[j]);
				mGraph.createActorEdge(firstActor, secondActor, movieName);
			}
		}
	}
}

// Leave here! Do not edit!!! Use in part 1
// DO NOT REMOVE THIS LINE
std::vector<std::string> IMDBData::sEmptyVector;
