/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:32:23 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/01 16:32:40 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _name("AForm default"), _IsSigned(false), _requiredGradeSign(75), _requiredGradeExecute(75) 
{
	std::cout << "AForm Constructor" << std::endl;
	std::cout	<< "AForm " 
			<< this->_name 
			<< " was created with required sign grade " 
			<< this->_requiredGradeSign 
			<< " and required execution grade " 
			<< this->_requiredGradeExecute 
			<< std::endl;
	return ;
}


AForm::AForm(std::string name, int requiredGradeSign, int requiredGradeExecute) : _name(name), _IsSigned(false), _requiredGradeSign(requiredGradeSign), _requiredGradeExecute(requiredGradeExecute) 
{
	_check();
	std::cout << "AForm Constructor" << std::endl;
	std::cout	<< "AForm " 
				<< this->_name 
				<< " was created with required sign grade " 
				<< this->_requiredGradeSign 
				<< " and required execution grade " 
				<< this->_requiredGradeExecute 
				<< std::endl;
	return ;
}


AForm::AForm(AForm const & src)
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = src;
	return ;
}

AForm::~AForm(void)
{
	std::cout << "AForm Destructor" << std::endl;;
	return ;
}

AForm & AForm::operator=(AForm const & rhs)
{
	std::cout << "AForm copy assigment constructor called" << std::endl;
	this->_name = rhs.getName();
	this->_IsSigned = rhs.getIsSigned();
	this->_requiredGradeSign = rhs.getRequiredGradeSign();
	this->_requiredGradeExecute = rhs.getRequiredGradeExecute();
	return (*this);	
}

std::string		AForm::getName(void) const
{
	return(this->_name);
}

bool			AForm::getIsSigned(void) const
{
	return(this->_IsSigned);
}

int				AForm::getRequiredGradeSign(void) const
{
	return(this->_requiredGradeSign);
}

int				AForm::getRequiredGradeExecute(void) const
{
	return(this->_requiredGradeExecute);
}

std::string			AForm::getTarget(void) const
{
	return(this->_target);
}

void				AForm::setTarget(std::string target)
{
	this->_target = target;
}

void				AForm::setName(std::string name)
{
	this->_name = name;
}

void				AForm::setIsSigned(bool IsSigned)
{
	this->_IsSigned = IsSigned;
}

void				AForm::setRequiredGradeSign(int requiredGradeSign)
{
	this->_requiredGradeSign = requiredGradeSign;
}

void				AForm::setRequiredGradeExecute(int requiredGradeExecute)
{
	this->_requiredGradeExecute = requiredGradeExecute;
}




void			AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getRequiredGradeSign())
	{
		throw AForm::GradeTooLowException();
	}
	else
	{
		this->_IsSigned = true;
	}
	return ;
}

void			AForm::_check(void)
{
	if (this->_requiredGradeExecute < 1 || this->_requiredGradeSign < 1)
	{
		throw AForm::GradeTooHighException();
	}
	if (this->_requiredGradeExecute > 150 || this->_requiredGradeSign > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

bool		AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_IsSigned)
	{
		throw AForm::NoSignatureException();
		return false;
	}
	if (executor.getGrade() > this->getRequiredGradeExecute())
	{
		throw AForm::GradeTooLowException();
		return false;
	}
	return true;
}

std::ostream & operator<<(std::ostream & o, AForm const & src)
{
	o	<< "AForm: " 
		<< src.getName()
		<< ", needs " 
		<< src.getRequiredGradeSign() 
		<< " to be signed and "
		<< src.getRequiredGradeExecute()
		<< " to be executed. "
		<< "Is signed?: ";
		if (src.getIsSigned())
		{
			o << "Yes." << std::endl;
		}
		else
		{
			o << "No." << std::endl;
		}
		
	return (o);
}
