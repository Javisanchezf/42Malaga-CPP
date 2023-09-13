/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:08:02 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/13 21:44:34 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string	replace(std::string s0, std::string s1, std::string s2)
{
	size_t	i = s0.find(s1);
	while (i != std::string::npos)
	{
		s0 = s0.substr(0, i) + s2 + s0.substr(i + s1.length());
		i = s0.find(s1, i + s2.length());
	}
	return (s0);
}

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
	
	std::string filecontent;
	char		ch = inputFile.get();
	while (ch != EOF)
	{
		filecontent += ch;
		ch = inputFile.get();
	}
	outputFile << replace(filecontent, argv[2], argv[3]);
	std::cout << "Replacement completed. Result in: " << argv[1] << ".replace.\n";
}
