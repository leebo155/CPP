# Abstract class
In this exercise, convert the Animal class created in the previous exercise into an abstract class.   
Through this process, learn about the characteristics and requirements of abstract classes.

## Rules
Animal class should not be instantiable.   
Fix the Animal class so nobody can instantiate it. Everything should work as before.   

## Execution
```cpp
class Animal
{
	public:
		...
		virtual void	makeSound(void) const = 0;
};
```
```cpp
int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();

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

	const Dog* oreo = new Dog(*choco);

	choco->saveIdea(5, "I am cat.");

	nero->setBrain(choco->getBrain());

	const Cat navi(*nero);

	nero->saveIdea(5, "My name is Nero.");
	
	choco->saveIdea(5, "I hate cat.");

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
```
```
$> ./a.out
+ Animal default constructor called.
+ Dog default constructor called.
+ Brain default constructor called.
+ Animal default constructor called.
+ Cat default constructor called.
+ Brain default constructor called.
Dog
Cat
Woof-woof! Ruff-ruf! Bark-bark!
Meow~ meooow~ meeoow!
- Dog destructor called.
- Brain destructor called.
- Animal destructor called.
- Cat destructor called.
- Brain destructor called.
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

======= Test Brain =======


++ Constructor ++

+ Animal default constructor called.
+ Cat default constructor called.
+ Brain default constructor called.
+ Animal default constructor called.
+ Cat default constructor called.
+ Brain default constructor called.
+ Animal default constructor called.
+ Cat default constructor called.
+ Brain default constructor called.
+ Animal default constructor called.
+ Cat default constructor called.
+ Brain default constructor called.
+ Animal default constructor called.
+ Cat default constructor called.
+ Brain default constructor called.
+ Animal default constructor called.
+ Dog default constructor called.
+ Brain default constructor called.
+ Animal default constructor called.
+ Dog default constructor called.
+ Brain default constructor called.
+ Animal default constructor called.
+ Dog default constructor called.
+ Brain default constructor called.
+ Animal default constructor called.
+ Dog default constructor called.
+ Brain default constructor called.
+ Animal default constructor called.
+ Dog default constructor called.
+ Brain default constructor called.

** MakeSound() **

Meow~ meooow~ meeoow!
Meow~ meooow~ meeoow!
Meow~ meooow~ meeoow!
Meow~ meooow~ meeoow!
Meow~ meooow~ meeoow!
Woof-woof! Ruff-ruf! Bark-bark!
Woof-woof! Ruff-ruf! Bark-bark!
Woof-woof! Ruff-ruf! Bark-bark!
Woof-woof! Ruff-ruf! Bark-bark!
Woof-woof! Ruff-ruf! Bark-bark!

-- Destructor --

- Cat destructor called.
- Brain destructor called.
- Animal destructor called.
- Cat destructor called.
- Brain destructor called.
- Animal destructor called.
- Cat destructor called.
- Brain destructor called.
- Animal destructor called.
- Cat destructor called.
- Brain destructor called.
- Animal destructor called.
- Cat destructor called.
- Brain destructor called.
- Animal destructor called.
- Dog destructor called.
- Brain destructor called.
- Animal destructor called.
- Dog destructor called.
- Brain destructor called.
- Animal destructor called.
- Dog destructor called.
- Brain destructor called.
- Animal destructor called.
- Dog destructor called.
- Brain destructor called.
- Animal destructor called.
- Dog destructor called.
- Brain destructor called.
- Animal destructor called.

** Brain Test **

+ Animal default constructor called.
+ Dog default constructor called.
+ Brain default constructor called.
+ Animal default constructor called.
+ Cat default constructor called.
+ Brain default constructor called.

empty
I love dog.

+ Animal copy constructor called.
+ Animal copy assignment constructor called.
+ Dog copy constructor called.
+ Brain default constructor called.
+ Dog copy assignment constructor called.
+ Brain copy assignment constructor called.
+ Brain copy assignment constructor called.
+ Animal copy constructor called.
+ Animal copy assignment constructor called.
+ Cat copy constructor called.
+ Brain default constructor called.
+ Cat copy assignment constructor called.
+ Brain copy assignment constructor called.

** All loadIdea:5  **

I hate cat.
I am dog.
My name is Nero.
I am cat.

-- Destructor --

- Dog destructor called.
- Brain destructor called.
- Animal destructor called.
- Dog destructor called.
- Brain destructor called.
- Animal destructor called.
- Cat destructor called.
- Brain destructor called.
- Animal destructor called.
- Cat destructor called.
- Brain destructor called.
- Animal destructor called.
```
