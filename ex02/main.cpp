/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:03:28 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/03 14:07:19 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	Base	base;
	Base	*ptr;

	std::cout << "Test1: Base.idnetify(ptr*)\n" << std::endl;

	ptr = new A();
	base.identify(ptr);
	delete ptr;

	ptr = new B();
	base.identify(ptr);
	delete ptr;

	ptr = new C();
	base.identify(ptr);
	delete ptr;
	
	std::cout << "\nTest2: Base.idnetify(ref&)\n" << std::endl;
	
	A a;
	B b;
	C c;

	base.identify(a);
	base.identify(b);
	base.identify(c);

	std::cout << "\nTest3: Base.generate()\n" << std::endl;

	ptr = base.generate();
	base.identify(ptr);
	base.identify(*ptr);
	delete ptr;

	ptr = base.generate();
	base.identify(ptr);
	base.identify(*ptr);
	delete ptr;

	return 0;
}
