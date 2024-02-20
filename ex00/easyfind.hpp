/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:45:39 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/20 20:25:21 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>

template <typename T>
typename T::iterator	easyfind(T container ,int n)
{
	typename T::iterator it = find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::runtime_error("can't find");
	return it;
};

#endif
