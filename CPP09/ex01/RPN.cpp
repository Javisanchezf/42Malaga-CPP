#include "RPN.hpp"

RPN::RPN()
{
	return;
}

RPN::~RPN()
{
	return;
}

RPN::RPN(const RPN &var)
{
	if (this != &var)
        this->numbers = var.numbers;
}

RPN &RPN::operator=(const RPN &var)
{
    if (this != &var)
        this->numbers = var.numbers;
    return (*this);
}

void RPN::calculate(std::string input)
{
    double a;
    double b;

	for (size_t i = 0; i < input.size(); i++)
	{
		char c = input[i];

		if (c == ' ')
			continue;
		else if (isdigit(c))
			numbers.push(c - '0');
		else if (c == '-' && isdigit(input[i + 1]))
			numbers.push(-(input[++i] - '0'));
		else if (c == '+' && numbers.size() >= 2)
		{
			b = numbers.top();
			numbers.pop();
			a = numbers.top();
			numbers.pop();
			numbers.push(a + b);
		}
		else if (c == '-' && numbers.size() >= 2)
		{
			b = numbers.top();
			numbers.pop();
			a = numbers.top();
			numbers.pop();
			numbers.push(a - b);
		}
		else if (c == '*' && numbers.size() >= 2)
		{
			b = numbers.top();
			numbers.pop();
			a = numbers.top();
			numbers.pop();
			numbers.push(a * b);
		}
		else if (c == '/' && numbers.size() >= 2)
		{
			b = numbers.top();
			numbers.pop();
			a = numbers.top();
			numbers.pop();
			numbers.push(a / b);
		}
		else
		{
			std::cout << "Error." << std::endl;
			return;
		}
	}

	if (numbers.size() == 1)
	{
		double result = numbers.top();
		numbers.pop();
		std::cout << result << std::endl;
	}
	else
		std::cout << "Error." << std::endl;
}