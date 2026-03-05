/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:49:58 by gpaupher          #+#    #+#             */
/*   Updated: 2025/09/10 18:03:19 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PresidentialPardonForm.hpp"
# include "./includes/Bureaucrat.hpp"

//////////////////////////////////////////////
////////--CONSTRUCTORS & DESTRUCTORS--////////
//////////////////////////////////////////////

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	this->_target = "PresidentialDefault";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
	this->_target = target;
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
: AForm(other)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;	
	*this = other;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
	
}

PresidentialPardonForm &PresidentialPardonForm::operator = (PresidentialPardonForm const &other)
{
	std::cout << "PresidentialPardonForm assignement constructor called" << std::endl;	
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

//////////////////////////////////////////////
////////-------MEMBER FUNCTIONS-------////////
//////////////////////////////////////////////

std::string PresidentialPardonForm::getTarget()
{
	return (this->_target);
}

void PresidentialPardonForm::execForm() const
{
	std::cout << this->_target
	<< " has been pardoned by Zaphod Beeblebrox"
	<< std::endl;
}