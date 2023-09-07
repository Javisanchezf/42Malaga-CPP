/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:52:44 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/07 20:59:25 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
#define PHONEBOOK_HPP

/*----------------------------LIBRARIES----------------------------*/

#include	"contact.hpp"

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

/*----------------------------CLASS----------------------------*/

class	phonebook
{
	private:
		contact	_contact[8];
		int		_index;
		std::string	_getinput(std::string	str) const;

	public:
		phonebook(void);
		~phonebook(void);
		void		welcome(void);
		void		add_contact(void);
		void		search_contact(void) const;

};

#endif