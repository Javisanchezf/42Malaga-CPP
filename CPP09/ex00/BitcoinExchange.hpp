#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

/*----------------------------LIBRARIES----------------------------*/
#include <iostream>
#include <fstream>
#include <unordered_map>

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


class BitcoinExchange
{
	private:
		std::unordered_map<std::string, float> bitcoinData;
		bool isDateValid(std::string date);
		bool isPriceValid(float price);
		BitcoinExchange();
	public:
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &copy);

};

#endif