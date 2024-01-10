#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vectorTime(0), _listTime(0), _dequeTime(0)
{
    return;
}

PmergeMe::~PmergeMe()
{
    return;
}

PmergeMe::PmergeMe(const PmergeMe &var)
{
    if (this != &var)
    {
        this->_vector = var._vector;
        this->_list = var._list;
        this->_deque = var._deque;
        this->_vectorTime = var._vectorTime;
        this->_listTime = var._listTime;
        this->_dequeTime = var._dequeTime;
    }
}

PmergeMe &PmergeMe::operator=(const PmergeMe &var)
{
    if (this != &var)
    {
        this->_vector = var._vector;
        this->_list = var._list;
        this->_deque = var._deque;
        this->_vectorTime = var._vectorTime;
        this->_listTime = var._listTime;
        this->_dequeTime = var._dequeTime;
    }
    return (*this);
}

void PmergeMe::_fillVector(char **input)
{
    int i = -1;

    while (input[++i])
        this->_vector.push_back((atoi(input[i])));
}

void PmergeMe::_fillList(char **input)
{
    int i = -1;

    while (input[++i])
        this->_list.push_back((atoi(input[i])));
}

void PmergeMe::_fillDeque(char **input)
{
    int i = -1;

    while (input[++i])
        this->_deque.push_back((atoi(input[i])));
}

void PmergeMe::_mergesort_vector()
{
    // std::clock_t start;
    // double duration;

    // start = std::clock();
    // std::sort(this->_vector.begin(), this->_vector.end());
    // duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    // this->_vectorTime = duration;
}

void PmergeMe::_mergesort_list()
{
    // std::clock_t start;
    // double duration;

    // start = std::clock();
    // this->_list.sort();
    // duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    // this->_listTime = duration;
}

void PmergeMe::_mergesort_deque()
{
    // std::clock_t start;
    // double duration;

    // start = std::clock();
    // std::sort(this->_deque.begin(), this->_deque.end());
    // duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    // this->_dequeTime = duration;
}

void PmergeMe::_printVector()
{
    std::cout << "Vector: ";
    for (size_t i = 0; i < this->_vector.size(); i++)
    {
        std::cout << this->_vector[i];
        if (i != this->_vector.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::_printList()
{
    std::cout << "List: ";
    for (std::list<int>::iterator it = this->_list.begin(); it != this->_list.end(); it++)
    {
        std::cout << *it;
        if (it != --this->_list.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::_printDeque()
{
    std::cout << "Deque: ";
    for (size_t i = 0; i < this->_deque.size(); i++)
    {
        std::cout << this->_deque[i];
        if (i != this->_deque.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}



void PmergeMe::_printTime()
{
    std::cout << "Vector: " << std::fixed << std::setprecision(3) << this->_vectorTime << "s" << std::endl;
    std::cout << "List: " << std::fixed << std::setprecision(3) << this->_listTime << "s" << std::endl;
    std::cout << "Deque: " << std::fixed << std::setprecision(3) << this->_dequeTime << "s" << std::endl;
}

void PmergeMe::merge(char **input)
{
    int i = -1;
    int j = -1;
    while (input[++i])
    {
        j = -1;
        while (input[i][++j])
        {
            if (!isdigit(input[i][j]))
            {
                if (input[i][j] == '-' && j == 0)
                    continue;
                else
                {
                    std::cout << "Error." << std::endl;
                    return;
                }
            }
        }
    }
    this->_fillVector(input);
    this->_fillList(input);
    this->_fillDeque(input);
    this->_mergesort_vector();
    this->_mergesort_list();
    this->_mergesort_deque();
    this->_printVector();
    this->_printList();
    this->_printDeque();
    this->_printTime();
    this->_vector.clear();
    this->_list.clear();
    this->_deque.clear();
    this->_vectorTime = 0;
    this->_listTime = 0;
    this->_dequeTime = 0;
}

