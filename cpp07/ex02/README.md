# Array
In this exercise, implement a class template.
Through this process, gain an understanding of containers and class template .

## Rules
Develop a class template **Array** that contains elements of type T and that implements
the following behavior and functions:

* Construction with no parameter: Creates an empty array.

* Construction with an unsigned int n as a parameter: Creates an array of n elementsinitialized by default.   
  Tip: Try to compile int * a = new int(); then display *a.
  
* Construction by copy and assignment operator. In both cases, modifying either the original array or its copy after copying musn’t affect the other array.

* You MUST use the operator new[] to allocate memory. Preventive allocation (allocating memory in advance) is forbidden. Your program must never access nonallocated memory.

* Elements can be accessed through the subscript operator: [ ].

* When accessing an element with the [ ] operator, if its index is out of bounds, an std::exception is thrown.

* A member function size() that returns the number of elements in the array.   
  This member function takes no parameter and musn’t modify the current instance.

## Execution
```cpp
template <typename T>
class Array
{
	private:
		T *array;
		unsigned int amount;

	public:
		class WrongIndexException: public std::exception
		{
			public:
				const char *what(void) const throw()
				{ return "Wrong Index"; };
		};
		Array(void) {
			array = new T[0];
			amount = 0;
		};
		Array(const Array &target) {
			amount = 0;
			array = new T[0];
			*this = target;
		};
		Array &operator=(const Array &target) {
			if (this != &target)
			{
				if (array)
					delete[] array;
				amount = target.amount;
				array = new T[amount];
				for (long long i = 0; i < amount; i++)
					array[i] = target.array[i];
			}
			return *this;
		};
		~Array(void)
		{ delete[] array; };

		Array(const unsigned int size) {
			amount = size;
			array = new T[amount];
		};
		T &operator[](const long long index) const throw(std::exception) {
			if (index < 0 || amount <= index)
				throw Array::WrongIndexException();
			return array[index];
		};
		unsigned int	size(void) const
		{ return amount; };
};
```
```cpp
int main(int, char**)
{
	Array<int> empty;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

	std::cout << numbers.size() << std::endl;

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    	for (int i = 0; i < MAX_VAL; i++)
    	{
        	if (tmp[i] != numbers[i] || test[i] != numbers[i])
        	{
          	   std::cerr << "didn't save the same value!!" << std::endl;
         	   return 1;
        	}
		}
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
```
```
$> ./a.out
750
Wrong Index
Wrong Index
````
