/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:39:47 by gpaupher          #+#    #+#             */
/*   Updated: 2025/09/10 18:03:07 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>
# include <exception>
# include <cstdlib>

class Bureaucrat;

class AForm
{
    private :
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExec;
        virtual void execForm() const = 0;

    public :
        AForm();
        AForm(const std::string name);
        AForm(const std::string name, int gradeToSign, int gradeToExec);
        AForm(AForm const &other);
        virtual ~AForm();

        AForm &operator = (const AForm &other);

        const std::string   getName() const;
        bool                getSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExec() const;

        void                beSigned(Bureaucrat &obj);

        void                execute(Bureaucrat const &executor) const;
        

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

        class  FormNotSigned : public std::exception
        {
            virtual const char *what() const throw();
        };

};
std::ostream &operator<<(std::ostream &os, const AForm &other);