/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:39:24 by wszurkow          #+#    #+#             */
/*   Updated: 2022/08/26 23:40:06 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator.hpp"
#include "iterator_traits.hpp"

#define RI reverse_iterator

/* ========================================================================== */
/* ------------------------- RANDOM ACCESS ITERATOR ------------------------- */
/* ========================================================================== */

// https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator.h.html

namespace ft
{
	template <typename T>
		class reverse_iterator : public iterator < ft::random_access_iterator_tag, T> // TODO WHAT THE FUCK IS THIS, WHY NO WORK WITHOUT
	{
		public :
			T* _ptr;

		public :
			typedef       T              value_type;
			typedef       T              iterator;
			typedef       T*             pointer;
			typedef       T&             reference;
			typedef const T*             const_pointer;
			typedef const T&             const_reference;
			typedef       ptrdiff_t difference_type;

			typedef typename ft::random_access_iterator_tag iterator_category;

			RI  (void)        : _ptr(NULL) {};
			RI  (iterator ptr) : _ptr(ptr)  {};

			~RI (void)                     {};

			RI  &operator = (RI const &to_copy) { this != &to_copy ? this->_ptr = to_copy._ptr : NULL ; return (*this); }

			/* ============================================================== */
			/* ------------------- COMPARAISON OVERLOADS -------------------- */
			/* ============================================================== */

			template <typename U>   bool operator >  (const RI<U> it) const { return (this->_ptr >  it._ptr); };
			template <typename U>   bool operator <  (const RI<U> it) const { return (this->_ptr <  it._ptr); };
			template <typename U>   bool operator <= (const RI<U> it) const { return (this->_ptr <= it._ptr); };
			template <typename U>   bool operator >= (const RI<U> it) const { return (this->_ptr >= it._ptr); };
			template <typename U> 	bool operator == (const RI<U> it) const { return (this->_ptr == it._ptr); };
			template <typename U>   bool operator != (const RI<U> it) const { return (this->_ptr != it._ptr); };

			// Used for comparaison iterator - const iterator
			// TODO explain this black magic
			operator reverse_iterator<value_type const>() const { return reverse_iterator<value_type const>(_ptr); }

			reference operator*() const {
				iterator it(this->_ptr);
				return *(--it);
			}

			/* ============================================================== */
			/* -------------- INCREMENT / DECREMENT OVERLOADS --------------- */
			/* ============================================================== */

			// PRE INCREMENT
			RI &operator ++ (void) { this->_ptr++; return (*this); };
			RI &operator -- (void) { this->_ptr--; return (*this); };

			// POST INCREMENT
			RI  operator ++ (int)  { RI buffer = *this; this->_ptr++; return (buffer); };
			RI  operator -- (int)  { RI buffer = *this; this->_ptr--; return (buffer); };

			// INCREMENT /DECREMENT BY N
			RI  operator +  (difference_type n) const { return (_ptr + n); };
			RI  operator -  (difference_type n) const { return (_ptr + n); };
			RI  operator += (difference_type n)       { _ptr += n; return (*this); };
			RI  operator -= (difference_type n)       { _ptr -= n; return (*this); };

			difference_type operator-(reverse_iterator const rhs) const {
				return (_ptr - rhs._ptr);
			}

			/* ============================================================== */
			/* --------------------------- MEMORY --------------------------- */
			/* ============================================================== */

			pointer   operator -> () { return (this->_ptr);  }; // This is bused to access member functions of template types
			reference operator *  () { return (*this->_ptr); };

			reference operator [] (difference_type n) const  {  return (this->_ptr[n]); };


			/* ============================================================== */
			/* ---------------------------- BASE ---------------------------- */
			/* ============================================================== */
			iterator base() const	{ return (this->_ptr); }
	};

	template <typename T>
		ft::RI<T> operator + (std::ptrdiff_t n, ft::RI<T> const &it) { return (it + n); }
}


#endif




