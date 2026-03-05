/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:50:28 by gpaupher          #+#    #+#             */
/*   Updated: 2025/09/10 17:51:52 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ShrubberyCreationForm.hpp"
# include "./includes/Bureaucrat.hpp"

//////////////////////////////////////////////
////////--CONSTRUCTORS & DESTRUCTORS--////////
//////////////////////////////////////////////

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	this->_target = "ShrubberyDefault";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
	this->_target = target;
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
: AForm(other)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;	
	*this = other;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (ShrubberyCreationForm const &other)
{
	std::cout << "ShrubberyCreationForm assignement constructor called" << std::endl;	
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

//////////////////////////////////////////////
////////-------MEMBER FUNCTIONS-------////////
//////////////////////////////////////////////

std::string &ShrubberyCreationForm::getTarget()
{
	return (this->_target);
}

void ShrubberyCreationForm::execForm() const
{
	const char		*fileName;
	std::string		fileTemp;
	std::ofstream	myFile;

	fileTemp = this->_target + "_shrubbery";
	fileName = fileTemp.c_str();
	myFile.open(fileName);
	if (!myFile.is_open())
		throw OpenFileErr();
	
	myFile << " _" << std::endl;
	myFile << "| |" << std::endl;
	myFile << "| |_ _ __ __  ___" << std::endl;
	myFile << "| __| '__/ _ \\/ _ \\" << std::endl;
	myFile << "| |_| | |  __/  __/" << std::endl;
	myFile << " \\__|_|  \\___|\\___|" << std::endl
	<< std::endl;
	myFile << "                @@@@@@@," << std::endl;
	myFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	myFile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	myFile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	myFile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	myFile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	myFile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	myFile << "       |o|        | |         | |" << std::endl;
	myFile << "       |.|        | |         | |" << std::endl;
	myFile << "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl
	<< std::endl;
	myFile << " _" << std::endl;
	myFile << "| |" << std::endl;
	myFile << "| |_ _ __ __  ___" << std::endl;
	myFile << "| __| '__/ _ \\/ _ \\" << std::endl;
	myFile << "| |_| | |  __/  __/" << std::endl;
	myFile << " \\__|_|  \\___|\\___|" << std::endl;

	myFile.close();
}

const char *ShrubberyCreationForm::OpenFileErr::what() const throw()
{
	return ("Error file openeing\n");
}

                 
                
 











