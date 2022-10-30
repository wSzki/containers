/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:51:40 by wszurkow          #+#    #+#             */
/*   Updated: 2022/10/29 18:54:12 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <cstdio>

#include "../inc/vector.hpp"
#include "tests.hpp"

#define VECTOR_SIZE std::cout << "Vector size : " << _vector.size() << std::endl;
#define VECTOR NS::vector<T>

bool step = false;
bool skip_all = false;
void breakpoint()
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

void print_vector(VECTOR &v)
{
	std::cout << "empty         " << " : " << Yel <<  v.empty()    << RCol << std::endl;
	std::cout << "size          " << " : " << Yel <<  v.size()     << RCol << std::endl;
	std::cout << "capacity      " << " : " << Yel <<  v.capacity() << RCol << std::endl;
	std::cout << "max_size      " << " : " << Yel <<  v.max_size() << RCol << std::endl;
	// NOTE front and back segfaults on empty vector on std
	if (v.size() > 3)
	{
		std::cout << std::endl;
		std::cout << "front         " << " : " << Yel <<  v.front()    << RCol << std::endl;
		std::cout << "back          " << " : " << Yel <<  v.back()     << RCol << std::endl;
		std::cout << std::endl;
		std::cout << "vector.at(0)  " << " : " << Yel <<  v.at(0)      << RCol << std::endl;
		std::cout << "vector.at(1)  " << " : " << Yel <<  v.at(1)      << RCol << std::endl;
		std::cout << "vector.at(2)  " << " : " << Yel <<  v.at(2)      << RCol << std::endl;
		std::cout << std::endl;
		std::cout << "vector[0]     " << " : " << Yel <<  v[0]      << RCol << std::endl;
		std::cout << "vector[1]     " << " : " << Yel <<  v[1]      << RCol << std::endl;
		std::cout << "vector[2]     " << " : " << Yel <<  v[2]      << RCol << std::endl;
	}

	std:: cout << "---------------------------------" << std::endl;
	VECTOR::iterator it = v.begin();
	VECTOR::iterator ite = v.end();
	std::cout << "Vector content :" << std::endl;
	if (it == ite)
		std::cout << Yel << "[EMPTY]" << RCol << std::endl;
	else
		while (it != ite)
			std::cout << Yel << *it++ << RCol << std::endl;
	std::cout << std::endl;
	breakpoint();
}


void test_vector(std::string s = NULL)
{
	CLEAR;
	(s == "y") ? step = true : skip_all = true;
	/* ====================================================================== */
	/* ------------------------------- VECTOR ------------------------------- */
	/* ====================================================================== */

	/* .................................................. */
	/* ............... EMPTY VECTOR TESTS ............... */
	/* .................................................. */

	title("Default construct");
	NS::vector<int> v;
	print_vector(v);
	///////////////////////////////

	title("Copy construct");
	NS::vector<int> v2(v);
	print_vector(v2);
	///////////////////////////////

	title("Assignation operator");
	NS::vector<int> v3;
	v3 = v2;
	print_vector(v3);

	///////////////////////////////

	title("Clear empty vector");
	v.clear();
	print_vector(v);

	/* .................................................. */
	/* .......... CREATING VECTOR WITH VALUES ........... */
	/* .................................................. */
	title("Creating vector with values");
	NS::vector<int>v1(10, 42);
	print_vector(v1);

	/* .................................................. */
	/* ................... PUSH BACK .................... */
	/* .................................................. */

	title("Push back 10 elements, then another 10");
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	for (int i = 10; i < 20; i++)
		v1.push_back(i);
	print_vector(v1);

	/* .................................................. */
	/* .................... POP BACK .................... */
	/* .................................................. */

	title("Pop back 5 elements");
	for (int i = 0; i < 5 ; i++)
		v1.pop_back();
	print_vector(v1);

	/* .................................................. */
	/* ...................... SWAP ...................... */
	/* .................................................. */

	title("Push back in an another vector");
	for (int i = 100; i < 110; i++)
		v2.push_back(i);
	print_vector(v2);

	title("Swapping 2 vectors");
	step = false;
	v1.swap(v2);
	std::cout << Gre << "# VECTOR A" << RCol <<std::endl;
	std::cout << Gre << "##########" << RCol <<std::endl;
	print_vector(v1);
	step = true;
	std::cout << Gre << "# VECTOR B" << RCol <<std::endl;
	std::cout << Gre << "##########" << RCol <<std::endl;
	print_vector(v2);

	/* .................................................. */
	/* . COPY CONSTR / ASSIGNATION OF NON EMPTY VECTORS . */
	/* .................................................. */

	title("Assign vector 1 to a new vector");
	VECTOR new_vector = v1;
	print_vector(new_vector);

	title("Copy vector 1 to a new vector");
	VECTOR another_new_vector(v1);
	print_vector(another_new_vector);

	title("Range copy + Inc / Dec");
	VECTOR::iterator it = v1.begin();
	VECTOR::iterator ite = v1.end();


	std::cout << On_Bla << "++(++(it)); it++;" << std::endl;
	++(++(it)); it++;
	std::cout << "--(--(ite)); ite--; ite--;" << std::endl;
	--(--(ite)); ite--; ite--;
	std::cout << RCol << std::endl;

	VECTOR range_vector(it, ite);
	step = false;
	print_vector(range_vector);
	step = true;

	std::cout << "Original vector content was :" << std::endl;
	print_vector(v1);


	/* .................................................. */
	/* ........... VECTOR OPERATOR OVERLOADS ............ */
	/* .................................................. */

	title("Vector operator overloads - Comparing 2 identical vectors");
	VECTOR a(v1);
	VECTOR b(a);
	compare(a, b);

	title("Vector operator overloads - Comparing full with empty vector");
	b.clear();
	compare(a, b);

	title("Vector operator overloads - Comparing 2 non empty vectors");
	for (int i = 0; i < 10; i++)
		b.push_back(42);
	compare(b, a);
	std::cout << Gre << "# VECTOR A" << RCol <<std::endl;
	std::cout << Gre << "##########" << RCol <<std::endl;
	step = false;
	print_vector(a);
	std::cout << Gre << "# VECTOR B" << RCol <<std::endl;
	std::cout << Gre << "##########" << RCol <<std::endl;
	step = true;
	print_vector(b);

	/* .................................................. */
	/* ............... ITERATOR OVERLOADS ............... */
	/* .................................................. */

	title("Iterator overloads - comparing 2 identitcal iterators");
	VECTOR::iterator ite1 = v1.begin();
	VECTOR::iterator ite2 = v1.begin();
	compare(ite1, ite2);

	title("Iterator overloads - comparing 2 diff iterators (a < b)");
	ite2 = v1.end();
	--ite2;
	--ite2;
	compare(ite1, ite2);

	title("Iterator overloads - comparing 2 diff iterators (b < a)");
	ite2 = v1.end();
	--ite2;
	--ite2;
	compare(ite2, ite1);


	title("Iterator overloads '-' '+' '+=' '-='");
	std::cout << "iter           : "<< Yel << *(ite1)       << RCol << std::endl;
	std::cout << "iter +  1      : "<< Yel << *(ite1  +  1) << RCol << std::endl;
	std::cout << "iter +  5      : "<< Yel << *(ite1  +  5) << RCol << std::endl;
	std::cout << "iter += 5      : "<< Yel << *(ite1  += 5) << RCol << std::endl;
	std::cout << "iter += 1      : "<< Yel << *(ite1  += 1) << RCol << std::endl;
	std::cout << "iter -  1      : "<< Yel << *(ite1  -  1) << RCol << std::endl;
	std::cout << "iter -  5      : "<< Yel << *(ite1  -  5) << RCol << std::endl;
	std::cout << "iter -= 5      : "<< Yel << *(ite1  -= 5) << RCol << std::endl;
	std::cout << "iter -= 1      : "<< Yel << *(ite1  -= 1) << RCol << std::endl;
	std::cout << std::endl;



	/* .................................................. */
	/* ..................... INSERT ..................... */
	/* .................................................. */

	title("Insert");
	VECTOR::iterator iter = v1.begin();
	v1.insert(iter, 424242);
	(++(++(iter)));
	v1.insert(iter, 424242);
	iter += 2;
	v1.insert(iter, 424242);
	print_vector(v1);


	/* .................................................. */
	/* ..................... ERASE ...................... */
	/* .................................................. */

	title("Single erase");
	v1.erase(iter);
	--(--(iter));
	v1.erase(iter);
	--(--(iter));
	v1.erase(iter);
	print_vector(v1);

	title("Range erase");
	++iter;
	v1.erase(++iter, v1.end());
	print_vector(v1);


	/* .................................................. */
	/* ................ REVERSE ITERATOR ................ */
	/* .................................................. */

	//title("Reverse iterators");
	//VECTOR::reverse_iterator rit = v1.begin(); // TODO problem
	//rit++;
	//std::cout << *(rit) << std::endl;


	/* .................................................. */
	/* ..................... CLEAR ...................... */
	/* .................................................. */
	title("Clear all vectors");
	v1.clear();
	new_vector.clear();
	another_new_vector.clear();
	step = false;
	print_vector(v1);
	print_vector(new_vector);
	print_vector(another_new_vector);
	step = true;
	breakpoint();
	title("END OF VECTOR TESTS");
	breakpoint();
}

