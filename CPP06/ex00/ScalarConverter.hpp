#pragma once
# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
#include <limits>

class ScalarConverter
{
	private:
		std::string _input;
		char _char;
		int _int;
		float _float;
		double _double;
		bool _isChar;
		bool _isInt;
		bool _isFloat;
		bool _isDouble;
		std::string _type;
		void _getType();
		ScalarConverter();
	public:
		ScalarConverter(std::string input);
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();

		void convert();
		void printScalar();
};

# endif