/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:38:25 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/04 21:19:35 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_total = 0;
	return ;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add_contact()
{
	if (this->_total < MAX_CONTACT)
	{
		if (this->_contacts[this->_total].get_contact() == true)
		{
			std::cout << "Contact added successfully" << std::endl;
			this->_total += 1;
		}
		else
			std::cout << "ERROR while adding new contact, try again" << std::endl;
	}
	else
	{
		if (delete_msg() == false)
			return ;		
		this->replace_contact();
	}
}

void	PhoneBook::replace_contact()
{
	int old = this->fetch_old();
	std::cout << "The following contact will be permanently deleted :" << std::endl;
	std::cout << "Index : " << old << " Name : "
	<< this->_contacts[old].get_firstName() << " "
	<< this->_contacts[old].get_lastName() << std::endl;
	this->_contacts[old].get_contact();
}

void	PhoneBook::fetch_contact()
{
	std::string str_index;
	int			index;

	index = 0;
	std::cout << "Which contact to search ?" << std::endl;
	std::cout << "Type the corresponding INDEX : ";
	getline(std::cin, str_index);
	if (check_data(str_index, 3) == false)
	{
		std::cout << "ERROR, incorrect index" << std::endl;
		return ;
	}
	std::istringstream(str_index) >> index;
	if (index > 0 && index <= this->_total)
		this->_contacts[index - 1].print_contact();
	else
	{
		std::cout << "ERROR, incorrect index" << std::endl;
		return ;
	}
	
}

int	PhoneBook::fetch_old()
{
	int	i;
	int	old;

	old = 0;
	i = 0;
	while (i < this->_total)
	{
		if (this->_contacts[old].get_time() > this->_contacts[i].get_time())
			old = i;
		i++;
	}
	return (old);
}