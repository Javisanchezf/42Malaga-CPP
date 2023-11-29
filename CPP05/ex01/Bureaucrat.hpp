/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:46:10 by javiersa          #+#    #+#             */
/*   Updated: 2023/11/29 12:35:53 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

/*----------------------------LIBRARIES----------------------------*/
#include <iostream>

/*----------------------------COLORS----------------------------*/
# define BOLD		"\033[1m"
# define GRAY		"\033[30;1m"
# define RED		"\033[31;1m"
# define GREEN		"\033[32;1m"
# define YELLOW		"\033[33;1m"
# define BLUE		"\033[34;1m"
# define MAGENTA	"\033[35;1m"
# define CYAN		"\033[36;1m"
# define WHITE		"\033[37;1m"
# define DEFAULT	"\033[0m"

/*----------------------------CLASSES----------------------------*/
class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
        void                setGrade(int grade);
		
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat& operator=(const Bureaucrat &equal);
        ~Bureaucrat();

		std::string		getName(void) const; 
		int     		getGrade(void) const;

        void            incrementGrade();
        void            decrementGrade();

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif