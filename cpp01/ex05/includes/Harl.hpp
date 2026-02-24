/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:18:51 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/29 00:27:56 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

# include <string>
# include <iostream>

class	Harl
{
	private :
		void debug();
		void info();
		void warning();
		void error();
		std::string	_LevelTab[4];
		void (Harl::*_LevelPtr[4])();

	public :
		Harl();
		~Harl();
		void complain(std::string level);

	
};

#endif
