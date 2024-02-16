/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:02:34 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/16 16:13:16 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T1, typename T2, typename T3>
void	iter(T1 &arr, T2 size, T3 func)
{
	for (T2 i = 0; i < size; i++)
		func(arr[i]);
}

#endif
