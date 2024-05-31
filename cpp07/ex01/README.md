# Iter
In this exercise, implement template functions that take arrays and functions as parameters and execute them.   
Through this process, gain a deeper understanding of templates.   

## Rules
Implement a function template iter that takes 3 parameters and returns nothing.

* The first parameter is the address of an array.

* The second one is the length of the array.
  
* The third one is a function that will be call on every element of the array.

Turn in a main.cpp file that contains your tests. Provide enough code to generate a test executable.

## Execution
```cpp
template <typename T>
void	iter(const T *arr, size_t size, void (*func)(const T))
{
	for (size_t i = 0; i < size; i++)
		func(arr[i]);
};
```
```cpp
template <typename T>
void	doublePrint(const T t)
{
	std::cout << t + t << std::endl;
};

template <typename T>
void	templatePrint(const T t)
{
	std::cout << t << std::endl;
};

void	intOnePlusPrint(const int i)
{
	std::cout << i + 1 << std::endl;
}

void	strLengthPrint(const std::string str)
{
	std::cout << str.length() << std::endl;
}
```
```cpp
int	main()
{

	int	i[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::string str[3] = {"Hello", "World", "42seoul"};

	std::cout << "Test1: templatePrint(int)" << std::endl;
	::iter(i, 10, &templatePrint);
	std::cout << "\nTest2: templatePrint(string)" << std::endl;
	::iter(str, 3, &templatePrint);
	std::cout << "\nTest3: doublePrint(int)" << std::endl;
	::iter(i, 10, &doublePrint);
	std::cout << "\nTest4: doublePrint(string)" << std::endl;
	::iter(str, 3, &doublePrint);
	std::cout << "\nTest5: intOnePlusPrint(int)" << std::endl;
	::iter(i, 10, &intOnePlusPrint);
	std::cout << "\nTest6: strLengthPrint(string)" << std::endl;
	::iter(str, 3, &strLengthPrint);

	return 0;

}
```
