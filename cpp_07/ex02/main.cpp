#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
#define BLUE	"\033[34;1m"
#define RESET	"\033[0m"

int main(int, char**)
{
    std::cout << BLUE"Tests from subject"RESET << std::endl;
    d
    int* mirror = new int[MAX_VAL];
    std::cout <<  numbers.size() << std::endl;
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
        std::cout <<  numbers[i] << std::endl;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;


    std::cout << BLUE"Tests for const"RESET << std::endl;
    Array<const int> numbers2(MAX_VAL);
    const int* mirror2 = new int[MAX_VAL];
    std::cout <<  numbers2.size() << std::endl;

    try
    {
        std::cout << numbers2[-2] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete [] mirror2;



    return 0;
}
