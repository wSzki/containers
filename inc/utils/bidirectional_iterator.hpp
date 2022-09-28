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
	template <class Node, class Pair>
		//https://en.cppreference.com/w/cpp/named_req/BidirectionalIterator
		class bidirectional_iterator
		{
			public:

				typedef Node * NodePtr;
				NodePtr _node;

				BI (void)    { _node = 0 ;        };
				BI (NodePtr n)  { _node = (n)      ;};
				template <class U1, class U2> BI (BI<U1, U2> & bi) { _node = bi._node ; };

				virtual ~BI() {};

				BI & operator =  (BI const &to_copy)
				{
					if (this != &to_copy)
						this->_node = to_copy._node;
					return (*this);
				}

				operator BI <Node const, Pair const>(void) const { return BI<Node const, Pair const>(_node);}

				BI   operator ++ (int)  { BI tmp(*this); operator++(); return (tmp);}
				BI   operator -- (int)  { BI tmp(*this); operator--(); return (tmp);}
				BI & operator ++ (void) { return (*this);}; // TODO need next() and previous()
				BI & operator -- (void) { return (*this);}; // TODO need next() and previous()

				Pair  * operator -> ()       {return (make_pair(_node->first, _node->second));}
				const Pair * operator -> ()  const     {return (make_pair(_node->first, _node->second));}
				Pair  & operator *  ()       {return ((_node->second));}
				const Pair  & operator *  () const {return ((_node->second));}
		};

	template <class U1, class P1, class U2, class P2>bool operator == (ft::BI<U1, P1> &a, ft::BI<U2, P2> &b) { return a._node == b._node; }
	template <class U1, class P1, class U2, class P2>bool operator != (ft::BI<U1, P1> &a, ft::BI<U2, P2> &b) { return a._node != b._node; }
}

#endif
