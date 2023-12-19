#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>

class Span
{
	private:
		unsigned int _n;
		unsigned int _size;
		int *_arr;
	public:
		Span(unsigned int n);
		Span(const Span &copy);
		~Span();
		Span &operator=(const Span &copy);
		void addNumber(int n);
		void addNumber(int *arr, unsigned int size);
		int shortestSpan();
		int longestSpan();
		class FullException: public std::exception
		{
			virtual const char *what() const throw();
		};
		class NoSpanException: public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif