/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:41:11 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/04 21:19:01 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Contact.hpp"

bool	delete_msg()
{
	std::string	buffer;

	std::cout << "WARNING PhoneBook is full, " 
	<< "PhoneBook will delete the oldest contact" << std::endl;
	std::cout << "Do you want to continue ? [Y/N] : ";
	std::getline(std::cin, buffer);
	if (buffer == "Y")
	{
		std::cout << "PhoneBook will proceed the operation..." << std::endl;
		return (true);
	}
	else if (buffer == "N")
		std::cout << "PhoneBook will cancel the operation..." << std::endl;
	else
		std::cout << "ERROR input, PhoneBook will cancel the operation..." << std::endl;
	return (false);	
}

bool	check_string(std::string buffer, int flag)
{
	int			i;
	const char	*str;

	str = buffer.c_str();
	i = -1;
	if (flag == 1)
	{
		while (str[++i])
		{
			if (std::isalpha(str[i]) == 0)
				return (false);
		}	
	}
	else
	{
		while (str[++i])
		{
			if (std::isdigit(str[i]) == 0)
				return (false);
		}	
	}
	return (true);
}

bool	check_data(std::string buffer, int flag)
{
	if (buffer.length() == 0)
	{
		std::cout << "ERROR, field cannot be empty" << std::endl;
		return (false);
	}
	if (flag == 1 && check_string(buffer, 1) == false)
	{
		std::cout << "ERROR, unallowed characters typed : NAME/LASTNAME (only alphabet char)" << std::endl;
		return (false);
	}
	if (flag == 2 && check_string(buffer, 2) == false)
	{
		std::cout << "ERROR, unallowed characters typed : PHONE NUMBER (only numbers)" << std::endl;
		return (false);
	}
	if (flag == 3 && check_string(buffer, 2) == false)
		return (false);
	return (true);
}

std::string	trunContact(std::string str)
{
	if (str.size() <= 10)
		return (str);
	str.resize(9);
	str.append(".");
	return (str);
}

void	print_header()
{
	std::cout << "|" << std::setfill (' ') << std::setw (10);
	std::cout << "index";
 	 std::cout << "|" << std::setfill (' ') << std::setw (10);
	std::cout << "First Name";
  	std::cout << "|" << std::setfill (' ') << std::setw (10);
	std::cout << "Last Name";
  	std::cout << "|" << std::setfill (' ') << std::setw (10);
	std::cout << "Number" << std::endl;
}