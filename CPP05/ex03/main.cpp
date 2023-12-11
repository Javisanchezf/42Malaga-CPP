/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:14:41 by javiersa          #+#    #+#             */
/*   Updated: 2023/12/11 20:21:04 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Intern someRandomIntern;
	AForm* rrf;
	AForm* rrf2;
	AForm* rrf3;
	AForm* rrf4;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf2 = someRandomIntern.makeForm("shrubbery creation", "Bender2");
	rrf3 = someRandomIntern.makeForm("shrubbery creation", "Bender3");
	rrf4 = someRandomIntern.makeForm("sdfsdg", "Bender4");
	Bureaucrat b("Bender", 1);
	b.signForm(*rrf2);
	rrf2->execute(b);
	delete rrf;
	delete rrf2;
	delete rrf3;
    return (0);
}