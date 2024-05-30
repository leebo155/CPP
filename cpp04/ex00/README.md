#  Polymorphism
In this exercise, implement **Dog** and **Cat** classes that inherit from an **Animal** class to understand polymorphism.   
Additionally, implement an incorrectly designed **WrongAnimal** class to understand improper inheritance.

## Rules
Start by implementing a simple base class called Animal. It has one protected attribute:   
```cpp
std::string type;
```

Implement a **Dog** class that inherits from Animal.   
Implement a **Cat** class that inherits from Animal.   

These two derived classes must set their type field depending on their name.   
Then, the Dog’s type will be initialized to "Dog", and the Cat’s type will be initialized to "Cat".

Every animal must be able to use the member function:
```cpp
void makeSound(void);
```
It will print an appropriate sound (cats don’t bark).

implement a WrongCat class that inherits from a WrongAnimal class. 
If replace the Animal and the Cat by the wrong ones in the code above, the WrongCat should output the WrongAnimal sound.

## Execution
```cpp
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
```
```
$> ./a.out
+ Animal default constructor called.
+ Animal default constructor called.
+ Dog default constructor called.
+ Animal default constructor called.
+ Cat default constructor called.
Animal
Dog
Cat
.. ..... .... ... .. .... ..
Woof-woof! Ruff-ruf! Bark-bark!
Meow~ meooow~ meeoow!
- Animal destructor called.
- Dog destructor called.
- Animal destructor called.
- Cat destructor called.
- Animal destructor called.

======= Test Wrong =======

+ WrongAnimal default constructor called.
+ WrongAnimal default constructor called.
+ WrongCat default constructor called.
WrongAnimal
WrongCat
Gunga Ginga Gong Go Gunga Ginga
Gunga Ginga Gong Go Gunga Ginga
- WrongAnimal destructor called.
- WrongAnimal destructor called.
```
