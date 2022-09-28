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
// NOTE this file is completed

#define PAIR_REF_ const pair<U1, U2> &
#define TEMPLATE_ template <class U1, class U2>

namespace ft
{
	template <typename T1, typename T2>
		struct pair
		{
			typedef T1 first_type;
			typedef T2 second_type;

			first_type  first;
			second_type second;

			pair          ( void )                     { first = 0       ; second = 0;        }
			pair          ( const T1& x, const T2& y ) : first(x)       , second(y)        {}
			TEMPLATE_ pair( PAIR_REF_ p )              { first = p.first ; second = p.second; }

			TEMPLATE_ pair &operator = (const pair<U1, U2>& to_copy)
			{
				if (this != &to_copy)
				{
					this->first  = to_copy.first;
					this->second = to_copy.second;
				}
				return (*this);
			}
			~pair(void){};
		};

	TEMPLATE_ pair<U1, U2> make_pair(U1 first, U2 second) {return pair<U1, U2>(first, second) ;};

	TEMPLATE_ bool operator == ( PAIR_REF_ lhs, PAIR_REF_ rhs ) { return  (lhs.first == rhs.first && lhs.second == rhs.second); }
	TEMPLATE_ bool operator != ( PAIR_REF_ lhs, PAIR_REF_ rhs ) { return !(lhs == rhs);                                         }
	TEMPLATE_ bool operator <= ( PAIR_REF_ lhs, PAIR_REF_ rhs ) { return !(rhs < lhs);                                          }
	TEMPLATE_ bool operator >  ( PAIR_REF_ lhs, PAIR_REF_ rhs ) { return  (rhs < lhs);                                          }
	TEMPLATE_ bool operator >= ( PAIR_REF_ lhs, PAIR_REF_ rhs ) { return !(lhs < rhs);                                          }
	// If lhs.first<rhs.first, returns true. Otherwise, if rhs.first<lhs.first, returns false. Otherwise, if lhs.second<rhs.second, returns true. Otherwise, returns false.
	TEMPLATE_ bool operator <  ( PAIR_REF_ lhs, PAIR_REF_ rhs ) {
		if      (lhs.first  < rhs.first)  return true;
		else if (rhs.first  < lhs.first)  return false;
		else if (lhs.second < rhs.second) return true;
		else                              return false;
	}
}

#endif
