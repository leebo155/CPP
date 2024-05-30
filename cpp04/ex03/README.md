# Interface & recap
In this exercise, implement a part of a game using polymorphism, abstract classes, and interfaces.   
Through this process, learn object-oriented programming using polymorphism.

## Rules
Complete the definition of the following **AMateria** class and implement the necessary member functions.
```cpp
class AMateria
{
  protected:
    [...]

  public:
    AMateria(std::string const & type);
    [...]

    std::string const & getType() const; //Returns the materia type

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};
```
Implement the Materias concrete classes **Ice** and **Cure**.   
Use their name in lowercase ("ice" for Ice, "cure" for Cure) to set their types. Of course, their member function clone() will return a new instance of the same type (i.e., if clone an Ice Materia, will get a new Ice Materia).

The use(ICharacter&) member function will display:   

* Ice: "* shoots an ice bolt at <name> *"   
* Cure: "* heals <name>’s wounds *"   

Write the concrete class **Character** which will implement the following interface:
```cpp
class ICharacter
{
  public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};
```

The **Character** possesses an inventory of 4 slots, which means 4 Materias at most.   
The inventory is empty at construction. They equip the Materias in the first empty slot they find. This means, in this order: from slot 0 to slot 3. In case they try to add a Materia to a full inventory, or use/unequip an unexisting Materia, don’t do anything (but still, bugs are forbidden). The **unequip()** member function must NOT delete the Materia!   

Handle the Materias your character left on the floor as you like.   
Save the addresses before calling unequip(), or anything else.   

The **use(int, ICharacter&)** member function will have to use the Materia at the slot[idx], and pass the target parameter to the **AMateria::use** function.

Your Character must have a constructor taking its name as a parameter.   
Any copy (using copy constructor or copy assignment operator) of a Character must be deep. During copy, the Materias of a Character must be deleted before the new ones are added to their inventory. Of course, the Materias must be deleted when a Character is destroyed.   

Write the concrete class MateriaSource which will implement the following interface:
```cpp
class IMateriaSource
{
  public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};
```

* **learnMateria( AMateria * )**
  Copies the Materia passed as a parameter and store it in memory so it can be cloned later. Like the Character, the **MateriaSource** can know at most 4 Materias. Theyare not necessarily unique.
* **createMateria( std::string const & )**   
  Returns a new Materia. The latter is a copy of the Materia previously learned by the **MateriaSource** whose type equals the one passed as parameter. Returns 0 if the type is unknown.

