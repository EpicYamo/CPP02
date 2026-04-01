/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 02:50:00 by aaycan            #+#    #+#             */
/*   Updated: 2026/04/01 03:33:16 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>

class Fixed
{
	private:
		int					_value;
		static int const	_digits = 8;
	public:
		Fixed(void);
		Fixed(Fixed const &input);
		~Fixed(void);

		Fixed	&operator=(Fixed const &input);
		int		getRawBits(void)const;
		void	setRawBits(int const raw);	
};

#endif
