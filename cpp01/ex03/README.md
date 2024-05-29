# Unnecessary violence
This exercise highlights the precautions to take when using reference and pointer members in classes.   

## Rules
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

## Execution
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
  ``` 
  $> ./program
  Bob attacks with their crude spiked club
  Bob attacks with their some other type of club
  Jim attacks with their crude spiked club
  Jim attacks with their some other type of club
  ```
