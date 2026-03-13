/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:34:07 by gpaupher          #+#    #+#             */
/*   Updated: 2025/06/30 21:44:26 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <string>
# include <cstring>
# include <iostream>
# include <fstream>
# include <exception>
# include <map>
# include <ctime>
# include <sstream>

class BitcoinExchange
{
	private :
		std::map<std::string, double> _csvData;
	public :
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator = (const BitcoinExchange &other);
		~BitcoinExchange();
		
		void							setData(std::map<std::string, double> &newData);
		std::map<std::string, double>	getData();
		void							printCsv();

		void							readCsv(std::string csvFile);
		void							readInfile(char *inFile);
		
		bool							checkData(std::string &date, double value);
		bool							isValidDate(std::string &date);
		double 							findDate(std::string &date);
		void 							eraseSpaces(std::string &str) ;

		class errFileOpen : public std::exception
		{
			virtual const char *what() const throw();	
		};
		class errParsing : public std::exception
		{
			virtual const char *what() const throw();	
		};
};