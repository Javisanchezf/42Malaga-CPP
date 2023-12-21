#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

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

/*---------------------------INCLUDES---------------------------*/
#include <iostream>


/*--------------------------PROTOTYPES--------------------------*/
template <typename T>
class Array{
private:
	unsigned int _size;
	T *_array;
public:
	Array() : _size(0), _array(NULL) {}
	Array(unsigned int n) : _size(n), _array(new T[n]) {}
	Array(Array const &other) : _size(other._size), _array(new T[other._size]) {
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	Array &operator=(Array const &other) {
		if (this != &other) {
			delete[] _array;
			_size = other._size;
			_array = new T[other._size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		return *this;
	}
	~Array() {
		delete[] _array;
	}

	T &operator[](unsigned int i) {
		if (i >= _size)
			throw std::exception();
		return _array[i];
	}

	unsigned int size() const {
		return _size;
	}
};

template < typename T >
std::ostream& operator<<( std::ostream& out, Array<T>& arr ) {
    for ( unsigned int i( 0 ); i < arr.size(); i++ )
        out << arr[i] << " ";
    return out;
}

#endif