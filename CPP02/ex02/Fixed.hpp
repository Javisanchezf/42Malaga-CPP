/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:19:30 by javiersa          #+#    #+#             */
/*   Updated: 2023/09/15 19:49:56 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once
#ifndef	FIXED_HPP
#define	FIXED_HPP

/*----------------------------LIBRARIES----------------------------*/
#include	<iostream>
#include	<cmath>

/*----------------------------COLORS----------------------------*/
# define BOLD		"\033[1m"
# define GRAY		"\033[30;1m"
# define RED		"\033[31;1m"
# define GREEN		"\033[32;1m"
# define YELLOW		"\033[33;1m"
# define BLUE		"\033[34;1m"
# define MAGENTA	"\033[35;1m"
# define CYAN		"\033[36;1m"
# define WHITE		"\033[37;1m"
# define DEFAULT	"\033[0m"

/*----------------------------CLASSES----------------------------*/
class Fixed
{
	private:
		int					_fixed_int;
		static const int	_fractionPart = 8;
	public:
		Fixed(void);
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed &copy);
		~Fixed();

		Fixed&	operator=(const Fixed &equal);

		float	operator+(const Fixed &nbr) const;
		float	operator-(const Fixed &nbr) const;
		float	operator*(const Fixed &nbr) const;
		float	operator/(const Fixed &nbr) const;

		bool	operator>(Fixed fixed)const;
		bool	operator<(Fixed fixed)const;
		bool	operator>=(Fixed fixed)const;
		bool	operator<=(Fixed fixed)const;
		bool	operator==(Fixed fixed)const;
		bool	operator!=(Fixed fixed)const;

		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed&		min( Fixed &a, Fixed &b );
		static const Fixed&	min( const Fixed &a, const Fixed &b );
		static Fixed&		max( Fixed &a, Fixed &b );
		static const Fixed&	max( const Fixed &a, const Fixed &b );
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif