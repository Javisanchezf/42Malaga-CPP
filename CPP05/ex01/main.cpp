/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:14:41 by javiersa          #+#    #+#             */
/*   Updated: 2023/11/29 20:17:54 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void)
{
    Bureaucrat  *bureaucrat1;
    bureaucrat1 = new Bureaucrat("Javier", 5);

    
    Form        *form1;
    form1 = new Form("Form1", 10, 10);
    Form        *form2;
    form2 = new Form("Form2", 1, 1);
	try
	{
        bureaucrat1->signForm(*form1);
        bureaucrat1->signForm(*form1);
        bureaucrat1->signForm(*form2);
        std::cout << *form1 << std::endl;
        std::cout << *form2 << std::endl;
        delete bureaucrat1;
        delete form1;
        delete form2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
    return (0);
}