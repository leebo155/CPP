# Mutated abomination
In this exercise, implement the class using a stack, a container adapter, which helps understand the difference between a container adapter and a container.

## Rules 
Have to make the **std::stack** container iterable.

Write a **MutantStack** class. It will be **implemented in terms of** a std::stack.
It will offer all its member functions, plus an additional feature: **iterators**.

## Execution
```cpp
template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack(void): std::stack<T>() {};
		MutantStack(const MutantStack &target): std::stack<T>(target) {};
		MutantStack &operator=(const MutantStack &target)
		{
			if (this != target)
			{
				std::stack<T> &st1 = *this;
				std::stack<T> &st2 = target;
				st1 = st2;
			}
			return *this;
		};
		virtual ~MutantStack(void) {};

		iterator				begin(void) { return this->c.begin(); };
		const_iterator			begin(void) const { return this->c.begin(); };
		iterator				end(void) { return this->c.end(); };
		const_iterator			end(void) const { return this->c.end(); };
		reverse_iterator		rbegin(void) { return this->c.rbegin(); };
		const_reverse_iterator	rbegin(void) const { return this->c.rbegin(); };
		reverse_iterator		rend(void) { return this->c.rend(); };
		const_reverse_iterator	rend(void) const { return this->c.rend(); };
		const_iterator			cbegin(void) const { return this->c.cbegin(); };
		const_iterator			cend(void) const { return this->c.cend(); };
		const_reverse_iterator	crbegin(void) const { return this->c.crbegin(); };
		const_reverse_iterator	crend(void) const { return this->c.crend(); };
};
```
```cpp
int main()
{
	std::cout << "Test0: default" << std::endl;
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "MutantStack top(): " << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "\nMutantStack size(): " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "\nMutantStack pirnt" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\nTest1: change type std::list" << std::endl;
	std::list<int> list;
	
	list.push_back(5);
	list.push_back(17);
	
	std::cout << "List top(): " << list.back() << std::endl;
	
	list.pop_back();
	
	std::cout << "\nList size(): " << list.size() << std::endl;
	
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);
	
	std::list<int>::iterator lit = list.begin();
	std::list<int>::iterator lite = list.end();
	++lit;
	--lit;
	std::cout << "\nList pirnt" << std::endl;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << "\nTest2: copy constructor pirnt" << std::endl;
	std::stack<int> s(mstack);
	MutantStack<int> ms(mstack);

	std::cout << "\nStack print" << std::endl;
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::cout << "\nMutantStack print" << std::endl;
	while (!ms.empty())
	{
		std::cout << ms.top() << std::endl;
		ms.pop();
	}

	std::cout << "Test3: copy assignement operator pirnt" << std::endl;
	std::stack<int> st = mstack;
	MutantStack<int> mst = mstack;

	std::cout << "\nStack print" << std::endl;
	while (!st.empty())
	{
		std::cout << st.top() << std::endl;
		st.pop();
	}

	std::cout << "\nMutantStack print" << std::endl;
	while (!mst.empty())
	{
		std::cout << mst.top() << std::endl;
		mst.pop();
	}
	return 0;
}
```
```
./a.out
Test0: default
MutantStack top(): 17

MutantStack size(): 1

MutantStack pirnt
5
3
5
737
0

Test1: change type std::list
List top(): 17

List size(): 1

List pirnt
5
3
5
737
0

Test2: copy constructor pirnt

Stack print
0
737
5
3
5

MutantStack print
0
737
5
3
5
Test3: copy assignement operator pirnt

Stack print
0
737
5
3
5

MutantStack print
0
737
5
3
5
```
