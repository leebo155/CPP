/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:33:10 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/24 11:56:40 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();

	delete(meta);
	delete(j);
	delete(i);

	std::cout << "\n======= Test Wrong =======\n" << std::endl;

	const WrongAnimal* h = new WrongAnimal();
	const WrongAnimal* r = new WrongCat();
	std::cout << h->getType() << " " << std::endl;
	std::cout << r->getType() << " " << std::endl;
	h->makeSound();
	r->makeSound();

	delete(h);
	delete(r);
	//system("leaks a.out");
	return 0;
}
