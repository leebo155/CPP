# Form up, maggots!
In this exercise, implement a Form class to be used by the Bureaucrat class implemented in the previous exercise.   
Through this process, can gain a better understanding of exception handling.   

## Rules
Make a Form class. It has:   
* A constant name.    
* A boolean indicating whether it is signed (at construction, it’s not).   
* A constant grade required to sign it.   
* And a constant grade required to execute it. All these attributes are private, not protected.

All these attributes are private, not protected.   

The grades of the Form follow the same rules that apply to the Bureaucrat.   
Thus, the following exceptions will be thrown if a form grade is out of bounds:    
**Form::GradeTooHighException** and **Form::GradeTooLowException**.

Same as before, write getters for all attributes and an overload of the insertion («) operator that prints all the form’s informations.

Add also a **beSigned()** member function to the Form that takes a Bureaucrat as parameter.   
It changes the form status to signed if the bureaucrat’s grade is high enough (higher or egal to the required one).   
Remember, grade 1 is higher than grade 2.   
If the grade is too low, throw a **Form::GradeTooLowException**.   

Lastly, add a **signForm()** member function to the Bureaucrat. If the form got signed,
it will print something like:
```
<bureaucrat> signed <form>
```
Otherwise, it will print something like:
```
<bureaucrat> couldn’t sign <form> because <reason>.
```

## Execution
```cpp
int	main(void)
{
	Form word("Word", 150, 35);
	Form excel("Excel", 1, 12);
	try
	{
		Form test1("Test 1", 151, 130);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form test2("Test 2", 0, 130);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form test3("Test 3", 120, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form test4("Test 4", 120, 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n" << std::endl;
	}
	
	Bureaucrat alice("Alice", 150);
	Bureaucrat bob("Bob", 1);

	std::cout << word << std::endl;
	std::cout << excel << std::endl;
	std::cout << alice << std::endl;
	std::cout << bob << "\n" << std::endl;

	try
	{
		excel.beSigned(alice);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n" << std::endl;
	}

	alice.signForm(word);
	alice.signForm(excel);
	
	bob.signForm(word);
	bob.signForm(excel);

	std::cout << "\n" << word << std::endl;
	std::cout << excel << std::endl;

	return 0;
}

```
```
$> ./a.out
Grade too low
Grade too high
Grade too low
Grade too high

Word, Form required grade for sign is 150, execution is 35 and this Form is not signed.
Excel, Form required grade for sign is 1, execution is 12 and this Form is not signed.
Alice, bureaucrat grade 150.
Bob, bureaucrat grade 1.

Grade too low

Alice signed Word
Alice couldn't sign Excel because Grade too low.
Bob signed Word
Bob signed Excel

Word, Form required grade for sign is 150, execution is 35 and this Form is signed.
Excel, Form required grade for sign is 1, execution is 12 and this Form is signed.
```
