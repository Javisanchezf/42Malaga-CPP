#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <deque>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <algorithm>


class PmergeMe
{
    private:
        char **_input;
        std::vector<int> _vector;
        std::list<int> _list;
        std::deque<int> _deque;
        double _vectorTime;
        double _listTime;
        double _dequeTime;

        template <typename Container>
        Container _fillContainer(Container &container, char **input);

        template <typename Container>
        void _printContainer(Container &container);


        template <typename Iterator>
        void merge(Iterator begin, Iterator mid, Iterator end);

        template <typename Iterator>
        void merge_sort(Iterator begin, Iterator end);

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
};

#endif