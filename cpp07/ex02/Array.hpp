/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:05:38 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/20 15:01:03 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>
# include <exception>

template <typename T>
class Array
{
	private:
		T *array;
		unsigned int amount;

	public:
		class WrongIndexException: public std::exception
		{
			public:
				const char *what(void) const throw()
				{ return "Wrong Index"; };
		};
		Array(void) {
			array = new T[0];
			amount = 0;
		};
		Array(const Array &target) {
			amount = 0;
			array = new T[0];
			*this = target;
		};
		Array &operator=(const Array &target) {
			if (this != &target)
			{
				if (array)
					delete[] array;
				amount = target.amount;
				array = new T[amount];
				for (long long i = 0; i < amount; i++)
					array[i] = target.array[i];
			}
			return *this;
		};
		~Array(void)
		{ delete[] array; };

		Array(const unsigned int size) {
			amount = size;
			array = new T[amount];
		};
		T &operator[](const long long index) const throw(std::exception) {
			if (index < 0 || amount <= index)
				throw Array::WrongIndexException();
			return array[index];
		};
		unsigned int	size(void) const
		{ return amount; };
};

#endif
