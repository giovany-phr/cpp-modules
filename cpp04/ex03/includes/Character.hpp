/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:38:40 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/06 22:44:32 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include "ICharacter.hpp"

class Character : public ICharacter
{
    protected :
        std::string _name;
        AMateria    *_inventory[4];

	public:
        Character();
        Character(std::string const &name);
        Character(Character const &other);
        ~Character();

        Character &operator = (Character const &other);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        
        bool CheckInventory(AMateria* m);
        void printInventory() const;
};