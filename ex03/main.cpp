
#include <iostream>
#include <unistd.h>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << ".............................Intern declaration................................" << std::endl;
	Intern intern;
	std::cout << "..............................................................................." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << ".............................Forms declaration................................." << std::endl;
	AForm *formPresidential = intern.makeForm("pardon", "pardonTest");
	AForm *formShrubbery = intern.makeForm("shrubbery", "shrubberytest");
	AForm *formRobotomy = intern.makeForm("robotomy", "robotomytest");
	AForm *inexitentForm = intern.makeForm("eioqpcagakkw", "randomTest");
	std::cout << "..............................................................................." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << ".............................Execution test...................................." << std::endl;
	Bureaucrat bureaucrat("Jonh", 1);

	bureaucrat.executeForm(*formPresidential);
	bureaucrat.signForm(*formPresidential);
	bureaucrat.executeForm(*formPresidential);
	bureaucrat.executeForm(*formShrubbery);
	bureaucrat.signForm(*formShrubbery);
	bureaucrat.executeForm(*formShrubbery);
	bureaucrat.executeForm(*formRobotomy);
	bureaucrat.signForm(*formRobotomy);
	bureaucrat.executeForm(*formRobotomy);
	delete formPresidential;
	delete formRobotomy;
	delete formShrubbery;
	delete inexitentForm;
	std::cout << ".............................................................................." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	return (0);
}
