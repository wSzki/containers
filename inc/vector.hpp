/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:55:26 by wszurkow          #+#    #+#             */
/*   Updated: 2022/08/29 18:55:27 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cctype>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <iostream>

#include <memory> // TODO something else calls it. WHAT
#include <new>
#include <stdexcept>

#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"

/*
https://devdocs.io/cpp/container/vector
https://m.cplusplus.com/reference/vector/vector/?kw=vector
https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_vector.h.html
*/

// 1. allocate.
// 2. construc
// 3. destroy
// 4.deallocate
//
// TODO
// reverse_iterator
// clear
// push_back
// pop_back
// reserve

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
		class vector {

			/* ============================================================== */
			/* -------------------------- TYPEDEFS -------------------------- */
			/* ============================================================== */

			public:
				typedef T                                     value_type;
				typedef Allocator                             allocator_type;

				typedef ft::random_access_iterator<T>         iterator;
				typedef ft::random_access_iterator<const T>   const_iterator;

				typedef ft::reverse_iterator<iterator>       reverse_iterator; // TODO replace with ft
				typedef ft::reverse_iterator<const_iterator> const_reverse_iterator; // TODO replace with ft

				typedef ptrdiff_t                             difference_type;
				typedef size_t                                size_type;

				typedef typename Allocator::pointer           pointer;
				typedef typename Allocator::const_pointer     const_pointer;
				typedef typename Allocator::reference         reference;
				typedef typename Allocator::const_reference   const_reference;

				/* ============================================================== */
				/* ---------------------- PRIVATE MEMBERS ----------------------- */
				/* ============================================================== */

			private:
				value_type     *_ptr;
				allocator_type _alloc;
				size_type      _capacity;
				size_type      _size;

				/* ============================================================== */
				/* -----------------------  CONSTRUCTORS  ----------------------- */
				/* ============================================================== */

			public:

				/* ------------------ DEFAULT CONSTRUCTOR ------------------- */
				vector (Allocator const &alloc = Allocator()) :
					_ptr      (NULL),
					_alloc    (alloc),
					_capacity (0),
					_size     (0) {}

				/* ---------------------   CONSTRUCTOR  --------------------- */
				// Checking that n is >= 0 from c++11
				vector (
						size_type n,
						const value_type &value = value_type(),
						const Allocator &alloc = Allocator()
					   ) :
					_ptr      (NULL),
					_alloc    (alloc),
					_capacity (n),
					_size     (n) {
						_ptr = _alloc.allocate(n);
						for (size_type i = 0; i < n; i++)
							_alloc.construct(_ptr + i, value);
					}

				/* -------------------- COPY CONSTRUCTOR -------------------- */
				vector (const vector &old_vector) :
					_ptr      (NULL),
					_alloc    (old_vector._alloc),
					_capacity (old_vector._capacity),
					_size     (old_vector._size) {
						_ptr = _alloc.allocate(_capacity);
						for (size_type i = 0; i < _size; i++)
							_alloc.construct(&(_ptr[i]), old_vector._ptr[i] );
					}

				/* ----------------------- DESTRUCTOR ----------------------- */
				~vector(void) {
					clear();
					if (_capacity > 0)
						_alloc.deallocate(_ptr, _capacity);
					_capacity = 0;
				}

				/* ---------------- ASSIGNATION CONSTRUCTOR ----------------- */

				vector & operator = (const vector& old_vector) {
					if (this == &old_vector)
						return (*this);
					this->~vector(); // this-> is needed for destructor call
					_size     = old_vector._size;
					_capacity = old_vector._capacity;
					//_alloc    = old_vector._alloc;
					_ptr = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&(_ptr[i]), old_vector._ptr[i] );
					return (*this);
				}


				/* ========================================================== */
				/* ----------------------- OVERLOADS ------------------------ */
				/* ========================================================== */

				bool operator >  (const vector v) const { return (this->_ptr >  v._ptr); };
				bool operator <= (const vector v) const { return (this->_ptr <= v._ptr); };
				bool operator >= (const vector v) const { return (this->_ptr >= v._ptr); };
				bool operator != (const vector v) const { return (this->_ptr != v._ptr); };

				// *  @brief  Vector ordering relation.
				// *  @param  __x  A %vector.
				// *  @param  __y  A %vector of the same type as @a __x.
				// *  @return  True iff @a __x is lexicographically less than @a __y.
				// *  This is a total ordering relation.  It is linear in the size of the
				// *  vectors.  The elements must be comparable with @c <.
				// *  See std::lexicographical_compare() for how the determination is made.
				bool operator <  (const vector v) const {
					return std::lexicographical_compare(this->begin(), this->end(),
							v.begin(), v.end()); }

				//*  This is an equivalence relation.  It is linear in the size of the
				//*  vectors.  Vectors are considered equivalent if their sizes are equal,
				//*  and if corresponding elements compare equal.
				// SOURCE : https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_vector.h.html
				bool operator == (const vector v) const {
					return ( this->size() == v.size())
						&& std::equal(this->begin(), this->end(), v.begin()) ;
				};

				/* ========================================================== */
				/* -------------------- ITERATOR METHODS -------------------- */
				/* ========================================================== */

				iterator       begin  ()       { return iterator(this->_ptr);               };
				iterator       end    ()       { return iterator(this->_ptr + this->_size); };
				const_iterator begin  () const { return const_iterator(this->_ptr);               };
				const_iterator end    () const { return const_iterator(this->_ptr + this->_size); };

				// TODO still in std
				reverse_iterator       rbegin ()       { return reverse_iterator(end());         };
				reverse_iterator       rend   ()       { return reverse_iterator(begin());       };
				const_reverse_iterator rbegin () const { return const_reverse_iterator(end());   };
				const_reverse_iterator rend   () const { return const_reverse_iterator(begin()); };


				/* ========================================================== */
				/* --------------------- MEMORY ACCESS ---------------------- */
				/* ========================================================== */

				reference       front ()       { return *(_ptr);             };
				reference       back  ()       { return *(_ptr + _size - 1); };
				const_reference front () const { return *(_ptr);             };
				const_reference back  () const { return *(_ptr + _size - 1); };

				reference       operator [] (const size_type n)       { return *(_ptr + n); };
				const_reference operator [] (const size_type n) const { return *(_ptr + n); };


				/* ========================================================== */
				/* ------------------------ GETTERS ------------------------- */
				/* ========================================================== */

				size_type size     () const { return (this->_size);               };
				size_type max_size () const { return (_alloc.max_size());         };
				size_type capacity () const { return (this->_capacity);           };
				bool      empty    () const { return (_size <= 0 ? true : false); };

				reference at (size_type n) {
					if (n >= _size)
						throw std::out_of_range("vector::at() error");
					return *(_ptr + n);
				};

				reference at (size_type n) const {
					if (n >= _size)
						throw std::out_of_range("vector::at() error");
					return *(_ptr + n);
				};


				/* ========================================================== */
				/* ---------------------- MISC METHODS ---------------------- */
				/* ========================================================== */

				void pop_back  (void)            { resize(_size - 1); }
				void push_back (value_type val)  { resize(_size + 1, val); }
				void clear     (void)            { while (empty() == false) pop_back(); }

				void reserve(size_type n) {
					if (n > max_size())
						std::length_error("vector::reserve error");
					if (n <= _capacity)
						return ;
					else {
						T *new_ptr = _alloc.allocate(n);

						for (size_type i = 0; i < _size; i++) {
							_alloc.construct(&new_ptr[i], _ptr[i]);
							_alloc.destroy(&_ptr[i]);
						}
						_alloc.deallocate(_ptr, _capacity);
						_ptr = new_ptr;
						_capacity = n;
					}
				};

				// https://cplusplus.com/reference/vector/vector/resize/
				// Note - out of range class ion is handled by std::allocator
				void resize(size_type n, value_type val = value_type()) { // TODO check val"?"
					if (n == _size) return ;
					if (n < _size && _size > 0)
					{
						while (n < _size && _size > 0)
						{
							_alloc.destroy(_ptr + _size - 1);
							_size--;
						}
					}
					if (n > _size)
					{
						if      (n >  _capacity * 2) reserve(n);
						else if (n <= _capacity * 2) reserve(_capacity * 2);
						for (size_type i = _size; i < n; i++)
							_alloc.construct(&(_ptr[i]), val);
						_size = n;
					};

				}

				/* ========================================================== */
				/* -------------------------- TODO -------------------------- */
				/* ========================================================== */


				iterator erase (iterator single_element_to_erase) {
					for (iterator it = single_element_to_erase; it != end(); it++)
					{
						_alloc.destroy(it);
						if (it != end() - 1)
							_alloc.construct(it, *(it + 1));
					}
					_size--;
					return (single_element_to_erase);
				} ;


				iterator erase (iterator first, iterator last) {


				} ; // TODO range


				//void assign (size_type n, const value_type& val) {
				//size_type i = 0;
				//if (_capacity < n)
				//i = 1;
				//clear();
				//if (i)
				//resize(n);
				//for (size_type it = 0; it != n; it++) {
				//_alloc.construct(_tab + it, val);
				//}
				//_size = n;
				//}




				/* ========================================================== */
				/* -------------------------- OLD --------------------------- */
				/* ========================================================== */

				// ELEMENT ACCESS

		};
}
#endif

