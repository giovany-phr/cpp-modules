/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:02:46 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/04 21:14:40 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Contact.hpp"

Contact::Contact()
{
	this->_tCreated = 0;
	return ;
}

Contact::~Contact()
{
}

std::string	Contact::get_firstName()
{
	return (this->_firstName);
}

std::string	Contact::get_lastName()
{
	return (this->_lastName);
}

std::string	Contact::get_nickName()
{
	return (this->_nickName);
}

std::string	Contact::get_phoneNum()
{
	return (this->_phoneNum);
}

std::string	Contact::get_darkSecret()
{
	return (this->_darkSecret);
}


bool	Contact::get_contact()
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNum;
	std::string darkSecret;
	time_t		tCreated;

	std::cout << "Enter your first name : ";
	std::getline(std::cin, firstName);
	std::cout << "Enter your last name : ";
	std::getline(std::cin, lastName);
	std::cout << "Enter your nickname : ";
	std::getline(std::cin, nickName);
	std::cout << "Enter your phone number : ";
	std::getline(std::cin, phoneNum);
	std::cout << "Enter your DARKEST secret : ";
	std::getline(std::cin, darkSecret);
	
	if (check_data(firstName, 1) == false)
		return (false);
	if (check_data(lastName, 1) == false)
		return (false);
	if (check_data(nickName, 0) == false)
		return (false);
	if (check_data(phoneNum, 2) == false)
		return (false);
	if (check_data(darkSecret, 0) == false)
		return (false);

	time(&tCreated);
	Contact::set_contact(firstName, lastName, nickName, phoneNum, darkSecret, tCreated);
	return (true);
}

void	Contact::set_contact(std::string firstName, std::string lastName,
			std::string nickName, std::string phoneNum, std::string darkSecret,
			time_t tCreated)
{
	Contact::_tCreated = tCreated;
	Contact::_firstName = firstName ;
	Contact::_lastName = lastName;
	Contact::_nickName = nickName;
	Contact::_phoneNum = phoneNum;
	Contact::_darkSecret = darkSecret;
}

time_t	Contact::get_time()
{
	return (this->_tCreated);
}

void	Contact::print_contact()
{
	std::cout << this->_firstName << '\n' << this->_lastName << '\n' << 
	this->_nickName << '\n' << this->_phoneNum << '\n' << this->_darkSecret << std::endl;
}
