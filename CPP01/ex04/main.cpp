/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:08:02 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/12 12:14:41 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Invalid number of arguments.\n";
		return (1);
	}
	std::ifstream inputFile(argv[1]);
	if (!inputFile)
	{
		std::cerr << "Error opening file " << argv[1] << ".\n";
		return (1);
	}
	std::ofstream outputFile(((std::string)argv[1] + ".replace").c_str());
	if (!inputFile)
	{
		std::cerr << "Error creating output file " << argv[1] << ".replace.\n";
		return (1);
	}

	char		ch;
	while (inputFile.get(ch))
	{
		if (ch == argv[2][0])
		{
			std::string	aux = "";
			aux += ch;
			size_t i = 0;
			while (++i < ((std::string)argv[2]).length() && inputFile.get(ch))
			{
				aux += ch;
				if (ch != argv[2][i])
					break;
			}
			if (i == ((std::string)argv[2]).length())
				outputFile << argv[3];
			else
				outputFile << aux;
		}
		else
		{
			outputFile.put(ch);
        }
    }
	std::cout << "Replacement completed. Result in: " << argv[1] << ".replace.\n";
}
