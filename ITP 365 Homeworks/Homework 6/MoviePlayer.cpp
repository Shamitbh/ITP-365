// ITP 365 Spring 2017
// HW6 Doubly Linked List and Movie Player
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac
//
// MoviePlayer.cpp
// Implements the Movie Player class
//

#include "MoviePlayer.h"

// Function: Parameterized Constructor
// Purpose: Sets member variables to input, clears list, and calls loader
// Input: None
// Returns: Nothing
MoviePlayer::MoviePlayer(std::string filmName)
{
	mFilmName = filmName;
	mFilm.clear();
	loadTape();
	rewind();
}

// Function: Destructor
// Purpose: Empties the list
// Input: None
// Returns: Nothing
MoviePlayer::~MoviePlayer()
{
	mFilm.clear();
	
}

// Function: goFwrd
// Purpose: Moves the current "frame" forward by 1 frame
// Also keeps track of how many frames have been viewed
// Shouldn't go past the end of the movie
// Input: None
// Returns: Nothing
void MoviePlayer::goFwrd()
{
	// While not at the end
	if (pos->mNext != nullptr){
		// Increment currFrameNum
		currFrameNum++;
		// Increment pos
		pos++;
	}
}

// Function: goBack
// Purpose: Moves the current "frame" backward by 1 frame
// Also keeps track of how many frames have been viewed
// Shouldn't go past the end of the movie
// Input: None
// Returns: Nothing
void MoviePlayer::goBack()
{
	// While not at the end
	if (pos->mPrev != nullptr){
		// Decrement currFrameNum
		currFrameNum--;
		// Decrement pos
		pos--;
	}
}

// Function: rewind
// Purpose: Moves the current "frame" to the movie's beginning again
// Input: None
// Returns: Nothing
void MoviePlayer::rewind()
{
    // Move pos to movie's beginning
	pos = mFilm.begin();
	// Make currFrameNum = 1
	currFrameNum = 1;
}

// Function: getCurrFrame
// Purpose: Gets the string that contains the current "frame" as stored
// in the list "mFilm"
// Input: None
// Returns: String with the current "frame"
std::string MoviePlayer::getCurrFrame()
{
    return *pos;
}

// Function: delCurrFrame
// Purpose: Deletes the current frame, moves forward to the next one
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::delCurrFrame()
{
	// Delete current frame and store back in pos
	if (pos->mNext != nullptr){
		pos = mFilm.erase(pos);
	}
}

// Function: copyCurrFrame
// Purpose: Copies current frame and places the copy BEFORE the current frame
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::copyCurrFrame()
{
	pos = mFilm.insert(pos, *pos);
}

// Function: getCurrFrameNum
// Purpose: Gets the "index" that corresponds to the current frame
// Input: None
// Returns: Number of frames that have been viewed
unsigned MoviePlayer::getCurrFrameNum() const
{
    // TODO: Implement
    return currFrameNum;
}

// Function: getNumFrames
// Purpose: Gets the total number of frames in the movie
// Input: None
// Returns: The overall number of frames in the movie
unsigned int MoviePlayer::getNumFrames() const
{
	// Gets total number of frames in movie - size of mFilm
    return mFilm.size();
}

// Function: getFrameSize
// Purpose: Gives the number of lines in a frame
// For how big the "screen" for the film should be
// Input: None
// Returns: The value stored in FRAMESIZE
unsigned int MoviePlayer::getFrameSize() const
{
    return FRAMESIZE;
}

// Function: getCurrFrame
// Purpose: Retrieves the current "frame" from the film list
// Modifies the inputted vector of GLabels to contain the current frame
// Input: A vector of "GLabels" that are the "screen" -- passed by reference
// Returns: Nothing
void MoviePlayer::getCurrFrame(Vector<GLabel*>& screen)
{
	std::string temp = *pos;
	std::stringstream stream(temp);
	
	std::string eachLine = "";
	for (int i = 0; i < screen.size(); i++){
		std::getline(stream, eachLine);
		screen[i]->setLabel(eachLine);
	}
}

// Function: loadTape
// Purpose: Uses mFilmName (set by constructor) to fill
// mFilm with strings that make up the movie to display
// Input: None
// Returns: Nothing
void MoviePlayer::loadTape()
{
	std::ifstream file(mFilmName);
	if (file.is_open()){
		while (!file.eof()){
			std::string currentLine;
			std::getline(file, currentLine);
			// Convert the string number into an integer for later use
			int numTimesToPush = atoi(currentLine.c_str());
			// Create big string of frame to push into list
			std::string stringToPush = "";
			for (int i = 0; i < FRAMESIZE; i++){
				// Get each line
				std::getline(file, currentLine);
				// Concatenate each line into big string
				stringToPush += currentLine + " \n";
			}
			// Push back frames number of times numTimesToPush
			for (int i = 0; i < numTimesToPush; i++){
				mFilm.push_back(stringToPush);
			}
		}
	}
	else{
		error("Error: File not found");
	}
}

