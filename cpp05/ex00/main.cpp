/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:20:39 by gpaupher          #+#    #+#             */
/*   Updated: 2025/06/30 12:53:05 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Bureaucrat.hpp"

int main()
{
	std::cout << "==== CONSTRUCTORS ====" << std::endl;
	Bureaucrat	John;
	Bureaucrat	Joestar("Jojo");
	Bureaucrat	Bob("Bob", 1);
	Bureaucrat	Jojo(Joestar);
	// try
	// {
	// 	Bureaucrat	newJohn;
	// 	Bureaucrat	newJoestar("Jojo");
	// 	Bureaucrat	newBob("Bob", 1);
	// 	Bureaucrat	newJojo(Joestar);
	// 	John = newJohn;
	// 	Joestar = newJoestar;
	// 	Bob = newBob;
	// 	Jojo = newJojo;
	// }
	// catch(std::exception &e)
	// {
	// 	std::cerr << e.what();
	// 	return (1);
	// }

	std::cout << "\n==== CONSTRUCTORS err ====" << std::endl;
	try
	{
		Bureaucrat	wrong1("BoJack", 200);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		Bureaucrat	wrong2("BoJack", -42);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		Bureaucrat	wrong3("BoJack", 0);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what();
	}

	std::cout << "\n==== BUREAUCRATS ====" << std::endl;
	std::cout << Joestar << std::endl;
	std::cout << Jojo << std::endl;
	std::cout << John << std::endl;
	std::cout << Bob << std::endl;
	
	std::cout << "\n==== TRY & CATCH TESTS ====" << std::endl;
	try
	{
		Bob.ft_demote();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	std::cout << Bob << std::endl;

	try
	{
		Bob.ft_promote();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	std::cout << Bob << std::endl;

	try
	{
		Bob.ft_promote();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	std::cout << Bob << std::endl;

	try
	{
		John.ft_demote();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	std::cout << John << std::endl;

	try
	{
		for (int i = 0; i < 10; i++)
			Jojo.ft_promote();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	std::cout << Jojo << std::endl;

	std::cout << "\n==== DESTRUCTORS ====" << std::endl;
	return (0);
}