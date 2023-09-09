/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:33:13 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/09 18:40:02 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact()
{
}

std::string		Contact::get_data(int i)	const
{
	return (this->_data[i]);
}

void			Contact::set_data(int i, std::string str)
{
	this->_data[i] = str;
}
