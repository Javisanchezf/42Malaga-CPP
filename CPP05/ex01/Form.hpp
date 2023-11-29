/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:06:07 by javiersa          #+#    #+#             */
/*   Updated: 2023/11/29 17:34:57 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
#define FORM_HPP

/*----------------------------LIBRARIES----------------------------*/
#include <iostream>
#include "Bureaucrat.hpp"

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

class Form
{
    private:
        const std::string   _name;
        const int           _gradeToSign;
        const int           _gradeToExecute;
        bool                _isSigned;
    public:
        Form(const std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form &copy);
        Form& operator=(const Form &equal);
        ~Form();

        std::string     getName(void) const;
        int             getGradeToSign(void) const;
        int             getGradeToExecute(void) const;
        bool            getIsSigned(void) const;
        void            beSigned(const Bureaucrat& bureaucrat);
        void			signForm(const Bureaucrat& bureaucrat);

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class FormAlreadySignedException: public std::exception
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

std::ostream&   operator<<( std::ostream& o, const Form& rhs );

#endif