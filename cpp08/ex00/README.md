# Easy find
In this exercise, implement a function template that finds values in integer containers, which gives a better understanding of the containers.

## Rules
Write a function template **easyfind** that accepts a type **T**.
It takes two parameters. The first one has type T and the second one is an integer.

Assuming T is a container of integers, this function has to find the first occurrence of the second parameter in the first parameter.

## Execution
```cpp
template <typename T>
typename T::iterator	easyfind(T container ,int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);

	if (it == container.end())
		throw std::runtime_error("can't find");
	return it;
};
```
```cpp
int main(void)
{
	std::vector<int> v;
	std::deque<int> d;
	std::list<int> l;

	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	d.push_front(1);
	d.push_front(3);
	d.push_front(4);

	l.push_back(1);
	l.push_back(2);
	l.push_back(4);

	std::cout << "std::vector<int> = {2, 3, 4};\nstd::deque<int> = {4, 3, 1};\nstd::list<int> = {1, 2, 4};\n" << std::endl;

	for (int i = 1; i < 5; i++)
	{
		try {
			std::vector<int>::iterator vit = easyfind(v, i);
			std::cout << "vector<int>: " << *vit << " find" << std::endl;
		} catch (std::exception &e) {
			std::cerr << "vector<int>: " << i << " " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	for (int i = 1; i < 5; i++)
	{

		try {
			std::deque<int>::iterator dit = easyfind(d, i);
			std::cout << "deque<int>: " << *dit << " find" << std::endl;
		} catch (std::exception &e) {
			std::cerr << "deque<int>: " << i << " " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	for (int i = 1; i < 5; i++)
	{
		try {
			std::list<int>::iterator lit = easyfind(l, i);
			std::cout << "list<int>: " << *lit << " find" << std::endl;
		} catch (std::exception &e) {
			std::cerr << "list<int>: " << i << " " << e.what() << std::endl;
		}
	}
	
	return 0;
}
```
```
$> ./a.out
std::vector<int> = {2, 3, 4};
std::deque<int> = {4, 3, 1};
std::list<int> = {1, 2, 4};

vector<int>: 1 can't find
vector<int>: 2 find
vector<int>: 3 find
vector<int>: 4 find

deque<int>: 1 find
deque<int>: 2 can't find
deque<int>: 3 find
deque<int>: 4 find

list<int>: 1 find
list<int>: 2 find
list<int>: 3 can't find
list<int>: 4 find
```
