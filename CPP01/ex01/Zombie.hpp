/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:33:42 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/11 18:32:32 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

/*----------------------------LIBRARIES----------------------------*/
#include <iostream>

/*----------------------------COLORS----------------------------*/
# define BOLD	"\033[1m"
# define BLACK	"\033[30;1m"
# define RED	"\033[31;1m"
# define GREEN	"\033[32;1m"
# define YELLOW	"\033[33;1m"
# define BLUE	"\033[34;1m"
# define MAGENTA	"\033[35;1m"
# define CYAN	"\033[36;1m"
# define WHITE	"\033[37;1m"
# define DEFAULT	"\033[0m"

/*----------------------------CLASSES----------------------------*/
class	Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie();
		void announce(void);
		void setName(std::string name);
};

#endif