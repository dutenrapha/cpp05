/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:15:29 by rdutenke          #+#    #+#             */
/*   Updated: 2022/02/17 22:18:07 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat john1;
	Bureaucrat john2("John2", 43);
	Bureaucrat *john3 = new Bureaucrat("John3", 45);
	std::cout << john1 << std::endl;
	std::cout << john2 << std::endl;
	std::cout << *john3 << std::endl;

	Bureaucrat *john3DeepCopy = new Bureaucrat(*john3);
	std::cout << *john3DeepCopy << std::endl;
	delete john3;
	std::cout << *john3DeepCopy << std::endl;
	delete john3DeepCopy;
	
	try
	{
		Bureaucrat fail_low("fail_low", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat fail_higt("fail_higt", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "Increase " << john1 << std::endl;
	try
	{
		john1.gradeInc();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Increase " << john1 << std::endl;
	
	std::cout << "Decrease " << john2 << std::endl;
	try
	{
		john2.gradeDec();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Decrease " << john2 << std::endl;
	
	return(0);
}