/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:06 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/25 19:31:01 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ClapTrap.hpp"

int	main()
{
	ClapTrap Clapi0;
	ClapTrap Clapi0copy = Clapi0;
	ClapTrap Clapi1("Paco");

	for (int _ = 0; _ < 12 ; _++)
		Clapi0.attack("someone");
	std::cout << "\nNow the copy...\n\n";
	for (int _ = 1; _ < 12 ; _++)
		Clapi0copy.beRepaired(_);
	
}