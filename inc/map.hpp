/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:48:47 by wszurkow          #+#    #+#             */
/*   Updated: 2022/09/20 19:10:28 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <functional> //std::less
#include <utility> //std::pair
#include <memory> //std::allocator

#include "iterator.hpp"

// TODO ? https://en.cppreference.com/w/cpp/container/map/value_compare

namespace ft
{
	template <
		class Key,                                             \
		class T,                                               \
		class Compare = std::less<Key>,                        \
		class Alloc = std::allocator<std::pair<const Key, T> > \
		>
		class map {
			public :
				typedef          Key                                                  key_type;
				typedef          T                                                    mapped_type;
				typedef          std::pair<const key_type, mapped_type>               value_type;

				typedef          Compare                                              key_compare;

				typedef          Alloc                                                allocator_type;
				typedef typename Alloc::reference                                     reference;
				typedef typename Alloc::pointer                                       pointer;
				typedef typename Alloc::const_reference                               const_reference;
				typedef typename Alloc::const_pointer                                 const_pointer;

				typedef          ft::random_access_iterator<value_type>               iterator;
				typedef          ft::random_access_iterator<const value_type>         const_iterator;

				typedef          ft::reverse_iterator<iterator>                       reverse_iterator;
				typedef          ft::reverse_iterator<const_iterator>                 const_reverse_iterator;

				typedef          std::ptrdiff_t                                       difference_type;
				typedef          std::size_t                                          size_type;

			protected :
				key_compare    _comp;
				allocator_type _alloc;


			public:

				/* ========================================================== */
				/* ---------------------- CONSTRUCTOR ----------------------- */
				/* ========================================================== */
				/* ------------------ DEFAULT CONSTRUCTOR ------------------- */
				explicit map ( \
						const key_compare    & comp  = key_compare(),   \
						const allocator_type & alloc = allocator_type() \
						) :
					_comp(comp),
					_alloc(alloc)
			{}; // TODO

				/* ------------------- RANGE CONSTRUCTOR -------------------- */
				template <class InputIterator>
					map ( \
							InputIterator first, \
							InputIterator last, \
							const key_compare& comp     = key_compare(), \
							const allocator_type& alloc = allocator_type() \
						) :
						_comp(comp),
						_alloc(alloc)
			{}; // TODO

				/* -------------------- COPY CONSTRUCTOR -------------------- */
				map (const map& to_copy) : _comp(to_copy._comp), _alloc(to_copy._alloc) {}; //TODO

				/* ----------------------- DESTRUCTOR ----------------------- */
				~map(void){};

				/* ----------------------- OVERLOAD = ----------------------- */
				map& operator =( const map& other ) {}; // TODO


				/* ========================================================== */
				/* --------------------- ELEMENT ACCESS --------------------- */
				/* ========================================================== */

				// Returns a reference to the mapped value of the element with key equivalent to key. If no such element exists, an exception of type std::out_of_range is thrown.
				T& at( const Key& key );
				const T& at( const Key& key ) const;

				// Returns a reference to the value that is mapped to a key equivalent to key, performing an insertion if such key does not already exist.
				T& operator[]( const Key& key );

				/* ========================================================== */
				/* ----------------------- ITERATORS ------------------------ */
				/* ========================================================== */

				iterator               begin  ();
				iterator               end    ();
				reverse_iterator       rbegin ();
				reverse_iterator       rend   ();

				const_iterator         begin  () const;
				const_iterator         end    () const;
				const_reverse_iterator rbegin () const;
				const_reverse_iterator rend   () const;

				/* ========================================================== */
				/* ------------------------ CAPACITY ------------------------ */
				/* ========================================================== */

				//Checks if the container has no elements, i.e. whether begin() == end().
				bool empty() const;

				//Returns the number of elements in the container, i.e. std::distance(begin(), end()).
				size_type size() const;

				//Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
				size_type max_size() const;

				/* ========================================================== */
				/* ----------------------- MODIFIERS ------------------------ */
				/* ========================================================== */

				//Erases all elements from the container. After this call, size() returns zero. Invalidates any references, pointers, or iterators referring to contained elements. Any past-the-end iterator remains valid.
				void clear();

				//https://en.cppreference.com/w/cpp/container/map/insert
				std::pair<iterator, bool> insert( const value_type& value );
				template< class InputIt > void insert( InputIt first, InputIt last );

				//Removes specified elements from the container.
				//https://en.cppreference.com/w/cpp/container/map/erase
				iterator erase( iterator pos );
				size_type erase( const Key& key );

				//Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.
				//All iterators and references remain valid. The past-the-end iterator is invalidated.
				void swap( map& other );

				/* ========================================================== */
				/* ------------------------- LOOKUP ------------------------- */
				/* ========================================================== */

				//Returns the number of elements with key that compares equivalent to the specified argument, which is either 1 or 0 since this container does not allow duplicates.
				size_type count( const Key& key ) const;

				//) Finds an element with key equivalent to key.
				iterator       find( const Key& key );
				const_iterator find( const Key& key ) const;

				//Returns a range containing all elements with the given key in the container. The range is defined by two iterators, one pointing to the first element that is not less than key and another pointing to the first element greater than key. Alternatively, the first iterator may be obtained with lower_bound(), and the second with upper_bound().
				std::pair<iterator,iterator>             equal_range( const Key& key );
				std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;

				// Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
				iterator lower_bound( const Key& key );
				const_iterator lower_bound( const Key& key ) const;

				//Returns an iterator pointing to the first element that is greater than key.
				iterator upper_bound( const Key& key );
				const_iterator upper_bound( const Key& key ) const;

				/* ========================================================== */
				/* ----------------------- OBSERVERS ------------------------ */
				/* ========================================================== */

				//Returns the function object that compares the keys, which is a copy of this container's constructor argument comp.
				key_compare key_comp() const;

				//Returns a function object that compares objects of type std::map::value_type (key-value pairs) by using key_comp to compare the first components of the pairs.
				//map::value_compare value_comp() const;





		};

#define KTCA template< class Key, class T, class Compare, class Alloc >
#define MAP  const ft::map  <Key,       T,       Compare,       Alloc >

	KTCA bool operator == ( MAP & lhs, MAP & rhs );
	KTCA bool operator != ( MAP & lhs, MAP & rhs );
	KTCA bool operator <  ( MAP & lhs, MAP & rhs );
	KTCA bool operator <= ( MAP & lhs, MAP & rhs );
	KTCA bool operator >  ( MAP & lhs, MAP & rhs );
	KTCA bool operator >= ( MAP & lhs, MAP & rhs );

	KTCA void swap(MAP & lhs, MAP & rhs );
}

#endif
