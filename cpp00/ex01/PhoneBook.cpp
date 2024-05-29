/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:03:19 by bohlee            #+#    #+#             */
/*   Updated: 2023/10/18 14:59:05 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::ft_set_phonebook(int index, std::string firstname,
			std::string lastname, std::string nickname,
			std::string phonenumber, std::string darkestsecret)
{
	Contacts[index].ft_set_contact(firstname, lastname, nickname, phonenumber,
			darkestsecret);
}

std::string	PhoneBook::ft_get_firstname(int index)
{
	return (Contacts[index].ft_get_firstname());
}

std::string	PhoneBook::ft_get_lastname(int index)
{
	return (Contacts[index].ft_get_lastname());
}

std::string	PhoneBook::ft_get_nickname(int index)
{
	return (Contacts[index].ft_get_nickname());
}

std::string	PhoneBook::ft_get_phonenumber(int index)
{
	return (Contacts[index].ft_get_phonenumber());
}

std::string	PhoneBook::ft_get_darkestsecret(int index)
{
	return (Contacts[index].ft_get_darkestsecret());
}
