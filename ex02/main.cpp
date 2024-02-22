/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:28:45 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/22 17:19:04 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <list>
# include "MutantStack.hpp"

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
