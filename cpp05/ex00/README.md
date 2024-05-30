# Mommy, when I grow up, I want to be a bureaucrat!
In this exercise, learn how to handle exceptions using try/catch statements.   
This process helps understand exception classes and the use of try/catch statements.   

# Rules
Bureaucrat class must have:
* A constant name.
* And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade).

Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception:   
either a **Bureaucrat::GradeTooHighException** or a **Bureaucrat::GradeTooLowException**.

Provide getters for both these attributes: getName() and getGrade().   
Implement also two member functions to increment or decrement the bureaucrat grade.    
If the grade is out of range, both of them will throw the same exceptions as the constructor.   

_Since grade 1 is the highest one and 150 the lowest, incrementing a grade 3 should give a grade 2 to the bureaucrat._

implement an overload of the insertion («) operator to print something like (without the angle brackets):
```
<name>, bureaucrat grade <grade>.
```

## Execution
```cpp
int	main(void)
{
	Bureaucrat kim("Kim", 1);
	Bureaucrat *lee = new Bureaucrat("Lee", 150);
	try // GradeTooHighException
	{
		Bureaucrat park("Park", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try // GradeTooLowException
	{
		Bureaucrat choi("Choi", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << kim << std::endl;
	std::cout << *lee << std::endl;

	try // GradeTooHighException
	{
		kim.increaseGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try // GradeTooLowException
	{
		lee->decreaseGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	kim.decreaseGrade();
	std::cout << kim << std::endl;
	kim.increaseGrade();
	std::cout << kim << std::endl;

	lee->increaseGrade();
	std::cout << *lee << std::endl;
	lee->decreaseGrade();
	std::cout << *lee << std::endl;

	delete lee;
	return 0;
}
```
```
$> ./a.out
Grade too high exception
Grade too low exception
Kim, bureaucrat grade 1.
Lee, bureaucrat grade 150.
Grade too high exception
Grade too low exception
Kim, bureaucrat grade 2.
Kim, bureaucrat grade 1.
Lee, bureaucrat grade 149.
Lee, bureaucrat grade 150.
```
