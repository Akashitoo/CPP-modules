#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	BitcoinExchange btc;

	if (argc < 2)
	{
		std::cout << "Bad arguments ! \n";
		return (0);
	}
	btc.fill_data();
	btc.handle_input(argv[1]);
}