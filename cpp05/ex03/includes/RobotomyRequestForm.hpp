/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:49:36 by gpaupher          #+#    #+#             */
/*   Updated: 2025/09/10 18:07:33 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>
# include <exception>
# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private :
		std::string	_target;
		void execForm() const;
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator = (RobotomyRequestForm const &other);
		
		std::string &getTarget();
};