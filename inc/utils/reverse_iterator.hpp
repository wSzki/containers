/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:13:41 by wszurkow          #+#    #+#             */
/*   Updated: 2022/09/27 20:15:05 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#define RI reverse_iterator
#include <cstddef>
#include "iterator.hpp"

#endif
/* ====================================================================== */
/* -------------------------- REVERSE ITERATOR -------------------------- */
/* ====================================================================== */
template <typename T>
class reverse_iterator
{
	protected:
		T _it;

	public:
		typedef typename ft::iterator_traits<T>::difference_type		difference_type;
		typedef typename ft::iterator_traits<T>::reference			reference;
		typedef typename ft::iterator_traits<T>::pointer				pointer;


		//operator RI<T const>() const { return RI<T const>(_it); }

		RI(void) : _it (NULL){};
		RI(T it) : _it (it)  {};

		RI  &operator = (RI const &to_copy) { this != &to_copy ? this->_it = to_copy.base() : NULL ; return (*this); }
		T base(void) const {return _it;}

		template <typename U> RI(const RI<U> &u) :_it(u.base()) {};

		reference operator *  (void)        const { T tmp = _it; return *--tmp; };
		pointer   operator -> (void)        const { return &(operator*()); };
		reference operator [] (ptrdiff_t n) const { return _it[-n - 1]; };


		/* -------------- INCREMENT / DECREMENT OVERLOADS --------------- */

		// PRE INCREMENT
		RI &operator ++ (void) { this->_it--; return (*this); };
		RI &operator -- (void) { this->_it++; return (*this); };

		// POST INCREMENT
		RI  operator ++ (int)  { RI buffer = *this; this->_it--; return (buffer); };
		RI  operator -- (int)  { RI buffer = *this; this->_it++; return (buffer); };

		// INCREMENT /DECREMENT BY N
		RI  operator +   (ptrdiff_t n) const { return (_it - n); };
		RI  operator -   (ptrdiff_t n) const { return (_it + n); };
		RI  operator +=  (ptrdiff_t n)       { _it -= n; return *this; };
		RI  operator -=  (ptrdiff_t n)       { _it += n; return *this; };

		//difference_type operator-(RAI const rhs) const { return (_it - rhs._it); }

		template <typename U>   bool operator >  (const RI<U> it) const { return (this->_it <  it.base()); };
		template <typename U>   bool operator <  (const RI<U> it) const { return (this->_it >  it.base()); };
		template <typename U>   bool operator <= (const RI<U> it) const { return (this->_it >= it.base()); };
		template <typename U>   bool operator >= (const RI<U> it) const { return (this->_it <= it.base()); };
		template <typename U> 	bool operator == (const RI<U> it) const { return (this->_it == it.base()); };
		template <typename U>   bool operator != (const RI<U> it) const { return (this->_it != it.base()); };



};
template <typename T>             RI<T> operator     + (std::ptrdiff_t n, ft::RI<T> const &it) { return (it + n); }
template <typename T>             RI<T> operator     - (std::ptrdiff_t n, ft::RI<T> const &it) { return (it - n); }
template <typename T, typename U> ptrdiff_t operator - (const RI<T> &a , const RI<U> &b) {return b.base() - a.base();}
