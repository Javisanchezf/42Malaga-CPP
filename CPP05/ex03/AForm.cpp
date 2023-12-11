/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:07:34 by javiersa          #+#    #+#             */
/*   Updated: 2023/11/29 20:41:22 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    this->_isSigned = false;
    if (gradeToSign < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150)
        throw AForm::GradeTooLowException();
}

/*----------------------------COPY-METHODS----------------------------*/

AForm::AForm(const AForm &copy): _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    this->_isSigned = copy._isSigned;
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

AForm& AForm::operator=(const AForm &equal)
{
    if (this != &equal)
        this->_isSigned = equal._isSigned;
    return (*this);
}

/*----------------------------DESTRUCTORS----------------------------*/

AForm::~AForm(void)
{
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

std::string     AForm::getName(void) const
{
    return (this->_name);
}

int             AForm::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

int             AForm::getGradeToExecute(void) const
{
    return (this->_gradeToExecute);
}

bool            AForm::getIsSigned(void) const
{
    return (this->_isSigned);
}

void            AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (this->_isSigned)
        throw AForm::AFormAlreadySignedException();
    else if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

/*----------------------------PRIVATE-FUNCTIONS----------------------------*/

/*----------------------------EXCEPTIONS----------------------------*/

const char* AForm::GradeTooHighException::what() const throw()
{
    return (RED BOLD "Grade too high" DEFAULT);
}

const char* AForm::AFormAlreadySignedException::what() const throw()
{
    return (RED BOLD "AForm already signed" DEFAULT);
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return (RED BOLD "Grade too low" DEFAULT);
}

const char* AForm::NotSignedException::what() const throw()
{
	return (RED BOLD "AForm not signed" DEFAULT);
}
/*----------------------------NON-MEMBER-FUNCTIONS----------------------------*/

std::ostream&   operator<<( std::ostream& o, const AForm& rhs )
{
    o  << rhs.getName() << ", form grade to sign " << rhs.getGradeToSign() <<
	", form grade to execute " << rhs.getGradeToExecute() <<
    ", form is signed " << BOLD << rhs.getIsSigned();
    return (o);
}

/* ************************************************************************** */