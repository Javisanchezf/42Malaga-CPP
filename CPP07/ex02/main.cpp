#include <iostream>
#include "Array.hpp"

// #define MAX_VAL 20
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << RED "didn't save the same value!!" DEFAULT << std::endl;
//             return 1;
//         }
// 		else
// 			std::cout << GREEN "numbers[" << i << "] = " << numbers[i] << DEFAULT << std::endl;
//     }
//     delete [] mirror;//

// 	Array<std::string> strings(4);
// 	strings[0] = "Hello";
// 	strings[1] = "World";
// 	strings[2] = "!";
// 	strings[3] = "How are you?";
// 	for (unsigned int i = 0; i < strings.size(); i++)
// 		std::cout << BLUE "strings[" << i << "] = " << strings[i] << DEFAULT << std::endl;	
//     return 0;
// }

#define SIZE 20

int main( void )
{
    std::cout << "-----------------------------------------------------" << std::endl;

    Array< float > test;

    Array< int > intArray(SIZE);
    Array< int > intArray2(0);

    for ( unsigned int i = 0; i < intArray.size(); i++ )
        intArray[i] = i * 2;

    std::cout << GREEN "Int Array 1: " << intArray << DEFAULT << std::endl;

    intArray2 = intArray;
	intArray2[0] = 42;
	std::cout << "Changing the first value of Array to : " << intArray2[0] << std::endl;
    std::cout << BLUE "int Array 2: " << intArray2 << DEFAULT << std::endl;

	std::cout << "-----------------------------------------------------" << std::endl;
    try {
        std::cout << GREEN "Accessing a valid index: " << intArray[5] << DEFAULT << std::endl;
        std::cout << RED "Accessing an invalid index: " << intArray[SIZE] << DEFAULT << std::endl;
    } catch ( std::exception & e) {
        std::cout << RED "Error: " << e.what() << DEFAULT << std::endl;
    }
    std::cout << "-----------------------------------------------------" << std::endl;
	Array<std::string> strings(4);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "!";
	strings[3] = "How are you?";
	for (unsigned int i = 0; i < strings.size(); i++)
		std::cout << BLUE "strings[" << i << "] = " << strings[i] << DEFAULT << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
    return 0;
}