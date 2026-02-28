/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:27:44 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/06 23:12:12 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/AMateria.hpp"
# include "./includes/MateriaSource.hpp"
# include "./includes/Ice.hpp"
# include "./includes/Cure.hpp"
# include "./includes/Character.hpp"

int main()
{
    std::cout << "=========TEST 1=========" << std::endl;
    std::cout << "\n>>> CONSTRUCTORS <<<" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    std::cout << "\n>>> CREATE AND EQUIP MATERIA <<<" << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << "\n>>> USE OF MATERIA <<<" << std::endl;
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << "\n>>> DESTRUCTORS <<<" << std::endl;
    delete bob;
    delete me;
    delete src;

    std::cout << "=========TEST 2=========" << std::endl;
    std::cout << "\n>>> CONSTRUCTORS <<<" << std::endl;
    IMateriaSource* mat = new MateriaSource();
    mat->learnMateria(new Ice());
    mat->learnMateria(new Cure());
    ICharacter* hero = new Character("hero");
    std::cout << "\n>>> CREATE AND EQUIP MATERIA <<<" << std::endl;
    AMateria* temp;
    temp = mat->createMateria("ice");
    hero->equip(temp);
    temp = mat->createMateria("cure");
    hero->equip(temp);
    hero->equip(temp);
    temp = mat->createMateria("fire");
    std::cout << "\n>>> USE OF MATERIA <<<" << std::endl;
    ICharacter* boby = new Character("boby");
    hero->use(2, *boby);
    hero->use(0, *boby);
    hero->use(1, *boby);
    hero->use(-1, *boby);
    hero->use(3, *boby);
    hero->use(4, *boby);
    std::cout << "\n>>> DESTRUCTORS <<<" << std::endl;
    delete boby;
    delete hero;
    delete mat;
    return 0;
}