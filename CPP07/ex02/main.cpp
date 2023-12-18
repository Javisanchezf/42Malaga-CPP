#include <iostream>
#include "Array.hpp"

#define MAX_VAL 20
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
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
            std::cerr << RED "didn't save the same value!!" DEFAULT << std::endl;
            return 1;
        }
		else
			std::cout << GREEN "numbers[" << i << "] = " << numbers[i] << DEFAULT << std::endl;
    }
    delete [] mirror;//

	Array<std::string> strings(4);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "!";
	strings[3] = "How are you?";
	for (unsigned int i = 0; i < strings.size(); i++)
		std::cout << BLUE "strings[" << i << "] = " << strings[i] << DEFAULT << std::endl;	
    return 0;
}
