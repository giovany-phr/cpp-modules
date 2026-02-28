/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:50:13 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/05 18:38:56 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Animal.hpp"
# include "./includes/Dog.hpp"
# include "./includes/Cat.hpp"
# include "./includes/WrongAnimal.hpp"
# include "./includes/WrongCat.hpp"

int main()
{
    std::cout << ">>========TEST 1========<<\n" << std::endl;
    std::cout << ">>>CONSTRUCTOR<<<" << std::endl;
    int nb = 8;
    const Animal  *mammal[nb];

    for (int i = 0; i < nb; i++)
    {
        if (i % 2 == 0)
            mammal[i] = new Cat();
        else
            mammal[i] = new Dog();
        if (!mammal[i])
        {
            std::cerr << "Error: memory allocation" << std::endl;
            for (int j = 0; j <= i; j++)
                delete (mammal[i]);
            return (1);
        }
    }
	std::cout << "\n>>>DISPLAY ANIMAL OBJECT ARRAY<<<" << std::endl;
    for (int i = 0; i < nb; i++)
	{
    	mammal[i]->makeSound();
		if (i == nb - 1)
			std::cout << "Number of animals is : " << i + 1 << std::endl;	
	}
	std::cout << "\n>>>DESTRUCTOR<<<" << std::endl;
    for (int i = 0; i < nb; i++)
	{
        delete (mammal[i]);	
	}

	std::cout << "\n>>========TEST 2========<<\n" << std::endl;
    std::cout << ">>>CONSTRUCTOR<<<" << std::endl;
	Cat *cat = new Cat();
	Dog *dog = new Dog();
	if (!dog || !cat)
	{
		perror("Error");
		std::cerr << "Memory allocation" << std::endl;
		if (dog)
			delete (dog);
		else
			delete (cat);
	}
	std::string idea = "sleep";
	std::cout << "\n" << cat->getType() << ": " << std::endl;
	cat->makeSound();
	cat->setIdea(0, idea);
	cat->setIdea(1, "eat");
	cat->setIdea(2, "nap");
	cat->setIdea(-54, "nothing");
	std::cout << "\n" << dog->getType() << ": " << std::endl;
	dog->makeSound();
	dog->setIdea(0, "wag tail");
	dog->setIdea(3, "wag tail still");
	dog->setIdea(0, idea);
	dog->setIdea(2, "wag tail again");
	dog->setIdea(99, "Be happy");
	dog->setIdea(-1, "wag tail");
	std::cout << "\n" << cat->getType() << "'s ideas :" << std::endl;
	cat->getIdeas();
	std::cout << "\n" << dog->getType() << "'s ideas :" << std::endl;
	dog->getIdeas();
	std::cout << "\n>>>DESTRUCTOR<<<" << std::endl;
	delete (cat);
	delete (dog);
    return (0);
}