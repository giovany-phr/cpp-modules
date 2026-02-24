/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:02:13 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/10 18:01:39 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include <string>
 # include <iostream>

int main()
{
	std::string str("HI THIS IS BRAIN");
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "string adress    : "<< &str << std::endl;
	std::cout << "stringPTR adress : "<< stringPTR << std::endl;
	std::cout << "stringREF adress : "<< &stringREF << std::endl << std::endl;

	std::cout << "string value    : "<< str << std::endl;
	std::cout << "stringPTR value : "<< *stringPTR << std::endl;
	std::cout << "stringREF value : "<< stringREF << std::endl;
	return (0);
}