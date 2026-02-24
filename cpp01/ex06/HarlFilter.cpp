/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:28:51 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/18 19:01:52 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/HarlFilter.hpp"


HarlFilter::HarlFilter()
{
	std::cout << "Constructor called\n" << std::endl;

	_LevelTab[0] = "DEBUG";
	_LevelTab[1] = "INFO";
	_LevelTab[2] = "WARNING";
	_LevelTab[3] = "ERROR";

	_LevelPtr[0] = &HarlFilter::debug;
	_LevelPtr[1] = &HarlFilter::info;
	_LevelPtr[2] = &HarlFilter::warning;
	_LevelPtr[3] = &HarlFilter::error;
}

HarlFilter::~HarlFilter()
{
	std::cout << "\nDestructor called" << std::endl;
}

void	HarlFilter::complain(std::string level)
{
	int	lvl = -1;

	for (int i= 0; i <= 3; i++)
		if (_LevelTab[i] == level)
			lvl = i;
	switch (lvl)
	{
		case 0 :
			(this->*_LevelPtr[0])();
		case 1 :
			(this->*_LevelPtr[1])();
		case 2 :
			(this->*_LevelPtr[2])();
		case 3 :
			(this->*_LevelPtr[3])();
		default :
			std::cout << "Harl has nothing to say today" << std::endl;
	}
	return ;
}

void	HarlFilter::debug( void )
{
	std::cout << "DEBUG :" << std::endl;
	std::cout << "I love Nintendo and their games. The next switch will be amazing"
	<< std::endl << "So so excited, I really am !" << std::endl;
}

void	HarlFilter::info( void )
{
	std::cout << "INFO :" << std::endl;
	std::cout << "I cannot believe it, the switch is almost the same as the first"
	<< std::endl << "90 euros THE game ?? Unbeliveble !" << std::endl;
}

void	HarlFilter::warning( void )
{
	std::cout << "WARNING :" << std::endl;
	std::cout << "I think I deserve some respect after all those loyal years"
	<< std::endl << "Who sets those prices ? DARN YOU SONY !" << std::endl;
}

void	HarlFilter::error( void )
{
	std::cout << "ERROR :" << std::endl;
	std::cout << "This is unacceptable ! You won't be earing from me ever again !"
	<< std::endl << "Mario kart open world ? take my money..." << std::endl;
}