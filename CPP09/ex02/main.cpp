#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: ./PmergeMe numbers" << std::endl;
        return 1;
    }
    argv++;
    PmergeMe merger;
    merger.merge(argv);
    return 0;
}