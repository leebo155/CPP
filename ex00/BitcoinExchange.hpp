/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:34:13 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/25 18:21:43 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <exception>
# include <fstream>
# include <ctime>
# include <cstdlib>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	database;

		std::string	trim(const std::string &line);
		struct tm	makeTime(const std::string &line);
		std::string checkDate(const std::string &line) throw(int);
		double		checkPrice(const std::string &line) throw(int);
		std::map<std::string, double>::iterator findDate(const std::string &date);

	public:

		BitcoinExchange(const char *csvfile) throw(std::exception);
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &target);
		BitcoinExchange &operator=(const BitcoinExchange &target);
		~BitcoinExchange(void);

		void	calculate(const char *inputfile) throw(std::exception);
		void	setDatabase(const char *csvfile) throw(std::exception);
};

#endif
