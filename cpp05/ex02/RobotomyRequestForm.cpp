/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:50:31 by gpaupher          #+#    #+#             */
/*   Updated: 2025/09/10 17:51:55 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/RobotomyRequestForm.hpp"
# include "./includes/Bureaucrat.hpp"

//////////////////////////////////////////////
////////--CONSTRUCTORS & DESTRUCTORS--////////
//////////////////////////////////////////////

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	this->_target = "RobotomyDefault";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	this->_target = target;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
: AForm(other)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;	
	*this = other;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
	
}

RobotomyRequestForm &RobotomyRequestForm::operator = (RobotomyRequestForm const &other)
{
	std::cout << "RobotomyRequestForm assignement constructor called" << std::endl;	
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

//////////////////////////////////////////////
////////-------MEMBER FUNCTIONS-------////////
//////////////////////////////////////////////

std::string &RobotomyRequestForm::getTarget()
{
	return (this->_target);
}

void RobotomyRequestForm::execForm() const
{
	int temp;

	temp = std::rand() % 2;
	std::cout << "*DRILLING NOISE*" << std::endl;
	if (temp == 1)
		std::cout << _target << " successfully robotomized" << std::endl;
	else
		std::cout << _target << " unsuccessfully robotomized" << std::endl;
}