/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:21:40 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/14 11:13:20 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(void)
{
	std::cout << "Default constructor called.\n";
	this->_fixedPoint = 0;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called.\n";
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called.\n";
	this->_fixedPoint = copy._fixedPoint;
}

Fixed& Fixed::operator=(const Fixed &equal)
{
	std::cout << "Copy assignment operator called.\n";
	this->_fixedPoint = equal._fixedPoint;
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits function called.\n";
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits function called.\n";
	this->_fixedPoint = raw;
}
