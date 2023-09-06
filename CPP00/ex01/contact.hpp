/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:33:16 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/06 21:44:35 by javiersa         ###   ########.fr       */
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

public:
	contact(void);
	~contact(void);

	std::string		get_firstname(void)	const;
	std::string		get_lastname(void)	const;
	std::string		get_nickname(void)	const;
	std::string		get_phone(void)	const;
	std::string		get_secret(void)	const;
	void			set_firstname(std::string str);
	void			set_lastname(std::string str);
	void			set_nickname(std::string str);
	void			set_phone(std::string str);
	void			set_secret(std::string str);
};

#endif