/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:57:53 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/03 14:13:02 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data	org = {'A', 124, 3.14f, 24.42};

	std::cout << "Org address: " << &org << std::endl;

	std::cout << "Org.char: " << org.c << std::endl;
	std::cout << "Org.int: " << org.i << std::endl;
	std::cout << "Org.float: " << org.f << std::endl;
	std::cout << "Org.double: " << org.d << std::endl;

	uintptr_t raw = Serializer::serialize(&org);
	Data	*dup = Serializer::deserialize(raw);

	std::cout << "\nDup address: " << dup << std::endl;

	std::cout << "Dup->char: " << dup->c << std::endl;
	std::cout << "Dup->int: " << dup->i << std::endl;
	std::cout << "Dup->float: " << dup->f << std::endl;
	std::cout << "Dup->double: " << dup->d << std::endl;

	return 0;
}
