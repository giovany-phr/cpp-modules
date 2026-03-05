/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:20:39 by gpaupher          #+#    #+#             */
/*   Updated: 2025/06/18 03:35:34 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Bureaucrat.hpp"
# include "./includes/Form.hpp"

int main()
{
	std::cout << "==== Documents CONSTRUCTORS ====" << std::endl;
	Form		Doc1;
	Form		Doc2("Document2");
	Form		Doc3("Document3", 100, 100);
	Form		Doc4("Document4", 1, 1);
	
	std::cout << "\n==== Bureaucrats CONSTRUCTORS ====" << std::endl;
	Bureaucrat	Boss("Boss", 1);
	Bureaucrat	Employee1("Employee");
	Bureaucrat	Employee2("Manager", 42);

	std::cout << "\n==== CONSTRUCTORS err ====" << std::endl;
	try{
		Form	wrong1("wrong", 200, 1);
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}
	try{
		Form	wrong2("wrong", 1, 200);
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}
	try{
		Form	wrong3("wrong", -42, 1);
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}
	try{
		Form	wrong4("wrong", 1, -42);
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}
	try{
		Form	wrong5("wrong", -42, 200);
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}
	
	std::cout << "\n==== BUREAUCRATS ====" << std::endl;

	std::cout << Boss << std::endl;
	std::cout << Employee1 << std::endl;
	std::cout << Employee2 << std::endl;

	std::cout << "\n==== DOCUMENTS ====" << std::endl;
	std::cout << Doc1 << std::endl;
	std::cout << Doc2 << std::endl;
	std::cout << Doc3 << std::endl;
	std::cout << Doc4 << std::endl;
	
	std::cout << "\n==== TRY & CATCH TESTS ====" << std::endl;
	Doc1.beSigned(Boss);
	Doc2.beSigned(Employee1);
	Doc3.beSigned(Boss);
	Doc3.beSigned(Employee1);
	Boss.signForm(Doc1);
	Employee1.signForm(Doc3);
	Employee2.signForm(Doc3);
	Employee2.signForm(Doc4);
	
	std::cout << "\n==== DESTRUCTORS ====" << std::endl;
	return (0);
}