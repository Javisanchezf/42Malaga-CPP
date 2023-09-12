/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:04:20 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/12 22:02:17 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void){}

Harl::~Harl(){}

void	Harl::debug(void)
{
	std::cout << GREEN "DEBUG DEFAULT MESSAGE:\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese\
-triple-picklespecial-ketchup burger.\nI really do!\n" DEFAULT;
}

void	Harl::info(void)
{
	std::cout << GRAY "INFO DEFAULT MESSAGE:\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou \
didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" DEFAULT;
}

void	Harl::warning(void)
{
	std::cout << YELLOW "WARNING DEFAULT MESSAGE:\n";
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve \
been coming for years whereas you started working here since last month.\n" DEFAULT;
}

void	Harl::error(void)
{
	std::cout << RED "ERROR DEFAULT MESSAGE:\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" DEFAULT;
}

void	Harl::complain(std::string level)
{
	std::string	type[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*function[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4;  i++)
		if (type[i].compare(level) == 0)
			(this->*function[i])();
}
