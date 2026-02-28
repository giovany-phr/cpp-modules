/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:49:52 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/29 08:22:58 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include  "Brain.hpp"
# include "Animal.hpp"

class Cat : public Animal
{
    private :
        Brain *_brain;

    public :
        Cat(),
        Cat(std::string type);
        Cat(const Cat &other);
        ~Cat();

        Cat &operator = (const Cat &other);

        void        makeSound() const;
        std::string getType() const;
        
        void        getIdeas();
        void        setIdea(size_t index, std::string idea);
};