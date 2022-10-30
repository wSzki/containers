/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/33 14:20:45 by wszurkow          #+#    #+#             */
/*   Updated: 2022/10/33 14:33:31 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <cstdio>

#include "../inc/map.hpp"
#include "../inc/utils/pair.hpp"
#include "tests.hpp"

#define T2 std::string
#define MAP NS::map<T, T2>
#define PAIR NS::pair<T, T2>

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
	std::cout << Red;
	std::cout << "=================================" << std::endl;
	std::cout << s  << std::endl;
	std::cout << "=================================" << std::endl;
	std::cout << RCol;
}

void print_map(MAP & m)
{
	std::cout << "empty         " << " : " << Yel <<  m.empty()    << RCol << std::endl;
	std::cout << "size          " << " : " << Yel <<  m.size()     << RCol << std::endl;
	std::cout << "max_size      " << " : " << Yel <<  m.max_size() << RCol << std::endl;
	if (m.size() > 0)
	{
		std::cout << "Content of map :" << std::endl;
		MAP::iterator it = m.begin();
		MAP::iterator ite = m.end();
		while (it != ite)
		{
			std::cout << Yel <<  it->first << " : " << it->second << RCol << std::endl;
			it++;
		}
	}
	else {
		std::cout << "Content of map :" << std::endl;
		std::cout << "[EMPTY]" << std::endl;
	}
}

void test_map(std::string s = NULL)
{
	CLEAR;
	(s == "y") ? step = true : skip_all = true;
	/* ====================================================================== */
	/* -------------------------------- MAP --------------------------------- */
	/* ====================================================================== */
	{
		title("Init");
		MAP m;
		print_map(m);
		breakpoint();
	}
	{
		title("Pushing 10 elements to map");
		MAP m;
		static int size = 10;
		int tab[10] = {42, 25, 50, 21, 33, 46, 55, 12, 38, 43};
		std::string text[10] = {"apple", "MAP", "banana", "orange", "pear", "cucumber", "candy", "burger", "kebab", "litchi"};
		for (int i = 0; i < size; i++) {
			m[tab[i]] = text[i];
		}
		print_map(m);
		breakpoint();
	}
	{
		title("Const iterator");
		MAP m;
		static int size = 10;
		int tab[10] = {42, 25, 50, 21, 33, 46, 55, 12, 38, 43};
		std::string text[10] = {"apple", "MAP", "banana", "orange", "pear", "cucumber", "candy", "burger", "kebab", "litchi"};
		std::cout << "Content of map with const iterators : " << std::endl;
		for (int i = 0; i < size; i++) {
			m[tab[i]] = text[i];
		}
		MAP::const_iterator cit = m.begin();
		MAP::const_iterator cite = m.end();
		while (cit != cite)
		{
			std::cout << cit->first << " : " << cit->second << std::endl;
			cit++;
		}
		breakpoint();
	}
	{
		title("Reverse iterator");
		MAP m;
		static int size = 10;
		int tab[10] = {42, 25, 50, 21, 33, 46, 55, 12, 38, 43};
		std::string text[10] = {"apple", "MAP", "banana", "orange", "pear", "cucumber", "candy", "burger", "kebab", "litchi"};
		std::cout << "Content of map with const iterators : " << std::endl;
		for (int i = 0; i < size; i++) {
			m[tab[i]] = text[i];
		}
		MAP::reverse_iterator rit = m.rbegin();
		MAP::reverse_iterator rite = m.rend();
		while (rit != rite)
		{
			std::cout << rit->first << " : " << rit->second << std::endl;
			rit++;
		}
		breakpoint();
	}
	{
		title("Insert pairs");
		MAP m;
		static int size = 10;
		int tab[10] = {42, 25, 50, 21, 33, 46, 55, 12, 38, 43};
		std::string text[10] = {"apple", "MAP", "banana", "orange", "pear", "cucumber", "candy", "burger", "kebab", "litchi"};
		for (int i = 0; i < size; i++) {
			m.insert(PAIR(tab[i], text[i]));
		}
		print_map(m);
		breakpoint();
	}
	{
		title("Insert Pairs II");
		MAP m;
		NS::pair<NS::map<T, T2>::iterator, bool> ret = m.insert(PAIR(101, "INSERTED VALUE"));
		std::cout << "Inserted key : " << ret.first->first <<  std::endl;
		std::cout << "Success?" << " : " << ret.second << std::endl;
		static int size = 10;
		int tab[10] = {42, 25, 50, 21, 33, 46, 55, 12, 38, 43};
		std::string text[10] = {"apple", "MAP", "banana", "orange", "pear", "cucumber", "candy", "burger", "kebab", "litchi"};
		for (int i = 0; i < size; i++) {
			m.insert(PAIR(tab[i], text[i]));
		}
		print_map(m);
		breakpoint();

		title("Range copy");
		MAP::iterator it = m.begin();
		MAP::iterator ite = m.end();
		MAP m2(it, ite);
		print_map(m2);
		breakpoint();


		title("Erase single");
		std::cout << "########## BEFORE" << std::endl;
		print_map(m);

		m.erase(42);
		m.erase(25);
		m.erase(m.begin(), ++(++(++(++(m.begin())))));
		m.erase(--(--m.end()));

		std::cout << "########### AFTER" << std::endl;
		print_map(m);
		breakpoint();

		title("Erase all range");
		std::cout << "########## BEFORE" << std::endl;
		print_map(m);
		m.erase(m.begin(), m.end());
		std::cout << "########### AFTER" << std::endl;
		print_map(m);
		breakpoint();
	}
	{
		title("Find");
		MAP m;
		static int size = 10;
		int tab[10] = {42, 25, 50, 21, 33, 46, 55, 12, 38, 43};
		std::string text[10] = {"apple", "MAP", "banana", "orange", "pear", "cucumber", "candy", "burger", "kebab", "litchi"};
		std::cout << "Content of map with const iterators : " << std::endl;
		for (int i = 0; i < size; i++) {
			m[tab[i]] = text[i];
		}
		MAP::iterator found = m.find(42);
		MAP::iterator not_found = m.find(777);
		std::cout << "Find key '42' result  : " << found->first << " : "    << found->second << std::endl;
		std::cout << "Is not_found == end?  : "  << ((not_found  == m.end()) ?  "yes"         :  "no") << std::endl;
		breakpoint();
	}
	{
		title("Count");
		MAP m;
		static int size = 10;
		int tab[10] = {42, 25, 50, 21, 33, 46, 55, 12, 38, 43};
		std::string text[10] = {"apple", "MAP", "banana", "orange", "pear", "cucumber", "candy", "burger", "kebab", "litchi"};
		std::cout << "Content of map with const iterators : " << std::endl;
		for (int i = 0; i < size; i++) {
			m[tab[i]] = text[i];
		}
		std::cout << "Is 33 a key in map? : ";
		std::cout << (m.count(33) ? "yes" : "no");
		std::cout << std::endl;
		std::cout << "Is 77 a key in map? : ";
		std::cout << (m.count(77) ? "yes" : "no");
		std::cout << std::endl;
		print_map(m);
		breakpoint();
	}
	{
		title("Range (Lower - Upper Bounds)");
		MAP m;
		static int size = 10;
		int tab[10] = {42, 25, 50, 21, 33, 46, 55, 12, 38, 43};
		std::string text[10] = {"apple", "MAP", "banana", "orange", "pear", "cucumber", "candy", "burger", "kebab", "litchi"};
		std::cout << "Content of map with const iterators : " << std::endl;
		for (int i = 0; i < size; i++) {
			m[tab[i]] = text[i];
		}
		MAP::iterator lower = m.lower_bound(7);
		MAP::iterator upper = m.upper_bound(47);
		std::cout << "Lower Bound of 7 : " << lower->first << std::endl;
		std::cout << "Upper Bound of 47: " << upper->first << std::endl;
		breakpoint();
	}
	{
		title("Equal");
		MAP m;
		static int size = 10;
		int tab[10] = {42, 25, 50, 21, 33, 46, 55, 12, 38, 43};
		std::string text[10] = {"apple", "MAP", "banana", "orange", "pear", "cucumber", "candy", "burger", "kebab", "litchi"};
		std::cout << "Content of map with const iterators : " << std::endl;
		for (int i = 0; i < size; i++) {
			m[tab[i]] = text[i];
		}
		NS::pair<MAP::iterator, MAP::iterator> ret;
		ret = m.equal_range(33);
		std::cout << "Lower bound points to : ";
		std::cout << ret.first->first << " : " << ret.first->second << std::endl;
		std::cout << "Upper bound points to : ";
		std::cout << ret.second->first << " : " << ret.second->second << std::endl;;
		breakpoint();
	}

	title("Swap");
	MAP m1;
	static int size = 10;
	int tab[10] = {42, 25, 50, 21, 33, 46, 55, 12, 38, 43};
	std::string text[10] = {"apple", "MAP", "banana", "orange", "pear", "cucumber", "candy", "burger", "kebab", "litchi"};
	std::cout << "Content of map with const iterators : " << std::endl;
	for (int i = 0; i < size; i++) {
		m1[tab[i]] = text[i];
	}

	MAP m2;
	int tab2[3] = {999, 998, 997};
	std::string text2[3] = {"a", "b", "c"};
	std::cout << "Content of map with const iterators : " << std::endl;
	for (int i = 0; i < 3; i++) {
		m2[tab2[i]] = text2[i];
	}

	std::cout << "Content of m1 before swap" << std::endl;
	print_map(m1);
	std::cout << "Content of m2 before swap" << std::endl;
	print_map(m2);

	m1.swap(m2);

	std::cout << "Content of m1 after swap" << std::endl;
	print_map(m1);
	std::cout << "Content of m2 after swap" << std::endl;
	print_map(m2);

	title("Swapping with empty map");
	MAP m3;

	m2.swap(m3);
	std::cout << "Content of m2 (was full) after swap" << std::endl;
	print_map(m2);
	std::cout << "Content of m3 (was empty) after swap" << std::endl;
	print_map(m3);
	breakpoint();

	title("Different Map Comparaisons");
	std::cout << "##### MAP A" << std::endl;
	print_map(m1);
	std::cout << "##### MAP B" << std::endl;
	print_map(m3);
	compare(m1, m3);
	breakpoint();

	title("Same Map Comparaisons");
	std::cout << "##### MAP A" << std::endl;
	print_map(m1);
	std::cout << "##### MAP B" << std::endl;
	print_map(m1);
	compare(m1, m1);
	breakpoint();


	title("Iterator comparaisons");
	MAP::iterator iter = m1.begin();
	MAP::iterator iter2 = m1.begin();
	++iter2;
	std::cout << "Is iter == iter2 " << (iter == iter2 ? "yes" : "no") << std::endl;
	std::cout << "Is iter != iter2 " << (iter != iter2 ? "yes" : "no") << std::endl;
	--iter2;
	std::cout << "Is iter == iter2 " << (iter == iter2 ? "yes" : "no") << std::endl;
	std::cout << "Is iter != iter2 " << (iter != iter2 ? "yes" : "no") << std::endl;
	breakpoint();
}

