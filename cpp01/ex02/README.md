# HI THIS IS BRAIN
This exercise teaches the difference between references and pointers.   

## Rules
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

# Execution
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

  ``` 
  $> ./program
  The memory address of the string : 0x7ffee35ff990
  The memory address held by stringPTR : 0x7ffee35ff990
  The memory address held by stringREF : 0x7ffee35ff990
  
  The value of the string : HI THIS IS BRAIN
  The value pointed to by stringPTR : HI THIS IS BRAIN
  The value pointed to by stringREF : HI THIS IS BRAIN
  ```
