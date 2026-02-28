/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:21:02 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/06 23:05:41 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	protected :
	
	public :
		Ice();
		Ice(Ice const &other);
		~Ice();

		Ice &operator = (Ice const &other);
		AMateria *clone() const;
		void use(ICharacter& target);
};
