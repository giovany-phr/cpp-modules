/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:50:13 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/01 16:37:23 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Animal.hpp"
# include "./includes/Dog.hpp"
# include "./includes/Cat.hpp"
# include "./includes/WrongAnimal.hpp"
# include "./includes/WrongCat.hpp"

int main()
{
    std::cout << "=================TEST 1=================" << std::endl;
    std::cout << ">>>Constructors<<<" << std::endl;
    Animal *ein = new Dog("chien");
    Animal *jiji = new Cat();
    Animal *human  = new Animal("dude");

    std::cout << "\n" << human->getType() << ": " << std::endl;
    human->makeSound();
    std::cout << ein->getType() << ": " << std::endl;
    ein->makeSound();
    std::cout << jiji->getType() << ": " << std::endl;
    jiji->makeSound();
    std::cout << "\n>>>Destructors<<<" << std::endl;
    delete ein;
    delete jiji;
    delete human;
    
    std::cout << "\n=================TEST 2=================" << std::endl;
    std::cout << ">>>Constructors<<<" << std::endl;
    WrongAnimal *furry1 = new WrongAnimal();
    WrongAnimal *furry2 = new WrongCat();
    
    std::cout << "\n" << furry1->getType() << ": " << std::endl;
    furry1->makeSound();
    std::cout << furry2->getType() << ": " << std::endl;
    furry2->makeSound();
    std::cout << "\n>>>Destructors<<<" << std::endl;
    delete furry1;
    delete furry2;
    return (0);
}