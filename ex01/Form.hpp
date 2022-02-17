/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:32:11 by rdutenke          #+#    #+#             */
/*   Updated: 2022/02/18 00:03:55 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("grade too high for sign or execute this form");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("grade too low for sign or execute this form");
			}
	};
	
	public:
		Form(void);
		Form(Form const & src);
		~Form(void);
		Form & operator=(Form const & rhs);

		Form(std::string name, int requiredGradeSign, int requiredGradeExecute);
		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		int				getRequiredGradeSign(void) const;
		int				getRequiredGradeExecute(void) const;
		void			beSigned(Bureaucrat const &bureaucrat);

	private:
		std::string 		_name;
		bool 				_IsSigned;
		int					_requiredGradeSign;
		int					_requiredGradeExecute;
		void				_check(void);
};

std::ostream & operator<<(std::ostream & o, Form const & src);

#endif