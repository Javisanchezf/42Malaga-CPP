/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:55:47 by javiersa          #+#    #+#             */
/*   Updated: 2023/11/29 20:07:58 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
    this->setGrade(grade);
}

/*----------------------------COPY-METHODS----------------------------*/

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name)
{
    this->setGrade(copy._grade);
}

/*----------------------------OVERLOAD-OPERATORS----------------------------*/

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &equal)
{
    if (this != &equal)
        this->setGrade(equal._grade);
    return (*this);
}

/*----------------------------DESTRUCTORS----------------------------*/

Bureaucrat::~Bureaucrat(void)
{
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

std::string		Bureaucrat::getName(void) const
{
    return (this->_name);
}

int     		Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void            Bureaucrat::incrementGrade()
{
    this->setGrade(this->_grade - 1);
}

void            Bureaucrat::decrementGrade()
{
    this->setGrade(this->_grade + 1);
}

void			Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signs " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << *this << " couldn't execute " << form << " because: " << e.what() << DEFAULT << std::endl;
	}
}

void		Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executes " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << *this << " couldn't execute " << form << " because " << e.what() << DEFAULT << std::endl;
	}
}
/*----------------------------PRIVATE-FUNCTIONS----------------------------*/

void            Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

/*----------------------------EXCEPTIONS----------------------------*/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low.");
}

/*----------------------------NON-MEMBER-FUNCTIONS----------------------------*/

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs )
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return (o);
}