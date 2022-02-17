/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:11:15 by rdutenke          #+#    #+#             */
/*   Updated: 2022/02/18 00:47:00 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	
	std::cout << "Declaration check for Bureaucrat" << std::endl;
	Bureaucrat john1;
	Bureaucrat john2("John2", 47);
	Bureaucrat *john3 = new Bureaucrat("John3", 45);
	std::cout << john1 << std::endl;
	std::cout << john2 << std::endl;
	std::cout << *john3 << std::endl;
	std::cout << ".............................................................................." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "Copy check for Bureaucrat" << std::endl;
	Bureaucrat *john3DeepCopy = new Bureaucrat(*john3);
	std::cout << *john3DeepCopy << std::endl;
	delete john3;
	std::cout << *john3DeepCopy << std::endl;
	delete john3DeepCopy;
	std::cout << ".............................................................................." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "Declaration check for Form" << std::endl;
	Form form1;
	Form form2("Form2", 45, 45);
	Form *form3 = new Form("Form3", 25, 25);
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << *form3 << std::endl;
	std::cout << ".............................................................................." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "Copy check for Form" << std::endl;
	Form *form3DeepCopy = new Form(*form3);
	std::cout << *form3DeepCopy << std::endl;
	delete form3;
	std::cout << *form3DeepCopy << std::endl;
	delete form3DeepCopy;
	std::cout << ".............................................................................." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
		
	std::cout << "Error validation check" << std::endl;
	try
	{
		Form		form4("form4", 777, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form		form5("form5", 42, -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << ".............................................................................." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "Test Sign" << std::endl;
	
	std::cout << john1 << std::endl;
	
	std::cout << john2 << std::endl;

		
	std::cout << form1 << std::endl;
	
	std::cout << form2 << std::endl;
	
	john1.signForm(form1);

	john1.signForm(form2);
	
	john2.signForm(form1);
		
	john2.signForm(form2);
	
	john2.gradeInc();

	john2.gradeInc();
	john2.gradeInc();

	std::cout << john2 << std::endl;

	john2.signForm(form2);
	std::cout << ".............................................................................." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	return(0);
}
