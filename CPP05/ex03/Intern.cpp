/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:28:37 by javiersa          #+#    #+#             */
/*   Updated: 2023/12/11 20:12:37 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

Intern::Intern(void)
{
	this->_names[0] = "presidential pardon";
	this->_names[1] = "robotomy request";
	this->_names[2] = "shrubbery creation";
}

/*----------------------------COPY-METHODS----------------------------*/

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

Intern& Intern::operator=(const Intern &equal)
{
	if (this != &equal)
	{
		for (int i = 0; i < 3; i++)
			this->_names[i] = equal._names[i];
	}
	return (*this);
}

/*----------------------------DESTRUCTORS----------------------------*/

Intern::~Intern(void)
{
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

AForm* Intern::makeForm(std::string name, std::string target)
{
	int i = -1;
	while (++i < 3)
	{
		if (name == this->_names[i])
			break ;
	}
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << name << std::endl;
			return (new PresidentialPardonForm(target));
		case 1:
			std::cout << "Intern creates " << name << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates " << name << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << "Intern can't create " << name << std::endl;
			return (NULL);
	}

}
