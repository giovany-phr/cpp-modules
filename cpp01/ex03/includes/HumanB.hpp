/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:33:38 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/28 23:42:55 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

# include "./Weapon.hpp"

class	HumanB
{
	private :
		std::string	_name;
		Weapon		*_Weapon;
	
	public :
		HumanB(std::string name);
		HumanB(std::string name, Weapon &weapon);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon &Weapon);
};

#endif
