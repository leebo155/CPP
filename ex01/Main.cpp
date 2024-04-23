/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:22:26 by bohlee            #+#    #+#             */
/*   Updated: 2023/11/09 12:24:52 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

static int	ft_my_getline(std::string *str)
{
	std::getline(std::cin, *str);
	if (std::cin.eof())
	{
		std::clearerr(stdin);
		std::cin.clear();
		std::cout << std::endl;
		return (1);
	}
	return (0);
}

static void	ft_add_contact(PhoneBook *phonebook, int *index, bool *flag)
{
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phonenumber;
	std::string	darkestsecret;

	std::cout << "Enter First Name : ";
	if (ft_my_getline(&firstname))
		return ;
	std::cout << "Enter Last Name : ";
	if (ft_my_getline(&lastname))
		return ;
	std::cout << "Enter Nick Name : ";
	if (ft_my_getline(&nickname))
		return ;
	std::cout << "Enter Phone Number : ";
	if (ft_my_getline(&phonenumber))
		return ;
	std::cout << "Enter Darkest Secret : ";
	if (ft_my_getline(&darkestsecret))
		return ;
	(*phonebook).ft_set_phonebook((*index)++, firstname, lastname, nickname,
			phonenumber, darkestsecret);
	if (*flag == false && *index == 8)
		*flag = true;
}

static void	ft_print_right_align(std::string name)
{
	int	index;

	index = 0;
	if (name.length() > 10)
	{
		name.resize(10);
		name.back() = '.';
	}
	std::cout << std::setw(10) << name << "|";
}

static int	ft_get_contact(PhoneBook *phonebook, int end, bool flag)
{
	std::string	index_str;
	int			index_num;

	index_num = 0;
	std::cout << "Please enter the contact's index to see more details." << std::endl;
	std::cout << ">";
	if (ft_my_getline(&index_str))
		return (0);
	index_num = std::atoi(index_str.c_str());
	index_num--;
	if ((flag && (0 <= index_num && index_num <= 7)) || (0 <= index_num && index_num < end))
	{
		std::cout << std::endl << "First Name : ";
		std::cout << (*phonebook).ft_get_firstname(index_num) << std::endl;
		std::cout << "Last Name : ";
		std::cout << (*phonebook).ft_get_lastname(index_num) << std::endl;
		std::cout << "Nickname : ";
		std::cout << (*phonebook).ft_get_nickname(index_num) << std::endl;
		std::cout << "Phone Number : ";
		std::cout << (*phonebook).ft_get_phonenumber(index_num) << std::endl;
		std::cout << "Darkest Secret : ";
		std::cout << (*phonebook).ft_get_darkestsecret(index_num) << std::endl << std::endl;
	}
	else
		return (1);
	return (0);
}

static void	ft_search_phonebook(PhoneBook *phonebook, int end, bool flag)
{
	std::string	margin;
	int			index;
	
	if (end == 0 && flag == false)
	{
		std::cout << "PhoneBook is empty. Please add contact." << std::endl;
		return ;
	}
	margin = "          ";
	index = 0;
	std::cout << std::endl;
	std::cout << margin << "|" << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|" << std::endl;
	while ((flag && index < 8 ) || index < end)
	{
		std::cout << margin << "|" << std::setw(10) << index + 1 << "|";
		ft_print_right_align((*phonebook).ft_get_firstname(index));
		ft_print_right_align((*phonebook).ft_get_lastname(index));
		ft_print_right_align((*phonebook).ft_get_nickname(index));
		std::cout << std::endl;
		index++;
	}
	std::cout << std::endl;
	if (ft_get_contact(phonebook, end, flag))
		std::cout << "Error: wrong index." <<std::endl;
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;
	int			index;
	bool		full_flag;

	index = 0;
	full_flag = false;
	std::cout << "Wellcome My Awesome PhoneBook" << std::endl;
	while (1)
	{
		std::cout << "Please, Enter your command (ADD | SEARCH | EXIT)" << std::endl;
		std::cout << ">";
		if (ft_my_getline(&command))
			continue ;
		if (command == "ADD")
			ft_add_contact(&phonebook, &index, &full_flag);
		else if (command == "SEARCH")
			ft_search_phonebook(&phonebook, index, full_flag);
		else if (command == "EXIT")
			break ;
		else if (command == "")
			continue ;
		else
			std::cout << "Error: wrong command." << std::endl;
		index %= 8;
	}
	return (0);
}
