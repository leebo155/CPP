/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:03:28 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/08 15:09:58 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base	*generate(void)
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

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Class Type A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Class Type B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Class Type C" << std::endl;
}

void	identify(Base& p)
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

int main(void)
{
	Base	*ptr;

	std::cout << "Test1: idnetify(ptr*)\n" << std::endl;

	ptr = new A();
	identify(ptr);
	delete ptr;

	ptr = new B();
	identify(ptr);
	delete ptr;

	ptr = new C();
	identify(ptr);
	delete ptr;
	
	std::cout << "\nTest2: idnetify(ref&)\n" << std::endl;
	
	A a;
	B b;
	C c;

	identify(a);
	identify(b);
	identify(c);

	std::cout << "\nTest3: generate()\n" << std::endl;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;

	return 0;
}
