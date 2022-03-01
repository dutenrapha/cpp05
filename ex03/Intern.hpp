/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:28:54 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/01 20:45:13 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
	public:
		typedef	AForm	*(Intern::*forms)(std::string target);
		Intern(void);
		Intern(Intern const & src);
		~Intern(void);
		Intern & operator=(Intern const & rhs);
		
		AForm	*makeForm(std::string name, std::string target);
		AForm	*shrubberyForm(std::string target);
		AForm	*robotomyForm(std::string target);
		AForm	*presidentialForm(std::string target);
};

#endif
