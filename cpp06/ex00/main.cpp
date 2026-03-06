/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:48:33 by gpaupher          #+#    #+#             */
/*   Updated: 2025/09/12 19:04:38 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/ScalarConverter.hpp"
# include "./includes/converter.hpp"

int main (int argc, char **argv)
{
	if (argc == 1)
		return (0);	
	if (argc > 1)
		for (int i = 1; i < argc; i++)
		{
			std::cout << "--------------" << std::endl;
			ScalarConverter::convert(argv[i]);
		}
	return (0);
}