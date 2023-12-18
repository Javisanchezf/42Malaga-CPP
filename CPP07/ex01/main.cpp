#include "iter.hpp"


template <typename T>
void print(T const &x) {
	std::cout << x << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string stringArray[] = {"Hello", "World", "!"};

    std::cout << "intArray: ";
    iter(intArray, sizeof(intArray) / sizeof(int), print);
    std::cout << std::endl;

    std::cout << "stringArray: ";
    iter(stringArray, sizeof(stringArray) / sizeof(std::string), print);
    std::cout << std::endl;

    return 0;
}