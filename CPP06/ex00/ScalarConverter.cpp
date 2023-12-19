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

void ScalarConverter::_getType()
{
	bool has_dot = false;

	for (unsigned long i = 0; i < this->_input.length(); i++)
	{
		if (this->_input[i] == '.')
		{
			if (has_dot || i == 0 || this->_input[i + 1] == '\0' || this->_input[i + 1] == 'f')
			{
				this->_type = "impossible";
				return;
			}
			has_dot = true;
		}
		else if (!isdigit(this->_input[i]))
		{
			if (this->_input[i] == 'f' && i == this->_input.length() - 1)
			{
				this->_type = "float";
				return;
			}
			else if (i == 0 && (this->_input[i] == '-' || this->_input[i] == '+'))
				continue;
			else
			{
				this->_type = "impossible";
				return;
			}
		}
	}
	if (has_dot)
		this->_type = "double";
	else
		this->_type = "int";
}

void ScalarConverter::convert()
{
	_getType();
	if (this->_input.length() == 1 && !isdigit(this->_input[0]))
	{
		this->_char = this->_input[0];
		this->_int = static_cast<int>(this->_char);
		this->_float = static_cast<float>(this->_char);
		this->_double = static_cast<double>(this->_char);
		this->_isChar = true;
		this->_isInt = true;
		this->_isFloat = true;
		this->_isDouble = true;
		this->_type = "char";
	}
	else if (this->_input == "nanf" || this->_input == "inff" || this->_input == "+inff" || this->_input == "-inff")
	{
		this->_float = std::stof(this->_input);
		this->_double = static_cast<double>(this->_float);
		this->_isFloat = true;
		this->_isDouble = true;
		this->_isChar = false;
		this->_isInt = false;
		this->_type = "float";
	}
	else if (this->_input == "nan" || this->_input == "inf" || this->_input == "-inf" || this->_input == "+inf")
	{
		this->_double = std::stod(this->_input);
		this->_float = static_cast<float>(this->_double);
		this->_isFloat = true;
		this->_isDouble = true;
		this->_isChar = false;
		this->_isInt = false;
		this->_type = "double";
	}
	else if (this->_type == "impossible")
	{
		this->_isChar = false;
		this->_isInt = false;
		this->_isFloat = false;
		this->_isDouble = false;
	}
	else if (this->_type == "float")
	{
		try
		{
			this->_float = std::stof(this->_input);
			if (this->_float >= 0 && this->_float <= 127)
			{
				this->_char = static_cast<char>(this->_float);
				this->_isChar = true;
			}
			if (this->_float >= INT_MIN && this->_float <= INT_MAX)
			{
				this->_int = static_cast<int>(this->_float);
				this->_isInt = true;
			}
			this->_double = static_cast<double>(this->_float);
			this->_isFloat = true;
			this->_isDouble = true;
		}
		catch(const std::exception& e)
		{
			this->_isChar = false;
			this->_isInt = false;
			this->_isFloat = false;
			this->_isDouble = false;
			this->_type = "impossible";
		}
	}
	else if (this->_type == "double")
	{
		try
		{
			this->_double = std::stod(this->_input);
			if (this->_double >= 0 && this->_double <= 127)
			{
				this->_char = static_cast<char>(this->_int);
				this->_isChar = true;
			}
			if (this->_double >= INT_MIN && this->_double <= INT_MAX)
			{
				this->_int = static_cast<int>(this->_double);
				this->_isInt = true;
			}
			if (this->_double >= std::numeric_limits<float>::lowest() && this->_double <= std::numeric_limits<float>::max())
			{
				this->_float = static_cast<float>(this->_double);
				this->_isFloat = true;
			}
			this->_isDouble = true;
		}
		catch (std::exception &e)
		{
			this->_isChar = false;
			this->_isInt = false;
			this->_isFloat = false;
			this->_isDouble = false;
			this->_type = "impossible";
		}
	}
	else if (this->_type == "int")
	{
		try
		{
			this->_int = std::stoi(this->_input);
			if (this->_int >= 0 && this->_int <= 127)
			{
				this->_char = static_cast<char>(this->_int);
				this->_isChar = true;
			}
			this->_float = static_cast<float>(this->_int);
			this->_double = static_cast<double>(this->_int);
			this->_isInt = true;
			this->_isFloat = true;
			this->_isDouble = true;
		}
		catch (std::exception &e)
		{
			this->_isChar = false;
			this->_isInt = false;
			this->_isFloat = false;
			this->_isDouble = false;
			this->_type = "impossible";
		}
	}
}

void ScalarConverter::printScalar()
{
	std::cout << "Type: " << this->_type << std::endl;
	if (this->_isChar)
		std::cout << "char: '" << this->_char << "'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (this->_isInt)
		std::cout << "int: " << this->_int << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (this->_isFloat)
		std::cout << "float: " << this->_float << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	if (this->_isDouble)
		std::cout << "double: " << this->_double << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}
