/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:10:49 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/06 23:05:47 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	protected :
	
	public :
		Cure();
		Cure(Cure const &other);
		~Cure();

		Cure &operator = (Cure const &other);
		AMateria *clone() const;
		void use(ICharacter& target);
};