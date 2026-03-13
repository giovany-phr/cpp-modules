/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:34:10 by gpaupher          #+#    #+#             */
/*   Updated: 2025/09/24 18:49:31 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/BitcoinExchange.hpp"

/************************************************************************/
/********************* CONSTRUCTORS/DESTRUCTORS *************************/
/************************************************************************/

BitcoinExchange::BitcoinExchange()
{
	// std::cout << "BitcoinExchange default constructor constructed" << std::endl;
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	// std::cout << "BitcoinExchange copy constructor constructed" << std::endl;
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &other)
{
	// std::cout << "BitcoinExchange assignement constructor constructed" << std::endl;
	if (this != &other)
		this->_csvData = other._csvData;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "BitcoinExchange destructor constructed" << std::endl;
}

/************************************************************************/
/************************** MEMBERS FUNCTIONS ***************************/
/************************************************************************/

/*=====================GETTERS/SETTERS=====================*/

void	BitcoinExchange::setData(std::map<std::string, double> &newData)
{
	this->_csvData = newData;
}

std::map<std::string, double> BitcoinExchange::getData()
{
	return (this->_csvData);
}

/*=====================UTILS FUNCTIONS=====================*/

void BitcoinExchange::printCsv()
{
	for (std::map<std::string, double>::iterator it = this->_csvData.begin(); it != this->_csvData.end(); it++)
		std::cout << it->first << " | " << it->second << std::endl;
}

void BitcoinExchange::eraseSpaces(std::string &str)
{
    size_t index = 0;
	size_t len, temp;

    while (index != std::string::npos)
    {
        index = str.find_first_of(" ");
		if (index == std::string::npos)
			break;
        temp = index;
		len = 0;
        while(temp < str.size() && str[temp++] == ' ')
            len++;
		str.erase(index, len);
    }
}

/*=====================MAIN FUNCTIONS=====================*/

void BitcoinExchange::readCsv(std::string csvFile)
{
	std::string			buffer;
	std::ifstream		inFile((csvFile.c_str()));

	if (!inFile)
		throw BitcoinExchange::errFileOpen();
	while (std::getline(inFile, buffer))
	{
		std::stringstream	ss(buffer);
		std::string			temp;
		double				nb;

		if(buffer == "date,exchange_rate")
			continue;
		if (!getline(ss, temp, ',') && temp.empty())
			throw BitcoinExchange::errParsing();
		if (!(ss >> nb))
			throw BitcoinExchange::errParsing();
		this->_csvData[temp] = nb;
	}
	inFile.close();
}

void BitcoinExchange::readInfile(char *file)
{
	std::string		buffer;
	std::ifstream	inFile(file);

	if (!inFile)
		throw BitcoinExchange::errFileOpen();
	while (getline(inFile, buffer))
	{
		std::stringstream	ss(buffer);
		std::string			date;
		double				value;

		if (buffer == "date | value")
			continue;
		if (getline(ss, date, '|'))
		{
			eraseSpaces(date);
			if (!(ss >> value) || !ss || !ss.eof())
				std::cerr << "Error: bad input => " << buffer << std::endl;
			else if (date == "")
				std::cerr << "Error: bad input date => " << buffer << std::endl;
			else if(checkData(date, value))
			{
				double result;
				std::map<std::string, double>::iterator it = _csvData.find(date);
				if (it != _csvData.end())
				{
					result = value * it->second;
					std::cout << date << " => " << value << " = " << result << std::endl;
				}
				else
				{
					result = value * (findDate(date));
					if (result >= 0)
						std::cout << date << " => " << value << " = " << result << std::endl;
				}
			}
		}
	}
	inFile.close();
}

double BitcoinExchange::findDate(std::string &date)
{
	std::map<std::string, double>::iterator temp = _csvData.end();
	
	temp--;
	if (date > temp->first)
		return (temp->second);
	temp = _csvData.begin();
	if (date < temp->first)
	{
		std::cerr << "Error: date not found => " << date << std::endl;
		return (-1);
	}
	
	for (std::map<std::string, double>::iterator it = _csvData.begin(); it != _csvData.end(); it++)
	{
		if (it->first > date)
			return (temp->second);
		if (it->first > temp->first)
			temp = it;
	}
	std::cerr << "Error: date not found => " << date << std::endl;
	return (-1);
}

bool BitcoinExchange::isValidDate(std::string &date)
{
	int 		year, month, day;
	char 		sep1, sep2;
	struct tm	timeData;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Error: bad input date => " << date << std::endl;
		return (false);
	}
	for(size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		else if (!isdigit(date[i]))
		{
			std::cerr << "Error: bad character, not digit => " << date << std::endl;
			return (false);
		}
	}
	std::stringstream ss(date);
	if (!(ss >> year >> sep1 >> month >> sep2 >> day))
		throw BitcoinExchange::errParsing();
	if ((day < 1 || 31 < day) || (month < 1 || 12 < month)
		|| (year < 1900)) // year limits 1900
	{
		std::cerr << "Error: date out limit => " << date << std::endl;	
		return (false);
	}
	std::memset(&timeData, 0, sizeof(std::tm));
	timeData.tm_mday = day;
	timeData.tm_mon = month - 1;
	timeData.tm_year = year - 1900;
	std::mktime(&timeData);
	if (timeData.tm_mday != day || timeData.tm_mon != (month - 1)
		|| timeData.tm_year != (year - 1900))
	{
		std::cerr << "Error: invalid date => " << date << std::endl;
		return (false);
	}
	return (true);
}

bool BitcoinExchange::checkData(std::string &date, double value)
{
	if (value < 0)
	{
		std::cerr << "Error: not a positive number" << std::endl;
		return (false);
	}
	if (1000 < value)
	{
		std::cerr << "Error: too large number" << std::endl;
		return (false);
	}
	if (!isValidDate(date))
		return (false);
	return (true);
}

/************************************************************************/
/*************************** EXCEPTION CLASS ****************************/
/************************************************************************/

const char *BitcoinExchange::errFileOpen::what() const throw()
{
	return ("Error: while opening input File\n");
}

const char *BitcoinExchange::errParsing::what() const throw()
{
	return ("Error: while parsing\n");
}