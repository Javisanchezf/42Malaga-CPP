/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:14:41 by javiersa          #+#    #+#             */
/*   Updated: 2023/11/29 11:20:12 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat  *bureaucrat;

    bureaucrat = new Bureaucrat("Javier", 1);
    bureaucrat->decrementGrade();
    std::cout << *bureaucrat << std::endl;
    try
    {
        bureaucrat->incrementGrade();
        bureaucrat->incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete bureaucrat;
    return (0);
}