/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:55:55 by rdutenke          #+#    #+#             */
/*   Updated: 2022/02/17 20:22:22 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("bureaucrat default"), _grade(150)
{
	std::cout << "Bureaucrat Constructor" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src): _name(src.getName())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat Destructor" << std::endl;;
	return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	std::cout << "Bureaucrat copy assigment constructor called" << std::endl;
	this->_grade = rhs.getGrade();
	return(*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	_check();
	std::cout << "Bureaucrat " << this->_name << " was created with grade " << this->_grade << std::endl;
	return ;
}

void		Bureaucrat::_check(void)
{
	if (this->_grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (this->_grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int		Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::gradeInc(void)
{
	this->_grade--;
	try
	{
		_check();
	}
	catch(const std::exception& e)
	{
		this->_grade++ ;
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::gradeDec(void)
{
	this->_grade++;
	try
	{
		_check();
	}
	catch(const std::exception& e)
	{
		this->_grade--;
		std::cerr << e.what() << '\n';
	}
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src)
{
	o	<< "Bureaucrat: " 
		<< src.getName()
		<< " Grade: "
		<< src.getGrade() 
		<< std::endl;
	return (o);
}
