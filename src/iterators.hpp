/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:41:53 by wszurkow          #+#    #+#             */
/*   Updated: 2022/06/10 16:01:45 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>
#include <iterator>

namespace ft
{
	template< typename Iterator_type >
		struct iterator_traits
		{
			typename Iterator_type::difference_type   difference_type;
			typename Iterator_type::value_type        value_type;
			typename Iterator_type::pointer           pointer;
			typename Iterator_type::reference         reference;
			typename Iterator_type::iterator_category iterator_category;
		};


	// Pointers specialization
	template<typename _Tp>
		struct iterator_traits<_Tp*>
		{
			typedef std::random_access_iterator_tag iterator_category;
			typedef _Tp                             value_type;
			typedef ptrdiff_t                       difference_type;
			typedef _Tp*                            pointer;
			typedef _Tp&                            reference;
		};

	// Const pointers specialization
	template<typename _Tp>
		struct iterator_traits<const _Tp*>
		{
			typedef std::random_access_iterator_tag iterator_category;
			typedef _Tp                             value_type;
			typedef ptrdiff_t                       difference_type;
			typedef const                           _Tp* pointer;
			typedef const                           _Tp& reference;
		};
}
#endif
