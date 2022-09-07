/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:39:24 by wszurkow          #+#    #+#             */
/*   Updated: 2022/09/04 23:51:32 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator.hpp"

#define RI reverse_iterator

/* ========================================================================== */
/* ------------------------- RANDOM ACCESS ITERATOR ------------------------- */
/* ========================================================================== */

// https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator.h.html

namespace ft
{
	template <typename T>
		class reverse_iterator : public iterator<ft::random_access_iterator_tag, T>
	{
		private :
			T* _ptr;

		public :
			typedef       T  value_type;
			typedef       T* pointer;
			typedef       T& reference;
			typedef const T* const_pointer;
			typedef const T& const_reference;

			typedef std::ptrdiff_t difference_type; // TODO what is diff type
			typedef std::size_t    size;

			typedef typename ft::random_access_iterator_tag iterator_category;

			RI  (void)        : _ptr(NULL) {};
			RI  (pointer ptr) : _ptr(ptr)  {};
			~RI (void)                     {};

			RI  &operator = (RI const &to_copy) { this != &to_copy ? this->_ptr = to_copy._ptr : NULL ; return (*this); }

			/* ============================================================== */
			/* -------------------- GETTER (FOR TESTING) -------------------- */
			/* ============================================================== */

			T* get_ptr() { return (this->_ptr); };

			/* ============================================================== */
			/* ------------------- COMPARAISON OVERLOADS -------------------- */
			/* ============================================================== */

			bool operator <  (const RI it) const { return (this->_ptr <  it._ptr); };
			bool operator >  (const RI it) const { return (this->_ptr >  it._ptr); };
			bool operator <= (const RI it) const { return (this->_ptr <= it._ptr); };
			bool operator >= (const RI it) const { return (this->_ptr >= it._ptr); };
			bool operator == (const RI it) const { return (this->_ptr == it._ptr); };
			bool operator != (const RI it) const { return (this->_ptr != it._ptr); };

			/* ============================================================== */
			/* -------------- INCREMENT / DECREMENT OVERLOADS --------------- */
			/* ============================================================== */

			// PRE INCREMENT
			RI &operator ++ (void) { this->_ptr--; return (*this); };

			//reverse_iterator	&operator++(void){_ptr++; return(*this);};

			RI &operator -- (void) { this->_ptr++; return (*this); };

			// POST INCREMENT
			RI  operator ++ (int)  { RI buffer = *this; this->_ptr--; return (buffer); };
			RI  operator -- (int)  { RI buffer = *this; this->_ptr++; return (buffer); };

			// INCREMENT /DECREMENT BY N
			RI  operator +  (difference_type n) const { return (this->_ptr - n); };
			RI  operator -  (difference_type n) const { return (this->_ptr + n); };
			RI  operator += (difference_type n) const { this->_ptr -= n; return (*this); };
			RI  operator -= (difference_type n) const { this->_ptr += n; return (*this); };

			// DIFF TYPE - difference of two iterators

			/* ============================================================== */
			/* --------------------------- MEMORY --------------------------- */
			/* ============================================================== */

			pointer   operator -> () { return (this->_ptr);  }; // This is bused to access member functions of template types
			reference operator *  () { return (*this->_ptr); };

			reference operator [] (difference_type n) const  {  return (this->_ptr[n]); };
	};

	template <typename T1>
	ft::RI<T1> operator + (std::ptrdiff_t n, T1 it) { return (it._ptr + n); }

	//template<class _Iterator>
	//ft::reverse_iterator<_Iterator> operator+(typename ft::reverse_iterator<_Iterator>::difference_type n, ft::reverse_iterator<_Iterator> const &lhs)
	//{
		//return (lhs + n);
	//}
}


#endif




