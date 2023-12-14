# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string input) : _input(input), _char(0), _int(0), _float(0), _double(0), _isChar(false), _isInt(false), _isFloat(false), _isDouble(false)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	if (this != &other)
	{
		this->_input = other._input;
		this->_char = other._char;
		this->_int = other._int;
		this->_float = other._float;
		this->_double = other._double;
		this->_isChar = other._isChar;
		this->_isInt = other._isInt;
		this->_isFloat = other._isFloat;
		this->_isDouble = other._isDouble;
	}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert()
{
	if (this->_input.length() == 1 && !isdigit(this->_input[0]))
	{
		this->_char = this->_input[0];
		this->_isChar = true;
	}
	else
	{
		try
		{
			this->_int = std::stoi(this->_input);
			this->_isInt = true;
			std::cout << "INT" << std::endl;
		}
		catch (std::exception &e)
		{
			;
		}
		try
		{
			this->_float = std::stof(this->_input);
			this->_isFloat = true;
			std::cout << "FLOAT" << std::endl;
		}
		catch (std::exception &e)
		{
			;
		}
		try
		{
			this->_double = std::stod(this->_input);
			this->_isDouble = true;
			std::cout << "DOUBLE" << std::endl;
		}
		catch (std::exception &e)
		{
			;
		}
	}
}

void ScalarConverter::printChar()
{
	if (this->_isChar)
	{
		std::cout << "char: '" << this->_char << "'" << std::endl;
	}
	else if (this->_isInt && this->_int >= 0 && this->_int <= 127)
	{
		std::cout << "char: '" << static_cast<char>(this->_int) << "'" << std::endl;
	}
	else if (this->_isFloat && this->_float >= 0 && this->_float <= 127)
	{
		std::cout << "char: '" << static_cast<char>(this->_float) << "'" << std::endl;
	}
	else if (this->_isDouble && this->_double >= 0 && this->_double <= 127)
	{
		std::cout << "char: '" << static_cast<char>(this->_double) << "'" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
	}
}

void ScalarConverter::printInt()
{
	if (this->_isChar)
	{
		std::cout << "int: " << static_cast<int>(this->_char) << std::endl;
	}
	else if (this->_isInt)
	{
		std::cout << "int: " << this->_int << std::endl;
	}
	else if (this->_isFloat && this->_float >= INT_MIN && this->_float <= INT_MAX)
	{
		std::cout << "int: " << static_cast<int>(this->_float) << std::endl;
	}
	else if (this->_isDouble  && this->_double >= INT_MIN && this->_double <= INT_MAX)
	{
		std::cout << "int: " << static_cast<int>(this->_double) << std::endl;
	}
	else
	{
		std::cout << "int: impossible" << std::endl;
	}
}


void ScalarConverter::printFloat()
{
	if (this->_isChar)
	{
		std::cout << "float: " << static_cast<float>(this->_char) << ".0f" << std::endl;
	}
	else if (this->_isInt)
	{
		std::cout << "float: " << static_cast<float>(this->_int) << ".0f" << std::endl;
	}
	else if (this->_isFloat)
	{
		std::cout << "float: " << this->_float << "f" << std::endl;
	}
	else if (this->_isDouble)
	{
		std::cout << "float: " << static_cast<float>(this->_double) << "f" << std::endl;
	}
	else
	{
		std::cout << "float: impossible" << std::endl;
	}
}


void ScalarConverter::printDouble()
{
	if (this->_isChar)
	{
		std::cout << "double: " << static_cast<double>(this->_char) << ".0" << std::endl;
	}
	else if (this->_isInt)
	{
		std::cout << "double: " << static_cast<double>(this->_int) << ".0" << std::endl;
	}
	else if (this->_isFloat)
	{
		std::cout << "double: " << static_cast<double>(this->_float) << std::endl;
	}
	else if (this->_isDouble)
	{
		std::cout << "double: " << this->_double << std::endl;
	}
	else
	{
		std::cout << "double: impossible" << std::endl;
	}
}

void ScalarConverter::printImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [input]" << std::endl;
		return (1);
	}
	ScalarConverter converter(argv[1]);
	converter.convert();
	converter.printChar();
	converter.printInt();
	converter.printFloat();
	converter.printDouble();
	return (0);
}

