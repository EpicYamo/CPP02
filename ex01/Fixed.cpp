/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 02:49:58 by aaycan            #+#    #+#             */
/*   Updated: 2026/04/01 05:01:59 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(Fixed const &input)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = input.getRawBits();
}

Fixed::Fixed(int const input)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = input << this->_digits;
}

Fixed::Fixed(float const input)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = (int)roundf(input * (1 << this->_digits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &input)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = input.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << this->_digits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_digits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &input)
{
	out << input.toFloat();
	return (out);
}
