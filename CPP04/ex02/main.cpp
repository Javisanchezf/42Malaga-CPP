/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:06 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/27 20:00:05 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << GREEN"\n\n";
	// //Cause abstract class error:
	// const Animal *meta = new Animal();
	// delete meta;
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << DEFAULT"\n\n";
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	std::cout << RED"\n\n";
	delete j;
	delete i;
}