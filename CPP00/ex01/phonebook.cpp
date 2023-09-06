/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:52:37 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/06 22:01:11 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"phonebook.hpp"

phonebook::phonebook(void)
{
	this->_index = 0;
	std::cout << "Created an empty phonebook for up to 8 contacts! 📞\n";
}

phonebook::~phonebook(void)
{
	std::cout << "Phonebook deleted! 🗑️\n"
}