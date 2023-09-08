/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:33:16 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/08 20:28:28 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define	CONTACT_HPP

/*----------------------------LIBRARIES----------------------------*/

#include	<iostream>
#include	<iomanip>
#include 	<string>
#include	<cstdlib>

/*----------------------------CLASS----------------------------*/

class contact
{
	private:
		std::string	_data[5];

	public:
		contact(void);
		~contact(void);

		std::string		get_data(int i)	const;
		void			set_data(int i, std::string str);
};

#endif
