/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:13:00 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/03 14:08:26 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(void) {};

Base	*Base::generate(void)
{
	clock_t	now;

	now = clock();

	std::srand(now);
	switch (std::rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return 0;
}

void	Base::identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Class Type A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Class Type B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Class Type C" << std::endl;
}

void	Base::identify(Base& p)
{

	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "Class Type A" << std::endl;
	} catch (std::exception &e) {};
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "Class Type B" << std::endl;
	} catch (std::exception &e) {};
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "Class Type C" << std::endl;
	} catch (std::exception &e) {};
}
