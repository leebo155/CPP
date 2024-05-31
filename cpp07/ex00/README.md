# Start with a few functions
In this exercise, implement simple template functions to understand templates.

## Rules
Implement the following function templates:

* **swap**: Swaps the values of two given arguments. Does not return anything.

* **min**: Compares the two values passed in its arguments and returns the smallest one.   
  If the two of them are equal, then it returns the second one.

* **max**: Compares the two values passed in its arguments and returns the greatest one.   
  If the two of them are equal, then it returns the second one.
  
These functions can be called with any type of argument. The only requirement is that the two arguments must have the same type and must support all the comparison operators.

## Execution
```cpp
template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
};

template <typename T>
T	&min(T &a, T &b)
{
	if (a > b)
		return b;
	return a;
};

template <typename T>
T	&max(T &a, T &b)
{
	if (a < b)
		return b;
	return a;
};
```
```cpp
int main( void ) {

	int a = 2;
	int b = 3;
	
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	return 0;

}
```
```
$> ./a.out
a = 3, b = 2
min( a, b ) = 2
max( a, b ) = 3
c = chaine2, d = chaine1
min( c, d ) = chaine1
max( c, d ) = chaine2
```