## Execution
```cpp
int main(void)
{
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
```
```
$> ./a.out
================ CASE1 =====================
+ MateriaSource default constructor called.

// Learn Materia //
+ AMateria defualt constructor called.
+ Ice default constructor called.
+ AMateria defualt constructor called.
+ Cure default constructor called.

// Create new Charater me //
+ Character name constructor called.

// Create and Equip Materia //
+ AMateria defualt constructor called.
+ Ice default constructor called.
+ AMateria defualt constructor called.
+ Cure default constructor called.

// Create new Charater bob //
+ Character name constructor called.

// Use Materia on bob //
* shoots an ice bolt at bob *
* heals bob's wounds *

// Delete Character bob //
- Character destructor called.

// Delete Character me //
- Character destructor called.
- Ice destructor called.
- AMateria destructor called.
- Cure destructor called.
- AMateria destructor called.

// Delete MateriaSource src //
- MateriaSource destructor called.
- Ice destructor called.
- AMateria destructor called.
- Cure destructor called.
- AMateria destructor called.

================ CASE2 =====================
+ Character name constructor called.
+ Character name constructor called.
+ MateriaSource default constructor called.

// Learn Materia //
+ AMateria defualt constructor called.
+ Ice default constructor called.
+ AMateria defualt constructor called.
+ Cure default constructor called.
+ AMateria defualt constructor called.
+ Ice default constructor called.
+ AMateria defualt constructor called.
+ Cure default constructor called.

// Learn more Materia //
+ AMateria defualt constructor called.
+ Ice default constructor called.
** Cannot learn new Materia, slot is full. **
- Ice destructor called.
- AMateria destructor called.
+ AMateria defualt constructor called.
+ Cure default constructor called.
** Cannot learn new Materia, slot is full. **
- Cure destructor called.
- AMateria destructor called.

// Use Unequiped Materias //

// Equip unknown Materias //

// Equip Materias //
+ AMateria defualt constructor called.
+ Ice default constructor called.
+ AMateria defualt constructor called.
+ Cure default constructor called.
+ AMateria defualt constructor called.
+ Ice default constructor called.
+ AMateria defualt constructor called.
+ Cure default constructor called.

// Use All Equiped Materia //
* shoots an ice bolt at jane *
* heals jane's wounds *
* shoots an ice bolt at jane *
* heals jane's wounds *

// Use Wrong Index //

// Equip more Materia//
+ AMateria defualt constructor called.
+ Cure default constructor called.
** Cannot equip, Inventory is full. **
- Cure destructor called.
- AMateria destructor called.

// Unequip Materia(idx:2) and Use //

// Unequip unequiped Materia(idx:2) and Use //

// Equip Materia(idx:1) and Use All //
+ AMateria defualt constructor called.
+ Cure default constructor called.
* shoots an ice bolt at jane *
* heals jane's wounds *
* heals jane's wounds *
* heals jane's wounds *

// Unequip Materia(idx:1) //

// Equip Materia(idx:1) and Use All //
+ AMateria defualt constructor called.
+ Ice default constructor called.
* shoots an ice bolt at jane *
* shoots an ice bolt at jane *
* heals jane's wounds *
* heals jane's wounds *

// Unquip All Materia and Equip All //
+ AMateria defualt constructor called.
+ Ice default constructor called.
+ AMateria defualt constructor called.
+ Ice default constructor called.
+ AMateria defualt constructor called.
+ Ice default constructor called.
+ AMateria defualt constructor called.
+ Ice default constructor called.

// Delete Character john //
- Character destructor called.
- Ice destructor called.
- AMateria destructor called.
- Ice destructor called.
- AMateria destructor called.
- Ice destructor called.
- AMateria destructor called.
- Ice destructor called.
- AMateria destructor called.
- Ice destructor called.
- AMateria destructor called.
- Cure destructor called.
- AMateria destructor called.
- Ice destructor called.
- AMateria destructor called.
- Ice destructor called.
- AMateria destructor called.
- Cure destructor called.
- AMateria destructor called.
- Cure destructor called.
- AMateria destructor called.

// Delete Character jane //
- Character destructor called.

// Delete MateriaSource book //
- MateriaSource destructor called.
- Ice destructor called.
- AMateria destructor called.
- Cure destructor called.
- AMateria destructor called.
- Ice destructor called.
- AMateria destructor called.
- Cure destructor called.
- AMateria destructor called.

================ CASE3 =====================
// Create original Character and MateriaSource //
+ Character name constructor called.
+ MateriaSource default constructor called.

// Original MateriaSource: Learn Ice //
+ AMateria defualt constructor called.
+ Ice default constructor called.

// Original Character: Equip Materia //
+ AMateria defualt constructor called.
+ Ice default constructor called.
+ AMateria defualt constructor called.
+ Ice default constructor called.
+ AMateria defualt constructor called.
+ Ice default constructor called.
+ AMateria defualt constructor called.
+ Ice default constructor called.

// Create Copied Character and MateriaSource //
+ Character copy constructor called.
+ Character copy assignment constructor called.
+ AMateria defualt constructor called.
+ Ice default constructor called.
+ AMateria defualt constructor called.
+ Ice default constructor called.
+ AMateria defualt constructor called.
+ Ice default constructor called.
+ AMateria copy assignment constructor called.
+ AMateria defualt constructor called.
+ Ice default constructor called.
+ MateriaSource copy constructor called.
+ MateriaSource copy assignmnet constructor called.
+ AMateria defualt constructor called.
+ Ice default constructor called.

// Original Character: Use Materia //
* shoots an ice bolt at tom *

// Copied MateriaSource: Learn Cure //
+ AMateria defualt constructor called.
+ Cure default constructor called.

// Original Character: Equip Copied Materia Cure //
+ AMateria defualt constructor called.
+ Cure default constructor called.

// Copied Character: Equip Original Materia Cure //

// Original Character: Use Materia //
* shoots an ice bolt at tom *
* heals tom's wounds *

// Copied Character: Use Materia //
* shoots an ice bolt at tom *

// Delete Original Character //
- Character destructor called.
- Ice destructor called.
- AMateria destructor called.
- Cure destructor called.
- AMateria destructor called.
- Ice destructor called.
- AMateria destructor called.
- Ice destructor called.
- AMateria destructor called.
- Ice destructor called.
- AMateria destructor called.

// Delete Copied Character //
- Character destructor called.
- Ice destructor called.
- AMateria destructor called.
- Ice destructor called.
- AMateria destructor called.
- Ice destructor called.
- AMateria destructor called.
- Ice destructor called.
- AMateria destructor called.

// Delete Original MateriaSource //
- MateriaSource destructor called.
- Ice destructor called.
- AMateria destructor called.

// Delete Copied MateriaSource //
- MateriaSource destructor called.
- Ice destructor called.
- AMateria destructor called.
- Cure destructor called.
- AMateria destructor called.
```
