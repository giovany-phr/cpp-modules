/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:49:52 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/26 19:55:27 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "Animal.hpp"

class Cat : public Animal
{
    private :
        // std::string type;

    public :
        Cat(),
        Cat(std::string type);
        Cat(const Cat &other);
        ~Cat();

        Cat &operator = (const Cat &other);

        void    makeSound() const;
        std::string getType() const; 
};