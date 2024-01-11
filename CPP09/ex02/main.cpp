#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: ./PmergeMe numbers" << std::endl;
        return 1;
    }
    argv++;
    try
    {
        PmergeMe merger(argv);
        merger.run();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}