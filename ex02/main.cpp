/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:11:15 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/01 19:13:37 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <unistd.h>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	std::cout << ".............................Forms declaration................................" << std::endl;
	PresidentialPardonForm form("presidentialPardonTest");
	ShrubberyCreationForm form2("shrubberyCreationTest");
	RobotomyRequestForm form3("robotomyRequestTest");
	std::cout << ".............................................................................." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	

	std::cout << ".............................Forms sign and excution.........................." << std::endl;	
	Bureaucrat	john;
	Bureaucrat	fred("fred", 1);
	std::cout << std::endl;
	std::cout << std::endl;
	
	john.executeForm(form);
	john.executeForm(form2);
	john.executeForm(form3);
	std::cout << std::endl;
	std::cout << std::endl;
	
	fred.executeForm(form);
	fred.executeForm(form2);
	fred.executeForm(form3);
	std::cout << std::endl;
	std::cout << std::endl;

	john.signForm(form);
	john.signForm(form2);
	john.signForm(form3);
	std::cout << std::endl;
	std::cout << std::endl;
	
	fred.signForm(form);
	fred.signForm(form2);
	fred.signForm(form3);
	std::cout << std::endl;
	std::cout << std::endl;
	
	john.executeForm(form);
	john.executeForm(form2);
	john.executeForm(form3);
	std::cout << std::endl;
	std::cout << std::endl;
	
	fred.executeForm(form);
	fred.executeForm(form2);
	fred.executeForm(form3);
	std::cout << ".............................................................................." << std::endl;	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	return (0);
}
