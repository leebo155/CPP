/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:34:13 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/23 19:03:37 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

class BitcoinExchange
{
	private:
		std::map<std::string, int>	database;

	public:
		BitcoinExchange(const char *csvfile) throw(std::exception);
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &target);
		BitcoinExchange &operator=(const BitcoinExchange &target);
		~BitcoinExchange(void);

		void	calculate(const char *inputfile) throw(std::exception);
};

#endif
