/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:24:17 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/12 21:37:23 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl(harl);

	std::cout << "\nExecuting harl.complain(\"DEBUG\"):\n";
	harl.complain("DEBUG");
	std::cout << "\nExecuting harl.complain(\"INFO\"):\n";
	harl.complain("INFO");
	std::cout << "\nExecuting harl.complain(\"WARNING\"):\n";
	harl.complain("WARNING");
	std::cout << "\nExecuting harl.complain(\"ERROR\"):\n";
	harl.complain("ERROR");
	std::cout << "\nExecuting harl.complain(\"RANDOM\"):\n";
	harl.complain("RANDOM");
}