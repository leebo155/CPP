/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:55:39 by bohlee            #+#    #+#             */
/*   Updated: 2024/03/05 16:38:11 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <vector>
# include <list>
# include <exception>

class PmergeMe
{
	private:
		std::vector<uint64_t> vt;
		std::list<uint64_t> lt;

		int		jacobsthalNumber(int n);
		template <typename T>
		void	splitPair(int size, T &t)
		{
			for (int i = 0; i + 1 < size; i += 2)
			{
				int a = i;
				int b = i + 1;
				if (t.at(a) < t.at(b))
				{
					T	tmp;
					tmp.insert(tmp.begin(), t.begin() + b, t.begin() + b + 1);
					t.erase(t.begin() + b);
					t.insert(t.begin() + a, tmp.begin(), tmp.end());
					tmp.clear();
					std::cout << "vector: ";
					for (typename T::iterator it = t.begin(); it != t.end(); it++)
						std::cout << *it << " ";
					std::cout << std::endl;
				}
			}
		};
		template <typename T>
		void	mergeRecur(int a, int b, int node_size, T &t)
		{
			int size = (b - a) / 2;
			if (b  - a + 1 < node_size )
				return ;
			else if (b - a + 1 == node_size * 2)
			{
				b = a + size + 1;
				if (t.at(a) < t.at(b))
				{
					T	tmp;
					tmp.insert(tmp.begin(), t.begin() + b, t.begin() + b + node_size);
					t.erase(t.begin() + b, t.begin() + b + node_size);
					t.insert(t.begin() + a, tmp.begin(), tmp.end());
					tmp.clear();
					std::cout << "vector: ";
					for (typename T::iterator it = t.begin(); it != t.end(); it++)
						std::cout << *it << " ";
					std::cout << std::endl;
				}
				return ;
			}

			this->mergeRecur(a, size, node_size, t);
			this->mergeRecur(a + size + 1, b, node_size, t);	
		};
		
		template <typename T>
		int	binarySearch(int pivot, int end, int node_size, T &a, T &b)
		{
			int	middle;
			int	low = 0;
			int high = end - 1;
			
			while (low <= high)
			{
				middle = (high + low) / 2;

				if (low == high)
					return middle;
				else if (b.at(pivot * node_size) <  a.at(middle * node_size))
					high = middle - 1;
				else
					low = middle + 1;
			}
			return -1;
		};

		template <typename T>
		void	insertMerge(int nodes, int node_size, T &t)
		{
			T	tmp;
			int	start, end;
			int b_blocks = nodes / 2;

			for (int i = 0; i < b_blocks; i++)
			{
				start = i * node_size + node_size;
				end = start + node_size;
				tmp.insert(tmp.end(), t.begin() + start, t.begin() + end);
				t.erase(t.begin() + start, t.begin() + end);

				std::cout << "vector a: ";
				for (typename T::iterator it = t.begin(); it != t.end(); it++)
					std::cout << *it << " ";
				std::cout << std::endl;
				std::cout << "vector b: ";
				for (typename T::iterator it = tmp.begin(); it != tmp.end(); it++)
					std::cout << *it << " ";
				std::cout << std::endl;
			}
			if (nodes % 2)
			{
				tmp.insert(tmp.end(), t.begin() + start, t.begin() + end);
				t.erase(t.begin() + start, t.begin() + end);
				b_blocks++;

				std::cout << "vector a: ";
				for (typename T::iterator it = t.begin(); it != t.end(); it++)
					std::cout << *it << " ";
				std::cout << std::endl;
				std::cout << "vector b: ";
				for (typename T::iterator it = tmp.begin(); it != tmp.end(); it++)
					std::cout << *it << " ";
				std::cout << std::endl;
			}
			t.insert(t.begin(), tmp.begin(), tmp.begin() + node_size);
			tmp.erase(tmp.begin(), tmp.begin() + node_size);

			std::cout << "vector a: ";
			for (typename T::iterator it = t.begin(); it != t.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
			std::cout << "vector b: ";
			for (typename T::iterator it = tmp.begin(); it != tmp.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;

			int selected = 1;
			int	move = 1;
			int first_move, jacob, select, find;
			for (int i = 3; !tmp.empty(); i++)
			{
				jacob = this->jacobsthalNumber(i);
				if (jacob >= b_blocks)
					jacob = b_blocks;
				end = jacob + move;
				if (nodes % 2)
					end--;
				select = jacob - move - 1;
				first_move = this->binarySearch(select, end, node_size, t, tmp);
				t.insert(t.begin() + first_move * node_size,
						tmp.begin() + select * node_size, tmp.begin() + (select + 1) * node_size);
				tmp.erase(tmp.begin() + select * node_size, tmp.begin() + (select + 1) * node_size);

				std::cout << "vector a: ";
				for (typename T::iterator it = t.begin(); it != t.end(); it++)
					std::cout << *it << " ";
				std::cout << std::endl;
				std::cout << "vector b: ";
				for (typename T::iterator it = tmp.begin(); it != tmp.end(); it++)
					std::cout << *it << " ";
				std::cout << std::endl;
				jacob--;
				for (int j = jacob; j > selected; j--)
				{
					end = j + move - 1;
					if (first_move <= end)
						end++;
					move++;
					select = j - move;
					find = this->binarySearch(select, end, node_size, t, tmp);
					t.insert(t.begin() + find * node_size,
							tmp.begin() + select * node_size, tmp.begin() + (select + 1) * node_size);
					tmp.erase(tmp.begin() + select * node_size, tmp.begin() + (select + 1) * node_size);
					std::cout << "vector a: ";
					for (typename T::iterator it = t.begin(); it != t.end(); it++)
						std::cout << *it << " ";
					std::cout << std::endl;
					std::cout << "vector b: ";
					for (typename T::iterator it = tmp.begin(); it != tmp.end(); it++)
						std::cout << *it << " ";
					std::cout << std::endl;
				}
				selected = jacob + 1;
				move++;
			}
		};

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &target);
		PmergeMe &operator=(const PmergeMe &target);
		~PmergeMe(void);

		void	sort(int argc, char **argv) throw(std::exception);
};

#endif
