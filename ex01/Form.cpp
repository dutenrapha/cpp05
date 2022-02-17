/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:32:23 by rdutenke          #+#    #+#             */
/*   Updated: 2022/02/18 00:37:07 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name("Form default"), _IsSigned(false), _requiredGradeSign(75), _requiredGradeExecute(75) 
{
	std::cout << "Form Constructor" << std::endl;
	std::cout	<< "Form " 
			<< this->_name 
			<< " was created with required sign grade " 
			<< this->_requiredGradeSign 
			<< " and required execution grade " 
			<< this->_requiredGradeExecute 
			<< std::endl;
	return ;
}


Form::Form(std::string name, int requiredGradeSign, int requiredGradeExecute) : _name(name), _IsSigned(false), _requiredGradeSign(requiredGradeSign), _requiredGradeExecute(requiredGradeExecute) 
{
	_check();
	std::cout << "Form Constructor" << std::endl;
	std::cout	<< "Form " 
				<< this->_name 
				<< " was created with required sign grade " 
				<< this->_requiredGradeSign 
				<< " and required execution grade " 
				<< this->_requiredGradeExecute 
				<< std::endl;
	return ;
}


Form::Form(Form const & src)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
	return ;
}

Form::~Form(void)
{
	std::cout << "Form Destructor" << std::endl;;
	return ;
}

Form & Form::operator=(Form const & rhs)
{
	std::cout << "Form copy assigment constructor called" << std::endl;
	this->_name = rhs.getName();
	this->_IsSigned = rhs.getIsSigned();
	this->_requiredGradeSign = rhs.getRequiredGradeSign();
	this->_requiredGradeExecute = rhs.getRequiredGradeExecute();
	return (*this);	
}

std::string		Form::getName(void) const
{
	return(this->_name);
}

bool			Form::getIsSigned(void) const
{
	return(this->_IsSigned);
}

int				Form::getRequiredGradeSign(void) const
{
	return(this->_requiredGradeSign);
}

int				Form::getRequiredGradeExecute(void) const
{
	return(this->_requiredGradeExecute);
}

void			Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getRequiredGradeSign())
	{
		throw Form::GradeTooLowException();
	}
	else
	{
		this->_IsSigned = true;
	}
	return ;
}

void			Form::_check(void)
{
	if (this->_requiredGradeExecute < 1 || this->_requiredGradeSign < 1)
	{
		throw Form::GradeTooHighException();
	}
	if (this->_requiredGradeExecute > 150 || this->_requiredGradeSign > 150)
	{
		throw Form::GradeTooLowException();
	}
}


std::ostream & operator<<(std::ostream & o, Form const & src)
{
	o	<< "Form: " 
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
