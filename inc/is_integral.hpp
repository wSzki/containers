/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:30:28 by wszurkow          #+#    #+#             */
/*   Updated: 2022/09/13 21:30:32 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _IS_INTEGRAL_HPP_
# define _IS_INTEGRAL_HPP_

namespace ft {
	template <class T> struct is_integral { static const bool value = false; };

	template <> struct is_integral<bool>               { static const bool value = true; };
	template <> struct is_integral<char>               { static const bool value = true; };
	template <> struct is_integral<signed char>        { static const bool value = true; };
	template <> struct is_integral<unsigned char>      { static const bool value = true; };
	template <> struct is_integral<wchar_t>            { static const bool value = true; };
	template <> struct is_integral<short>              { static const bool value = true; };
	template <> struct is_integral<int>                { static const bool value = true; };
	template <> struct is_integral<long>               { static const bool value = true; };
	template <> struct is_integral<long long>          { static const bool value = true; };
	template <> struct is_integral<unsigned short>     { static const bool value = true; };
	template <> struct is_integral<unsigned int>       { static const bool value = true; };
	template <> struct is_integral<unsigned long>      { static const bool value = true; };
	template <> struct is_integral<unsigned long long> { static const bool value = true; };
}

#endif

