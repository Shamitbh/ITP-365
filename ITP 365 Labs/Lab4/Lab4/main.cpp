// ITP 365 Spring 2017
// LP04 - Money
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: MAC
//
// main.cpp

#include <iostream>
#include "money.h"

int main(int argc, const char * argv[]) {

	double incomeFirst = 0.0;
	double incomeSecond = 0.0;
	int kids = 0;
	
	// read in input from user
	std::cout << "How much money do you have? ";
	std::cin >> incomeFirst;
	
	std::cout << "How much money does your spouse have? ";
	std::cin >> incomeSecond;
	
	std::cout << "How many kids do you have? ";
	std::cin >> kids;
	
	// basically take numbers before decimal and make dollars
	// and make the numbers after the decimal cents
	int incomeFirstDollar = int(incomeFirst);
	int incomeFirstCent = int(incomeFirst * 100) % 100;
	
	int incomeSecondDollar = int(incomeSecond);
	int incomeSecondCent = int(incomeSecond * 100) % 100;
	
	// create objects of Money class
	Money m1(incomeFirstDollar, incomeFirstCent);
	Money m2(incomeSecondDollar, incomeSecondCent);
	
	// do Calculation
	Money m3 = (m1 + m2) / kids;
	
	std::cout << "Split evenly, your kids will all get " << m3 << " if you both died today." << std::endl;
	
    return 0;
}
