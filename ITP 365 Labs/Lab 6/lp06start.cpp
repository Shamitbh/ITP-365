
#include <iostream>
#include <chrono>
#include <list>


int main()
{
    unsigned int stopNum = -1;
    std::cout << "Where shall I stop counting?\n> ";
    std::cin >> stopNum;
    
    std::chrono::time_point<std::chrono::system_clock> timeStart, timeEnd;
    std::chrono::duration<double> elapsedTime;
    
    // Counting tests
    std::cout << "Counting to " << stopNum << "... ";
    timeStart = std::chrono::system_clock::now();
    for (unsigned int i = 0; i < stopNum; i++)
    {
        // Does nothing,
        // Just timing loop
    }
    timeEnd = std::chrono::system_clock::now();
    elapsedTime = timeEnd - timeStart;
    std::cout << elapsedTime.count() << "s" << std::endl;
    
    return 0;
}


