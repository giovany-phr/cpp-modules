/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:39:47 by gpaupher          #+#    #+#             */
/*   Updated: 2025/06/18 03:39:06 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
    private :
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExec;

    public :
        Form();
        Form(const std::string name);
        Form(const std::string name, int gradeToSign, int gradeToExec);
        Form(Form const &other);
        ~Form();

        Form &operator = (const Form &other);

        const std::string   getName() const;
        bool                getSigned();
        int                 getGradeToSign() const;
        int                 getGradeToExec() const;

        void beSigned(Bureaucrat &obj);

        class GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw();            
        };
        
        class dejaSignedException : public std::exception
        {
            virtual const char *what() const throw();            
        };

};
std::ostream &operator<<(std::ostream &os, const Form &other);