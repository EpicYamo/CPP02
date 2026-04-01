/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 02:50:00 by aaycan            #+#    #+#             */
/*   Updated: 2026/04/01 04:30:14 by aaycan           ###   ########.fr       */
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
};

std::ostream &operator<<(std::ostream &out, Fixed const &input);

#endif
