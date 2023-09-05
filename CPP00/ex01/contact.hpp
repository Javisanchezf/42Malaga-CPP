/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:33:16 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/05 20:10:43 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define	CONTACT_HPP

#include	<iostream>
#include	<iomanip>

class contact
{
private:
	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_phone;
	std::string	_secret;
	int			_index;

	std::string	_getstrinput(std::string	str) const;
	int			_getintinput(std::string	str) const;

public:
	contact(/* args */);
	~contact();

	void	init(void);
};

#endif