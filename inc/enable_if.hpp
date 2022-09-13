/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:57:12 by wszurkow          #+#    #+#             */
/*   Updated: 2022/09/13 21:31:55 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

//https://www.fluentcpp.com/2018/05/15/make-sfinae-pretty-1-what-value-sfinae-brings-to-code/

//template<bool Condition, typename T = void>
//struct enable_if
//{
//};

//template<typename T>
//struct enable_if<true, T>
//{
//typedef T type;
//};

//template<typename T>
//void f(T x, typename T::type y)
//{
//// ...
//}

//template<typename T>
//void f(T x, typename T::other_type y)
//{
//// ...
//}

//enable_if is a template that takes a boolean Condition and a type T as template parameters.

//If that Condition is true, enable_if has an underlying type called type.
//If that Condition is false, enable_if has no underling type.

//Then invoking an expression that looks like this:

//typename enable_if<a_certain_condition, MyType>::type

//will trigger SFINAE and therefore take away with it all its containing template declaration when a_certain_condition is false. This declaration is then colloquially known to be “SFINAE’d away”.

//But when a_certain_condition is true, all this expression resolves itself into MyType.

//So the expression let’s its containing code enabled if a_certain_condition holds. Hence its name.

namespace ft {

	template <bool Condition, typename T = void>
		struct enable_if
		{};

	template <typename T>
		struct enable_if<true, T>
		{
			typedef T type;
		};
}
#endif
