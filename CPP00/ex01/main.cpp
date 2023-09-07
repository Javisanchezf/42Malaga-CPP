/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:02:08 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/07 21:09:58 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"phonebook.hpp"

int	main(void)
{
	phonebook	book;

	book.welcome();
	book.add_contact();
	book.add_contact();
	book.search_contact();
}
