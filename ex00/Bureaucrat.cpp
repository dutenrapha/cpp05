/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:55:55 by rdutenke          #+#    #+#             */
/*   Updated: 2022/02/16 02:32:54 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("bureaucrat default"), _grade(150)
{
	std::cout << "Bureaucrat Constructor" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src): : _name(src.getName())
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
}

void	Bureaucrat::gradeDec(void)
{
	this->_grade++;
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
