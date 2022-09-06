/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:39:24 by wszurkow          #+#    #+#             */
/*   Updated: 2022/08/26 23:40:06 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

#define RAI random_access_iterator

/* ========================================================================== */
/* ------------------------- RANDOM ACCESS ITERATOR ------------------------- */
/* ========================================================================== */

// https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator.h.html

namespace ft
{
	template <typename T>
		class random_access_iterator : public iterator<ft::random_access_iterator_tag, T> // TODO WHAT THE FUCK IS THIS, WHY NO WORK WITHOUT
	{
		public :
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

			RAI  (void)        : _ptr(NULL) {};
			RAI  (pointer ptr) : _ptr(ptr)  {};
			~RAI (void)                     {};

			RAI  &operator = (RAI const &to_copy) { this != &to_copy ? this->_ptr = to_copy._ptr : NULL ; return (*this); }

			/* ============================================================== */
			/* -------------------- GETTER (FOR TESTING) -------------------- */
			/* ============================================================== */

			T* get_ptr() { return (this->_ptr); };

			/* ============================================================== */
			/* ------------------- COMPARAISON OVERLOADS -------------------- */
			/* ============================================================== */


			bool operator <  (const RAI it) const { return (this->_ptr <  it._ptr); };
			bool operator >  (const RAI it) const { return (this->_ptr >  it._ptr); };
			bool operator <= (const RAI it) const { return (this->_ptr <= it._ptr); };
			bool operator >= (const RAI it) const { return (this->_ptr >= it._ptr); };
			bool operator == (const RAI it) const { return (this->_ptr == it._ptr); };
			bool operator != (const RAI it) const { return (this->_ptr != it._ptr); };

			// TODO
			//template <typename U> bool operator <  (const RAI<U> &it) const { return (this->_ptr <  (U*)&it._ptr); };
			//template <typename U> bool operator >  (const RAI<U> &it) const { return (this->_ptr >  (U*)&it._ptr); };
			//template <typename U> bool operator <= (const RAI<U> &it) const { return (this->_ptr <= (U*)&it._ptr); };
			//template <typename U> bool operator >= (const RAI<U> &it) const { return (this->_ptr >= (U*)&it._ptr); };
			//template <typename U> bool operator == (const RAI<U> &it) const { return (this->_ptr == (U*)&it._ptr); };
			//template <typename U> bool operator != (const RAI<U> &it) const { return (this->_ptr != (U*)&it._ptr); };
			//// TODO

			// Used for comparaison iterator - const iterator
			operator random_access_iterator<value_type const>() const { return random_access_iterator<value_type const>(_ptr); }



			/* ============================================================== */
			/* -------------- INCREMENT / DECREMENT OVERLOADS --------------- */
			/* ============================================================== */

			// PRE INCREMENT
			RAI &operator ++ (void) { this->_ptr++; return (*this); };
			RAI &operator -- (void) { this->_ptr--; return (*this); };

			// POST INCREMENT
			RAI  operator ++ (int)  { RAI buffer = *this; this->_ptr++; return (buffer); };
			RAI  operator -- (int)  { RAI buffer = *this; this->_ptr--; return (buffer); };

			// INCREMENT /DECREMENT BY N
			RAI  operator +  (difference_type const  n) { return (_ptr + n); };
			RAI  operator -  (difference_type const  n) { return (_ptr - n); };
			RAI  operator += (difference_type const  n) { _ptr += n; return (*this); };
			RAI  operator -= (difference_type const  n) { _ptr -= n; return (*this); };

			difference_type operator-(random_access_iterator const rhs) const {
				return (_ptr - rhs._ptr);
			}



			// TODO
			template <typename U> RAI  operator +  (const RAI<U>it) const { return (this->_ptr + (U*)&it._ptr); };
			//template <typename U> RAI  operator -  (const RAI<U>it) const { return (this->_ptr - (U*)&it._ptr); };
			//template <typename U> RAI  operator += (const RAI<U>it) const { this->_ptr += (U*)&it._ptr; return (*this); };
			//template <typename U> RAI  operator -= (const RAI<U>it) const { this->_ptr -= (U*)&it._ptr; return (*this); };
			// TODO


			// DIFF TYPE - difference of two iterators

			/* ============================================================== */
			/* --------------------------- MEMORY --------------------------- */
			/* ============================================================== */

			pointer   operator -> () { return (this->_ptr);  }; // This is bused to access member functions of template types
			reference operator *  () { return (*this->_ptr); };

			reference operator [] (difference_type n) const  {  return (this->_ptr[n]); };
	};

	template <typename T>
	ft::RAI<T> operator + (std::ptrdiff_t n, ft::RAI<T> const &it) { return (it + n); }

	//template <typename T1, typename T2>
	//ft::RAI<T1> operator - (ft::RAI<T1> it1, ft::RAI<T2> it2) { return (it1._ptr - it2._ptr); } // TODO how the fuck can it access private member _ptr


	//template<class _Iterator>
	//ft::random_access_iterator<_Iterator> operator+(typename ft::random_access_iterator<_Iterator>::difference_type n, ft::random_access_iterator<_Iterator> const &lhs)
	//{
		//return (lhs + n);
	//}
}


#endif




