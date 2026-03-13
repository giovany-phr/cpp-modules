/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:34:18 by gpaupher          #+#    #+#             */
/*   Updated: 2025/06/30 22:38:15 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		BitcoinExchange csvData;
		try{
			csvData.readCsv("data.csv");
			csvData.readInfile(av[1]);
		}catch(std::exception &e){
			std::cerr << e.what();
		}
	}	
	else 
		std::cerr << "Error: Number Of Arguments" << std::endl;
	return (0);
}