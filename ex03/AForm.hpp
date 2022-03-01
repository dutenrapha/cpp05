/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:32:11 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/01 20:33:49 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
	
	class NoSignatureException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("The form is not signed");
				}
		};
		
	public:
		AForm(void);
		AForm(AForm const & src);
		virtual ~AForm(void);
		AForm & operator=(AForm const & rhs);

		AForm(std::string name, int requiredGradeSign, int requiredGradeExecute);
		std::string			getName(void) const;
		bool				getIsSigned(void) const;
		int					getRequiredGradeSign(void) const;
		int					getRequiredGradeExecute(void) const;
		void				beSigned(Bureaucrat const &bureaucrat);
		virtual bool		execute(Bureaucrat const &executor) const = 0;

		std::string			getTarget(void) const;
		void				setTarget(std::string target);
		
		void				setName(std::string name);
		void				setIsSigned(bool IsSigned);
		void				setRequiredGradeSign(int requiredGradeSign);
		void				setRequiredGradeExecute(int requiredGradeExecute);
		
	private:
		std::string 		_name;
		bool 				_IsSigned;
		int					_requiredGradeSign;
		int					_requiredGradeExecute;
		std::string			_target;
		void				_check(void);
};

std::ostream & operator<<(std::ostream & o, AForm const & src);

#endif