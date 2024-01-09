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


class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::list<int> _list;
        std::deque<int> _deque;
        float _vectorTime;
        float _listTime;
        float _dequeTime;
        void _printVector();
        void _printList();
        void _printDeque();
        void _fillVector(char **input);
        void _fillList(char **input);
        void _fillDeque(char **input);
        void _mergesort_vector();
        void _mergesort_list();
        void _mergesort_deque();
        void _printTime();

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &var);
        PmergeMe &operator=(const PmergeMe &var);
        ~PmergeMe();
        void merge(char **input);
};

#endif