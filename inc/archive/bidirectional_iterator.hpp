/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:16:18 by wszurkow          #+#    #+#             */
/*   Updated: 2022/09/27 20:17:15 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BIDIRECTIONAL_ITERATOR_H__
#define __BIDIRECTIONAL_ITERATOR_H__

#include "pair.hpp"
#define TEMPLATE_ template <class U1, class U2>
#define bidirectional_iterator BI
namespace ft
{

	/* ====================================================================== */
	/* --------------------------- BIDIRECTIONAL ---------------------------- */
	/* ====================================================================== */
	template <class Node, class Key, class Value>
		//https://en.cppreference.com/w/cpp/named_req/BidirectionalIterator
		class bidirectional_iterator
		{
			public:

				typedef Node * NodePtr;
				NodePtr _node;
				ft::pair<Key, Value> p;

				BI (void)    { _node = 0 ; p = 0;        };
				BI (NodePtr n)  { _node = (n) ; p = make_pair(n->first, n->second)     ;};
				template <class U1, class U2, class U3> BI (BI<U1, U2, U3> & bi) { _node = bi._node ; };

				virtual ~BI() {};

				BI & operator =  (BI const &to_copy)
				{
					if (this != &to_copy)
						this->_node = to_copy._node;
					return (*this);
				}

				operator BI <Node const, Key const, Value const>(void) const { return BI<Node const, Key const, Value const>(_node);}

				BI   operator ++ (int)  { BI tmp(*this); operator++(); return (tmp);}
				BI   operator -- (int)  { BI tmp(*this); operator--(); return (tmp);}
				BI & operator ++ (void) { return (*this);}; // TODO need next() and previous()
				BI & operator -- (void) { return (*this);}; // TODO need next() and previous()

				ft::pair<Key, Value>  * operator -> () { return &(p); }
				ft::pair<Key, Value>  & operator *  () { return (p);  }

				const ft::pair<Key, Value>  & operator *  ()  const { return (p);  }
				const ft::pair<Key, Value>  * operator -> ()  const { return &(p); }
		};

	template <class U1, class K1, class D1, class U2, class K2, class D2>bool operator == (ft::BI<U1, K1, D1> &a, ft::BI<U2, K2, D2> &b) { return a._node == b._node; }
	template <class U1, class K1, class D1, class U2, class K2, class D2>bool operator != (ft::BI<U1, K1, D1> &a, ft::BI<U2, K2, D2> &b) { return a._node != b._node; }
}

#endif
