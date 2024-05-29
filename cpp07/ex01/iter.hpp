/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:02:34 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/20 15:23:16 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(const T *arr, size_t size, void (*func)(const T))
{
	for (size_t i = 0; i < size; i++)
		func(arr[i]);
};

template <typename T>
void	doublePrint(const T t)
{
	std::cout << t + t << std::endl;
};

template <typename T>
void	templatePrint(const T t)
{
	std::cout << t << std::endl;
};

#endif
