// Shamit Bhatia
// ITP 365, Spring 2017
// Lab 1
// Shamitbh@usc.edu

#include <iostream>

// Function header goes here:
unsigned int fib(unsigned int num);

int main(){
    unsigned int input = 0;
    std::cout << "How many Fibonacci numbers shall I compute? ";
    std::cin >> input;
    
    for (int i = 0; i <= input; i++){
        std::cout << i << "\t" << fib(i)<< std::endl;
    }
    return 0;
}

// Function: fib
// Purpose: Compute the fibonnaci number given an input number
// Input: One unsigned int to compute fibonacci number
// Output: Returns the unsigned integral result
unsigned int fib(unsigned int num){
    if (num < 2){
        return num;
    }
    else{
        unsigned int result = 0;
        unsigned int oneback = 1;
        unsigned int twoback = 0;
        
        for (unsigned int i = 1; i < num; i++){
            result = oneback + twoback;
            
            twoback = oneback;
            oneback = result;
        }
        return result;
    }
}
