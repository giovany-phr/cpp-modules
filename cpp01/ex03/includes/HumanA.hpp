/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:34:28 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/28 23:43:30 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

# include "./Weapon.hpp"

class	HumanA
{
	private :
		std::string	_name;
		Weapon		&_Weapon;
	
	public :
		HumanA(std::string name, Weapon &Weapon);
		~HumanA();
		void	attack();
};

#endif
