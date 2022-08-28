/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:23:13 by wszurkow          #+#    #+#             */
/*   Updated: 2022/06/14 15:13:28 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cctype>
#include <cstddef>
#include <iostream>
#include <iterator>

/*
 ** https://devdocs.io/cpp/container/vector
 ** https://m.cplusplus.com/reference/vector/vector/?kw=vector
 */

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T> >
		class vector {

			public:


				// TYPEDEFS
				typedef T                                     value_type;
				typedef Allocator                             allocator_type;
				typedef T*                                    iterator;
				typedef const T*                               const_iterator;
				typedef std::reverse_iterator<iterator>       reverse_iterator;
				typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
				typedef ptrdiff_t                             difference_type;
				typedef size_t                                size_type;
				typedef typename Allocator::pointer           pointer;
				typedef typename Allocator::const_pointer     const_pointer;
				typedef typename Allocator::reference         reference;
				typedef typename Allocator::const_reference   const_reference;

				// MEMBER FUNCTIONS
				vector()  { std::cout << "Constructor" << std::endl; }
				~vector() { std::cout << "Destructor"  << std::endl; }

				// ITERATORS
				iterator               begin        ()       { return this->iterator; };

				iterator               end          ()       { return iterator(Allocator::end(),   this); };
				reverse_iterator       rbegin       ()       { return reverse_iterator(end());            };
				reverse_iterator       rend         ()       { return reverse_iterator(begin());          };
				const_iterator         begin        () const { return iterator(Allocator::begin(), this); };
				const_iterator         end          () const { return iterator(Allocator::end(),   this); };
				const_reverse_iterator rbegin       () const { return const_reverse_iterator(end());      };
				const_reverse_iterator rend         () const { return const_reverse_iterator(begin());    };

				// CAPACITY
				size_type              size       () const;
				size_type              max_size   () const;
				size_type              capacity   () const;
				bool                   empty      () const;
				void                   resize     (size_type n, value_type val = value_type());
				void                   reserve    (size_type n);

				// ELEMENT ACCESS
				reference              operator[] (size_type n);
				reference              at         (size_type n);
				reference              front      ();
				reference              back       ();
				const_reference        operator[] (size_type n) const;
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

