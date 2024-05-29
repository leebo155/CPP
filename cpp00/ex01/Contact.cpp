/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:51:18 by bohlee            #+#    #+#             */
/*   Updated: 2023/10/18 14:58:10 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::ft_set_contact(std::string firstname, std::string lastname, 
			std::string nickname, std::string phonenumber,
			std::string darkestsecret)
{
	FirstName = firstname;
	LastName = lastname;
	NickName = nickname;
	PhoneNumber = phonenumber;
	DarkestSecret = darkestsecret;
}

std::string	Contact::ft_get_firstname(void)
{
	return (FirstName);
}

std::string	Contact::ft_get_lastname(void)
{
	return (LastName);
}

std::string	Contact::ft_get_nickname(void)
{
	return (NickName);
}

std::string	Contact::ft_get_phonenumber(void)
{
	return (PhoneNumber);
}

std::string	Contact::ft_get_darkestsecret(void)
{
	return (DarkestSecret);
}
