/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:28:57 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/01 20:51:55 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void)
{
	std::cout << "Intern Constructor" << std::endl;
	return ;
}

Intern::Intern(Intern const & src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Intern Destructor" << std::endl;;
	return ;
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return(*this);
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	int	i;

	Intern::forms functions[] = {&Intern::shrubberyForm,
						 		 &Intern::robotomyForm,
						 		 &Intern::presidentialForm};
	std::string	formNames[] = {"shrubbery", "robotomy", "pardon"};
	
	i = 0;
	while (i < 3)
	{
		if(name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*functions[i])(target));
		}
		i++;
	}
	std::cout << "Form " << name << " does not exist" << std::endl;
	return (NULL);	
}

AForm	*Intern::shrubberyForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::robotomyForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::presidentialForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}
