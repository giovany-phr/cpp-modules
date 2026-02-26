/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:58:26 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/25 15:55:27 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private :
		std::string	_name;
		int			_hitPt;
		int			_energyPt;
		int			_attackDmg;
		
	public :
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, int hitPt, int energyPt, int attackDmg);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

		ClapTrap &operator = (const ClapTrap &othter);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	getStatus();
};

#endif