# Aaaaand... OPEN!
In this exercise, create a **ClapTrap** class, a robot character from the game Borderlands.

## Rules
**ClapTrap** have the following private attributes initialized to the values specified in brackets:

* Name, which is passed as parameter to a constructor

* Hit points (10), represent the health of the ClapTrap

* Energy points (10)

* Attack damage (0)

Add the following public member functions so the ClapTrap looks more realistic:
```cpp
void attack(const std::string& target);

void takeDamage(unsigned int amount);

void beRepaired(unsigned int amount);
```

When ClapTrack attacks, it causes its target to lose <attack damage> hit points.   

When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points or energy points left.

In all of these member functions, you have to print a message to describe what happens. For example,   
the attack() function may display something like (of course, without the angle brackets):
```
ClapTrap <name> attacks <target>, causing <damage> points of damage!
```
The constructors and destructor must also display a message.

# Execution
```cpp
int main(void)
{
	ClapTrap tom("Tom");
	ClapTrap *alice = new ClapTrap("Alice");

	std::cout << " Tom Energy : " << tom.getEnergy() << std::endl;
	tom.attack(alice->getName());
	alice->takeDamage(tom.getDamage());
	std::cout << " Tom Energy : " << tom.getEnergy() << "\n" << std::endl;
	tom.setEnergy(0);
	std::cout << " Tom Energy : " << tom.getEnergy() << "\n" << std::endl;
	tom.attack(alice->getName());

	std::cout << "\n Alice Health : " << alice->getHealth() << std::endl;
	alice->takeDamage(9);
	std::cout << " Alice Health : " << alice->getHealth() << "\n" << std::endl;
	alice->beRepaired(12);
	std::cout << " Alice Health : " << alice->getHealth() << std::endl;
	std::cout << " Alice Energy : " << alice->getEnergy() << "\n" << std::endl;
	alice->takeDamage(10);
	std::cout << " Alice Health : " << alice->getHealth() << "\n" << std::endl;
	alice->beRepaired(10);
	std::cout << " Alice Health : " << alice->getHealth() << std::endl;
	std::cout << " Alice Energy : " << alice->getEnergy() << "\n" << std::endl;
	std::cout << std::endl;
	delete(alice);
	std::cout << std::endl;

	return 0;
}
```
```
$> ./a.out
+ Name parameter constructor called.
+ Name parameter constructor called.
 Tom Energy : 10
ClapTrap Tom attacks Alice, causing 0 point of damage!
ClapTrap Alice takes 0 point of damage!
 Tom Energy : 9

 Tom Energy : 0

ClapTrap Tom doesn't have enough energy.

 Alice Health : 10
ClapTrap Alice takes 9 point of damage!
 Alice Health : 1

ClapTrap Alice be repaired 12 point!
 Alice Health : 10
 Alice Energy : 9

ClapTrap Alice takes 10 point of damage!
 Alice Health : 0

 Alice Health : 0
 Alice Energy : 9


- Destructor called.
-- ClapTrap Alice stops working...

- Destructor called.
-- ClapTrap Tom stops working...
```
