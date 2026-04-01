/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 02:49:58 by aaycan            #+#    #+#             */
/*   Updated: 2026/04/01 05:31:04 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	this->_value = 0;
}

Fixed::Fixed(Fixed const &input)
{
	this->_value = input.getRawBits();
}

Fixed::Fixed(int const input)
{
	this->_value = input << this->_digits;
}

Fixed::Fixed(float const input)
{
	this->_value = (int)roundf(input * (1 << this->_digits));
}

Fixed::~Fixed(void)
{
}

Fixed &Fixed::operator=(Fixed const &input)
{
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

bool Fixed::operator>(Fixed const &input) const
{
	return (this->_value > input._value);
}

bool Fixed::operator<(Fixed const &input) const
{
	return (this->_value < input._value);
}

bool Fixed::operator>=(Fixed const &input) const
{
	return (this->_value >= input._value);
}

bool Fixed::operator<=(Fixed const &input) const
{
	return (this->_value <= input._value);
}

bool Fixed::operator==(Fixed const &input) const
{
	return (this->_value == input._value);
}

bool Fixed::operator!=(Fixed const &input) const
{
	return (this->_value != input._value);
}

Fixed Fixed::operator+(Fixed const &input) const
{
	return (Fixed(this->toFloat() + input.toFloat()));
}

Fixed Fixed::operator-(Fixed const &input) const
{
	return (Fixed(this->toFloat() - input.toFloat()));
}

Fixed Fixed::operator*(Fixed const &input) const
{
	return (Fixed(this->toFloat() * input.toFloat()));
}

Fixed Fixed::operator/(Fixed const &input) const
{
	return (Fixed(this->toFloat() / input.toFloat()));
}

Fixed Fixed::operator++(void)
{
	++(this->_value);
	return (*this);
}

Fixed Fixed::operator--(void)
{
	--(this->_value);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	++(this->_value);
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	--(this->_value);
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a._value < b._value)
		return (a);
	return (b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a._value < b._value)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a._value > b._value)
		return (a);
	return (b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a._value > b._value)
		return (a);
	return (b);
}
