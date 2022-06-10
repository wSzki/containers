/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:54:01 by wszurkow          #+#    #+#             */
/*   Updated: 2022/06/10 19:09:16 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <memory>

using namespace ft;

// DEFAULT
template <class T>
vector<T>::vector (void)
{
	std::cout << GREEN "[vector] Default constructor called\n" << _R;
}

// COPY
vector::vector(vector const &obj)
{
	std::cout << GREEN "[vector] Copy constructor called\n" << _R;
	if (this == &obj)
		return ;
	*this = obj;
}

// OVERLOADS
vector &vector::operator = (vector const &obj)
{
	std::cout << GREEN "[vector] Assignation operator called" << _R << std::endl;
	if (this == &obj)
		return (*this);
	*this = obj;
	//this-> = obj.
	return (*this);
}

// METHODS
//[...]

// DESTRUCTOR
vector::~vector (void)
{
	std::cout << RED << "[vector] Destructor Called\n" <<  _R;
}
