/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:58:05 by javiersa          #+#    #+#             */
/*   Updated: 2023/11/29 18:32:18 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

Form::Form(const std::string name, int gradeToSign, int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    this->_isSigned = false;
    if (gradeToSign < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150)
        throw Form::GradeTooLowException();
}

/*----------------------------COPY-METHODS----------------------------*/

Form::Form(const Form &copy): _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    this->_isSigned = copy._isSigned;
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

Form& Form::operator=(const Form &equal)
{
    if (this != &equal)
        this->_isSigned = equal._isSigned;
    return (*this);
}

/*----------------------------DESTRUCTORS----------------------------*/

Form::~Form(void)
{
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

std::string     Form::getName(void) const
{
    return (this->_name);
}

int             Form::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

int             Form::getGradeToExecute(void) const
{
    return (this->_gradeToExecute);
}

bool            Form::getIsSigned(void) const
{
    return (this->_isSigned);
}

void            Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (this->_isSigned)
        throw Form::FormAlreadySignedException();
    else if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

void			Form::signForm(const Bureaucrat& bureaucrat)
{
	try
	{
		this->beSigned(bureaucrat);
		std::cout << GREEN << bureaucrat.getName() << " signed " << this->_name << DEFAULT << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << bureaucrat.getName() << " couldn't sign " <<
		this->_name << " because: " << DEFAULT;
		std::cerr << e.what() << '\n';
	}
}
/*----------------------------PRIVATE-FUNCTIONS----------------------------*/

/*----------------------------EXCEPTIONS----------------------------*/

const char* Form::GradeTooHighException::what() const throw()
{
    return (RED BOLD "Grade too high" DEFAULT);
}

const char* Form::FormAlreadySignedException::what() const throw()
{
    return (RED BOLD "Form already signed" DEFAULT);
}

const char* Form::GradeTooLowException::what() const throw()
{
    return (RED BOLD "Grade too low" DEFAULT);
}

/*----------------------------NON-MEMBER-FUNCTIONS----------------------------*/

std::ostream&   operator<<( std::ostream& o, const Form& rhs )
{
    o << BOLD << rhs.getName() << DEFAULT << ", form grade to sign " << BOLD << rhs.getGradeToSign() <<
    DEFAULT << ", form grade to execute " << BOLD << rhs.getGradeToExecute() <<
    DEFAULT << ", form is signed " << BOLD << rhs.getIsSigned() << DEFAULT;
    return (o);
}

/* ************************************************************************** */