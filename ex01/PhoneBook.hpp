/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:10:10 by bohlee            #+#    #+#             */
/*   Updated: 2023/10/18 14:53:59 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	Contacts[8];

	public:
		void	ft_set_phonebook(int index, std::string firstname,
					std::string lastname, std::string nickname,
					std::string phonenumber, std::string darkestsecret);
		std::string	ft_get_firstname(int index);
		std::string	ft_get_lastname(int index);
		std::string	ft_get_nickname(int index);
		std::string	ft_get_phonenumber(int index);
		std::string	ft_get_darkestsecret(int index);
};

#endif
