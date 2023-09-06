/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:52:44 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/06 21:52:31 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include	"contact.hpp"

class	phonebook
{
	private:
		contact	_contacts[8];
		int		_index;
	public:
		phonebook(void);
		~phonebook(void);
};

#endif