#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **input) : _vectorTime(0), _dequeTime(0)
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
        this->_deque = var._deque;
        this->_vectorTime = var._vectorTime;
        this->_dequeTime = var._dequeTime;
    }
}

PmergeMe &PmergeMe::operator=(const PmergeMe &var)
{
    if (this != &var)
    {
        this->_input = var._input;
        this->_vector = var._vector;
        this->_deque = var._deque;
        this->_vectorTime = var._vectorTime;
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
void PmergeMe::_merge(Iterator begin, Iterator mid, Iterator end)
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
void PmergeMe::_merge_sort(Iterator begin, Iterator end)
{
    typename std::iterator_traits<Iterator>::difference_type size = std::distance(begin, end);

    if (size < 2)
        return;

    Iterator mid = begin + size / 2;

    _merge_sort(begin, mid);
    _merge_sort(mid, end);

    _merge(begin, mid, end);
}


template <typename Container>
void PmergeMe::_execute(Container &container, double &time)
{
    std::clock_t start;
    std::clock_t end;

    if (time == 0)
    {
        start = std::clock();
        this->_fillContainer(container, this->_input);
        this->_merge_sort(container.begin(), container.end());
        end = std::clock();
    }
    time = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000.0);
}

void PmergeMe::run()
{
    std::string color_v = DEFAULT;
    std::string color_d = DEFAULT;
    this->_execute(this->_vector, this->_vectorTime);
    this->_execute(this->_deque, this->_dequeTime);
    if (this->_vectorTime < this->_dequeTime)
    {
        color_v = GREEN;
        color_d = YELLOW;
    }
    else if (this->_vectorTime > this->_dequeTime)
    {
        color_v = YELLOW;
        color_d = GREEN;
    }
    else
    {
        color_v = BLUE;
        color_d = BLUE;
    }

    std::cout << "Before sorting: ";
    for (int i = 0; this->_input[i] && i < 10; i++)
        std::cout << this->_input[i] << " ";
    if (this->_vector.size() > 10)
        std::cout << " [...]";
    std::cout << std::endl;
    std::cout << "After sorting: ";
    for (unsigned long i = 0; i < 10 && i < this->_vector.size(); i++)
        std::cout << this->_vector[i] << " ";
    if (this->_vector.size() > 10)
        std::cout << " [...]";
    std::cout << std::endl;
    std::cout << color_v;
    std::cout << "Time to proccess a range of "<< this->_vector.size() << " elements with std::vector: " <<std::fixed << std::setprecision(4) << this->_vectorTime << " ms" << std::endl;
    std::cout << color_d;
    std::cout << "Time to proccess a range of "<< this->_deque.size() << " elements with std::deque: " <<std::fixed << std::setprecision(4) << this->_dequeTime << " ms" << std::endl;
    std::cout << DEFAULT;

}

void PmergeMe::run_vector()
{
    this->_execute(this->_vector, this->_vectorTime);

    std::cout << "Before sorting: ";
    for (int i = 0; this->_input[i] && i < 10; i++)
        std::cout << this->_input[i] << " ";
    if (this->_vector.size() > 10)
        std::cout << " [...]";
    std::cout << std::endl;
    std::cout << "After sorting: ";
    for (unsigned long i = 0; i < 10 && i < this->_vector.size(); i++)
        std::cout << this->_vector[i] << " ";
    if (this->_vector.size() > 10)
        std::cout << " [...]";
    std::cout << std::endl;
    std::cout << "Time to proccess a range of "<< this->_vector.size() << " elements with std::vector: " <<std::fixed << std::setprecision(4) << this->_vectorTime << " ms" << std::endl;
}

void PmergeMe::run_deque()
{
    std::cout << "Before sorting: ";
    for (int i = 0; this->_input[i] && i < 10; i++)
        std::cout << this->_input[i] << " ";
    if (this->_deque.size() > 10)
        std::cout << " [...]";
    std::cout << std::endl;
    std::cout << "After sorting: ";
    for (unsigned long i = 0; i < 10 && i < this->_deque.size(); i++)
        std::cout << this->_deque[i] << " ";
    if (this->_deque.size() > 10)
        std::cout << " [...]";
    std::cout << std::endl;
    std::cout << "Time to proccess a range of "<< this->_deque.size() << " elements with std::deque: " <<std::fixed << std::setprecision(4) << this->_dequeTime << " ms" << std::endl;
    std::cout << DEFAULT;
}