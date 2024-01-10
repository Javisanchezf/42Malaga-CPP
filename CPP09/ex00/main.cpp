#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc data.csv" << std::endl;
		return (1);
	}
	BitcoinExchange exchange("data.csv");
	exchange.consulteData(argv[1]);
	(void)argv;
}