// ITP 365 Spring 2017
// Lab03
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac

#include <iostream>
#include "map.h"

// Function: loadSubreddits
// Purpose: Read from file and make map of all subreddits
// Input: fileName, and map to store subreddit keys/values
// Output: None
void loadSubreddits(std::string& fileName, Map<std::string, std::string>& Subreddits);

// Function: print Menu
// Purpose: print the Menu to user
// Input: None
// Output: None
void printMenu();

int main(int argc, char** argv)
{
	Map<std::string, std::string> SubReddits;
	std::string filename = "srtallies.csv";
	loadSubreddits(filename, SubReddits);
	
	std::string userInput = "";
	while (true){
		printMenu();
		std::getline(std::cin, userInput);
		if (userInput != "1" && userInput != "2"){
			// quit program
			std::cout << "Bye!" << std::endl;
			break;
		}
		else if(userInput == "1"){
			// look up subreddit
			std::string subredditName = "";
			std::cout << "Enter a subreddit name: ";
			std::getline(std::cin, subredditName);
			if (SubReddits.containsKey(subredditName)){
				std::cout << subredditName << " --> " << SubReddits[subredditName] << std::endl;
			}
			else{
				std::cout << subredditName << " --> No known subreddit!" << std::endl;
			}
		}
		else{
			// list subreddits codes
			for (std::string code : SubReddits){
				std::cout << code << std::endl;
			}
		}
	}
    return 0;
}

void loadSubreddits(std::string& fileName, Map<std::string, std::string>& Subreddits){
	std::ifstream file(fileName);
	// open file
	if (file.is_open()){
		// go through file contents
		while (!file.eof()){
			std::string line;
			std::getline(file, line);
			//find index of comma
			int index = line.find(",", 0);
			// get characters up to comma and make it the key
			std::string key = line.substr(0, index);
			// get characters after comma and make it the value
			std::string value = line.substr(index + 1);
			// add key and value to map
			Subreddits[key] = value;
		}
	}
	else{
		std::cout << "Error! File failed to open properly." << std::endl;
	}
}

void printMenu(){
	std::cout << "1) Look up subreddit" << std::endl;
	std::cout << "2) List subreddits codes" << std::endl;
	std::cout << "?) Quit" << std::endl;
	std::cout << "> ";
}

