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

#define TEMPLATE_ template <class U1, class U2>
#define bidirectional_iterator BI
namespace ft
{

	/* ====================================================================== */
	/* --------------------------- BIDIRECTIONAL ---------------------------- */
	/* ====================================================================== */
	template <class Node>
		//https://en.cppreference.com/w/cpp/named_req/BidirectionalIterator
		class bidirectional_iterator
		{
			public:
				Node _node;

				BI (void)      { _node() ; };
				BI (Node n)    {_node = (n);};
				BI (BI & bi)   { _node(bi._node) ; };

				virtual ~BI() {};

				BI & operator =  (BI const &to_copy) const
				{
					if (this != &to_copy)
						this->_node = to_copy._node;
					return (*this);
				}

				operator BI <Node const>(void) const { return BI<Node const>(_node);}

				BI   operator ++ (int)  { BI tmp(*this); operator++(); return (tmp);}
				BI   operator -- (int)  { BI tmp(*this); operator--(); return (tmp);}
				BI & operator ++ (void) { }; // TODO need next() and previous()
				BI & operator -- (void) { }; // TODO need next() and previous()

				Node * operator -> ()       {return (&(_node->data));}
				Node * operator -> () const {return (&(_node->data));}
				Node & operator *  ()       {return ( (_node->data));}
				Node & operator *  () const {return ( (_node->data));}
		};

	template <class U1, class U2>bool operator == (ft::BI<U1> &a, ft::BI<U2> &b) { return a._node == b._node; }
	template <class U1, class U2>bool operator != (ft::BI<U1> &a, ft::BI<U2> &b) { return a._node != b._node; }
}

#endif
