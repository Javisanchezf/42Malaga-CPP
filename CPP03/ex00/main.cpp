/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:06 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/26 17:48:47 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ClapTrap.hpp"

int	main()
{
	ClapTrap Clapi0;
	ClapTrap Clapi0copy = Clapi0;
	ClapTrap Clapi1("Paco");

	// for (int _ = 0; _ < 12 ; _++)
	// 	Clapi0.attack("someone");
	// std::cout << "\nNow the copy...\n\n";
	// for (int _ = 1; _ < 12 ; _++)
	// 	Clapi0copy.beRepaired(_);
	// std::cout << "\nKilling the copy...\n\n";
	// for (int _ = 1; _ < 13 ; _++)
	// 	Clapi0copy.takeDamage(_);
	// std::cout << "\nNow Paco mix...\n\n";
	Clapi1.takeDamage(9);
	for (int _ = 1; _ < 6 ; _++)
		Clapi1.beRepaired(_);
	for (int _ = 0; _ < 6 ; _++)
		Clapi1.attack("some other one");
	Clapi1.takeDamage(1000);
	Clapi1.attack("some other one");
}
