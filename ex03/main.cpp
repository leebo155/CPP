/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:41:07 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/25 13:47:54 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

/*void	leak(void)
{
	system("leaks a.out");
}*/

int main(void)
{
	//atexit(&leak);
	// CASE1: default test //
	std::cout << "================ CASE1 =====================" << std::endl;
	IMateriaSource* src = new MateriaSource();
	
	std::cout << "\n// Learn Materia //" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	std::cout << "\n// Create new Charater me //" << std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;

	std::cout << "\n// Create and Equip Materia //" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\n// Create new Charater bob //" << std::endl;
	ICharacter* bob = new Character("bob");
	
	std::cout << "\n// Use Materia on bob //" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n// Delete Character bob //" << std::endl;
	delete bob;
	std::cout << "\n// Delete Character me //" << std::endl;
	delete me;
	std::cout << "\n// Delete MateriaSource src //" << std::endl;
	delete src;

	// CASE2: define error test //
	std::cout << "\n================ CASE2 =====================" << std::endl;
	ICharacter	*john = new Character("john");
	ICharacter	*jane = new Character("jane");
	IMateriaSource	*book = new MateriaSource();

	std::cout << "\n// Learn Materia //" << std::endl;
	book->learnMateria(new Ice());
	book->learnMateria(new Cure());
	book->learnMateria(new Ice());
	book->learnMateria(new Cure());

	std::cout << "\n// Learn more Materia //" << std::endl;
	book->learnMateria(new Ice());
	book->learnMateria(new Cure());

	std::cout << "\n// Use Unequiped Materias //" << std::endl;
	john->use(0, *jane);
	john->use(1, *jane);
	john->use(2, *jane);
	john->use(3, *jane);

	std::cout << "\n// Equip unknown Materias //" << std::endl;
	john->equip(book->createMateria("fire")); // unknown
	john->equip(book->createMateria("stone")); // unknown
											   
	std::cout << "\n// Equip Materias //" << std::endl;
	john->equip(book->createMateria("ice")); // idx0
	john->equip(book->createMateria("cure")); // idx1
	john->equip(book->createMateria("ice")); // idx2
	john->equip(book->createMateria("cure")); // idx3

	std::cout << "\n// Use All Equiped Materia //" << std::endl;
	john->use(0, *jane); // ice
	john->use(1, *jane); // cure
	john->use(2, *jane); // ice
	john->use(3, *jane); // cure

	std::cout << "\n// Use Wrong Index //" << std::endl;
	john->use(-1, *jane);
	john->use(4, *jane);

	std::cout << "\n// Equip more Materia//" << std::endl;
	tmp = book->createMateria("cure");
	john->equip(tmp);
	delete(tmp);

	std::cout << "\n// Unequip Materia(idx:2) and Use //" << std::endl;
	john->unequip(2);
	john->use(2, *jane);
	// idx[0]: ice
	// idx[1]: cure
	// idx[2]: 
	// idx[3]: cure
	// wastes : ice

	std::cout << "\n// Unequip unequiped Materia(idx:2) and Use //" << std::endl;
	john->unequip(2);
	john->use(2, *jane);

	std::cout << "\n// Equip Materia(idx:1) and Use All //" << std::endl;
	john->equip(book->createMateria("cure")); // idx2
	john->use(0, *jane); // ice
	john->use(1, *jane); // cure
	john->use(2, *jane); // cure
	john->use(3, *jane); // cure

	std::cout << "\n// Unequip Materia(idx:1) //" << std::endl;
	john->unequip(1);
	john->use(1, *jane);
	// idx[0]: ice
	// idx[1]: 
	// idx[2]: cure
	// idx[3]: cure
	// wastes : ice -> cure

	std::cout << "\n// Equip Materia(idx:1) and Use All //" << std::endl;
	john->equip(book->createMateria("ice")); // idx1
	john->use(0, *jane); // ice
	john->use(1, *jane); // ice
	john->use(2, *jane); // cure
	john->use(3, *jane); // cure
	
	std::cout << "\n// Unquip All Materia and Equip All //" << std::endl;
	john->unequip(0);
	john->unequip(1);
	john->unequip(2);
	john->unequip(3);

	john->equip(book->createMateria("ice")); // idx0
	john->equip(book->createMateria("ice")); // idx1
	john->equip(book->createMateria("ice")); // idx2
	john->equip(book->createMateria("ice")); // idx3
					 
	std::cout << "\n// Delete Character john //" << std::endl;
	delete(john);
	// idx[0]: ice
	// idx[1]: ice
	// idx[2]: ice
	// idx[3]: ice
	// wastes : ice->cure->ice->ice->cure->cure
	std::cout << "\n// Delete Character jane //" << std::endl;
	delete(jane);
	std::cout << "\n// Delete MateriaSource book //" << std::endl;
	delete(book);

	// CASE3: copy test //
	std::cout << "\n================ CASE3 =====================" << std::endl;
	std::cout << "// Create original Character and MateriaSource //" << std::endl;
	Character *tom = new Character("tom");
	MateriaSource *ice = new MateriaSource();

	std::cout << "\n// Original MateriaSource: Learn Ice //" << std::endl;
	ice->learnMateria(new Ice());
	
	std::cout << "\n// Original Character: Equip Materia //" << std::endl;
	tom->equip(ice->createMateria("ice"));
	tom->equip(ice->createMateria("ice"));
	tom->equip(ice->createMateria("ice"));
	tom->equip(ice->createMateria("ice"));
	tom->unequip(2);
	tom->unequip(1);
	tom->equip(ice->createMateria("cure"));
	// tom inventory
	// [0]: ice
	// [1]: NULL
	// [2]: NULL
	// [4]: ice

	std::cout << "\n// Create Copied Character and MateriaSource //" << std::endl;
	ICharacter *copied_tom = new Character(*tom);
	MateriaSource *ice_cure = new MateriaSource(*ice);

	std::cout << "\n// Original Character: Use Materia //" << std::endl;
	tom->use(0, *copied_tom);
	tom->use(1, *copied_tom);

	std::cout << "\n// Copied MateriaSource: Learn Cure //" << std::endl;
	ice_cure->learnMateria(new Cure());

	std::cout << "\n// Original Character: Equip Copied Materia Cure //" << std::endl;
	tom->equip(ice_cure->createMateria("cure"));
	std::cout << "\n// Copied Character: Equip Original Materia Cure //" << std::endl;
	copied_tom->equip(ice->createMateria("cure"));

	std::cout << "\n// Original Character: Use Materia //" << std::endl;
	tom->use(0, *copied_tom);
	tom->use(1, *copied_tom);

	std::cout << "\n// Copied Character: Use Materia //" << std::endl;
	copied_tom->use(0, *tom);
	copied_tom->use(1, *tom);

	std::cout << "\n// Delete Original Character //" << std::endl;
	delete(tom);
	std::cout << "\n// Delete Copied Character //" << std::endl;
	delete(copied_tom);
	std::cout << "\n// Delete Original MateriaSource //" << std::endl;
	delete(ice);
	std::cout << "\n// Delete Copied MateriaSource //" << std::endl;
	delete(ice_cure);

	return 0;
}
