/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:30:31 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/01 18:51:34 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm Constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = src;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm Destructor" << std::endl;;
	return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	std::cout << "PresidentialPardonForm copy assigment constructor called" << std::endl;
	setName(rhs.getName());
	setIsSigned(rhs.getIsSigned());
	setRequiredGradeSign(rhs.getRequiredGradeSign());
	setRequiredGradeExecute(rhs.getRequiredGradeExecute());
	return (*this);	
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5)
{
	this->setTarget(target);
	std::cout << *this << std::endl;
}

bool	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (AForm::execute(executor))
	{
		std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
		return (true);
	}
	return (false);	
}

std::ostream &operator<<(std::ostream & o, PresidentialPardonForm const & src)
{
	o	<< src.getName()
		<< std::endl
		<< "Grade to sign: "
		<< src.getRequiredGradeSign()
		<< std::endl
		<< "Grade to execute: "
		<< src.getRequiredGradeExecute()
		<< std::endl
		<< "Target: "
		<< src.getTarget()
		<< std::endl
		<< "Is signed: ";
	if (src.getIsSigned())
		o << "Yes." << std::endl;
	else
		o << "No." << std::endl;
	return (o);
}
