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



				explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
				template <class InputIterator>  map (InputIterator first, InputIterator last,       const key_compare& comp = key_compare(),       const allocator_type& alloc = allocator_type());
				map (const map& x);

		};
}





#endif
