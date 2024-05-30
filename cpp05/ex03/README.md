# At least this beats coffee-making
In this exercise, implement the **Intern** class, which returns subtypes of the **AForm** class that created in the previous exercise.

## Rules
The intern has no name, no grade, no unique characteristics.   
The only thing the bureaucrats care about is that they do their job.   

However, the intern has one important capacity: the makeForm() function.   
It takes two strings. The first one is the name of a form and the second one is the target of the form.    
It return a pointer to a **Form object** (whose name is the one passed as parameter) whose target will be initialized to the second parameter.   

It will print something like:
```
Intern creates <form>
```
If the form name passed as parameter doesn’t exist, print an explicit error message.

Must avoid unreadable and ugly solutions like using a if/elseif/else forest.   
This kind of things won’t be accepted during the evaluation process.

## Execution
```cpp
int	main(void)
{
	Bureaucrat	kim("Kim", 1);
	Intern		intern;
	AForm		*rrf;

	std::cout << "Test 1: Shrubbery Creation Form" << std::endl;
	
	rrf = intern.makeForm("shrubbery creation", "Bender");
	std::cout << *rrf << std::endl;
	kim.signForm(*rrf);
	kim.executeForm(*rrf);

	delete rrf;
	
	std::cout << "\nTest 2: Robotomy Request Form" << std::endl;

	rrf = intern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;
	kim.signForm(*rrf);
	kim.executeForm(*rrf);

	delete rrf;
	
	std::cout << "\nTest 3: Presidential Pardon Form" << std::endl;

	rrf = intern.makeForm("presidential pardon", "Bender");
	std::cout << *rrf << std::endl;
	kim.signForm(*rrf);
	kim.executeForm(*rrf);

	delete rrf;

	std::cout << "\nTest 4: Unknown Form" << std::endl;
	
	try
	{
		rrf = intern.makeForm("unknown", "Bender");
		std::cout << *rrf << std::endl;
		kim.signForm(*rrf);
		kim.executeForm(*rrf);
	
		delete rrf;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
```
```
$> ./a.out
Test 1: Shrubbery Creation Form
ShrubberyCreationForm, Form required grade for sign is 145, execution is 137 and this Form is not signed.
Kim signed ShrubberyCreationForm
Kim executed ShrubberyCreationForm

Test 2: Robotomy Request Form
RobotomyRequestForm, Form required grade for sign is 72, execution is 45 and this Form is not signed.
Kim signed RobotomyRequestForm
Drrrrrr.. drr.. drrrr... drrr.
Bender failed robotomized.
Kim executed RobotomyRequestForm

Test 3: Presidential Pardon Form
PresidentialPardonForm, Form required grade for sign is 25, execution is 5 and this Form is not signed.
Kim signed PresidentialPardonForm
Bender has been pardoned by Zaphod Beeblebrox.
Kim executed PresidentialPardonForm

Test 4: Unknown Form
Can't find Form
```
