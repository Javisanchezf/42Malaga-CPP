#include "Span.hpp"

Span::Span(unsigned int n): _n(n), _size(0)
{
	_arr = new int[n];
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span::~Span()
{
	delete [] _arr;
}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		_n = copy._n;
		_size = copy._size;
		delete [] _arr;
		_arr = new int[_n];
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = copy._arr[i];
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_size == _n)
		throw FullException();
	_arr[_size++] = n;
}

void Span::addNumber(int *arr, unsigned int size)
{
	if (_size + size > _n)
		throw FullException();
	for (unsigned int i = 0; i < size; i++)
		_arr[_size++] = arr[i];
}

int Span::shortestSpan()
{
	if (_size < 2)
		throw NoSpanException();
	std::sort(_arr, _arr + _size);
	int min = _arr[1] - _arr[0];
	for (unsigned int i = 2; i < _size; i++)
	{
		if (_arr[i] - _arr[i - 1] < min)
			min = _arr[i] - _arr[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (_size < 2)
		throw NoSpanException();
	std::sort(_arr, _arr + _size);
	return _arr[_size - 1] - _arr[0];
}

const char *Span::FullException::what() const throw()
{
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw()
{
	return "No span to find";
}
