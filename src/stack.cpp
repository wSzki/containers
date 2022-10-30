/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:51:38 by wszurkow          #+#    #+#             */
/*   Updated: 2022/10/29 22:05:04 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <cstdio>

#include "../inc/stack.hpp"
#include "tests.hpp"

#define STACK NS::stack<T>

	template <typename U>
static void compare(U & a, U & b)
{
	std::cout << "(a == b)       : " << Yel << (a == b) << RCol  << std::endl;
	std::cout << "(a != b)       : " << Yel << (a != b) << RCol  << std::endl;
	std::cout << "(a <  b)       : " << Yel << (a <  b) << RCol  << std::endl;
	std::cout << "(a >  b)       : " << Yel << (a >  b) << RCol  << std::endl;
	std::cout << "(a <= b)       : " << Yel << (a <= b) << RCol  << std::endl;
	std::cout << "(a >= b)       : " << Yel << (a >= b) << RCol  << std::endl;
	std::cout << std::endl;
}

static bool step = false;
static bool skip_all = false;
static void breakpoint()
{
	if (step == true && skip_all == false)
	{
		std::cout << std::endl;
		std::cout << "PRESS ENTER TO CONTINUE ";
		getchar();
		CLEAR;
	}
}

static void title(std::string s)
{
	std::cout << Yel;
	std::cout << "=================================" << std::endl;
	std::cout << s  << std::endl;
	std::cout << "=================================" << std::endl;
	std::cout << RCol;
}

static void print_stack(STACK &st)
{
	std::cout << "empty        " << " : " << Yel <<  st.empty() << RCol << std::endl;
	std::cout << "size         " << " : " << Yel <<  st.size()  << RCol << std::endl;
	if (st.size() > 0)
		std::cout << "Top of stack  : " << Yel << st.top() << RCol << std::endl;
	else
		std::cout << "Top of stack  : " << Yel << "[EMPTY]" << RCol << std::endl;;
	std::cout << "---------------------------------" << std::endl;
}

void test_stack(std::string s = NULL)
{
	(s == "y") ? step = true : skip_all = true;
	title("Init empty stack");
	STACK st;
	print_stack(st);
	breakpoint();

	title("Pushing 10 elements to stack");
	for (int i = 101; i <= 110; i++)
	{
		st.push(i);
		print_stack(st);
	}
	breakpoint();

	STACK st_copy(st);
	STACK st_copy_copy = st_copy;

	title("Popping 2 elements from stack copy");
	print_stack(st_copy);
	st_copy.pop();
	print_stack(st_copy);
	st_copy.pop();
	print_stack(st_copy);
	breakpoint();

	title("Stack comparaison");
	compare(st, st_copy_copy);
	compare(st, st_copy);
	breakpoint();

	title("Popping everything");
	title("First stack");
	while (st.size() > 0)
	{
		print_stack(st);
		st.pop();
	}
	print_stack(st);
	breakpoint();

	title("Copied stack");
	while (st_copy.size() > 0)
	{
		print_stack(st_copy);
		st_copy.pop();
	}
	print_stack(st_copy);
	breakpoint();

	title("Empty stack compare");
	compare(st, st_copy);
	breakpoint();
}
