/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:38:47 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/04 21:21:04 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# define MAX_CONTACT 8

class PhoneBook
{
	private :
		Contact _contacts[MAX_CONTACT];
		int		_total;
		
	public :
		PhoneBook();
		~PhoneBook();
		void	add_contact();
		bool	print_book();
		void	fetch_contact();
		void	replace_contact();
		int		fetch_old();
};

#endif

