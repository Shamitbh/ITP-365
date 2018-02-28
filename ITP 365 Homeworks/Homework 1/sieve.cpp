#include "sieve.h"


void drawSquare(GWindow& gw, int number, NumberType color, double x, double y){
    // set color depending on NumberType
    switch (color){
        case UNKNOWN:
            gw.setColor("WHITE");
            break;
        case PRIME:
            gw.setColor("GREEN");
            break;
        case COMPOSITE:
            gw.setColor("RED");
            break;
    }
    //actually draw the filled rectangle
    gw.fillRect(x, y, 50, 50);
    
    //switch color back to black and draw rect. border
    gw.setColor("BLACK");
    gw.drawRect(x, y, 50, 50);
    
    //draw label in middle of rectangle
    gw.drawLabel(std::to_string(number), x + 25, y + 25);
}

void initVectors(Vector<int>& numbers, Vector<NumberType>& numType){
    // add elements 2 -> 101 in numbers vector
    for (int i = 2; i <= 101; i++){
        numbers.add(i);
    }
    //initialize 100 elements to UNKNOWN
    for (int i = 0; i < 100; i++){
        numType.add(UNKNOWN);
    }
}

void drawGrid(GWindow& gw, Vector<int>& numbersSieve, Vector<NumberType>& numTypeSieve){
    double x = 0;
    double y = 0;
    for (int i = 0; i < 100; i++){
        drawSquare(gw, numbersSieve[i], numTypeSieve[i], x, y);
        x += 50;
		// if last square on the line go down one row
        if (x > 450){
            x = 0;
            y += 50;
        }
    }
}

int calcNextPrime(Vector<int>& numSieve, Vector<NumberType>& typeSieve, int startAt){
    int nextPrimeNum = -1;
    // go through the typeSieve vector
    for (int i = startAt - 2; i < typeSieve.size(); i++)
    {
        
        if (typeSieve[i] == UNKNOWN)
        {
            // this number guaranteed to be prime
            nextPrimeNum = numSieve[i];
            typeSieve[i] = PRIME;
            break;
        }
    }
    // go through type vector and make all multiples of num COMPOSITE
    if (nextPrimeNum > 0)
    {
        for (int j = nextPrimeNum - 1; j < typeSieve.size(); j++)
        {
            if (numSieve[j] % nextPrimeNum  == 0)
            {
                // its a multiple of num
                typeSieve[j] = COMPOSITE;
            }
        }
    }
    return nextPrimeNum;
}
