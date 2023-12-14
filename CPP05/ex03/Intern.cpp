/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:28:37 by javiersa          #+#    #+#             */
/*   Updated: 2023/12/12 18:36:05 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

Intern::Intern(void)
{
}

/*----------------------------COPY-METHODS----------------------------*/

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

Intern& Intern::operator=(const Intern &equal)
{
	(void)equal;
	return (*this);
}

/*----------------------------DESTRUCTORS----------------------------*/

Intern::~Intern(void)
{
}

/*----------------------------PRIVATE-FUNCTIONS----------------------------*/

AForm *makeShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *makeRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *makePresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

AForm* Intern::makeForm(std::string name, std::string target)
{
    typedef AForm *(*funcPtr)(std::string target);
    std::string NameArray[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    funcPtr funcArray[3] = {&makeShrubberyCreationForm, &makeRobotomyRequestForm, &makePresidentialPardonForm};
    for (int i = 0; i < 3; i++)
    {
        if (name == NameArray[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return (funcArray[i])(target);
        }
    }
    std::cout << "Intern can't create " << name << std::endl;
    return NULL;
}
