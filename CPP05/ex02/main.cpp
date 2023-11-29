/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:14:41 by javiersa          #+#    #+#             */
/*   Updated: 2023/11/29 20:12:45 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat  *bureaucrat = new Bureaucrat("Bureaucrat", 40);
        AForm        *form = new PresidentialPardonForm("AForm");
        AForm        *form2 = new RobotomyRequestForm("AForm2");
        AForm        *form3 = new ShrubberyCreationForm("Tree_Name");

        std::cout << *bureaucrat << std::endl;
        std::cout << *form << std::endl;
        std::cout << *form2 << std::endl;
        std::cout << *form3 << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Sign Form section " << std::endl;
        bureaucrat->signForm(*form);
        bureaucrat->signForm(*form2);
        bureaucrat->signForm(*form3);

        std::cout << "----------------------------------------" << std::endl;
        std::cout << *bureaucrat << std::endl;
        std::cout << *form << std::endl;
        std::cout << *form2 << std::endl;
        std::cout << *form3 << std::endl;

        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Execute Form section " << std::endl;
        bureaucrat->executeForm(*form);
        bureaucrat->executeForm(*form2);
        bureaucrat->executeForm(*form3);
    
        delete bureaucrat;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Grade out of range " << '\n';
    }

    return (0);
}