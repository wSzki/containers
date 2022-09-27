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
//#include <iterator>
#include <iostream>

#include <memory> // TODO something else calls it. WHAT
#include <new>
#include <stdexcept>

//#include "random_access_iterator.hpp"
//#include "reverse_iterator.hpp"

#include "./utils/iterator.hpp"
#include "./utils/enable_if.hpp"
#include "./utils/is_integral.hpp"

#define DISABLE_METHOD_IF_INTEGRAL_PARAMETERS(a) typename ft::enable_if<!ft::is_integral<a>::value, a>::type* = NULL
/*
https://devdocs.io/cpp/container/vector
https://m.cplusplus.com/reference/vector/vector/?kw=vector
https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_vector.h.html
*/

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

				typedef ft::random_access_iterator<value_type>         iterator;
				typedef ft::random_access_iterator<value_type const>   const_iterator;

				typedef ft::reverse_iterator<iterator>        reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>  const_reverse_iterator;

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
				// NOTE Checking rhs n is >= 0 from c++11
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
						if (_capacity == 0)
							_capacity = _size;
						if (_capacity != 0)
							_ptr = _alloc.allocate(_capacity);
						for (size_type i = 0; i < _size; i++)
							_alloc.construct(&(_ptr[i]), (old_vector._ptr)[i] );
					}

				/* ------------------- RANGE CONSTRUCTOR -------------------- */


				//vector (_InputIterator first, _InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<_InputIterator>::value, _InputIterator>::type* = NULL) : _alloc(alloc), _tab(NULL) {
				template <class U>
					vector (
							U first,
							U last,
							DISABLE_METHOD_IF_INTEGRAL_PARAMETERS(U),
							const allocator_type& alloc = allocator_type()
						   ) :
						_ptr(NULL),
						_alloc(alloc){



							size_type	n = 0; //= last - first;=
							for (U it = first; it!= last; it++)
								n++;
							_size = n;
							_capacity = n;
							_ptr = _alloc.allocate(_capacity);
							for (size_type i = 0; i < _size; i++) {
								_alloc.construct(_ptr + i, *(first++));
							}
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
					_alloc    = old_vector._alloc;
					_ptr = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&(_ptr[i]), old_vector._ptr[i] );
					return (*this);
				}





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

				/* ------------------------ RESERVE ------------------------- */
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


				/* ========================================================== */
				/* ------------------------ GETTERS ------------------------- */
				/* ========================================================== */

				size_type size     () const { return (this->_size);               };
				size_type max_size () const { return (_alloc.max_size());         };
				size_type capacity () const { return (this->_capacity);           };
				bool      empty    () const { return (_size <= 0 ? true : false); };

				reference at (size_type n) const {
					if (n >= _size)
						throw std::out_of_range("vector::at() error");
					return *(_ptr + n);
				};

				/* ========================================================== */
				/* ---------------------- MISC METHODS ---------------------- */
				/* ========================================================== */

				/* --------------------- POP PUSH CLEAR --------------------- */
				void pop_back  (void)            { resize(_size - 1); }
				void push_back (value_type val)  { resize(_size + 1, val); }
				void clear     (void)            { while (empty() == false) pop_back(); }


				/* ------------------------- RESIZE ------------------------- */
				// https://cplusplus.com/reference/vector/vector/resize/
				// NOTE - out of range class is handled by std::allocator
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

				/* ------------------ ASSIGN RANGE VERSION ------------------ */

				template <typename U>
					void assign (
							U first,
							U last,
							DISABLE_METHOD_IF_INTEGRAL_PARAMETERS(U)
							)
					{
						size_type n = 0;//last - first; //last = list first == list (list - list)

						for (U it = first; it != last; it++)
							n++;

						U &tmp = first;

						if (n > _capacity)
							reserve(n);
						for (size_type i = 0; i < n; i++)
						{
							_alloc.destroy(_ptr + i);
							_alloc.construct(_ptr + i, *tmp);
							tmp++;
						}
						for (size_type i = n; i < _size; i++)
							_alloc.destroy(_ptr + i);
						_size = n;
					};

				/* ------------------ ASSIGN FILL VERSION ------------------- */
				void assign (size_type n, const value_type& val)
				{
					if (n > _capacity)
						reserve(n);
					for (size_type i = 0; i < n; i++)
					{
						_alloc.destroy(_ptr + i);
						_alloc.construct(_ptr + i, val);
					}
					for (size_type i = n; i < _size; i++)
						_alloc.destroy(_ptr + i);
					_size = n;
				}

				/* -------------------------- SWAP -------------------------- */
				void swap (vector &x) // NOTE .swap() needs a *SHALLOW* copy
				{
					T*              tmp_ptr      = x._ptr;
					size_type       tmp_size     = x._size;
					size_type       tmp_capacity = x._capacity;
					allocator_type  tmp_alloc    = x._alloc;

					x._ptr                       = this->_ptr;
					x._capacity                  = this->_capacity;
					x._size                      = this->_size;
					x._alloc                     = this->_alloc;

					this->_ptr                   = tmp_ptr;
					this->_capacity              = tmp_capacity;
					this->_size                  = tmp_size;
					this->_alloc                 = tmp_alloc;
				};

				/* ---------------------- ERASE SINGLE ---------------------- */
				iterator erase (iterator single_element_to_erase)
				{
					for (iterator it = single_element_to_erase; it != end(); it++)
					{
						_alloc.destroy(&*it);
						if (it != end() - 1)
							_alloc.construct(&*it, *(it + 1));
					}
					_size--;
					return (single_element_to_erase);
				} ;

				/* ---------------------- ERASE RANGE ----------------------- */
				iterator erase (iterator first, iterator last)
				{
					size_type n = last - first;
					for (iterator it = first; it < last; it++)
						_alloc.destroy(&*it);
					for (iterator it = first; (it + n) < end(); it++)
						(_alloc.construct(&(*it), *(it + n)), _alloc.destroy(&*(it + n)));
					_size -= n;
					return (first);
				};

				/* --------------------- INSERT SINGLE ---------------------- */
				iterator insert (iterator position, const value_type& val)
				{
					difference_type index = position - begin();
					insert(position, 1, val);
					return (iterator(begin() + index));
				}

				/* ------------------- INSERT RANGE FILL -------------------- */
				void insert (iterator position, size_type n, const value_type &val) 
				{
					difference_type const diff_position_begin = position - begin();
					resize(_size + n);
					position = begin() + diff_position_begin;
					iterator last_iterator = end();
					iterator end_of_insert_range = end() - n;
					while (end_of_insert_range != position)
						_alloc.construct(&*(--last_iterator), (*(--end_of_insert_range)));
					while (n--)
						_alloc.construct(&*(position++), val);
				}

				/* ----------------- INSERT RANGE ITERATOR ------------------ */

				template <typename U>
					void insert (
							iterator position,
							U first,
							U last,
							DISABLE_METHOD_IF_INTEGRAL_PARAMETERS(U)
							)
					{
						size_type n = 0;
						for (U it = first; it != last; it++)
							n++;

						difference_type const diff_position_begin = position - begin();
						resize(_size + n);
						position = begin() + diff_position_begin;
						iterator last_iterator = end();
						iterator end_of_insert_range = end() - n;
						while (end_of_insert_range != position)
							_alloc.construct(&*(--last_iterator), (*(--end_of_insert_range)));
						while (first != last)
							*position++ = *first++;
					}
		};
		/* ========================================================== */
		/* ----------------------- OVERLOADS ------------------------ */
		/* ========================================================== */
		/* --------------------- NON-MEMBER METHODS --------------------- */
		// NOTE
		// *  @brief  Vector ordering relation.
		// *  @param  __x  A %vector.
		// *  @param  __y  A %vector of the same type as @a __x.
		// *  @return  True iff @a __x is lexicographically less than @a __y.
		// *  This is a total ordering relation.  It is linear in the size of the
		// *  vectors.  The elements must be comparable with @c <.
		// *  See std::lexicographical_compare() for how the determination is made.
		template <typename T, typename U> bool operator <  (const vector<T>&lhs, const vector<U> &rhs) {
			return std::lexicographical_compare(lhs.begin(), lhs.end(),
					rhs.begin(), rhs.end()); }

		// NOTE All these overloads are based on <
		template <typename T, typename U> bool operator >  (const vector<T>&lhs, const vector<U> &rhs) { return (rhs < lhs); };
		template <typename T, typename U> bool operator >= (const vector<T>&lhs, const vector<U> &rhs) { return !(lhs < rhs); };
		template <typename T, typename U> bool operator <= (const vector<T>&lhs, const vector<U> &rhs) { return !(lhs > rhs); };

		/* --------------------- OVERLOAD == != --------------------- */
		//eNOTE
		//*  This is an equivalence relation.  It is linear in the size of the
		//*  vectors.  Vectors are considered equivalent if their sizes are equal,
		//*  and if corresponding elements compare equal.
		// SOURCE : https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_vector.h.html
		template <typename T, typename U> bool operator == (const vector<T>&lhs, const vector<U> &rhs) {
			return ( lhs.size() == rhs.size())
				&& std::equal(lhs.begin(), lhs.end(), rhs.begin()) ;
		};

		// NOTE != operator is negation of ==
		template <typename T, typename U> bool operator != (const vector<T>&lhs, const vector<U> &rhs) { return !(lhs == rhs); };
		}
#endif

