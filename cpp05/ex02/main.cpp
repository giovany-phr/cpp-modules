/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:20:39 by gpaupher          #+#    #+#             */
/*   Updated: 2025/09/10 17:51:14 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Bureaucrat.hpp"
# include "./includes/AForm.hpp"
# include "./includes/ShrubberyCreationForm.hpp"
# include "./includes/RobotomyRequestForm.hpp"
# include "./includes/PresidentialPardonForm.hpp"

int main()
{
	srand(time(0));
	std::cout << "==== Documents CONSTRUCTORS ====" << std::endl;
	AForm					*Doc1;
	ShrubberyCreationForm	Shrub;
	RobotomyRequestForm		Robot;
	PresidentialPardonForm	Prez;
	(void)Doc1;
	
	std::cout << "\n==== Bureaucrats CONSTRUCTORS ====" << std::endl;
	Bureaucrat	Boss("Boss", 1);
	Bureaucrat	Employee1("Employee");
	Bureaucrat	Employee2("Manager", 42);

	// std::cout << "\n==== CONSTRUCTORS err ====" << std::endl;
	// try{
	// 	Form	wrong1("wrong", 200, 1);
	// }
	// catch(std::exception &e){
	// 	std::cerr << e.what();
	// }
	// try{
	// 	Form	wrong2("wrong", 1, 200);
	// }
	// catch(std::exception &e){
	// 	std::cerr << e.what();
	// }
	// try{
	// 	Form	wrong3("wrong", -42, 1);
	// }
	// catch(std::exception &e){
	// 	std::cerr << e.what();
	// }
	// try{
	// 	Form	wrong4("wrong", 1, -42);
	// }
	// catch(std::exception &e){
	// 	std::cerr << e.what();
	// }
	// try{
	// 	Form	wrong5("wrong", -42, 200);
	// }
	// catch(std::exception &e){
	// 	std::cerr << e.what();
	// }

	std::cout << "\n==== BUREAUCRATS ====" << std::endl;

	std::cout << Boss << std::endl;
	std::cout << Employee1 << std::endl;
	std::cout << Employee2 << std::endl;

	std::cout << "\n==== DOCUMENTS ====" << std::endl;
	std::cout << Shrub << std::endl;
	std::cout << Robot << std::endl;
	std::cout << Prez << std::endl;

	
	std::cout << "\n==== TRY & CATCH TESTS ====" << std::endl;

	std::cout << "\n>> Sign success <<" << std::endl;
	Employee2.signForm(Shrub);
	Robot.beSigned(Boss);
	std::cout << std::endl << Shrub << std::endl;
	std::cout << Robot << std::endl;

	std::cout << "\n>> Sign Fail <<" << std::endl;
	Employee1.signForm(Shrub);
	Robot.beSigned(Employee1);
	Shrub.beSigned(Employee2);
	

	std::cout << "\n>> Execute fail <<" << std::endl;
	Employee1.executeForm(Shrub);
	Robot.execute(Employee1);
	Boss.executeForm(Prez);
	Prez.execute(Employee2);

	std::cout << "\n>> Execute success <<" << std::endl;
	Prez.beSigned(Boss);
	Employee2.executeForm(Shrub);
	std::cout <<  std::endl;
	Robot.execute(Employee2);
	Boss.executeForm(Robot);
	Robot.execute(Boss);
	Employee2.executeForm(Robot);
	std::cout <<  std::endl;
	Boss.executeForm(Prez);
	
	std::cout << "\n==== DESTRUCTORS ====" << std::endl;
	return (0);
}