/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:33:10 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/24 11:58:26 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*void	leak(void)
{
	system("leaks a.out");
}*/

int main()
{
//	atexit(&leak);
//	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();
//	meta->makeSound();

//	delete(meta);
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

	std::cout << "\n======= Test Brain =======\n" << std::endl;

	const Animal *animals[10];

	std::cout << "\n++ Constructor ++\n" << std::endl;

	for (int i = 0; i < 5; i++)
		animals[i] = new Cat();
	for (int i = 5; i < 10; i++)
		animals[i] = new Dog();
	
	std::cout << "\n** MakeSound() **\n" << std::endl;

	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();

	std::cout << "\n-- Destructor --\n" << std::endl;

	for (int i = 0; i < 10; i++)
		delete(animals[i]);

	std::cout << "\n** Brain Test **\n" << std::endl;

	const Dog* choco = new Dog();
	const Cat* nero = new Cat();

	choco->saveIdea(5, "I love dog.");
	choco->saveIdea(-1, "I hate cat."); // wrong idx
	choco->saveIdea(100, "I am dog."); // wrong idx
	std::cout << choco->loadIdea(-1) << std::endl; // wrong idx
	std::cout << choco->loadIdea(0) << std::endl; // empty
	std::cout << choco->loadIdea(5) << std::endl; // I love dog.
	std::cout << choco->loadIdea(100) << std::endl; // wrong idx

	choco->saveIdea(5, "I am dog.");
	// choco 5: I am dog.
	
	const Dog* oreo = new Dog(*choco);
	// choco 5: I am dog.
	// oreo 5: I am dog. ,choco Copy!

	choco->saveIdea(5, "I am cat.");
	// choco 5: I am cat. ,Modify!
	// oreo 5: I am dog.
	
	nero->setBrain(choco->getBrain());
	// choco 5: I am cat.
	// oreo 5: I am dog.
	// nero 5: I am cat. ,choco Copy!

	const Cat navi(*nero);
	// choco 5: I am cat.
	// oreo 5: I am dog.
	// nero 5: I am cat.
	// navi 5: I am cat. ,nero Copy!

	nero->saveIdea(5, "My name is Nero.");
	// choco 5: I am cat.
	// oreo 5: I am dog.
	// nero 5: My name is Nero. ,Modify!
	// navi 5: I am cat.
	
	choco->saveIdea(5, "I hate cat.");
	// choco 5: I hate cat. ,Modify!
	// oreo 5: I am dog.
	// nero 5: My name is Nero.
	// navi 5: I am cat.

	std::cout << "\n** All loadIdea:5  **\n" << std::endl;
	std::cout << choco->loadIdea(5) << std::endl;
	std::cout << oreo->loadIdea(5) << std::endl;
	std::cout << nero->loadIdea(5) << std::endl;
	std::cout << navi.loadIdea(5) << std::endl;

	std::cout << "\n-- Destructor --\n" << std::endl;
	delete (choco);
	delete (oreo);
	delete (nero);
	return 0;
}
