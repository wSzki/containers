/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:17:38 by wszurkow          #+#    #+#             */
/*   Updated: 2022/06/14 17:24:43 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP
# include <iostream>
# include <cctype>
# include <cstddef>

namespace ft
{
	template< class Iter >
		struct iterator_traits
		{
			typedef typename Iter::iterator_category iterator_category;
			typedef typename Iter::value_type        value_type;
		typedef typename Iter::difference_type   difference_type;
			typedef typename Iter::pointer           pointer;
			typedef typename Iter::reference         reference;
		};

	template< class _Tp >
		struct iterator_traits<_Tp*>
		{
			typedef std::random_access_iterator_tag iterator_category;
			typedef _Tp                             value_type;
			typedef ptrdiff_t                       difference_type;
			typedef _Tp*                            pointer;
			typedef _Tp&                            reference;
		};

	template< class _Tp >
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
