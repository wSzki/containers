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
		class reverse_iterator  // TODO WHAT THE FUCK IS THIS, WHY NO WORK WITHOUT
		{
			protected :
				T _ptr;

			public :
				//typedef       T              value_type;
				//typedef       T*             pointer;
				//typedef       T&             reference;
				//typedef const T*             const_pointer;
				//typedef const T&             const_reference;
				//typedef       std::ptrdiff_t difference_type;

				//typedef Iter
				//
				typedef T               iterator_type;
				typedef typename iterator_traits<T>::iterator_category iterator_category;
				typedef typename iterator_traits<T>::value_type        value_type      ;
				typedef typename iterator_traits<T>::difference_type   difference_type ;
				typedef typename iterator_traits<T>::pointer           pointer         ;
				typedef typename iterator_traits<T>::reference         reference       ;

				//typedef       T              value_type;
				//typedef       T*             pointer;
				//typedef       T&             reference;
				//typedef const T*             const_pointer;
				//typedef const T&             const_reference;
				//typedef       std::ptrdiff_t difference_type;


				//typedef typename ft::random_access_iterator_tag iterator_category;

				RI  (void)        : _ptr(NULL) {};
				RI  (T it)  : _ptr(it) {};
				RI  (reverse_iterator<T> &ptr) : _ptr(ptr)  {};
				//RI  (reference ptr) : _ptr(ptr)  {};
				//RI  (const RI<T> *ptr) : _ptr(ptr)  {};
				~RI (void)                     {};

				RI  &operator = (RI<T> const &to_copy) { this != &to_copy ? this->_ptr = to_copy._ptr : NULL ; return (*this); }


				/* ============================================================== */
				/* ------------------- COMPARAISON OVERLOADS -------------------- */
				/* ============================================================== */

				template <typename U>   bool operator >  (const RI<U> &it) const { return (this->_ptr >  it._ptr); };
				template <typename U>   bool operator <  (const RI<U> &it) const { return (this->_ptr <  it._ptr); };
				template <typename U>   bool operator <= (const RI<U> &it) const { return (this->_ptr <= it._ptr); };
				template <typename U>   bool operator >= (const RI<U> &it) const { return (this->_ptr >= it._ptr); };
				template <typename U> 	bool operator == (const RI<U> &it) const { return (this->_ptr == it._ptr); };
				template <typename U>   bool operator != (const RI<U> &it) const { return (this->_ptr != it._ptr); };

				// Used for comparaison iterator - const iterator
				// TODO explain this black magic
				operator RI <value_type const>() const { return RI <value_type const>(_ptr); }

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
				RI  operator -  (difference_type n) { return (_ptr - n); };
				RI  operator += (difference_type n) { _ptr += n; return (*this); };
				RI  operator -= (difference_type n) { _ptr -= n; return (*this); };

				difference_type operator-(RI const rhs) const {
					return (_ptr - rhs._ptr);
				}

				T base() const {
					return (this->_ptr);
				}

							template <class _It>
			friend bool operator==(const reverse_iterator<_It> &lhs, const reverse_iterator<_It> &rhs);


				/* ============================================================== */
				/* --------------------------- MEMORY --------------------------- */
				/* ============================================================== */

				pointer   operator -> () { return (this->_ptr);  }; // This is bused to access member functions of template types
				reference operator *  () { return (*this->_ptr); };

				reference operator [] (difference_type n) const  {  return (this->_ptr[n]); };
		};

	template <typename T>
		ft::RI<T> operator + (std::ptrdiff_t n, ft::RI<T> const &it) { return (it + n); }


	template <class _It, class _Iter>
	bool operator==(const reverse_iterator<_It> &lhs, const reverse_iterator<_Iter> &rhs) {
		return (lhs.base() == rhs.base());			// --> coder BASE ! renvoie l'iterateur courant !
	}

	/* ============================================================== */
	/* -------------------------- ARCHIVE --------------------------- */
	/* ============================================================== */

	//bool operator <  (const RI it) const { return (this->_ptr <  it._ptr); };
	//bool operator >  (const RI it) const { return (this->_ptr >  it._ptr); };
	//bool operator <= (const RI it) const { return (this->_ptr <= it._ptr); };
	//bool operator >= (const RI it) const { return (this->_ptr >= it._ptr); };
	//bool operator == (const RI it) const { return (this->_ptr == it._ptr); };
	//bool operator != (const RI it) const { return (this->_ptr != it._ptr); };
	// TODO
	//template <typename U> bool operator <  (const RI<U> &it) const { return (this->_ptr <  (U*)&it._ptr); };
	//template <typename U> bool operator >  (const RI<U> &it) const { return (this->_ptr >  (U*)&it._ptr); };
	//template <typename U> bool operator <= (const RI<U> &it) const { return (this->_ptr <= (U*)&it._ptr); };
	//template <typename U> bool operator >= (const RI<U> &it) const { return (this->_ptr >= (U*)&it._ptr); };
	//template <typename U> bool operator == (const RI<U> &it) const { return (this->_ptr == (U*)&it._ptr); };
	//template <typename U> bool operator != (const RI<U> &it) const { return (this->_ptr != (U*)&it._ptr); };
	//// TODO
	// TODO
	//template <typename U> RI  operator +  (const RI<U>it) const { return (this->_ptr + (U*)&it._ptr); };
	//template <typename U> RI  operator -  (const RI<U>it) const { return (this->_ptr - (U*)&it._ptr); };
	//template <typename U> RI  operator += (const RI<U>it) const { this->_ptr += (U*)&it._ptr; return (*this); };
	//template <typename U> RI  operator -= (const RI<U>it) const { this->_ptr -= (U*)&it._ptr; return (*this); };
	// TODO


	//template <typename T>
	//ft::RI<T> operator + (ft::RI<T> const &it,std::ptrdiff_t n ) { return (it + n); }
	//
	//template <typename T>
	//ft::RI<T> operator + (ft::RI<T> const &it) { return (it + n); }


	//template <typename T1, typename T2>
	//ft::RI<T1> operator - (ft::RI<T1> it1, ft::RI<T2> it2) { return (it1._ptr - it2._ptr); } // TODO how the fuck can it access private member _ptr


	//template<class _Iterator>
	//ft::random_access_iterator<_Iterator> operator+(typename ft::random_access_iterator<_Iterator>::difference_type n, ft::random_access_iterator<_Iterator> const &lhs)
	//{
	//return (lhs + n);
	//}
	//
}


#endif




