# cpp01
  **Memory allocation, pointers to members, references, switch statement**

## Introduction
  This project helps understand the memory allocation, reference, pointers to members and the usage of the switch in CPP.
  
## Contents
* ex00: BraiiiiiiinnnzzzZ
* ex01: Moar brainz!
* ex02: HI THIS IS BRAIN
* ex03: Unnecessary violence
* ex04: Sed is for losers
* ex05: Harl 2.0
* ex06: Harl filter

## Makefile
All Exercises follow a common Make rule.
| Rules | Description |
| ----- | ----------- |
| all | Compile a program. |
| clean | Remove all the temporary generated files. |
| fclean | Remove all the generated files. |
| re | Remove all the generated files and compile a program. |

## ex00: BraiiiiiiinnnzzzZ
This exercise involves implementing a Zombie class to learn about memory allocation in C++.   
The program's writing rules are as follows:
* Zombie class has a string private attribute name and a member function void announce( void ) that announce itself.
  ```
  <name>: BraiiiiiiinnnzzzZ...
  ```

* Then, implement the two following functions:
  ```cpp 
  Zombie* newZombie( std::string name );
  ```
  It creates a zombie, name it, and return it so you can use it outside of the function.
  scope.

  ```cpp 
  void randomChump( std::string name );
  ```
  It creates a zombie, name it, and the zombie announces itself.

main.cpp
  ```cpp 
  int	main(void)
  {
  	Zombie	tom("tom");
  	Zombie	*alice = newZombie("alice");
  
  	delete alice;
  	randomChump("bob");
  	return 0;
  }
  ```

Run
  ``` 
  $> ./zombie
  alice is dead.
  bob: BraiiiiiiinnnzzzZ...
  bob is dead.
  tom is dead.
  ```
  
## ex01: Moar brainz!
This exercise implements the zombieHorde function to learn about resource management in C++.
```cpp 
Zombie* zombieHorde( int N, std::string name );
```
It must allocate **N** Zombie objects in a single allocation. Then, it has to initialize the zombies, giving each one of them the name passed as parameter. The function returns a pointer to the first zombie.

main.cpp
  ```cpp
  int main(int argc, char *argv[])
  {
	  if (argc - 1 != 2)
	  {
  		std::cout << "usage: ./zombie [amount of zombies] [name]" << std::endl;
		  return (1);
	  }
  
  	int	amount = std::atoi(argv[1]);
  	int	index = 0;
  	Zombie* zombies = zombieHorde(amount, argv[2]);

  	while (index < amount)
  	{
		  std::cout << index + 1 << " ";
		  zombies[index++].announce();
	  }
	  delete[] zombies;
	  return 0;
  }
  ```

Run
  ```
  $> ./zombie 3 bab
  1 bab: BraiiiiiiinnnzzzZ...
  2 bab: BraiiiiiiinnnzzzZ...
  3 bab: BraiiiiiiinnnzzzZ...
  bab is dead.
  bab is dead.
  bab is dead.
  ```

## ex02: HI THIS IS BRAIN
This exercise teaches the difference between references and pointers.   
The program's writing rules are as follows:
* A program that contains:   
  ◦ A string variable initialized to "HI THIS IS BRAIN".   
  ◦ **stringPTR**: A pointer to the string.   
  ◦ **stringREF**: A reference to the string.

* It has to print:   
  ◦ The memory address of the string variable.   
  ◦ The memory address held by **stringPTR**.   
  ◦ The memory address held by **stringREF**.   
  ◦ The value of the string variable.   
  ◦ The value pointed to by **stringPTR**.   
  ◦ The value pointed to by **stringREF**.

main.cpp
  ```cpp
  int main()
  {
	  std::string str = "HI THIS IS BRAIN";
	  std::string* stringPTR = &str;
	  std::string& stringREF = str;
  
  	std::cout << "The memory address of the string : " << &str << std::endl;
  	std::cout << "The memory address held by stringPTR : " << stringPTR << std::endl;
  	std::cout << "The memory address held by stringREF : " << &stringREF << std::endl;

  	std::cout << "\nThe value of the string : " << str << std::endl;
  	std::cout << "The value pointed to by stringPTR : " << *stringPTR << std::endl;
  	std::cout << "The value pointed to by stringREF : " << stringREF << std::endl;
  	return 0;
  }
  ```

Run
  ``` 
  $> ./program
  The memory address of the string : 0x7ffee35ff990
  The memory address held by stringPTR : 0x7ffee35ff990
  The memory address held by stringREF : 0x7ffee35ff990
  
  The value of the string : HI THIS IS BRAIN
  The value pointed to by stringPTR : HI THIS IS BRAIN
  The value pointed to by stringREF : HI THIS IS BRAIN
  ```

