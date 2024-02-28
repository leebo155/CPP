/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:55:39 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/28 19:41:24 by bohlee           ###   ########.fr       */
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

		template <typename T>;
		void	splitMerge(

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &target);
		PmergeMe &operator=(const PmergeMe &target);
		~PmergeMe(void);

		void	sort(int argc, char **argv) throw(std::exception);
};

#endif
