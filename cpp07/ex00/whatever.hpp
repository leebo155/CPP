/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:39:11 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/20 14:45:41 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
};

template <typename T>
T	&min(T &a, T &b)
{
	if (a > b)
		return b;
	return a;
};

template <typename T>
T	&max(T &a, T &b)
{
	if (a < b)
		return b;
	return a;
};

#endif