## ex03: Unnecessary violence
This exercise highlights the precautions to take when using reference and pointer members in classes.   
The program's writing rules are as follows:
* Implement a Weapon class that has:   
  ◦ A private attribute type, which is a string.   
  ◦ A getType() member function that returns a const reference to type.   
  ◦ A setType() member function that sets type using the new one passed as parameter.

* Create two classes: HumanA and HumanB. They both have a Weapon and a name.
  
* They also have a member function attack() that displays:
  ```cpp
  <name> attacks with their <weapon type>
  ```
  
* HumanA and HumanB are almost the same except for these two tiny details:   
  ◦ While HumanA takes the Weapon in its constructor, HumanB doesn’t.   
  ◦ HumanB may not always have a Weapon, whereas HumanA will always be armed.
  
main.cpp
  ```cpp
  int main()
  {
  	{
  		Weapon club = Weapon("crude spiked club");
  
  		HumanA bob("Bob", club);
  		bob.attack();
  		club.setType("some other type of club");
  		bob.attack();
  	}
  	{
  		Weapon club = Weapon("crude spiked club");
  
  		HumanB jim("Jim");
  		jim.setWeapon(club);
  		jim.attack();
  		club.setType("some other type of club");
  		jim.attack();
  	}
  
  return 0;
  }
  ```

Run
  ``` 
  $> ./program
  Bob attacks with their crude spiked club
  Bob attacks with their some other type of club
  Jim attacks with their crude spiked club
  Jim attacks with their some other type of club
  ```

## ex04: Sed is for losers
This exercise involves writing a program similar to the sed command, allowing you to learn about the string class.   
The program's writing rules are as follows:
* Create a program that takes three parameters in the following order: a `filename` and two strings, `s1` and `s2`.
* It will open the file `filename` and copies its content into a new file `filename.replace`, replacing every occurrence of `s1` with `s2`.

Run
  ``` 
  $> cat text
  ABC BBC ABE ACD

  $> ./replace text B F

  $> cat text.replace
  AFC FFC AFE ACDb
  ```

## ex05: Harl 2.0
This exercise involves learning about function pointers.   
The program's writing rules are as follows:
* Create a Harl class with the following private member functions:
  ```cpp
  void debug( void );
  void info( void );
  void warning( void );
  void error( void );
  ```

* Harl also has a public member function that calls the four member functions above depending on the level passed as parameter:
  ```cpp
  void complain( std::string level );
  ```

* The goal of this exercise is to use pointers to member functions.

Implement
```cpp
void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*func[5])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::unknown};
	int	index = 0;

	while (index < 4 && levels[index] != level)
		index++;
	(this->*func[index])();
}
```

Run
```
$> ./harl DEBUG
I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.
I really do!

$> ./harl INFO
I cannot believe adding extra bacon costs more money.
You didn’t put enough bacon in my burger!
If you did, I wouldn’t be asking for more!

$> ./harl WARNING
I think I deserve to have some extra bacon for free.
I’ve been coming for years whereas you started working here since last month.

$> ./harl ERROR
This is unacceptable!
I want to speak to the manager now.

$> ./harl unkown
$> 
```


## ex06: Harl filter
This exercise involves learning about switch statements.   
The program's writing rules are as follows:
* Create a program that takes as parameter one of the four levels. It will display all messages from this level and above. For example:
  ```
  $> ./harlFilter "WARNING"
  [ WARNING ]
  I think I deserve to have some extra bacon for free.
  I've been coming for years whereas you started working here since last month.
  [ ERROR ]
  This is unacceptable, I want to speak to the manager now.
  $> ./harlFilter "I am not sure how tired I am today..."
  ```

Implement
```cpp
void	Harl::complain(std::string level)
{
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  int	index = 0;
  
  while (index < 4 && levels[index] != level)
    index++;
  switch (index)
  {
  case 0:
  	this->debug();
  case 1:
  	this->info();
  case 2:
  	this->warning();
  case 3:
  	this->error();
  	break;
  default:
  	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
  }
}
```

RUN
```
$> ./harlFilter DEBUG
[ DEBUG ]
I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.
I really do!

[ INFO ]
I cannot believe adding extra bacon costs more money.
You didn’t put enough bacon in my burger!
If you did, I wouldn’t be asking for more!

[ WARNING ]
I think I deserve to have some extra bacon for free.
I’ve been coming for years whereas you started working here since last month.

[ ERROR ]
This is unacceptable!
I want to speak to the manager now.

$> ./harlFilter WARNING
[ WARNING ]
I think I deserve to have some extra bacon for free.
I’ve been coming for years whereas you started working here since last month.

[ ERROR ]
This is unacceptable!
I want to speak to the manager now.
```
