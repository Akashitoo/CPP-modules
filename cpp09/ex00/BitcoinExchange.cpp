#include "BitcoinExchange.hpp"

void BitcoinExchange::fill_data()
{
	std::fstream input;

	input.open("data.csv", std::fstream::in);
	std::string line;
	int i = 0;
	while (std::getline(input, line))
	{
		if (i >= 1)
		{
			std::string key(line.c_str(), std::strchr(line.c_str() , ','));
			std::string value = line.substr(line.find(',') + 1);
			this->data[key] = std::strtod(value.c_str(), NULL);	
		}
		i++;
	}
}

void BitcoinExchange::get_data()
{
	std::map<std::string , double>::iterator it;
	for (it = this->data.begin(); it != this->data.end(); it++)
	{
		std::cout << it->first << " "<< it->second << "\n";
	}
}

void BitcoinExchange::check_date(std::string date)
{
	for (size_t i = 0; i < date.length(); i++)
	{
		if ((i == 4 || i == 7) && date[i] == '-')
			continue;
		else if ((i == 4 || i == 7)&& date[i] != '-')
			throw BadInput();
		else if (!std::isdigit(date[i]))
			throw BadInput();
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month > 12 || month <= 0 || day <= 0)
		throw BadInput();
	if (year < 2009)
		throw BadInput();
	if (month == 2 && ((!(year%4) && year%100) || !(year%400)))
	{ 
		if (day > 29)
			throw BadInput();
	}
	else if (day > daysInMonth[month - 1])
		throw BadInput();
}

void BitcoinExchange::check_value(std::string value)
{
	float v = std::strtod(value.c_str(), NULL);
	if (v < 0)
		throw NotPositiveNumber();
	if (v > 1000)
		throw TooLargeNumber();
}

void BitcoinExchange::exchange_rate(std::string date , std::string value)
{
	try
	{
		check_date(date);
		check_value(value);
		std::map<std::string , double>::iterator it = this->data.find(date);
		if (it != this->data.end())
		{
			std::cout << date << " => " << std::strtod(value.c_str(), NULL) << " => "<< std::strtod(value.c_str(), NULL) * it->second << '\n';
		}
		else
		{
			it = this->data.lower_bound(date);
			it--;
			std::cout << date << " => "<< std::strtod(value.c_str(), NULL) << " => " << std::strtod(value.c_str(), NULL) * it->second << '\n';
		}
	}
	catch (const BadInput& e)
	{
		std::cerr << "Error: " << e.what() << " => " << date << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}

void BitcoinExchange::handle_input(std::string file)
{
	std::fstream input;

	input.open(file.c_str(), std::fstream::in);
	std::string line;
	int i = 0;
	if (!input.is_open())
	{
		std::cout << "File cannot be open !\n";
		return;
	}
	while (std::getline(input, line))
	{
		if (i >= 1)
		{
			try
			{
				std::string key(line.c_str(), std::strchr(line.c_str() , ' '));
				std::string value = line.substr(line.find('|') + 2);
				this->exchange_rate(key, value);
			}
			catch (const std::exception& e)
			{
				std::cerr << "Error: " << BadInput().what() << " => " << line << '\n';
			}
		}
		i++;
	}
}