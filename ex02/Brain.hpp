/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:01:56 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/07 19:34:59 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
		
	public:
		Brain(void);
		Brain(const Brain &target);
		Brain &operator= (const Brain &target);
		~Brain(void);

		std::string getIdeas(int index) const;
		void		setIdeas(int index, std::string idea);
};

#endif
