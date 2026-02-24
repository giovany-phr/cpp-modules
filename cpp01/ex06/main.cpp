/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:31:05 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/18 19:03:45 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/HarlFilter.hpp"

int main(int ac, char **av)
{
	HarlFilter karen;
	if (ac == 2)
		karen.complain(av[1]);
	if (ac == 1)
		karen.complain("DEBUG");
	return (0);
}