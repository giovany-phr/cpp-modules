/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:24:30 by gpaupher          #+#    #+#             */
/*   Updated: 2025/09/10 17:54:01 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>
# include <exception>

class AForm;

class Bureaucrat
{
	private: 
		const std::string	_name;
		int					_grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string const name);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &other);
		~Bureaucrat();

		Bureaucrat &operator = (const Bureaucrat &other);

		const std::string	&getName() const;
		int					getGrade() const;
		void				setName(std::string const &name);
		void				setGrade(int grade);
		
		void				ft_promote();
		void				ft_demote();

		void				signForm(AForm &obj);
		
		void				executeForm(AForm const & form) const;

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other);