/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:41:53 by wszurkow          #+#    #+#             */
/*   Updated: 2022/09/17 03:44:51 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>
#define RAI random_access_iterator
#define RI reverse_iterator

namespace ft
{

	/* ====================================================== */
	/* --------------------- ITERATORS ---------------------- */
	/* ====================================================== */
	// https://en.cppreference.com/w/cpp/iterator/iterator_tags

	// Iterator tags, used to define which type of iterator is used.
	// Not sure how to use it, a method (not sure which one)
	// returns one of the following empty structs

	struct input_iterator_tag{ };
	struct forward_iterator_tag : public input_iterator_tag{ };
	struct bidirectional_iterator_tag : public forward_iterator_tag{ };
	struct random_access_iterator_tag : public bidirectional_iterator_tag{ };

	// https://cplusplus.com/reference/iterator/iterator/
	// This is a base class template that can be used to derive iterator classes from it.
	// It is not an iterator class and does not provide any of the functionality an iterator is expected to have.
	//
	// This base class only provides some member types, which in fact are not required to be present in any iterator type
	// (iterator types have no specific member requirements), but they might be useful,
	// since they define the members needed for the default iterator_traits class template to generate
	// the appropriate instantiation automatically (and such instantiation is required to be valid for all iterator types).

	template <
		class Category,
			  class T,
			  class Distance  = ptrdiff_t,
			  class Pointer   = T*,
			  class Reference = T& >
				  struct iterator {
					  typedef T         value_type;
					  typedef Distance  difference_type;
					  typedef Pointer   pointer;
					  typedef Reference reference;
					  typedef Category  iterator_category;
				  };

	/* ====================================================== */
	/* ------------------ ITERATOR_TRAITS ------------------- */
	/* ====================================================== */
	// https://code.woboq.org/linux/include/c++/8.2.1/bits/stl_iterator_base_types.h.html
	// https://devdocs.io/cpp/iterator/iterator_traits

	template<typename T>
		struct iterator_traits
		{
			typedef typename T::difference_type   difference_type;
			typedef typename T::value_type        value_type;
			typedef typename T::pointer           pointer;
			typedef typename T::reference         reference;
			typedef typename T::iterator_category iterator_category;
		};

	/* --------------------- // Pointers specialization --------------------- */

	template<typename T>
		struct iterator_traits<T*>
		{
			typedef T                          value_type;
			typedef ptrdiff_t                  difference_type;
			typedef T*                         pointer;
			typedef T&                         reference;
			typedef random_access_iterator_tag iterator_category;
		};

	/* ------------------ // Const pointers specialization ------------------ */

	template<typename T>
		struct iterator_traits<const T*>
		{
			typedef T                          value_type;
			typedef ptrdiff_t                  difference_type;
			typedef const                      T* pointer;
			typedef const                      T& reference;
			typedef random_access_iterator_tag iterator_category;
		};



	/* ========================================================================== */
	/* ------------------------- RANDOM ACCESS ITERATOR ------------------------- */
	/* ========================================================================== */

	// https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator.h.html

	template <typename T>
		class random_access_iterator
		{
			protected:
				T* _ptr;

			public :

				typedef iterator <random_access_iterator_tag, T> Iterator;

				typedef typename Iterator::value_type        value_type;
				typedef typename Iterator::iterator_category iterator_type;
				typedef typename Iterator::difference_type   difference_type;
				typedef typename Iterator::reference         reference;
				typedef typename Iterator::pointer           pointer;

				typedef const T*             const_pointer;
				typedef const T&             const_reference;

				typedef random_access_iterator_tag iterator_category;

				RAI  (void)        : _ptr(NULL) {};
				RAI  (pointer ptr) : _ptr(ptr)  {};

				~RAI (void)                     {};

				RAI  &operator = (RAI const &to_copy) { this != &to_copy ? this->_ptr = to_copy.base() : NULL ; return (*this); }

				/* --------------------------- GETTER --------------------------- */

				T* base() const {return _ptr;}

				/* ------------------- COMPARAISON OVERLOADS -------------------- */

				template <typename U>   bool operator >  (const RAI<U> it) const { return (this->_ptr >  it.base()); };
				template <typename U>   bool operator <  (const RAI<U> it) const { return (this->_ptr <  it.base()); };
				template <typename U>   bool operator <= (const RAI<U> it) const { return (this->_ptr <= it.base()); };
				template <typename U>   bool operator >= (const RAI<U> it) const { return (this->_ptr >= it.base()); };
				template <typename U> 	bool operator == (const RAI<U> it) const { return (this->_ptr == it.base()); };
				template <typename U>   bool operator != (const RAI<U> it) const { return (this->_ptr != it.base()); };

				// NOTE if RAI<T const>, returns const RAI<T const>
				operator random_access_iterator<value_type const>() const { return random_access_iterator<value_type const>(_ptr); }

				/* -------------- INCREMENT / DECREMENT OVERLOADS --------------- */

				// PRE INCREMENT
				RAI &operator ++ (void) { this->_ptr++; return (*this); };
				RAI &operator -- (void) { this->_ptr--; return (*this); };

				// POST INCREMENT
				RAI  operator ++ (int)  { RAI buffer = *this; this->_ptr++; return (buffer); };
				RAI  operator -- (int)  { RAI buffer = *this; this->_ptr--; return (buffer); };

				// INCREMENT /DECREMENT BY N
				RAI  operator +  (ptrdiff_t n) const { return (_ptr + n); };
				RAI  operator -  (ptrdiff_t n) const { return (_ptr - n); };
				RAI  operator += (ptrdiff_t n)       { _ptr += n; return (*this); };
				RAI  operator -= (ptrdiff_t n)       { _ptr -= n; return (*this); };
				//difference_type operator-(RAI const rhs) const { return (_ptr - rhs._ptr); }

				/* --------------------------- MEMORY --------------------------- */

				pointer   operator -> () { return (this->_ptr);  }; // This is used to access member functions of template types
				reference operator *  () { return (*this->_ptr); };
				reference operator [] (difference_type n) const  {  return (this->_ptr[n]); };
		};
	/* ----------------------------- (n +- RAI) ------------------------------ */
	template <typename T>             RAI<T> operator     + (ptrdiff_t n, ft::RAI<T> const &it) { return (it + n); }
	template <typename T>             RAI<T> operator     - (ptrdiff_t n, ft::RAI<T> const &it) { return (it - n); }
	/* ----------------------------- diff size ------------------------------ */
	template <typename T, typename U> ptrdiff_t operator - (const RAI<T> &a , const RAI<U> &b) {return a.base() - b.base();}
	template <typename T, typename U> ptrdiff_t operator + (const RAI<T> &a , const RAI<U> &b) {return a.base() + b.base();}

	// NOTE end random_access_iterator

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


} // NOTE end namepsace ft
#endif
