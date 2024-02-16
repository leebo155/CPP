/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:48:41 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/16 16:07:23 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	intOnePlusPrint(int i)
{	std::cout << i + 1 << std::endl; }

int	main()
{

	int	i[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	::iter(i, 10, &intOnePlusPrint);

	return 0;

}
