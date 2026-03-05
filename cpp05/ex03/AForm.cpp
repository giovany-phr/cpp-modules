/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:39:41 by gpaupher          #+#    #+#             */
/*   Updated: 2025/09/10 18:03:33 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/AForm.hpp"
# include "./includes/Bureaucrat.hpp"

//////////////////////////////////////////////
////////--CONSTRUCTORS & DESTRUCTORS--////////
//////////////////////////////////////////////

AForm::AForm() : 
_name("Document"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string name) : 
_name(name), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Form constructor called" << std::endl;
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExec) : 
_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "Form constructor called" << std::endl;
	if (gradeToSign <= 0 || gradeToExec <= 0)
		throw GradeTooHighException();
	else if (150 < gradeToSign || 150 < gradeToExec)
		throw GradeTooLowException();	
}

AForm::AForm(AForm const &other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
	std::cout << "Form copy constructor called" << std::endl;
}

AForm &AForm::operator = (AForm const &other)
{
	std::cout << "Form assignement constructor called" << std::endl;
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

AForm::~AForm()
{
		std::cout << "Form destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, AForm const &other)
{
    os << other.getName() << " :\n"
	<< "- Grade to sign -> " << other.getGradeToSign() << std::endl
	<< "- Grade to exec -> " << other.getGradeToExec() << std::endl
	<< "- Grade signed --> ";
	if (other.getSigned() == true)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
    return (os);
}

//////////////////////////////////////////////
////////------------GETTERS-----------////////
//////////////////////////////////////////////

const std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

//////////////////////////////////////////////
////////-------MEMBER FUNCTIONS-------////////
//////////////////////////////////////////////

void	AForm::beSigned(Bureaucrat &obj)
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

void AForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->_signed == false)
			throw FormNotSigned();
		else if (this->getGradeToExec() < executor.getGrade())
			throw GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
		std::cout << executor.getName() << " did not execute " 
		<< this->getName()
		<< std::endl;
		return ;
	}
	try 
	{
		execForm();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
		return ;
	}
	std::cout << executor.getName() << " executed " 
	<< this->getName()
	<< std::endl;
}

//////////////////////////////////////////////
////////-----------EXCEPTION----------////////
//////////////////////////////////////////////

const char *AForm::GradeTooHighException::what() const throw()
{
	return 	("Grade is too high\n");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return 	("Grade is too low\n");
}

const char *AForm::dejaSignedException::what() const throw()
{
    return("Form is already signed\n");           
}

const char *AForm::FormNotSigned::what() const throw()
{
	return ("Form is not signed yet\n");
}

