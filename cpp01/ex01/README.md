# Moar brainz!
This exercise implements the zombieHorde function to learn about resource management in C++.   
Use the Zombie class from ex00.

## Rules
```cpp 
Zombie* zombieHorde( int N, std::string name );
```
It must allocate **N** Zombie objects in a single allocation. Then, it has to initialize the zombies, giving each one of them the name passed as parameter. The function returns a pointer to the first zombie.

## Execution
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

  ```
  $> ./zombie 3 bab
  1 bab: BraiiiiiiinnnzzzZ...
  2 bab: BraiiiiiiinnnzzzZ...
  3 bab: BraiiiiiiinnnzzzZ...
  bab is dead.
  bab is dead.
  bab is dead.
  ```
