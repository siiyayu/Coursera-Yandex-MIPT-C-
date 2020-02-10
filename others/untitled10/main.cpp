#include <iostream>
#include <random>
#include <ctime>

int main()
{
    std::mt19937 gen;
    //gen.seed(time(0)); // try to comment this string
    std::cout << "My number: " << gen() << std::endl;
}