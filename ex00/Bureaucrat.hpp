/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:55:52 by rdutenke          #+#    #+#             */
/*   Updated: 2022/02/17 20:23:26 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include <iostream>

class Bureaucrat
{
	class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade too high");
				}
		};

	class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade too low");
				}
		};
		
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);
		Bureaucrat & operator=(Bureaucrat const & rhs);

		Bureaucrat(std::string name, int grade);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		gradeInc(void);
		void		gradeDec(void);
		
	private:
		std::string 	const _name;
		int				_grade;
		void			_check(void);
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src);

#endif