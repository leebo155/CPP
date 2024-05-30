 # No, you need form 28B, not 28C...
In this exercise, implement subtype classes that inherit from the Form class created in the previous exercise.   
Through this process, learn how to handle exceptions using the exception objects from the parent class.   

 ## Rules
In all cases, the base class Form must be an abstract class, and therefore should be renamed AForm. Keep in mind the form’s attributes need to remain private and that they are in the base class.   

Add the following concrete classes:

* **ShrubberyCreationForm**: Required grades: sign 145, exec 137
  Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.

* **RobotomyRequestForm**: Required grades: sign 72, exec 45   
  Makes some drilling noises. Then, informs that <target> has been robotomized successfully 50% of the time. Otherwise, informs that the robotomy failed.
  
* **PresidentialPardonForm**: Required grades: sign 25, exec 5   
  Informs that <target> has been pardoned by Zaphod Beeblebrox.

All of them take only one parameter in their constructor: the target of the form. For
example, "home" if you want to plant shrubbery at home.

Now, add the **execute(Bureaucrat const & executor)** const member function to the base form and implement a function to execute the form’s action of the concrete classes. You have to check that the form is signed and that the grade of the bureaucrat attempting to execute the form is high enough. Otherwise, throw an appropriate exception.     

Whether you want to check the requirements in every concrete class or in the base class (then call another function to execute the form) is up to you. However, one way is prettier than the other one.   

Lastly, add the executeForm(AForm const & form) member function to the Bureaucrat. It must attempt to execute the form. If it’s successful, print something like:
```
<bureaucrat> executed <form>
```
If not, print an explicit error message.

 ## Execution
```cpp
int	main(void)
{
	AForm *test1 = new ShrubberyCreationForm("Test1");
	AForm *test2 = new RobotomyRequestForm("Test2");
	AForm *test3 = new PresidentialPardonForm("Test3");

	Bureaucrat kim("Kim", 1);
	Bureaucrat lee("Lee", 150);

	std::cout << ">>Test 1: Form.execute() not signed Forms" << std::endl;
	try
	{
		test1->execute(lee);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		test2->execute(lee);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		test3->execute(lee);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n>>Test 2: Form.execute() signed Forms but low grade Bureaucrat" << std::endl;

	kim.signForm(*test1);
	kim.signForm(*test2);
	kim.signForm(*test3);
	
	try
	{
		test1->execute(lee);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		test2->execute(lee);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		test3->execute(lee);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n>>Test 3: Form.execute() signed Forms high grade Bureaucrat" << std::endl;
	
	try
	{
		test1->execute(kim);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		test2->execute(kim);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		test3->execute(kim);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete test1;
	delete test2;
	delete test3;

	AForm *test4 = new ShrubberyCreationForm("Test4");
	AForm *test5 = new RobotomyRequestForm("Test5");
	AForm *test6 = new PresidentialPardonForm("Test6");

	std::cout << "\n>>Test 4: Bureaucrat.executeForm() not signed Forms" << std::endl;
	kim.executeForm(*test4);
	kim.executeForm(*test5);
	kim.executeForm(*test6);

	std::cout << "\n>>Test 5: Low grade Bureaucrat.executeForm() signed Forms" << std::endl;
	kim.signForm(*test4);
	kim.signForm(*test5);
	kim.signForm(*test6);

	lee.executeForm(*test4);
	lee.executeForm(*test5);
	lee.executeForm(*test6);

	std::cout << "\n>>Test 6: High grade Bureaucrat.executeForm() signed Forms" << std::endl;
	kim.executeForm(*test4);
	kim.executeForm(*test5);
	kim.executeForm(*test6);

	delete test4;
	delete test5;
	delete test6;

	return 0;
}
```
```
$> ./a.out
>>Test 1: Form.execute() not signed Forms
Form is not signed
Form is not signed
Form is not signed

>>Test 2: Form.execute() signed Forms but low grade Bureaucrat
Kim signed ShrubberyCreationForm
Kim signed RobotomyRequestForm
Kim signed PresidentialPardonForm
Grade too low
Grade too low
Grade too low

>>Test 3: Form.execute() signed Forms high grade Bureaucrat
Drrrrrr.. drr.. drrrr... drrr.
Test2 has been successfully robotomized.
Test3 has been pardoned by Zaphod Beeblebrox.

>>Test 4: Bureaucrat.executeForm() not signed Forms
Kim couldn't execute ShrubberyCreationForm because Form is not signed.
Kim couldn't execute RobotomyRequestForm because Form is not signed.
Kim couldn't execute PresidentialPardonForm because Form is not signed.

>>Test 5: Low grade Bureaucrat.executeForm() signed Forms
Kim signed ShrubberyCreationForm
Kim signed RobotomyRequestForm
Kim signed PresidentialPardonForm
Lee couldn't execute ShrubberyCreationForm because Grade too low.
Lee couldn't execute RobotomyRequestForm because Grade too low.
Lee couldn't execute PresidentialPardonForm because Grade too low.

>>Test 6: High grade Bureaucrat.executeForm() signed Forms
Kim executed ShrubberyCreationForm
Drrrrrr.. drr.. drrrr... drrr.
Test5 has been successfully robotomized.
Kim executed RobotomyRequestForm
Test6 has been pardoned by Zaphod Beeblebrox.
Kim executed PresidentialPardonForm
```
