// ITP 365 Spring 2017
// LP7 - Templated Function
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: Mac

#include <iostream>
#include <vector>
#include <cmath>


// Function: average
// Purpose: returns average of elements in vector
// Input: templated vector
// Output: templated average
template <typename T>
T average(std::vector<T> vec){
	T total = 0;
	for (int i = 0; i < vec.size(); i++){
		total += vec[i];
	}
	return total / vec.size();
}

int main(int argc, const char * argv[]) {
	// Create vector of ints and decimal values
	std::vector<int> intVec;
	std::vector<double> doubleVec;
	
	int stoppingNum;
	std::cout << "How many items should I use: ";
	std::cin >> stoppingNum;
	
	for (int i = 0; i < stoppingNum; i++){
		intVec.push_back(i);
		doubleVec.push_back(sqrt(i));
	}
	
	int averageTotalInt;
	averageTotalInt = average(intVec);
	
	
	double averageTotalDouble;
	averageTotalDouble = average(doubleVec);
	
	std::cout << "Integer average is: " << averageTotalInt << std::endl;
	std::cout << "Double average is: " << averageTotalDouble << std::endl;
	
    return 0;
}
