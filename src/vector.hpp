/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:23:13 by wszurkow          #+#    #+#             */
/*   Updated: 2022/06/08 16:24:13 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ctype.h>
#include <iostream>

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T>>
		class vector {

			public:
				typedef typename Alloc::reference       reference;
				typedef typename Alloc::pointer         pointer;
				typedef typename Alloc::const_reference const_reference;
				typedef typename Alloc::const_pointer   const_pointer;

			private:
		};

}
