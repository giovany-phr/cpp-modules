/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:35:15 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/06 22:46:32 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria 	*_inventory[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &other);
		~MateriaSource();
		
		MateriaSource &operator = (MateriaSource const &other);
		
		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);

		bool CheckInventory(AMateria* m);
		void printInventory() const;
};