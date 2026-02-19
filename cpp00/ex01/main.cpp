/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:47:24 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/04 21:17:22 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PhoneBook.hpp"

int	main()
{
	std::string input;
	PhoneBook PhoneBook;
	
	std::cout << ">>> Welcome to your Phone Book <<<" << std::endl;
	while (1)
	{
		std::cout << "> TYPE YOUR COMMAND HERE (ADD, SEARCH or EXIT) : ";
		getline(std::cin, input);
		if (std::cin.eof() == true) // to take care of ctrl d 
		{
			std::cout << '\n' <<"You Pressed ^D. WHY DO THAT ? >_<'" << std::endl;
			return (0);
		}
		if (input == "ADD")
		{
			std::cout << "ADDING..." << std::endl;
			PhoneBook.add_contact();
		}
		else if (input == "SEARCH")
		{
			std::cout << "SEARCHING..." << std::endl;
			if (PhoneBook.print_book() == true)
				PhoneBook.fetch_contact();
		}
		else if (input == "EXIT")
			break ;
	}
	std::cout << "Thank you for your visit, See you next time >_<" << std::endl;
	return (0);
}
