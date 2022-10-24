/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsz </var/spool/mail/wsz>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:42:28 by wsz               #+#    #+#             */
/*   Updated: 2022/10/24 12:42:46 by wsz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BIDIRECTIONAL_ITERATOR_H__
#define __BIDIRECTIONAL_ITERATOR_H__

#include <cstddef>
#include <iostream>
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
				typedef Node												value_type;
				typedef std::ptrdiff_t									difference_type;
				typedef Node&												reference;
				typedef const Node&										const_reference;
				typedef Node*												pointer;
				typedef const Node*										const_pointer;
				typedef std::bidirectional_iterator_tag					iterator_category;


				NodePtr _node;
				NodePtr _root;
				NodePtr _end;

				BI (void)    { _node = 0 ;_root = 0 ;_end = 0 ;};
				BI (NodePtr n, NodePtr nr, NodePtr ne)  { _node = n; _root = nr ; _end = ne ;};
				template <class U1> BI (BI<U1> & bi) { _node = bi._node ; _root = bi._root; _end = bi._end;};

				virtual ~BI() {};

				BI & operator =  (BI const &to_copy)
				{
					if (this != &to_copy) {
						this->_node = to_copy._node;
						this->_root = to_copy._root;
						this->_end = to_copy._end;
					}
					return (*this);
				}

				operator BI <Node const>(void) const { return BI<Node const>(_node, _root, _end);}

				BI   operator ++ (int)  { BI tmp(*this); operator++(); return (tmp);}
				BI   operator -- (int)  { BI tmp(*this); operator--(); return (tmp);}

				BI & operator ++ (void) {
					if (_node  != _node->end)
						_node = next(_node);
					return (*this);
				};

				BI & operator -- (void) {
					// std::cout << "HELLO : " << _node->first << std::endl;
					if (_node) // addded
					{
						// std::cout << "END: " << _node->end << std::endl;
						if (_node == _end)
						{
							// while (_node->parent != _node->end) // added
								// _node = _node->parent; // added
							_node = largest_node_from(_root);
						// std::cout << "END: " << _node->first << std::endl;
						}
						else
							_node = previous(_node);
					}
					return (*this);
				};

				Node *  operator -> ()       { return _node;  }
				Node &  operator *  ()       { return *_node; }
				const Node *  operator -> () const { return _node;  }
				const Node &  operator *  () const { return *_node; }


			private:

				NodePtr smallest_node_from(NodePtr node) { while (node->left  != node->end && node->left != NULL) node = node->left ; return node; }
				NodePtr largest_node_from (NodePtr node) { while (node->right != node->end && node->right != NULL) node = node->right; return node; }

				NodePtr previous(NodePtr current)
				{
					NodePtr end = current->end;
					if (current->left != end)
						return largest_node_from(current->left);

					NodePtr parent = current->parent;
					while (parent != NULL && current == parent->left)
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
					while (parent != end && current == parent->right)
					{
						current = parent;
						parent = current->parent;
					}

					if (parent == NULL)
						return end;
					return parent;
				}

		};

	TEMPLATE_ bool operator == (const ft::BI<U1> &a, const ft::BI<U2> &b) { return a._node == b._node; }
	TEMPLATE_ bool operator != (const ft::BI<U1> &a, const ft::BI<U2> &b) { return a._node != b._node; }
}

#endif
