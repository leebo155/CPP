# BraiiiiiiinnnzzzZ
This exercise involves implementing a Zombie class to learn about memory allocation in C++.   

## Rules
* Zombie class has a string private attribute name and a member function void announce( void ) that announce itself.
  ```
  <name>: BraiiiiiiinnnzzzZ...
  ```

* Then, implement the two following functions:
  ```cpp 
  Zombie* newZombie( std::string name );
  ```
  It creates a zombie, name it, and return it so you can use it outside of the function.

  ```cpp 
  void randomChump( std::string name );
  ```
  It creates a zombie, name it, and the zombie announces itself.

## Execution
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

    ``` 
    $> ./zombie
    alice is dead.
    bob: BraiiiiiiinnnzzzZ...
    bob is dead.
    tom is dead.
    ```
