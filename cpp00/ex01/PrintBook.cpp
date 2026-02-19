/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:49:18 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/04 21:16:38 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PhoneBook.hpp"

bool	PhoneBook::print_book()
{
	int	i;
	std::string	firstName;
	std::string	lastName;
	std::string	phoneNum;
	
	i = 0;
	if (this->_total == 0)
	{
		std::cout << "Phone Book is empty" << std::endl;
		return (false);
	}
	print_header();
	while (i < this->_total)
	{
		firstName = this->_contacts[i].get_firstName();
		lastName = this->_contacts[i].get_lastName();
		phoneNum = this->_contacts[i].get_phoneNum();
	
		std::cout << "|" << std::setfill (' ') << std::setw (10);
		std::cout << (i + 1);
		std::cout << "|" << std::setfill (' ') << std::setw (10);
		std::cout << trunContact(firstName);
		std::cout << "|" << std::setfill (' ') << std::setw (10);
		std::cout << trunContact(lastName);
		std::cout << "|" << std::setfill (' ') << std::setw (10);
		std::cout << trunContact(phoneNum) << "|" << std::endl;
		i++;
	}
	return (true);
}