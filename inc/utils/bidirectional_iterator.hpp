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

#include <cstddef>
#include "pair.hpp"
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

				typedef Node * NodePtr;

				NodePtr _node;

				BI (void)    { _node = 0 ;        };
				BI (NodePtr n)  { _node = (n)      ;};
				template <class U1> BI (BI<U1> & bi) { _node = bi._node ; };

				virtual ~BI() {};

				BI & operator =  (BI const &to_copy)
				{
					if (this != &to_copy)
						this->_node = to_copy._node;
					return (*this);
				}

				operator BI <Node const>(void) const { return BI<Node const>(_node);}

				BI   operator ++ (int)  { BI tmp(*this); operator++(); return (tmp);}
				BI   operator -- (int)  { BI tmp(*this); operator--(); return (tmp);}

				BI & operator ++ (void) { if (_node  != _node->end) _node = next(_node); return (*this); };
				BI & operator -- (void) {
					if (_node  == _node->end)
						_node = largest_node_from(_node);
					else
						_node = previous(_node);
					return (*this);
				};

				      Node *  operator -> ()       { return _node;  }
				const Node *  operator -> () const { return _node;  }
				      Node &  operator *  ()       { return *_node; }
				const Node &  operator *  () const { return *_node; }


			private:


				NodePtr smallest_node_from(NodePtr node) { while (node->left  != node->end) node = node->left ; return node; }
				NodePtr largest_node_from (NodePtr node) { while (node->right != node->end) node = node->right; return node; }

				NodePtr previous(NodePtr current)
				{
					NodePtr end = current->end;
					if (current->left != end)
						return smallest_node_from(current->left);

					NodePtr parent = current->parent;
					while (parent != NULL && current != parent->left)
					{
						current = parent;
						parent = current->parent;
					}

					if (parent == NULL)
						return end;
					return parent;
				}

				NodePtr next(NodePtr current)
				{
					NodePtr end = current->end;
					if (current->right != end)
						return smallest_node_from(current->right);

					NodePtr parent = current->parent;
					while (parent != NULL && current != parent->right)
					{
						current = parent;
						parent = current->parent;
					}

					if (parent == NULL)
						return end;
					return parent;
				}

		};

	template <class U1, class U2>bool operator == (ft::BI<U1> &a, ft::BI<U2> &b) { return a._node == b._node; }
	template <class U1, class U2>bool operator != (ft::BI<U1> &a, ft::BI<U2> &b) { return a._node != b._node; }
}

#endif
