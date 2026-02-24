/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:16:55 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/29 00:25:38 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Harl.hpp"

int main(int ac, char **av)
{
	Harl karen;

	if (ac == 2)
		karen.complain(av[1]);
	if (ac == 1)
	{
		karen.complain("DEBUG");
		karen.complain("INFO");
		karen.complain("WARNING");
		karen.complain("ERROR");
	}
	return (0);
}