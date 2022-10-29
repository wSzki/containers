/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:51:38 by wszurkow          #+#    #+#             */
/*   Updated: 2022/10/29 21:36:46 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>

#include "../inc/stack.hpp"
#include "tests.hpp"

#define STACK NS::stack<T>

template <typename U>
void compare(U & a, U & b)
{
	std::cout << "(a == b)       : " << Yel << (a == b) << RCol  << std::endl;
	std::cout << "(a != b)       : " << Yel << (a != b) << RCol  << std::endl;
	std::cout << "(a <  b)       : " << Yel << (a <  b) << RCol  << std::endl;
	std::cout << "(a >  b)       : " << Yel << (a >  b) << RCol  << std::endl;
	std::cout << "(a <= b)       : " << Yel << (a <= b) << RCol  << std::endl;
	std::cout << "(a >= b)       : " << Yel << (a >= b) << RCol  << std::endl;
	std::cout << std::endl;
}

void title(std::string s)
{
	std::cout << Blu;
	std::cout << "=================================" << std::endl;
	std::cout << s  << std::endl;
	std::cout << "=================================" << std::endl;
	std::cout << RCol;
}

void print_stack(STACK &v)
{
	std::cout << "empty   " << " : " << Yel <<  v.empty() << RCol << std::endl;
	std::cout << "size    " << " : " << Yel <<  v.size()  << RCol << std::endl;
	std::cout << "top     " << " : " << Yel <<  v.top()   << RCol << std::endl;
	std:: cout << "---------------------------------" << std::endl;
}

int main(void)
{
	title("Init empty stack");
	STACK st;
	for (int i = 0; i < 10; i++)
	{
		st.push(i);
		st.top();
	}

}
