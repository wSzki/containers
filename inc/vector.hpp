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

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
		class vector {

			/* ============================================================== */
			/* -------------------------- TYPEDEFS -------------------------- */
			/* ============================================================== */

			public:
				// TYPEDEFS
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
				/* ----------------------- PUBLIC MEMBERS ----------------------- */
				/* ============================================================== */

			public:

				/* ------------------ DEFAULT CONSTRUCTOR ------------------- */
				vector (Allocator const &alloc = Allocator()) :
					_ptr(NULL),
					_alloc(alloc),
					_capacity(0),
					_size(0) {}

				/* ---------------------   CONSTRUCTOR  --------------------- */
				vector (
						size_type n,
						const T &value = T(),
						const Allocator &alloc = Allocator()
					   ) :
					_ptr(NULL),
					_alloc(alloc),
					_capacity(n),
					_size(n) {
						_ptr = _alloc.allocate(n);
						for (size_type i = 0; i < n; i++)
							_alloc.construct(_ptr + i, value);
					}

				/* ----------------------- DESTRUCTOR ----------------------- */
				~vector() {
					// TODO clear to clean all vars and ptr to NULL;
					_alloc.deallocate(_ptr, _capacity); _capacity = 0;
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
						throw std::out_of_range("at:: index out of range");
					return *(_ptr + n);
				};

				/* ========================================================== */
				/* -------------------------- OLD --------------------------- */
				/* ========================================================== */

				void                   resize     (size_type n, value_type val = value_type());
				void                   reserve    (size_type n);

				// ELEMENT ACCESS
				//reference              operator[] (size_type n);
				reference              front      ();
				reference              back       ();
				//const_reference        operator[] (size_type n) const;
				const_reference        at         (size_type n) const;
				const_reference        front      ()            const;
				const_reference        back       ()            const;

				// MODIFIERS
				void           push_back          (const value_type& val);
				void           pop_back           ();
				iterator       erase              (iterator position);
				iterator       erase              (iterator first, iterator last);
				void           swap               (vector&  x);
				void           clear              ();
				// -- Insert
				iterator insert (iterator position, const value_type& val);              // Single element
				void     insert (iterator position, size_type n, const value_type& val); // Fill elements
				template <class InputIterator>                                           // Range
					void insert (iterator position, InputIterator first, InputIterator last);
				// -- Assign
				void assign     (size_type n, const value_type& val); // Fill elements
				template <class InputIterator>                    // Range of elements
					void assign (InputIterator first, InputIterator last);

				// ALLOCATOR
				allocator_type get_allocator() const;


				// NON MEMBER FUNCTION OVERLOADS
				// TODO ? template <class value_type, class Alloc>
				// TODO ?	void swap (vector<value_type, Alloc>& x, vector<value_type ,Alloc>& y);

				// TEMPLATE SPECIALIZATIONS
				//TODO ? vector<bool> Vector of bool (class template specialization )


			private:


		};

}
#endif

