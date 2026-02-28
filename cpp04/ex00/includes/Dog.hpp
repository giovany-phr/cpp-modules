/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:49:53 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/26 19:55:17 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "Animal.hpp"

class Dog : public Animal
{
    private :
        // std::string type;

    public :
        Dog(),
        Dog(std::string type);
        Dog(const Dog &other);
        ~Dog();

        Dog &operator = (const Dog &other);
        
        void    makeSound() const;
        std::string getType() const;
};