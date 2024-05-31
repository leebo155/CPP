# Serialization
In this exercise, implement functions that convert between integers and pointers using reinterpret_cast.   
Through this process, understand how reinterpret_cast works.   

## Rules
Implement a class Serializer, who will not be initializable by the user by any way,   
with the following static methods:   

```cpp
uintptr_t serialize(Data* ptr);
```
It takes a pointer and converts it to the unsigned integer type uintptr_t

```cpp
Data* deserialize(uintptr_t raw);
```
It takes an unsigned integer parameter and converts it to a pointer to Data.   

Use serialize() on the address of the Data object and pass its return value to deserialize().   
Then, ensure the return value of deserialize() compares equal to the original pointer.   

## Execution
```cpp
typedef struct	s_Data
{
	char	c;
	int		i;
	float	f;
	double	d;
} Data;
```
```cpp
int main(void)
{
	Data	org = {'A', 124, 3.14f, 24.42};

	std::cout << "Org address: " << &org << std::endl;

	std::cout << "Org.char: " << org.c << std::endl;
	std::cout << "Org.int: " << org.i << std::endl;
	std::cout << "Org.float: " << org.f << std::endl;
	std::cout << "Org.double: " << org.d << std::endl;

	uintptr_t raw = Serializer::serialize(&org);
	Data	*dup = Serializer::deserialize(raw);

	std::cout << "\nDup address: " << dup << std::endl;

	std::cout << "Dup->char: " << dup->c << std::endl;
	std::cout << "Dup->int: " << dup->i << std::endl;
	std::cout << "Dup->float: " << dup->f << std::endl;
	std::cout << "Dup->double: " << dup->d << std::endl;

	return 0;
}
```
```
$> ./a.out
Org address: 0x7ffee8d91a20
Org.char: A
Org.int: 124
Org.float: 3.14
Org.double: 24.42

Dup address: 0x7ffee8d91a20
Dup->char: A
Dup->int: 124
Dup->float: 3.14
Dup->double: 24.42
```
