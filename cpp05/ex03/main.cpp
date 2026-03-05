/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:20:39 by gpaupher          #+#    #+#             */
/*   Updated: 2025/09/10 18:06:52 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Bureaucrat.hpp"
# include "./includes/AForm.hpp"
# include "./includes/ShrubberyCreationForm.hpp"
# include "./includes/RobotomyRequestForm.hpp"
# include "./includes/PresidentialPardonForm.hpp"
# include "./includes/Intern.hpp"

int main()
{
	srand(time(0));
	std::cout << "==== Documents CONSTRUCTORS ====" << std::endl;
	AForm	*newShrub;
	AForm	*newRobot;
	AForm	*newPrez;
	
	std::cout << "\n==== Bureaucrats CONSTRUCTORS + intern ====" << std::endl;
	Bureaucrat	Boss("Boss", 1);
	Bureaucrat	Employee1("Employee");
	Bureaucrat	Employee2("Manager", 42);
	Intern		temp;
	Intern 		intern(temp);

	std::cout << "\n==== BUREAUCRATS ====" << std::endl;

	std::cout << Boss << std::endl;
	std::cout << Employee1 << std::endl;
	std::cout << Employee2 << std::endl;

	std::cout << "\n==== Intern makeForm err ====" << std::endl;
	try{
		newShrub = intern.makeForm("ShrubberyCreation Form", "ShrubberyTarget");
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}
	try{
		newRobot = intern.makeForm("Robotomy Request", "RobotomyTarget");
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}
	try{
		newPrez = intern.makeForm("123456", "PresidentialTarget");
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}

	std::cout << "\n==== Intern makeForm success ====" << std::endl;
	try{
		newShrub = intern.makeForm("ShrubberyCreation", "ShrubberyTarget");
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}
	try{
		newRobot = intern.makeForm("RobotomyRequest", "RobotomyTarget");
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}
	try{
		newPrez = intern.makeForm("PresidentialPardon", "PresidentialTarget");
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}

	std::cout << "\n==== DOCUMENTS ====" << std::endl;
	std::cout << *newShrub << std::endl;
	std::cout << *newRobot << std::endl;
	std::cout << *newPrez << std::endl;
	
	std::cout << "\n==== TRY & CATCH TESTS ====" << std::endl;
	std::cout << "\n>> Sign Fail <<" << std::endl;
	Employee1.signForm(*newShrub);
	newRobot->beSigned(Employee1);

	std::cout << "\n>> Sign success <<" << std::endl;
	Employee2.signForm(*newShrub);
	newRobot->beSigned(Boss);
	std::cout << std::endl << *newShrub << std::endl;
	std::cout << *newRobot << std::endl;

	std::cout << "\n>> Execute fail <<" << std::endl;
	Employee1.executeForm(*newShrub);
	newRobot->execute(Employee1);
	Boss.executeForm(*newPrez);
	newPrez->execute(Employee2);

	std::cout << "\n>> Execute success <<" << std::endl;
	newPrez->beSigned(Boss);
	Employee2.executeForm(*newShrub);
	std::cout <<  std::endl;
	newRobot->execute(Employee2);
	Boss.executeForm(*newRobot);
	newRobot->execute(Boss);
	Employee2.executeForm(*newRobot);
	std::cout <<  std::endl;
	Boss.executeForm(*newPrez);
	
	std::cout << "\n==== DESTRUCTORS ====" << std::endl;
	delete(newShrub);
	delete(newRobot);
	delete(newPrez);
	return (0);
}