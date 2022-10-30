/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:20:45 by wszurkow          #+#    #+#             */
/*   Updated: 2022/10/30 14:33:31 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <cstdio>

#include "../inc/map.hpp"
#include "tests.hpp"

#define MAP NS::map<T, T>

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

static void title(std::string s)
{
	std::cout << Blu;
	std::cout << "=================================" << std::endl;
	std::cout << s  << std::endl;
	std::cout << "=================================" << std::endl;
	std::cout << RCol;
}

void function(MAP & m)
{
	std::cout << "empty         " << " : " << Yel <<  m.empty()    << RCol << std::endl;
	std::cout << "size          " << " : " << Yel <<  m.size()     << RCol << std::endl;
	std::cout << "max_size      " << " : " << Yel <<  m.max_size() << RCol << std::endl;
	if (m.size() > 0)
	{
		std::cout << std::endl;
		std::cout << "begin      " << " : " << Yel << *(m.begin()) << RCol << std::endl;
		std::cout << "end      " << " : " << Yel <<  m.end() << RCol << std::endl;

	}

}

void test_map(std::string s = NULL)
{
	CLEAR;
	(s == "y") ? step = true : skip_all = true;
	/* ====================================================================== */
	/* -------------------------------- MAP --------------------------------- */
	/* ====================================================================== */







}

