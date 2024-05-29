# Harl filter
This exercise involves learning about switch statements.   
Use the Harl class from ex05.

## Rules
When a slevel is input, the strings of that level and below are printed.
  ```
  $> ./harlFilter "WARNING"
  [ WARNING ]
  I think I deserve to have some extra bacon for free.
  I've been coming for years whereas you started working here since last month.
  [ ERROR ]
  This is unacceptable, I want to speak to the manager now.
  ```

## Execution
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
