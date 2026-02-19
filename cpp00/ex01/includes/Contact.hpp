/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:05:54 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/04 20:45:38 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "Utils.hpp"
# include <string>
# include <ctime>
# include <iostream>
# include <sstream> 
# include <iomanip>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNum;
		std::string	_darkSecret;
		time_t		_tCreated;
		
	public:
		Contact();
		~Contact();

		bool		get_contact();
		void		set_contact(std::string _firstName, std::string _lastName, std::string _nickName,
						std::string _phoneNum, std::string _darkSecret, time_t tCreated);
		void		print_contact();
		void		print_table();
		time_t		get_time();
		std::string	get_firstName();
		std::string	get_lastName();
		std::string	get_nickName();
		std::string	get_phoneNum();
		std::string	get_darkSecret();
		
};

#endif