/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:49:48 by gpaupher          #+#    #+#             */
/*   Updated: 2025/09/10 18:07:36 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		std::string	_target;
		void execForm() const;
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		~PresidentialPardonForm();
		
		PresidentialPardonForm &operator = (PresidentialPardonForm const &other);
		
		std::string getTarget();		
};