/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:04 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/27 20:55:47 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

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
class AMateria
{
	protected:
		std::string		_type;
	public:
		AMateria(void);
		AMateria(std::string type);
		AMateria(const AMateria &copy);
		AMateria& operator=(const AMateria &equal);
		virtual ~AMateria();

		virtual AMateria*	clone() const = 0;
		std::string const &	getType() const;
		// virtual void		use(ICharacter& target);
};

#endif
