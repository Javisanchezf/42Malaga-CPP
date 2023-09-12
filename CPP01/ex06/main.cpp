/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:24:17 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/12 22:00:12 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED "INVALID NUMBER OF INPUTS!\n";
		return (1);
	}
	Harl(harl);
	switch (harl.getlevel(argv[1]))
	{
	case 0:
		harl.complain("DEBUG");
	case 1:
		harl.complain("INFO");
	case 2:
		harl.complain("WARNING");
	case 3:
		harl.complain("ERROR");
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}