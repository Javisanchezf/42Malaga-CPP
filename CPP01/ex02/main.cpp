/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:53:08 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/10 14:01:54 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string stringORG = "HI THIS IS BRAIN";
	std::string	*stringPTR = &stringORG;
	std::string	&stringREF = stringORG;
	std::cout << "\nMemory address of the string variable:\t" << &stringORG << "\n";
	std::cout << "Memory address of the string stringPTR:\t" << stringPTR << "\n";
	std::cout << "Memory address of the string stringREF:\t" << &stringREF << "\n\n";
	std::cout << "String variable value:\t" << stringORG << "\n";
	std::cout << "Value pointed to by stringPTR:\t" << *stringPTR << "\n";
	std::cout << "Value pointed to by stringREF:\t" << stringREF << "\n";

}
