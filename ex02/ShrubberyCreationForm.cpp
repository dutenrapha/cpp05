/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:38:52 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/01 17:01:28 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 75, 75)
{
	std::cout << "ShrubberyCreationForm Constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = src;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Destructor" << std::endl;;
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	std::cout << "ShrubberyCreationForm copy assigment constructor called" << std::endl;
	setName(rhs.getName());
	setIsSigned(rhs.getIsSigned());
	setRequiredGradeSign(rhs.getRequiredGradeSign());
	setRequiredGradeExecute(rhs.getRequiredGradeExecute());
	return (*this);	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
	this->setTarget(target);
	std::cout << *this << std::endl;
}

bool	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream	textOutput;
	std::string		filename;

	std::string	 TREES = "     ###\n    #o###\n  #####o###\n #o##*|*####\n  ###*|*#o#\n   # }|{ #\n     }|{\n\n               ###\n              #o###\n            #####o###\n           #o##*|*####\n            ###*|*#o#\n             # }|{ #\n               }|{\n\n     ###\n    #o###\n  #####o###\n #o##*|*####\n  ###*|*#o#\n   # }|{ #\n     }|{";
	if (AForm::execute(executor))
	{
		filename = this->getTarget() + "_shrubbery";
		textOutput.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
		if (!(textOutput.is_open()))
		{
			std::cout << filename << "Unable to open file" << std::endl;
			textOutput.close();
			return(false);
		}
		textOutput << TREES;
		textOutput.flush();
		textOutput.close();
		return (true);
	}
	return (false);	
}

std::ostream &operator<<(std::ostream & o, ShrubberyCreationForm const & src)
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

