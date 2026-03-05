/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:39:41 by gpaupher          #+#    #+#             */
/*   Updated: 2025/06/18 00:47:40 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Form.hpp"
# include "./includes/Bureaucrat.hpp"

//////////////////////////////////////////////
////////--CONSTRUCTORS & DESTRUCTORS--////////
//////////////////////////////////////////////

Form::Form() : 
_name("Document"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name) : 
_name(name), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const std::string name, int gradeToSign, int gradeToExec) : 
_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "Form constructor called" << std::endl;
	if (gradeToSign <= 0 || gradeToExec <= 0)
		throw GradeTooHighException();
	else if (150 < gradeToSign || 150 < gradeToExec)
		throw GradeTooLowException();	
}

Form::Form(Form const &other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator = (Form const &other)
{
	std::cout << "Form assignement constructor called" << std::endl;
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

Form::~Form()
{
		std::cout << "Form destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, Form const &other)
{
    os << other.getName() << ", Document grade " << other.getGradeToSign();
    return (os);
}

//////////////////////////////////////////////
////////------------GETTERS-----------////////
//////////////////////////////////////////////

const std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned()
{
	return (this->_signed);
}

int	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

//////////////////////////////////////////////
////////-------MEMBER FUNCTIONS-------////////
//////////////////////////////////////////////

void	Form::beSigned(Bureaucrat &obj)
{
	try 
	{
		if (obj.getGrade() > this->getGradeToSign())
			throw GradeTooLowException();
		if (this->getSigned() == true)
			throw dejaSignedException();
	}
	catch (std::exception &e)
	{
		std::cout << obj.getName() << " couldn't  sign "
		<< this->getName() << " because " << e.what();
		return;
	}
	this->_signed = true;
	std::cout << obj.getName() << " signed "
	<< this->getName() << std::endl;
}

//////////////////////////////////////////////
////////-----------EXCEPTION----------////////
//////////////////////////////////////////////

const char *Form::GradeTooHighException::what() const throw()
{
	return 	("Grade is too high\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return 	("Grade is too low\n");
}

const char *Form::dejaSignedException::what() const throw()
{
    return("Form is already signed\n");           
}

