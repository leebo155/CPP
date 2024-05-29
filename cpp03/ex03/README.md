# Now it’s weird!
This exercise involves implementing a **DiamondTrap** class that inherits from both **ScavTrap** and **FragTrap** classes. Through this process, It halps understand multiple inheritance

## Rules
The DiamondTrap class will have a name private attribute. Give to this attribute exactly the same variable’s name (not talking about the robot’s name here) than the one in the ClapTrap base class.

To be more clear, here are two examples.   
If ClapTrap’s variable is name, give the name name to the one of the DiamondTrap.   
If ClapTrap’s variable is _name, give the name _name to the one of the DiamondTrap.   

Its attributes and member functions will be picked from either one of its parent classes:

* Name, which is passed as parameter to a constructor

* ClapTrap::name (parameter of the constructor + "_clap_name" suffix)

* Hit points (FragTrap)

* Energy points (ScavTrap)

* Attack damage (FragTrap)

* attack() (Scavtrap)

In addition to the special functions of both its parent classes, DiamondTrap will have its own special capacity:
```cpp
void whoAmI();
```
This member function will display both its name and its ClapTrap name.

Of course, the ClapTrap subobject of the DiamondTrap will be created once, and only once.

## Execution
```cpp
int main(void)
{
  ...
	DiamondTrap michael("Michael");
	DiamondTrap *sam = new DiamondTrap("Sam");

	std::cout << "\nMichael name : " << michael.getName() << std::endl;
	std::cout << "Michael Health : " << michael.getHealth() << std::endl;
	std::cout << "Michael Energy : " << michael.getEnergy() << std::endl;
	std::cout << "Michael Attack damage : " << michael.getDamage() << "\n" << std::endl;
	michael.attack(sam->getName());
	sam->takeDamage(michael.getDamage());
	std::cout << "Michael Energy : " << michael.getEnergy() << std::endl;
	std::cout << "Sam Health : " << sam->getHealth() << "\n" << std::endl;
	sam->beRepaired(35);
	std::cout << "Sam Health : " << sam->getHealth() << std::endl;
	std::cout << "Sam Energy : " << sam->getEnergy() << "\n" << std::endl;
	michael.whoAmI();
	std::cout << "Michael Energy : " << michael.getEnergy() << "\n" << std::endl;
	sam->whoAmI();
	std::cout << "Sam Energy : " << sam->getEnergy() << "\n" << std::endl;
	sam->setEnergy(0);	
	std::cout << "Sam Energy : " << sam->getEnergy() << "\n" << std::endl;
	sam->whoAmI();
	michael.takeDamage(150);
	std::cout << "Michael Health : " << michael.getHealth() << "\n" << std::endl;
	michael.beRepaired(200);
	std::cout << std::endl;
	delete(sam);
	std::cout << std::endl;

	return 0;
}
```
```
$> ./a.out
...
+ClapTrap Default constructor called.
+ScavTrap Default constructor called.
+FragTrap Default constructor called.
+DiamondTrap Name parameter constructor called.
+ClapTrap Default constructor called.
+ScavTrap Default constructor called.
+FragTrap Default constructor called.
+DiamondTrap Name parameter constructor called.

Michael name : Michael
Michael Health : 100
Michael Energy : 50
Michael Attack damage : 30

ScavTrap Michael_clap_name attacks Sam, causing 30 point of damage!
ClapTrap Sam_clap_name takes 30 point of damage!
Michael Energy : 49
Sam Health : 70

ClapTrap Sam_clap_name be repaired 35 point!
Sam Health : 100
Sam Energy : 49

Hi! I'm Michael and Michael_clap_name.
Nice to meet you.
Michael Energy : 48

Hi! I'm Sam and Sam_clap_name.
Nice to meet you.
Sam Energy : 48

Sam Energy : 0

ClapTrap Sam_clap_name doesn't have enough energy.
ClapTrap Michael_clap_name takes 150 point of damage!
Michael Health : 0


-DiamondTrap Destructor called.
-- DiamondTrap Sam stops working...
-FragTrap Destructor called.
-- FragTrap Sam_clap_name stops working...
-ScavTrap Destructor called.
-- ScavTrap Sam_clap_name stops working...
-ClapTrap Destructor called.
-- ClapTrap Sam_clap_name stops working...

-DiamondTrap Destructor called.
-- DiamondTrap Michael stops working...
-FragTrap Destructor called.
-- FragTrap Michael_clap_name stops working...
-ScavTrap Destructor called.
-- ScavTrap Michael_clap_name stops working...
-ClapTrap Destructor called.
-- ClapTrap Michael_clap_name stops working...
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
