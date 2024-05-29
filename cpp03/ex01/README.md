# Serena, my love!
In this exercise, implement a **ScavTrap** class that inherits from **ClapTrap** class havee previously created. This process helps understand inheritance.

## Rules
ScavTrap use the attributes of ClapTrap (update ClapTrap in consequence) and must initialize them to:

* Name, which is passed as parameter to a constructor

* Hit points (100), represent the health of the ClapTrap

* Energy points (50)

* Attack damage (20)

ScavTrap will also have its own special capacity:

```cpp
void guardGate();
```
This member function will display a message informing that ScavTrap is now in Gatekeeper mode.

## Execution
```cpp
int main(void)
{
	... 
	std::cout << "\n====== ScavTrap Test ======" << std::endl;
	ScavTrap bob("Bob");
	ScavTrap *andy = new ScavTrap("Andy");
	
	std::cout << " Andy Health : " << andy->getHealth() << std::endl;
	std::cout << " Andy Energy : " << andy->getEnergy() << std::endl;
	std::cout << " Bob Energy : " << bob.getEnergy() << "\n" << std::endl;
	bob.attack(andy->getName());
	andy->takeDamage(bob.getDamage());
	std::cout << " Andy Health : " << andy->getHealth() << std::endl;
	std::cout << " Bob Energy : " << bob.getEnergy() << "\n" << std::endl;
	andy->beRepaired(30);
	std::cout << " Andy Health : " << andy->getHealth() << std::endl;
	std::cout << " Andy Energy : " << andy->getEnergy() << "\n" << std::endl;
	andy->takeDamage(120);
	std::cout << " Andy Health : " << andy->getHealth() << std::endl;
	andy->beRepaired(100);
	std::cout << " Andy Health : " << andy->getHealth() << "\n" << std::endl;

	std::cout << " Bob Energy : " << bob.getEnergy() << std::endl;
	bob.guardGate();
	std::cout << " Bob Energy : " << bob.getEnergy() << "\n" << std::endl;
	bob.setGate(true);
	bob.guardGate();
	std::cout << " Bob Energy : " << bob.getEnergy() << "\n" << std::endl;
	bob.setGate(false);
	std::cout << " Bob Energy : " << bob.getEnergy() << "\n" << std::endl;
	bob.setEnergy(0);
	std::cout << " Bob Energy : " << bob.getEnergy() << std::endl;
	bob.guardGate();
	bob.setGate(true);
	std::cout << std::endl;
	delete(andy);
	std::cout << std::endl;

	return 0;
}
```
```
$> ./a.out
...
+ClapTrap Default constructor called.
+ScavTrap Name parameter constructor called.
+ClapTrap Default constructor called.
+ScavTrap Name parameter constructor called.
 Andy Health : 100
 Andy Energy : 50
 Bob Energy : 50

ScavTrap Bob attacks Andy, causing 20 point of damage!
ClapTrap Andy takes 20 point of damage!
 Andy Health : 80
 Bob Energy : 49

ClapTrap Andy be repaired 30 point!
 Andy Health : 100
 Andy Energy : 49

ClapTrap Andy takes 120 point of damage!
 Andy Health : 0
 Andy Health : 0

 Bob Energy : 49
=ScavTrapBob is not keeping the door.
 Bob Energy : 48

The gate closes.
=ScavTrap Bobis guarding the door.
 Bob Energy : 46

The gate opens.
 Bob Energy : 45

 Bob Energy : 0
ClapTrap Bob doesn't have enough energy.
ClapTrap Bob doesn't have enough energy.

-ScavTrap Destructor called.
-- ScavTrap Andy stops working...
-ClapTrap Destructor called.
-- ClapTrap Andy stops working...

-ScavTrap Destructor called.
-- ScavTrap Bob stops working...
-ClapTrap Destructor called.
-- ClapTrap Bob stops working...
-ClapTrap Destructor called.
-- ClapTrap Tom stops working...
```
