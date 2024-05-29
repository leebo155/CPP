/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:18:20 by bohlee            #+#    #+#             */
/*   Updated: 2023/10/18 14:53:52 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class	Contact
{
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	DarkestSecret;

	public:
		void ft_set_contact(std::string firstname, std::string lastname,
				std::string nickname, std::string phonenumber,
				std::string darkestsecret);
		std::string	ft_get_firstname(void);
		std::string ft_get_lastname(void);
		std::string ft_get_nickname(void);
		std::string ft_get_phonenumber(void);
		std::string ft_get_darkestsecret(void);
};

#endif
