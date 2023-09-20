/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:21:40 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/15 19:57:49 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*----------------------------CONSTRUCTORS----------------------------*/

Fixed::Fixed(void)
{
	std::cout << "Default constructor called.\n";
	this->_fixed_int = 0;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called.\n";
	this->_fixed_int = (float)nbr * (1 << this->_fractionPart);
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called.\n";
	this->_fixed_int = roundf(nbr * (1 << this->_fractionPart));
}

/*----------------------------DESTRUCTORS----------------------------*/

Fixed::~Fixed(void)
{
	std::cout << "Destructor called.\n";
}

/*----------------------------COPY-METHODS----------------------------*/

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called.\n";
	this->_fixed_int = copy._fixed_int;
}


/*----------------------------OVERLOAD-OPERATORS----------------------------*/

Fixed&	Fixed::operator=(const Fixed &equal)
{
	std::cout << "Copy assignment operator called.\n";
	this->_fixed_int = equal._fixed_int;
	return (*this);
}


float	Fixed::operator+(const Fixed &nbr) const
{
	return (this->toFloat() + nbr.toFloat());
}

float	Fixed::operator-(const Fixed &nbr) const
{
	return (this->toFloat() - nbr.toFloat());
}

float	Fixed::operator*(const Fixed &nbr) const
{
	return (this->toFloat() * nbr.toFloat());
}

float	Fixed::operator/(const Fixed &nbr) const
{
	return (this->toFloat() / nbr.toFloat());
}


bool	Fixed::operator>(Fixed fixed)const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed)const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed)const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed)const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed)const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed)const
{
	return (this->toFloat() != fixed.toFloat());
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	return (o << fixed.toFloat());
}


Fixed&			Fixed::operator++(void)
{
	++this->_fixed_int;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	--this->_fixed_int;
	return (*this);
}

Fixed			Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixed_int++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixed_int--;
	return (tmp);
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits function called.\n";
	return (this->_fixed_int);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits function called.\n";
	this->_fixed_int = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)((float)this->_fixed_int / (1 << this->_fractionPart));
}

int		Fixed::toInt(void) const
{
	return ((float)this->_fixed_int / (1 << this->_fractionPart));
}


Fixed&			Fixed::min( Fixed &a, Fixed &b )
{
	if (a < b)
		return a;
	return b;
}

const Fixed&	Fixed::min( const Fixed &a, const Fixed &b )
{
	if (a < b)
		return a;
	return b;
}

Fixed&			Fixed::max( Fixed &a, Fixed &b )
{
	if (a > b)
		return a;
	return b;
}

const Fixed&	Fixed::max( const Fixed &a, const Fixed &b )
{
	if (a > b)
		return a;
	return b;
}