#include "BitcoinExchange.hpp"

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    
    size_t last = str.find_last_not_of(' ');

    if (first == std::string::npos || last == std::string::npos)
        return "";

    return str.substr(first, last - first + 1);
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);
	// std::cout << "First line: " << line << std::endl;
	// if (line != "date,price")
	// {
	// 	std::cerr << "Error: invalid file format" << std::endl;
	// 	return ;
	// }
	std::cout << BLUE "date | price" DEFAULT << std::endl;
	while (std::getline(file, line))
	{
		if (line.empty() || line.find_first_of('|') == std::string::npos)
			std::cout << RED "Error: invalid line" DEFAULT << std::endl;
		else
		{
			std::string date = trim(line.substr(0, line.find_first_of('|')));
			std::string price = trim(line.substr(line.find_first_of('|') + 1));
			try
			{
				bitcoinData[date] = std::stof(price);
				if (!isDateValid(date))
					std::cout << RED "Error: invalid data format" DEFAULT << std::endl;
				else if (!isPriceValid(bitcoinData[date]))
					std::cout << RED "Error: invalid price" DEFAULT << std::endl;
				else
					std::cout << BLUE << date << " | " << price << DEFAULT <<std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << RED "Error: " << e.what() << DEFAULT << std::endl;
			}
		}
	}
	file.close();
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
	{
		this->bitcoinData = copy.bitcoinData;
	}
	return (*this);
}

bool BitcoinExchange::isDateValid(std::string date)
{
	if (date.length() != 10)
		return (false);
	if (!isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[2]) || !isdigit(date[3]))
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	if (!isdigit(date[5]) || !isdigit(date[6]))
		return (false);
	if ((date[5] == '1' && date[6] > '2') || (date[5] > '1') || (date[5] == '0' && date[6] == '0'))
		return (false);
	if (!isdigit(date[8]) || !isdigit(date[9]))
		return (false);
	if ((date[8] == '3' && date[9] > '1') || (date[8] > '3'))
		return (false);
	return (true);
}

bool BitcoinExchange::isPriceValid(float price)
{
	if (price < 0 || price > 100000)
		return (false);
	return (true);
}

