/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator_test.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:07:54 by wszurkow          #+#    #+#             */
/*   Updated: 2022/08/29 16:10:55 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random_access_iterator.hpp"
#include "palette.hpp"
#include "containers_definitions.hpp"

#include <vector>
#include <iostream>
#include <iterator>
#include <cstdio> // getchar

void test_random_access_iterator_comparaison(void)
{
	ft::RAI<int> it1;
	ft::RAI<int> it2;
	std::vector<int>::iterator stdit1;
	std::vector<int>::iterator stdit2;

	PRINTY("## Random access iterator - comparaison overload test ");
	PRINTR("Address of it1        = " << &it1);
	PRINTB("Address of it2        = " << &it2);
	PRINTR("Value   of it1._ptr   = NULL (default constructor)");
	PRINTB("Value   of it2._ptr   = NULL (default constructor)");
	PRINTG("Result  of it1 <  it2 = " << (it1 <  it2) << " | " << (stdit1 < stdit2));
	PRINTG("Result  of it1 >  it2 = " << (it1 >  it2) << " | " << (stdit1 > stdit2));
	PRINTG("Result  of it1 <= it2 = " << (it1 <= it2) << " | " << (stdit1 <= stdit2));
	PRINTG("Result  of it1 >= it2 = " << (it1 >= it2) << " | " << (stdit1 >= stdit2));
	PRINTG("Result  of it1 == it2 = " << (it1 == it2) << " | " << (stdit1 == stdit2));
	PRINTG("Result  of it1 != it2 = " << (it1 != it2) << " | " << (stdit1 != stdit2));
	CONTINUE;
}

void test_random_access_iterator_comparaison_different_type(void)
{
	//ft::RAI<int> it1;
	//std::vector<char>::iterator it2;

	PRINTY("## Random access iterator - comparaison overload test on different types of iterators ");
	PRINT("/!\\ Comparaison between different types of iterators does not seem to be supported");
	//PRINTR("Address of it1        = " << &it1);
	//PRINTB("Address of it2        = " << &it2);
	//PRINTR("Value   of it1._ptr   = NULL (default constructor)");
	//PRINTB("Value   of it2._ptr   = NULL (default constructor)");
	//PRINTG("Result  of it1 <  it2 = " << (it1 <  it2));
	//PRINTG("Result  of it1 >  it2 = " << (it1 >  it2));
	//PRINTG("Result  of it1 <= it2 = " << (it1 <= it2));
	//PRINTG("Result  of it1 >= it2 = " << (it1 >= it2));
	//PRINTG("Result  of it1 == it2 = " << (it1 == it2));
	//PRINTG("Result  of it1 != it2 = " << (it1 != it2));
	CONTINUE;
}

void test_random_access_iterator_increment_decrement(void)
{
	PRINTY("## Random access iterator - increment/decrement overload tests");
	ft::RAI<int> it;

	PRINTR("Address of it              = " << &it);
	NEWLINE;
	PRINTR("Address of it->_ptr        = " << it.get_ptr());
	PRINTG("Address of (++it)->_ptr    = " << (++it).get_ptr());
	PRINTB("Address of (it++)->_ptr    = " << (it++).get_ptr());
	PRINTB("Address of (it)->_ptr      = " << (it).get_ptr());
	NEWLINE;
	PRINTR("Address of it->_ptr        = " << it.get_ptr());
	PRINTG("Address of (--it)->_ptr    = " << (--it).get_ptr());
	PRINTB("Address of (it--)->_ptr    = " << (it--).get_ptr());
	PRINTB("Address of (it)->_ptr      = " << (it).get_ptr());
	NEWLINE;
	PRINTR("Address of it->_ptr        = " << it.get_ptr());
	PRINTG("Address of (it + 1)->_ptr  = " << (it + 1).get_ptr());
	PRINTG("Address of (it + 5)->_ptr  = " << (it + 5).get_ptr());
	PRINTG("Address of (it - 1)->_ptr  = " << (it - 1).get_ptr());
	PRINTG("Address of (it - 5)->_ptr  = " << (it - 5).get_ptr());
	NEWLINE;
	PRINTR("Address of it->_ptr        = " << it.get_ptr());
	PRINTG("Address of (it += 1)->_ptr = " << (it += 1).get_ptr());
	PRINTG("Address of (it += 5)->_ptr = " << (it += 5).get_ptr());
	PRINTG("Address of (it -= 1)->_ptr = " << (it -= 1).get_ptr());
	PRINTG("Address of (it -= 5)->_ptr = " << (it -= 5).get_ptr());
	CONTINUE;
}

//class foo
//{
	//public :
		//foo() : value(42) {};
		//~foo() {} ;
		//void bar () { PRINT(this->value); }
	//private:
		//int value;
//};

void test_random_access_iterator(void)
{
	NEWLINE;
	PRINTY(" ====================================================================== ");
	PRINTY(" ------------------- RANDOM ACCESS ITERATOR TESTS --------------------- ");
	PRINTY(" ====================================================================== ");
	NEWLINE;

	test_random_access_iterator_comparaison();
	test_random_access_iterator_comparaison_different_type();
	test_random_access_iterator_increment_decrement();
}
