// ITP 365 Spring 2017
// Lab02
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac

#include <string>
#include <fstream>
#include "vector.h"
#include <iostream>
#include "strlib.h"


int main(int argc, char** argv)
{
	// Code goes here!
    std::string fname = "";
    
    // Prompt user for input
    std::cout << "Where are Shakespeare's sonnets saved? ";
    std::cin >> fname;
    
    std::cin.ignore();
    
    // Open up the file
    std::ifstream file(fname);
    
    // Check to see if it opened successfully...
    if (!file.is_open()){
        std::cout << "Bad file name!" << std::endl;
        return 1;
    }
    
    std::string line1 = "";
    std::string line2 = "";
    std::string currSonnet = "";
    Vector<std::string> sonnets;
    
    // Slurp up the file
    while (!file.eof()){
        std::getline(file, line1);
        // std::cout << line1 << std::endl;
        if (line1.find("THE SONNETS", 0) == 0){
            // found the SONNETS!
            // std::cout << "Found the beginning of the sonnets!" << std::endl;
            //skip 2 lines
            std::getline(file, line1);
            std::getline(file, line1);
            
            
            while (!file.eof()){
                std::getline(file, line2);
                
                if (line2.find("THE END", 0) == 0){
                    // std::cout << "Found the end of the sonnets!" << std::endl;
                    break;
                }
                else if (stringIsInteger(trim(line2))){ // trim gets rid of extra spaces
                    // found the beginning of a sonnet
                    //std::cout << trim(line2) << std::endl;
                }
                else if (trim(line2).size() == 0){
                    // found an empty line...skip it!
                    // means I hit the end of a sonnet
                    if (currSonnet.size() > 0){
                        // store currSonnet before resetting it
                        sonnets.add(currSonnet);
                        // current Sonnet is over, so reset current sonnet
                        currSonnet = "";
                    }
                }
                else{
                    // we found sonnet text!
                    // std::cout << line2 << std::endl;
                    currSonnet += line2 + "\n";
                }
                
                
                
            } // Inner loop's end
            // std::cout << currSonnet << std::endl;
        }// If for "THE SONNETS" end
    } // Outer loop's end
    
    std::cout << "Just loaded " << sonnets.size() << " sonnets!" << std::endl;
    
    
    // handle user input
    
    std::string userInput;
    int index = 0;
    
    // loop goes here
    while (1){
        std::cout << "Which would you like to read? ";
        std::getline(std::cin, userInput);
        // Clean up the user's input
        userInput = trim(userInput);
        
        if (stringIsInteger(userInput)){
            // we have a number
            index = stringToInteger(userInput);
            
            if (index <= 0){
                return 0;
            }
            else if (index > sonnets.size()){
                std::cout << "Please enter a number between 1 and 154" << std::endl;
            }
            else{
                std::cout << "Sonnet #" << index << std::endl;
                std::cout << sonnets[index - 1] << std::endl;
            }
            // std::cout << index << std::endl;
        }
        else{
            std::cout << "Please enter a number between 1 and 154" << std::endl;
        }
    } // end forever while loop
    
    
	return 0;
}
