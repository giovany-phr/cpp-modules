/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:22:30 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/28 23:47:09 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <string>
# include <iostream>

class	Weapon
{
	private :
		std::string	_type;

	public :
		Weapon();
		Weapon(std::string type);
		~Weapon();
		
		void				setType(std::string type);
		std::string const	&getType() const;
};

#endif
