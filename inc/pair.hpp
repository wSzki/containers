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
	template <typename A, typename B>
		class pair
		{
			protected:
				A _a;
				B _b;

				pair (void)      : A()  , B()   {};
				pair (A _a, B _b): A(_a), B(_b) {};
				pair &operator = (const pair& to_copy)
				{
					if (this == &to_copy)
						return ;
					this->A = to_copy._a;
					this->B = to_copy._b;
					return (*this);
				}
				~pair(void){};
		};

	template< class A, class B > pair<A,B> make_pair( A a, B b ) { return (pair<A, B>(a, b));}

	template <class A, class B> bool operator == ( const pair<A, B> & lhs, const pair<A, B> & rhs ) { return (lhs._a == rhs._a && lhs._b == rhs._b); }
	template <class A, class B> bool operator != ( const pair<A, B> & lhs, const pair<A, B> & rhs ) { return !(lhs == rhs);  }
	// If lhs.first<rhs.first, returns true. Otherwise, if rhs.first<lhs.first, returns false. Otherwise, if lhs.second<rhs.second, returns true. Otherwise, returns false.
	template <class A, class B> bool operator <  ( const pair<A, B> & lhs, const pair<A, B> & rhs ) {
		if (lhs._a < rhs._a)
			return true;
		else if (rhs._a < lhs._a)
			return false;
		else if (lhs._b < rhs._b)
			return true;
		else
			return false;
	}
	template <class A, class B> bool operator <= ( const pair<A, B> & lhs, const pair<A, B> & rhs ) { return !(rhs < lhs); }
	template <class A, class B> bool operator >  ( const pair<A, B> & lhs, const pair<A, B> & rhs ) { return (rhs < lhs); }
	template <class A, class B> bool operator >= ( const pair<A, B> & lhs, const pair<A, B> & rhs ) { return !(lhs < rhs);}

}

#endif
