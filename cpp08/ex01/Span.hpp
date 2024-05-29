/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:13:04 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/22 15:15:18 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <algorithm>
# include <list>

class Span
{
	private:
		std::list<int>	storage;
		unsigned int	size;
		
	public:
		Span(unsigned int n);
		Span(void);
		Span(const Span &target);
		Span &operator=(const Span &target);
		~Span(void);

		void	printElements(void);
		void	addNumber(int n) throw(std::exception);
		void	addNumber(unsigned int n, int min, int max) throw(std::exception);
		unsigned int		shortestSpan(void) throw(std::exception);
		unsigned int		longestSpan(void) throw(std::exception);
};

#endif
