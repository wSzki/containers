/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:37:28 by wszurkow          #+#    #+#             */
/*   Updated: 2022/09/17 19:06:51 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_H
#define PAIR_H

//https://en.cppreference.com/w/cpp/utility/pair

namespace ft
{
	template <typename T1, typename T2>
		struct pair
		{
			public:
				T1 a;
				T2 b;

				pair (void)      :a(0)  , b(0)   {};
				pair (const T1 a, const T2 b): a(a), b(b) {};
				pair &operator = (const pair& to_copy)
				{
					if (this == &to_copy)
						return ;
					this->a = to_copy.a;
					this->b = to_copy.b;
					return (*this);
				}
				~pair(void){};
		};

	template< class T1, class T2 > pair<T1,T2> make_pair( T1 a, T2 b ) { return (pair<T1, T2>(a, b));}
	template <class T1, class T2> bool operator == ( const pair<T1, T2> & lhs, const pair<T1, T2> & rhs ) { return (lhs.a == rhs.a && lhs.b == rhs.b); }
	template <class T1, class T2> bool operator != ( const pair<T1, T2> & lhs, const pair<T1, T2> & rhs ) { return !(lhs == rhs);  }
	// If lhs.first<rhs.first, returns true. Otherwise, if rhs.first<lhs.first, returns false. Otherwise, if lhs.second<rhs.second, returns true. Otherwise, returns false.
	template <class T1, class T2> bool operator <  ( const pair<T1, T2> & lhs, const pair<T1, T2> & rhs ) {
		if (lhs.a < rhs.a)
			return true;
		else if (rhs.a < lhs.a)
			return false;
		else if (lhs.b < rhs.b)
			return true;
		else
			return false;
	}
	template <class T1, class T2> bool operator <= ( const pair<T1, T2> & lhs, const pair<T1, T2> & rhs ) { return !(rhs < lhs); }
	template <class T1, class T2> bool operator >  ( const pair<T1, T2> & lhs, const pair<T1, T2> & rhs ) { return (rhs < lhs); }
	template <class T1, class T2> bool operator >= ( const pair<T1, T2> & lhs, const pair<T1, T2> & rhs ) { return !(lhs < rhs);}

}

#endif
