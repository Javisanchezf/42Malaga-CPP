#pragma once
#ifndef RPN_HPP
# define RPN_HPP

/*----------------------------LIBRARIES----------------------------*/
#include <iostream>
#include <stack>

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

/*----------------------------CLASSES----------------------------*/
class RPN
{
    private:
        std::stack<double> numbers;
    public:
        RPN();
        RPN(const RPN &var);
        RPN &operator=(const RPN &var);
        ~RPN();
        void calculate(std::string input);
};

#endif