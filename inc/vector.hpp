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
				typedef ft::random_access_iterator<T>         const_iterator;

				typedef std::reverse_iterator<iterator>       reverse_iterator;
				typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

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
						const T &value = T(),
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
				vector (vector &old_vector) :
					_ptr      (NULL),
					_alloc    (old_vector._alloc),
					_capacity (old_vector._capacity),
					_size     (old_vector._size) {
						_ptr = _alloc.allocate(_capacity);
						for (size_type i = 0; i < _size; i++)
							_alloc.construct(&(_ptr[i]), old_vector._ptr[i] );
					}

				/* ----------------------- DESTRUCTOR ----------------------- */
				~vector() {
					clear();
					if (_capacity > 0)
						_alloc.deallocate(_ptr, _capacity);
					_capacity = 0;
				}

				/* ========================================================== */
				/* ----------------------- OVERLOADS ------------------------ */
				/* ========================================================== */

				reference       operator [] (const size_type n)       { return (*_ptr + n); };
				const_reference operator [] (const size_type n) const { return (*_ptr + n); };

				/* ========================================================== */
				/* -------------------- ITERATOR METHODS -------------------- */
				/* ========================================================== */

				iterator       begin  ()       { return iterator(this->_ptr);               };
				iterator       end    ()       { return iterator(this->_ptr + this->_size); };
				const_iterator begin  () const { return iterator(this->_ptr);               };
				const_iterator end    () const { return iterator(this->_ptr + this->_size); };

				// TODO still in std
				reverse_iterator       rbegin ()       { return reverse_iterator(end());         };
				reverse_iterator       rend   ()       { return reverse_iterator(begin());       };
				const_reverse_iterator rbegin () const { return const_reverse_iterator(end());   };
				const_reverse_iterator rend   () const { return const_reverse_iterator(begin()); };

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

				/* ========================================================== */
				/* ---------------------- MISC METHODS ---------------------- */
				/* ========================================================== */

				void clear() {
					while (empty() == false)
						pop_back();
				}

				/* ========================================================== */
				/* -------------------------- TODO -------------------------- */
				/* ========================================================== */

				void reserve(size_type n) { // TODO
					if (n > max_size())
						std::length_error("vector::reserve error");
					value_type *tmp(_ptr);
				};

				void pop_back (void) { if (_size > 0) _alloc.destroy(_ptr + _size - 1); _size--; }

				void push_back (value_type val) { // TODO
					if (_size == _capacity)
					{
					}
				}

				// https://cplusplus.com/reference/vector/vector/resize/
				// Note - out of range class ion is handled by std::allocator
				void resize (size_type n, value_type val = value_type())
				{
					if (n == _capacity)
						return ;
					if (n < _size)
						while (n < _size)
							pop_back();
					else
					{
						// TODO memory management
						while (n > _size)
							push_back(val);
					}
				}

				/* ========================================================== */
				/* -------------------------- OLD --------------------------- */
				/* ========================================================== */

				// ELEMENT ACCESS
				//reference              operator[] (size_type n);
				reference              front      ();
				reference              back       ();
				//const_reference        operator[] (size_type n) const;
				const_reference        front      ()            const;
				const_reference        back       ()            const;

		};
}
#endif

