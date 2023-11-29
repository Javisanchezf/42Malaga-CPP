/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:06:07 by javiersa          #+#    #+#             */
/*   Updated: 2023/11/29 19:33:04 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

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
class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        const int           _gradeToSign;
        const int           _gradeToExecute;
        bool                _isSigned;
    public:
        AForm(const std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &copy);
        AForm& operator=(const AForm &equal);
        virtual ~AForm();

        std::string     getName(void) const;
        int             getGradeToSign(void) const;
        int             getGradeToExecute(void) const;
        bool            getIsSigned(void) const;
        void            beSigned(const Bureaucrat& bureaucrat);

		virtual void	execute(const Bureaucrat& executor) const = 0;
        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class AFormAlreadySignedException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
		class NotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&   operator<<( std::ostream& o, const AForm& rhs );

#endif