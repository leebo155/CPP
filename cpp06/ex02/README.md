#  Identify real type
In this exercise, implement functions that convert parent class to child class using dynamic casting.   
Through this process, understand how dynamic casting works.   

## Rules
Implement a Base class that has a public virtual destructor only. Create three empty classes A, B and C, that publicly inherit from Base.

Implement the following functions:
   
```cpp
Base * generate(void);
```
It randomly instanciates **A**, **B** or **C** and returns the instance as a **Base** pointer.   
Feel free to use anything you like for the random choice implementation.   
   
```cpp
void identify(Base* p);
```
It prints the actual type of the object pointed to by p: "A", "B" or "C".   
   
```cpp
void identify(Base& p);
```
It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer inside this function is forbidden.   

Including the typeinfo header is forbidden

## Execution
```cpp
class Base
{
	public:
		virtual ~Base(void);
};

class A: public Base {};

class B: public Base {};

class C: public Base {};
```
```cpp
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
```
```
$> ./a.out
Test1: idnetify(ptr*)

Class Type A
Class Type B
Class Type C

Test2: idnetify(ref&)

Class Type A
Class Type B
Class Type C

Test3: generate()

Class Type A
Class Type A
Class Type A
Class Type A
```
