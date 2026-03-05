#pragma once
# include <string>
# include <iostream>
# include <exception>

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class AForm;

class Intern 
{
    private :

    public :
        Intern();
        Intern(AForm const &other);
        Intern &operator = (AForm const &other);
        ~Intern();

        AForm   *makeForm(std::string nameForm, std::string targetForm);

        class errorFormNotFound : public std::exception
        {
           virtual const char *what() const throw();
        };
};