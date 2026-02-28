/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:07:56 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/06 23:03:26 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
		AMateria(std::string const & type);
		AMateria(AMateria const &other);
		
	public:
		virtual ~AMateria();
		
		AMateria &operator = (AMateria const &other);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
};