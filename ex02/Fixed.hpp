/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 02:50:00 by aaycan            #+#    #+#             */
/*   Updated: 2026/04/01 05:29:42 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>

class Fixed
{
	private:
		int _value;
		static int const _digits = 8;
	public:
		Fixed(void);
		Fixed(Fixed const &input);
		~Fixed(void);
		Fixed(int const input);
		Fixed(float const input);

		Fixed &operator=(Fixed const &input);
		
		int getRawBits(void)const;
		void setRawBits(int const raw);	
		
		float toFloat(void) const;
		int toInt(void) const;

		bool operator>(Fixed const &input) const;
		bool operator<(Fixed const &input) const;
		bool operator>=(Fixed const &input) const;
		bool operator<=(Fixed const &input) const;
		bool operator==(Fixed const &input) const;
		bool operator!=(Fixed const &input) const;

		Fixed operator+(Fixed const &input) const;
		Fixed operator-(Fixed const &input) const;
		Fixed operator*(Fixed const &input) const;
		Fixed operator/(Fixed const &input) const;

		Fixed operator++(void);
		Fixed operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &out, Fixed const &input);

#endif
