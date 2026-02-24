/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:19:51 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/18 18:27:17 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Harl.hpp"

Harl::Harl()
{
	std::cout << "Constructor called\n" << std::endl;
	
	_LevelTab[0] = "DEBUG";
	_LevelTab[1] = "INFO";
	_LevelTab[2] = "WARNING";
	_LevelTab[3] = "ERROR";

	_LevelPtr[0] = &Harl::debug;
	_LevelPtr[1] = &Harl::info;
	_LevelPtr[2] = &Harl::warning;
	_LevelPtr[3] = &Harl::error;
}

Harl::~Harl()
{
	std::cout << "\nDestructor called" << std::endl;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i <= 3; i++)
	{
		if (_LevelTab[i] == level)
		{
			(this->*_LevelPtr[i])();
			return;
		}
	}
	std::cout << "Harl has nothing to say today" << std::endl;
}

void	Harl::debug( void )
{
	std::cout << "DEBUG :" << std::endl;
	std::cout << "I love Nintendo and their games. The next switch will be amazing"
	<< std::endl << "So so excited, I really am !" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "INFO :" << std::endl;
	std::cout << "I cannot believe it, the switch is almost the same as the first"
	<< std::endl << "90 euros THE game ?? Unbeliveble !" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "WARNING :" << std::endl;
	std::cout << "I think I deserve some respect after all those loyal years"
	<< std::endl << "Who sets those prices ? DARN YOU SONY !" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "ERROR :" << std::endl;
	std::cout << "This is unacceptable ! You won't be earing from me ever again !"
	<< std::endl << "Mario kart open world ? take my money..." << std::endl;
}