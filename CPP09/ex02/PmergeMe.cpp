#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **input) : _vectorTime(0), _listTime(0), _dequeTime(0)
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
                    throw InvalidInputException();
            }
        }
    }
    this->_input = input;
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
        this->_input = var._input;
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
        this->_input = var._input;
        this->_vector = var._vector;
        this->_list = var._list;
        this->_deque = var._deque;
        this->_vectorTime = var._vectorTime;
        this->_listTime = var._listTime;
        this->_dequeTime = var._dequeTime;
    }
    return (*this);
}

template <typename Container>
Container PmergeMe::_fillContainer(Container &container, char **input)
{
    int i = -1;

    while (input[++i])
        container.push_back((atoi(input[i])));
    return (container);
}

template <typename Container>
void PmergeMe::_printContainer(Container &container)
{
    for (typename Container::iterator it = container.begin(); it != container.end(); it++)
    {
        std::cout << *it;
        if (it != --container.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}

template <typename Iterator>
void PmergeMe::merge(Iterator begin, Iterator mid, Iterator end)
{
    std::vector<typename std::iterator_traits<Iterator>::value_type> left(begin, mid);
    std::vector<typename std::iterator_traits<Iterator>::value_type> right(mid, end);

    typename std::vector<typename std::iterator_traits<Iterator>::value_type>::iterator leftIter = left.begin();
    typename std::vector<typename std::iterator_traits<Iterator>::value_type>::iterator rightIter = right.begin();
    Iterator currentIter = begin;

    while (leftIter != left.end() && rightIter != right.end())
    {
        if (*leftIter < *rightIter)
        {
            *currentIter = *leftIter;
            ++leftIter;
        }
        else
        {
            *currentIter = *rightIter;
            ++rightIter;
        }
        ++currentIter;
    }

    std::copy(leftIter, left.end(), currentIter);
    std::copy(rightIter, right.end(), currentIter);
}

template <typename Iterator>
void PmergeMe::merge_sort(Iterator begin, Iterator end)
{
    typename std::iterator_traits<Iterator>::difference_type size = std::distance(begin, end);

    if (size < 2)
        return;

    Iterator mid = begin + size / 2;

    merge_sort(begin, mid);
    merge_sort(mid, end);

    merge(begin, mid, end);
}


template <typename Container>
void PmergeMe::_execute(Container &container, float &time)
{
    std::clock_t start;
    std::clock_t end;

    if (time == 0)
    {
        start = std::clock();
        this->_fillContainer(container, this->_input);
        this->merge_sort(container.begin(), container.end());
        end = std::clock();
    }
    time = (end - start) / ((float)CLOCKS_PER_SEC / 1000000.0f);
}

void PmergeMe::run()
{
    this->_execute(this->_vector, this->_vectorTime);
    this->_execute(this->_deque, this->_dequeTime);
    std::cout << "Before sorting: ";
    for (int i = 0; this->_input[i]; i++)
        std::cout << this->_input[i] << " ";
    std::cout << std::endl;
    std::cout << "After sorting: ";
    this->_printContainer(this->_vector);
    std::cout << "Time to proccess a range of "<< this->_vector.size() << " elements with std::vector: " <<std::fixed << std::setprecision(4) << this->_vectorTime << "us" << std::endl;
    std::cout << "Time to proccess a range of "<< this->_deque.size() << " elements with std::deque: " <<std::fixed << std::setprecision(4) << this->_dequeTime << "us" << std::endl;

}

