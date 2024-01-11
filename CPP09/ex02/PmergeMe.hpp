#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

/*----------------------------LIBRARIES----------------------------*/
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>
#include <algorithm>

/*----------------------------COLORS----------------------------*/
# define BOLD		"\033[1m"
# define GRAY		"\033[30;1m"
# define RED		"\033[31;1m"
# define GREEN		"\033[32;1m"
# define YELLOW		"\033[33;1m"
# define BLUE		"\033[34;1m"
# define MAGENTA	"\033[35;1m"
# define CYAN		"\033[36;1m"
# define WHITE		"\033[37;1m"
# define DEFAULT	"\033[0m"

/*----------------------------CLASSES----------------------------*/
class PmergeMe
{
    private:
        char **_input;
        std::vector<int> _vector;
        std::deque<int> _deque;
        double _vectorTime;
        double _dequeTime;

        template <typename Container>
        Container _fillContainer(Container &container, char **input);

        template <typename Container>
        void _printContainer(Container &container);


        template <typename Iterator>
        void _merge(Iterator begin, Iterator mid, Iterator end);

        template <typename Iterator>
        void _merge_sort(Iterator begin, Iterator end);

        template <typename Container>
        void _execute(Container &container, double &time);

        class InvalidInputException: public std::exception
        {
            public:
                const char* what() const throw ()
                {
                    return ("Exception: invalid input");
                }
        };
    public:
        PmergeMe(char **input);
        PmergeMe(const PmergeMe &var);
        PmergeMe &operator=(const PmergeMe &var);
        ~PmergeMe();
        void run();
        void run_vector();
        void run_deque();
};

#endif