/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:18:05 by bohlee            #+#    #+#             */
/*   Updated: 2024/03/06 15:52:31 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

std::string	BitcoinExchange::trim(const std::string &line)
{
	const std::string white = " \n\r\t\f\v";

	size_t start = line.find_first_not_of(white);
	size_t end = line.find_last_not_of(white);
	if (start == std::string::npos || end == std::string::npos)
		return "";
	return line.substr(start, end - start + 1);
}

struct tm	BitcoinExchange::makeTime(const std::string &line)
{
	struct tm	t;

	t.tm_year = static_cast<int>(strtod(line.substr(0, 4).c_str(), NULL));
	t.tm_mon = static_cast<int>(strtod(line.substr(5, 2).c_str(), NULL)) - 1;
	t.tm_mday = static_cast<int>(strtod(line.substr(8, 2).c_str(), NULL));
	t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_isdst = 0;

	return t;
}

std::string BitcoinExchange::checkDate(const std::string &line) throw(int)
{
	std::string trimed_line = this->trim(line);
	if (trimed_line.empty())
		throw 0;
	
	size_t index = 0;
	while (isdigit(trimed_line[index]))
		index++;
	if (trimed_line[index] != '-' || index != 4)
		throw 0;
	index++;
	while (isdigit(trimed_line[index]))
		index++;
	if (trimed_line[index] != '-' || index != 7)
		throw 0;
	index++;
	while (isdigit(trimed_line[index]))
		index++;
	if (trimed_line[index] != 0 || index != 10)
		throw 0;

	struct tm	org = this->makeTime(trimed_line);
	struct tm	copy = org;
	std::mktime(&org);		

	if (org.tm_year != copy.tm_year || org.tm_mon != copy.tm_mon
			|| org.tm_mday != copy.tm_mday)
		throw 0;

	return trimed_line;
}

double BitcoinExchange::checkPrice(const std::string &line) throw(int)
{
	std::string trimed_line = this->trim(line);
	if (trimed_line.empty())
		throw 0;

	size_t index = 0;
	if (trimed_line[index] == '-' || trimed_line[index] == '+')
		index++;
	while (isdigit(trimed_line[index]))
		index++;
	if (trimed_line[index] == '.')
	{
		index++;
		while (isdigit(trimed_line[index]))
			index++;
	}
	if (trimed_line[index] != 0)
		throw 0;

	double res = strtod(trimed_line.c_str(), 0);
	if (res < 0)
		throw 1;

	return res;
}

std::map<std::string, double>::iterator BitcoinExchange::findDate(const std::string &date)
{
	std::map<std::string, double>::iterator it = database.begin();
	std::map<std::string, double>::iterator res;
	struct tm	t = this->makeTime(date);
	time_t pivot = std::mktime(&t);
	time_t diff = pivot;

	while (it != database.end())
	{
		t = this->makeTime(it->first);
		time_t search = std::mktime(&t);

		if ((pivot > search && diff > pivot - search))
		{
			diff = pivot - search;
			res = it;
		}
		it++;
	}
	if (diff == pivot)
		return database.end();
	return res;
}

BitcoinExchange::BitcoinExchange(const char *csvfile) throw(std::exception)
{
	this->setDatabase(csvfile);
}

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &target)
{
	*this = target;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &target)
{
	if (this != &target)
	{
		database.clear();
		std::map<std::string, double>::const_iterator it = target.database.begin();
		while (it != target.database.end())
		{
			database.insert(std::pair<std::string, double>(it->first, it->second));
			it++;
		}
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
	database.clear();
}

void	BitcoinExchange::calculate(const char *inputfile) throw(std::exception)
{
	std::ifstream	input;
	std::string		line;
	std::string 	date;
	double			price;
	size_t			pos;

	input.open(inputfile, std::ifstream::in);
	if (!input.is_open())
		throw std::runtime_error("could not open file.");

	getline(input, line);
	pos = line.find('|');
	if (pos == std::string::npos)
	{
		input.close();
		throw std::runtime_error("bad input => " + line);
	}
	if ("date" != this->trim(line.substr(0, pos))
				|| "value" != this->trim(line.substr(pos + 1)))
	{
		input.close();
		throw std::runtime_error("bad input => " + line);
	}

	while (input.good())
	{
		getline(input, line);
		if (line.empty())
			continue;
		pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " + line << std::endl;
			continue;
		}
		try {
			date = this->checkDate(line.substr(0, pos));
			price = this->checkPrice(line.substr(pos + 1));
		} catch (int exception_num) {
			switch (exception_num)
			{
				case 0:
					std::cerr << "Error: bad input => " + line << std::endl;
					break;
				case 1:
					std::cerr << "Error: not a positive number." << std::endl;
			}
			continue;
		}
		std::map<std::string, double>::iterator it = database.find(date);
		if (it == database.end())
		{
			it = this->findDate(date);
			if (it == database.end())
			{
				std::cerr << "Error: bad input => " + line << std::endl;
				continue;
			}
		}
		if (price > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		std::cout << date << " => " << price;
		std::cout << " = " << it->second * price << std::endl;
	}

	if (input.bad())
	{
		input.close();	
		throw std::runtime_error("could not reached eof.");
	}
	input.close();
}

void	BitcoinExchange::setDatabase(const char *csvfile) throw(std::exception)
{
	std::ifstream	csv;
	std::string		line;
	std::string 	date;
	double			price;
	size_t			pos;

	csv.open(csvfile, std::ifstream::in);
	if (!csv.is_open())
		throw std::runtime_error("could not open file.");

	getline(csv, line);
	pos = line.find(',');
	if (pos == std::string::npos)
	{
		csv.close();
		throw std::runtime_error("bad input => " + line);
	}
	if ("date" != this->trim(line.substr(0, pos))
				|| "exchange_rate" != this->trim(line.substr(pos + 1)))
	{
		csv.close();
		throw std::runtime_error("bad input => " + line);
	}

	while (csv.good())
	{
		getline(csv, line);
		if (line.empty())
			continue;
		pos = line.find(',');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " + line << std::endl;
			continue;
		}
		try {
			date = this->checkDate(line.substr(0, pos));
			price = this->checkPrice(line.substr(pos + 1));
		} catch (int exception_num) {
			switch (exception_num)
			{
				case 0:
					std::cerr << "Error: bad input => " + line << std::endl;
					break;
				case 1:
					std::cerr << "Error: not a positive number." << std::endl;
			}
			continue;
		}
		std::map<std::string, double>::iterator it = database.find(date);
		if (it == database.end())
			database.insert(std::pair<std::string, double>(date, price));
		else
			std::cerr << "Error: duplicated date." << std::endl;
	}

	if (csv.bad())
	{
		csv.close();
		throw std::runtime_error("could not reached eof.");
	}
	csv.close();
}
