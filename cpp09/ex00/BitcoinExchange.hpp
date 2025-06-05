#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <string>
# include <iostream>
# include <map>
# include <cstring>
# include <cstdlib>
# include <stdexcept>

class BitcoinExchange
{
	public :
		BitcoinExchange(){}
		~BitcoinExchange(){}
		void fill_data();
		void get_data();
		void check_date(std::string date);
		void check_value(std::string value);
		void exchange_rate(std::string data, std::string value);
		void handle_input(std::string file);

		private :
		
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		std::map<std::string, double> data;

		class NotPositiveNumber : public std::exception
		{
			public :
				virtual const char*  what() const throw()
				{
					return ("not a positive number!");
				}
		};

		class TooLargeNumber: public std::exception
		{
			public :
				virtual const char*  what() const throw()
				{
					return ("too large a number !");
				}
		};

		class BadInput: public std::exception
		{
			public :
				virtual const char*  what() const throw()
				{
					return ("bad input");
				}
		};
};

#endif