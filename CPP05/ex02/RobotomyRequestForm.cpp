/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:28:27 by javiersa          #+#    #+#             */
/*   Updated: 2023/11/29 19:10:48 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
	AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):
	AForm(copy), _target(copy._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &equal)
{
	AForm::operator=(equal);
	_target = equal._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!getIsSigned())
		throw AForm::NotSignedException();
	else
	{
		std::cout << "Bzzzzzz... \n";
		if (rand() % 2)
			std::cout << _target << " has been robotomized successfully." << std::endl;
		else
			std::cout << _target << " robotomization failed." << std::endl;
	}
}