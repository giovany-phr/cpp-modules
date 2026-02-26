/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:17:00 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/29 12:28:48 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "./ClapTrap.hpp"

class ScavTrap : public virtual  ClapTrap
{
	protected :
		bool _guarding_gate;
		
	public :
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		virtual ~ScavTrap();
		
		ScavTrap &operator = (const ScavTrap &other);
		
		void	attack(const std::string& target);
		void	guardGate();
		
		void	getScavStatus();
		int		getHit();
		int		getEnergy();
		int		getAttack();

	private :
		static const int _hit = 100;
		static const int _nrg = 50;
		static const int _atk = 20;
};

#endif