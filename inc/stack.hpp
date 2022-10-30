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

#pragma once

#define STACK_H

#include "vector.hpp"

#define TEMPLATE_A 	template <typename T, class Container >
#define STACK_A ft::stack<T, Container>

#define TEMPLATE_B template <class U1, class U2>
#define STACK_B ft::stack<U1, U2>

namespace ft {
	template <typename T, class Container = ft::vector<T> >
		class stack {
			protected :
				Container c;
			public:
				typedef Container container_type;
				typedef Container Vector;
				typedef typename  Container::value_type      value_type;
				typedef typename  Container::size_type       size_type;
				typedef typename  Container::reference       reference;
				typedef typename  Container::const_reference const_reference;

				explicit stack (const Vector & ref = Vector()) : c(ref)   {}
				stack (const stack  & ref           ) : c(ref.c) {}
				stack & operator=(const stack &ref) { if (this != &ref) c = ref.c;  return (*this); }
				~stack(void) {}

				bool       empty (void)                  const { return (c.empty()); }
				size_type  size  (void)                  const { return (c.size());  }
				void        push (const value_type &val)       { c.push_back(val);   }
				void        pop  (void)                        { c.pop_back();       }

				value_type &top ()       { return (c.back()) ;}
				const value_type &top () const { return (c.back()) ;}

				TEMPLATE_B friend bool operator == (const STACK_B &l, const STACK_B &r);
				TEMPLATE_B friend bool operator != (const STACK_B &l, const STACK_B &r);
				TEMPLATE_B friend bool operator <  (const STACK_B &l, const STACK_B &r);
				TEMPLATE_B friend bool operator >  (const STACK_B &l, const STACK_B &r);
				TEMPLATE_B friend bool operator <= (const STACK_B &l, const STACK_B &r);
				TEMPLATE_B friend bool operator >= (const STACK_B &l, const STACK_B &r);
		};
	TEMPLATE_A	bool operator == (const STACK_A & ref1, const STACK_A & ref2) { return (ref1.c == ref2.c);}
	TEMPLATE_A	bool operator != (const STACK_A & ref1, const STACK_A & ref2) { return (ref1.c != ref2.c);}
	TEMPLATE_A	bool operator <  (const STACK_A & ref1, const STACK_A & ref2) { return (ref1.c <  ref2.c);}
	TEMPLATE_A	bool operator >  (const STACK_A & ref1, const STACK_A & ref2) { return (ref1.c >  ref2.c);}
	TEMPLATE_A	bool operator <= (const STACK_A & ref1, const STACK_A & ref2) { return (ref1.c <= ref2.c);}
	TEMPLATE_A	bool operator >= (const STACK_A & ref1, const STACK_A & ref2) { return (ref1.c >= ref2.c);}
}
