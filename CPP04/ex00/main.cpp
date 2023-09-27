/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:06 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/27 13:17:26 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << BLUE "ANIMAL CLASS\n\n";
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << YELLOW "\nNOW THE WRONG ANIMAL\n\n";
	const WrongAnimal *meta1 = new WrongAnimal();
	const WrongAnimal *j1 = new WrongCat();
	std::cout << j1->getType() << " " << std::endl;
	j1->makeSound();
	j1->makeSound();
	delete meta1;
	delete j1;
	std::cout << DEFAULT;
	return 0;
}