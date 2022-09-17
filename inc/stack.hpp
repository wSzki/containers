/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:05:35 by wszurkow          #+#    #+#             */
/*   Updated: 2022/09/17 16:40:39 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

#include "vector.hpp"

namespace ft {

	template <typename T, class Container = ft::vector<T> > // TODO wtf is Container
		class stack {

			protected :
				Container _vector;

			public:
				typedef Container container_type;
				typedef Container Vector;
				typedef typename  Container::value_type      value_type;
				typedef typename  Container::size_type       size_type;
				typedef typename  Container::reference       reference;
				typedef typename  Container::const_reference const_reference;

				stack (const Vector & ref = Vector()) : _vector(ref)         {}
				stack (const stack  & ref           ) : _vector(ref._vector) {}
				stack & operator=(const stack &ref) { if (this != &ref) _vector = ref._vector;  return (*this); }
				~stack(void) {}

				bool       empty (void)                  const { return (_vector.empty()) ;}
				size_type  size  (void)                  const { return (_vector.size())  ;}
				void push        (const value_type &val)       { _vector.push_back(val); }
				void pop         (void)                        { _vector.pop_back();     }

                      value_type &top ()       { return (_vector.back()) ;}
				const value_type &top () const { return (_vector.back()) ;}

				bool operator == (const stack & ref) const { return (this->_vector == ref._vector);}
				bool operator != (const stack & ref) const { return (this->_vector != ref._vector);}
				bool operator <  (const stack & ref) const { return (this->_vector <  ref._vector);}
				bool operator >  (const stack & ref) const { return (this->_vector >  ref._vector);}
				bool operator <= (const stack & ref) const { return (this->_vector <= ref._vector);}
				bool operator >= (const stack & ref) const { return (this->_vector >= ref._vector);}
		};
}

#endif
