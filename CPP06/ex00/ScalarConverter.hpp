#pragma once
# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

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
		ScalarConverter();
	public:
		ScalarConverter(std::string input);
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();

		void convert();
		void printChar();
		void printInt();
		void printFloat();
		void printDouble();
		void printImpossible();
};


# endif