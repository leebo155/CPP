# Harl 2.0
This exercise involves learning about function pointers.   

## Rules
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

## Execution
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
