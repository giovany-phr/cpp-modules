/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:05:26 by gpaupher          #+#    #+#             */
/*   Updated: 2025/09/10 19:07:50 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/converter.hpp"

void	isSpe(std::string str)
{
	std::string		type[6] = {"nan", "nanf", "+inf", "+inff", "-inf", "-inff"};
	int				index = 0;

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	while (index < 6)
	{
		if (str == type[index])
			break;
		index++;
	}

	switch (index)
	{
		case 0 :
		case 1 :
		{
			std::cout << "double: nan" << std::endl;
			std::cout << "float: nanf" << std::endl;
			break;
		}
		case 2 :
		case 3 :
		{
			std::cout << "double: +inf" << std::endl;
			std::cout << "float: +inff" << std::endl;
			break;
		}
		case 4 :
		case 5 :
		{
			std::cout << "double: -inf" << std::endl;
			std::cout << "float: -inff" << std::endl;
			break;
		}
	}
}

void	isChar(std::string str)
{
	char	_char = static_cast<char>(str[0]);
	int		_int = static_cast<int>(_char);
	double	_double = static_cast<double>(_int);
	float	_float = static_cast<float>(_double);

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "char: " << _char << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "double: " << _double << std::endl;
	std::cout << "float: " << _float << 'f' << std::endl;
}

void	isInt(std::string str)
{
	long	temp = std::atol(str.c_str());
	
	std::cout << std::fixed << std::setprecision(1);
	if (32 <= temp && temp <= 126)
		std::cout << "char: " << static_cast<char>(temp) << std::endl;
	else if (32 > temp)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;
	if (INT_MIN <= temp && temp <= INT_MAX)
		std::cout << "char: " << static_cast<int>(temp) << std::endl;
	else
		std::cout << "int: Impossible" << std::endl;
	std::cout << "double: " << static_cast<double>(temp) << std::endl;
	std::cout << "float: " << static_cast<float>(temp) << 'f' << std::endl;
}

void	isFloat(std::string str)
{
	float	temp = std::atof(str.c_str());

	std::cout << std::fixed << std::setprecision(1);
	if (32 <= temp && temp <= 126)
		std::cout << "char: " << static_cast<char>(temp) << std::endl;
	else if (32 > temp)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;
	std::cout << "char: " << static_cast<int>(temp) << std::endl;
	std::cout << "double: " << static_cast<double>(temp) << std::endl;
	std::cout << "float: " << temp << 'f' << std::endl;
}

void	isDouble(std::string str)
{
	double	temp = std::atof(str.c_str());

	std::cout << std::fixed << std::setprecision(1);
	if (32 <= temp && temp <= 126)
		std::cout << "char: " << static_cast<char>(temp) << std::endl;
	else if (32 > temp)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;
	if (INT_MIN <= temp && temp <= INT_MAX)
		std::cout << "char: " << static_cast<int>(temp) << std::endl;
	else
		std::cout << "int: Impossible" << std::endl;
	std::cout << "double: " << temp << std::endl;
	std::cout << "float: " << static_cast<float>(temp) << 'f' << std::endl;
}