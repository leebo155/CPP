# Repetitive work
This exercise involves implementing a **FragTrap** class that inherits from the **ClapTrap** class.

## Rules
Implement a FragTrap class that inherits from ClapTrap. It is very similar to ScavTrap. However, its construction and destruction messages must be different.

Same things for the attributes, but with different values this time:

* Name, which is passed as parameter to a constructor

* Hit points (100), represent the health of the ClapTrap

* Energy points (100)

* Attack damage (30)

FragTrap has a special capacity too:
```cpp
void highFivesGuys(void);
```
This member function displays a positive high fives request on the standard output.

## Execution
```cpp
int main(void)
{
	...
	FragTrap john("John");
	FragTrap *jane = new FragTrap("Jane");

	std::cout << " Jane Health : " << jane->getHealth() << std::endl;
	std::cout << " Jane Energy : " << jane->getEnergy() << std::endl;
	std::cout << " John Energy : " << john.getEnergy() << "\n" << std::endl;
	john.attack(jane->getName());
	jane->takeDamage(john.getDamage());
	std::cout << " Jane Health : " << jane->getHealth() << std::endl;
	std::cout << " John Energy : " << john.getEnergy() << "\n" << std::endl;
	jane->beRepaired(30);
	std::cout << " Jane Health : " << jane->getHealth() << std::endl;
	std::cout << " Jane Energy : " << jane->getEnergy() << "\n" << std::endl;
	jane->takeDamage(120);
	std::cout << " Jane Health : " << jane->getHealth() << std::endl;
	jane->beRepaired(100);
	std::cout << " Jane Health : " << jane->getHealth() << "\n" << std::endl;

	std::cout << "John Energy : " << john.getEnergy() << std::endl;
	john.highFivesGuys();
	std::cout << "John Energy : " << john.getEnergy() << "\n" << std::endl;
	john.highFivesGuys();
	std::cout << "John Energy : " << john.getEnergy() << "\n" << std::endl;
	john.highFivesGuys();
	std::cout << "John Energy : " << john.getEnergy() << "\n" << std::endl;
	john.setEnergy(0);
	std::cout << "John Energy : " << john.getEnergy() << std::endl;
	john.highFivesGuys();
	std::cout << std::endl;
	delete(jane);
	std::cout << std::endl;

	return 0;
}
```
```
$> ./a.out
...
+ClapTrap Default constructor called.
+FragTrap Name parameter constructor called.
+ClapTrap Default constructor called.
+FragTrap Name parameter constructor called.
 Jane Health : 100
 Jane Energy : 100
 John Energy : 100

ClapTrap John attacks Jane, causing 30 point of damage!
ClapTrap Jane takes 30 point of damage!
 Jane Health : 70
 John Energy : 99

ClapTrap Jane be repaired 30 point!
 Jane Health : 100
 Jane Energy : 99

ClapTrap Jane takes 120 point of damage!
 Jane Health : 0
 Jane Health : 0

John Energy : 99
Hello! Do you want to give me a high five? (Y or N)
>>Y
Clap! Nice highfives!
John Energy : 98

Hello! Do you want to give me a high five? (Y or N)
>>N
Well... Let's do it next time!
John Energy : 97

Hello! Do you want to give me a high five? (Y or N)
>>Y
Clap! Nice highfives!
John Energy : 96

John Energy : 0
ClapTrap John doesn't have enough energy.

-FragTrap Destructor called.
-- FragTrap Jane stops working...
-ClapTrap Destructor called.
-- ClapTrap Jane stops working...

-FragTrap Destructor called.
-- FragTrap John stops working...
-ClapTrap Destructor called.
-- ClapTrap John stops working...
-ScavTrap Destructor called.
-- ScavTrap Bob stops working...
-ClapTrap Destructor called.
-- ClapTrap Bob stops working...
-ClapTrap Destructor called.
-- ClapTrap Tom stops working...
```
