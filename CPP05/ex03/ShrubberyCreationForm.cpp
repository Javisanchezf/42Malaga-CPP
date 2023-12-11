/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:35:16 by javiersa          #+#    #+#             */
/*   Updated: 2023/11/29 20:11:58 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
	AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
	AForm(copy), _target(copy._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &equal)
{
	AForm::operator=(equal);
	_target = equal._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

void        ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!getIsSigned())
		throw AForm::NotSignedException();
	else
	{
		std::ofstream file((_target + "_shrubbery"));
		if (!file.is_open())
		{
			std::cout << "Error opening file." << std::endl;
			return ;
		}
		file << "              _{\\ _{\\{\\/{}/}/}__" <<  std::endl;
		file << "             {/{/\\}{/{/\\}(}{/\\} _" <<  std::endl;
		file << "            {/{/\\}{/{/\\}(_){/\\}  _" <<  std::endl;
		file << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" <<  std::endl;
		file << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}" <<  std::endl;
		file << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" <<  std::endl;
		file << "      {/{/{\\{\\{\\(/}{\\{\\/{/}/})/}/}/}" <<  std::endl;
		file << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" <<  std::endl;
		file << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" <<  std::endl;
		file << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" <<  std::endl;
		file << "       {/{\\{\\/}{/{\\{\\/{\\/}/}{\\{\\/}/}\\}(_)" <<  std::endl;
		file << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" <<  std::endl;
		file << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" <<  std::endl;
		file << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" <<  std::endl;
		file << "          (_){/{\\/}{\\{\\/}/}{\\(_)/}(_)" <<  std::endl;
		file << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" <<  std::endl;
		file << "             {/{\\{\\{\\/}/}{\\{\\\\}/}" <<  std::endl;
		file << "              {){/ {\\/}{\\/} \\}\\}" <<  std::endl;
		file << "              (_)  \\.-'.-/" <<  std::endl;
		file << "          __...--- |'-.-'| --...__" <<  std::endl;
		file << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--.." <<  std::endl;
		file << " -\"    ' .  . '    |.'-._| '  . .  '" <<  std::endl;
		file << " .  '-  '    .--'  | '-.'|    .  '  . '" <<  std::endl;
		file << "          ' ..     |'-_.-|" <<  std::endl;
		file << "  .  '  .       _.-|-._ -|-._  .  '  ." <<  std::endl;
		file << "              .'   |'- .-|   '." <<  std::endl;
		file << "  ..-'   ' .  '.   `-._.-'   .'  '  - ." <<  std::endl;
		file << "   .-' '        '-._______.-'     '  ." <<  std::endl;
		file << "        .      ~," <<  std::endl;
		file << "    .       .   |\\   .    ' '-." <<  std::endl;
		file << "    ___________/  \\____________" <<  std::endl;
		file << "   /        The answer         \\" <<  std::endl;
		file << "  |             is              |" <<  std::endl;
		file << "  |             42              |" <<  std::endl;
		file << "   \\___________________________/" <<  std::endl;
		file.close();
	}
}