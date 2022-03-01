/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:50:09 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/01 18:51:34 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = src;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm Destructor" << std::endl;;
	return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	std::cout << "RobotomyRequestForm copy assigment constructor called" << std::endl;
	setName(rhs.getName());
	setIsSigned(rhs.getIsSigned());
	setRequiredGradeSign(rhs.getRequiredGradeSign());
	setRequiredGradeExecute(rhs.getRequiredGradeExecute());
	return (*this);	
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
	this->setTarget(target);
	std::cout << *this << std::endl;
}

bool	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (AForm::execute(executor))
	{
		std::srand((unsigned int)time(NULL));
		if ((rand() % 2) != 0)
			std::cout <<"Robotomization Failure"  << std::endl;
		else
			std::cout <<"Robotomization completed " << this->getTarget() << "  has been robotomized successfully" << std::endl;
		return (true);
	}
	return (false);	
}

std::ostream &operator<<(std::ostream & o, RobotomyRequestForm const & src)
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
