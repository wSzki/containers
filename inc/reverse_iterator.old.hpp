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

#include "iterator_traits.hpp"
#include <cstddef>

/* ========================================================================== */
/* ------------------------- RANDOM ACCESS ITERATOR ------------------------- */
/* ========================================================================== */

// https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator.h.html

namespace ft
{
	template <typename T>
		class reverse_iterator: public iterator < ft::random_access_iterator_tag, T> // TODO WHAT THE FUCK IS THIS, WHY NO WORK WITHOUT
	{
		protected :
			T _ptr_to_iterator;

		public :
			typedef       T              iterator_type;
			typedef	typename		iterator_traits<T>::iterator_category	category;
			typedef	typename		iterator_traits<T>::value_type			value_type;
			typedef	typename		iterator_traits<T>::difference_type		difference_type;
			typedef	typename		iterator_traits<T>::pointer				pointer;
			typedef	typename 		iterator_traits<T>::reference			reference;

			typedef typename ft::random_access_iterator_tag iterator_category;


			/* ========================================================== */
			/* ---------------------- CONSTRUCTORS ---------------------- */
			/* ========================================================== */

			/* --------------------- DEFAULT CONSTRUCT ---------------------- */
			reverse_iterator  (void)        : _ptr_to_iterator(NULL) {};

			/* ----------------------- COPY CONSTRUCT ----------------------- */
			reverse_iterator  (iterator_type it) : _ptr_to_iterator(it)   {};

			/* --------------------- COPY CONSTRUCT REF --------------------- */
			reverse_iterator(const reverse_iterator &r_iterator) : _ptr_to_iterator(r_iterator.base()) {}

			/* ------------------------- OVERLOAD = ------------------------- */
			reverse_iterator &operator=(reverse_iterator const &r_iterator) {
				if (this != &r_iterator) {
					_ptr_to_iterator = r_iterator._ptr_to_iterator;
				}
				return (*this);
			}

			/* ----------------------- DESTRUCTOR ----------------------- */
			virtual ~reverse_iterator (void) {};

			/* ============================================================== */
			/* ---------------------------- BASE ---------------------------- */
			/* ============================================================== */

			iterator_type base() const {return _ptr_to_iterator;}

			//template<typename _It>
			//reverse_iterator(const reverse_iterator<_It> &rev_it) : _ptr_to_iterator(rev_it.base()) {}
			//reverse_iterator  &operator = (reverse_iterator const &to_copy) { this != &to_copy ? this->_ptr_to_iterator = to_copy._ptr_to_iterator : NULL ; return (*this); }


			operator reverse_iterator <value_type const>() const
			{
				return reverse_iterator<value_type const>(_ptr_to_iterator);
			}

			/* ============================================================== */
			/* ------------------- COMPARAISON OVERLOADS -------------------- */
			/* ============================================================== */

			template <typename U>   bool operator >  (const reverse_iterator<U> it) const { return (this->base() >  it.base()); };
			template <typename U>   bool operator <  (const reverse_iterator<U> it) const { return (this->base() <  it.base()); };
			template <typename U>   bool operator <= (const reverse_iterator<U> it) const { return (this->base() <= it.base()); };
			template <typename U>   bool operator >= (const reverse_iterator<U> it) const { return (this->base() >= it.base()); };
			template <typename U> 	bool operator == (const reverse_iterator<U> it) const { return (this->base() == it.base()); };
			template <typename U>   bool operator != (const reverse_iterator<U> it) const { return (this->base() != it.base()); };

			// Used for comparaison iterator_type - const itr
			// if reverse_iterator<T const>, returns const reverse_iterator<T const>
			//operator reverse_iterator<value_type const>() const { return reverse_iterator<value_type const>(_ptr_to_iterator); }

			/* ============================================================== */
			/* -------------- INCREMENT / DECREMENT OVERLOADS --------------- */
			/* ============================================================== */

			// PRE INCREMENT
			reverse_iterator &operator ++ (void) { this->_ptr_to_iterator++; return (*this); };
			reverse_iterator &operator -- (void) { this->_ptr_to_iterator--; return (*this); };

			// POST INCREMENT
			reverse_iterator  operator ++ (int)  { reverse_iterator buffer = *this; this->_ptr_to_iterator++; return (buffer); };
			reverse_iterator  operator -- (int)  { reverse_iterator buffer = *this; this->_ptr_to_iterator--; return (buffer); };

			// INCREMENT /DECREMENT BY N
			reverse_iterator  operator +  (difference_type n) const { return (_ptr_to_iterator + n); };
			reverse_iterator  operator -  (difference_type n)       const { return (_ptr_to_iterator - n); };
			reverse_iterator  operator += (difference_type n)             { _ptr_to_iterator += n; return (*this); };
			reverse_iterator  operator -= (difference_type n)             { _ptr_to_iterator -= n; return (*this); };

			difference_type operator-(reverse_iterator const rhs) const { return (_ptr_to_iterator - rhs._ptr_to_iterator); }

			/* ============================================================== */
			/* --------------------------- MEMORY --------------------------- */
			/* ============================================================== */

			//pointer   operator -> () { return (this->_ptr_to_iterator);  }; // This is bused to access member functions of template types

			pointer operator->() const {
				return &(operator*());
			}
			//reference operator *  () { return (*this->_ptr_to_iterator); };

			reference operator [] (difference_type n) const  {  return (this->_ptr_to_iterator[n]); };

			reference operator*() const {
				T newref(this->_current);
				newref--;
				return *(newref);
			};
	};

	template <typename T> ft::reverse_iterator<T> operator + (std::ptrdiff_t n, ft::reverse_iterator<T> const &it) { return (it.base() + n); }
	template <typename T> ft::reverse_iterator<T> operator - (std::ptrdiff_t n, ft::reverse_iterator<T> const &it) { return (it.base() - n); }

	//template <typename T> typename ft::reverse_iterator<T>::difference_type operator + (std::ptrdiff_t n, ft::reverse_iterator<T> const &it) { return (it.base() + n); }
	//template <typename T> typename ft::reverse_iterator<T>::difference_type operator - (std::ptrdiff_t n, ft::reverse_iterator<T> const &it) { return (it.base() - n); }

	template <typename T, typename U> std::ptrdiff_t operator - (const reverse_iterator<T> &a , const reverse_iterator<U> &b) {return a.base() - b.base();}

}


#endif




