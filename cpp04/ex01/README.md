#  I don’t want to set the world on fire
In this exercise, enhance the previously implemented Dog and Cat classes by adding a Brain class.   
Through this process, gain a deeper understanding of polymorphism and its caveats.   

## Rules
Implement a Brain class. It contains an array of 100 std::string called ideas.   
This way, Dog and Cat will have a private Brain* attribute.   
Upon construction, Dog and Cat will create their Brain using new Brain();   
Upon destruction, Dog and Cat will delete their Brain.   

The main function, create and fill an array of Animal objects.   
Half of it will be Dog objects and the other half will be Cat objects. At the end of program execution, loop over this array and delete every Animal. must delete directly dogs and cats as Animals.    
The appropriate destructors must be called in the expected order.

A copy of a Dog or a Cat mustn’t be shallow.

## Execution
```cpp
int main()
{
  ...
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
```
```
$> a.out
...
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
