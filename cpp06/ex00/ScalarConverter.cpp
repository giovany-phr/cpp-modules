/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:48:36 by gpaupher          #+#    #+#             */
/*   Updated: 2025/06/05 19:49:38 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/ScalarConverter.hpp"

////////////////////////////////////////
////--- CONSTRUCTOR & DESTRUCTOR ---////
///////////////////////////////////////

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default construcor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "ScalarConverter copy construcor called" << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &other)
{
	std::cout << "ScalarConverter assignement construcor called" << std::endl;
	if (this != &other)
		(void) other;
	return (*this);
}

///////////////////////////////////////
///////////--- FUNCTIONS ---///////////
///////////////////////////////////////

void ScalarConverter::convert(std::string str)
{
	int	type = typeFinder(str);

	switch (type)
	{
		case CHAR:
		{
			// std::cout << "input is char" << std::endl;
			isChar(str);
			break;
		}
		case INT:
		{
			// std::cout << "input is int" << std::endl;
			isInt(str);
			break;
		}
		case FLOAT:
		{
			// std::cout << "input is float" << std::endl;
			isFloat(str);
			break;
		}
		case DOUBLE:
		{
			// std::cout << "input is double" << std::endl;
			isDouble(str);
			break;
		}

		case NAN_INF:
		{
			// std::cout << "input is special" << std::endl;
			isSpe(str);
			break;
		}
	
		default:
		{
			std::cout << "invalid input" << std::endl;
			break;
		}
	}
}