/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:20:43 by gpaupher          #+#    #+#             */
/*   Updated: 2025/06/18 03:32:06 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Form.hpp"
# include "./includes/Bureaucrat.hpp"

//////////////////////////////////////////////
////////--CONSTRUCTORS & DESTRUCTORS--////////
//////////////////////////////////////////////

Bureaucrat::Bureaucrat() : _name("John Doe"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name): _name(name), _grade(150)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade <= 0)
		throw GradeTooHighException();		
	else if (150 < grade)
		throw GradeTooLowException();	
	this->_grade = grade;
}
Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = other;
}		
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator = (Bureaucrat const &other)
{
	std::cout << "Bureaucrat assignement constructor called" << std::endl;
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
    os << other.getName() << ", bureaucrat grade " << other.getGrade();
    return (os);
}

//////////////////////////////////////////////
////////-------GETTERS & SETTERS------////////
//////////////////////////////////////////////

const std::string	&Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade <= 0)
		throw GradeTooHighException();
	else if (150 < grade)
		throw GradeTooLowException();
	this->_grade = grade;
}

//////////////////////////////////////////////
////////-------MEMBER FUNCTIONS-------////////
//////////////////////////////////////////////

void	Bureaucrat::ft_promote()
{
	if ((this->_grade - 1) <= 0)
		throw GradeTooLowException();
	else
	{
		std::cout << this->getName() << " got promoted"<< std::endl;
		this->_grade = this->_grade - 1;
	}
}

void	Bureaucrat::ft_demote()
{
	if ((this->_grade + 1) > 150)
		throw GradeTooLowException();
	else
	{
		std::cout << this->getName() << " got demoted" << std::endl;
		this->_grade = this->_grade + 1;
	}
}

void	Bureaucrat::signForm(Form &obj)
{
	obj.beSigned(*this);
}

//////////////////////////////////////////////
////////-----------EXCEPTION----------////////
//////////////////////////////////////////////

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low\n");
}