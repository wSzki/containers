#include <iostream>
#include "palette.hpp"
#include "../inc/vector.hpp"
#include <vector>

#define NS ft
#define VECTOR_SIZE std::cout << "Vector size : " << _vector.size() << std::endl;
#define T int
#define VECTOR NS::vector<T>


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
}

int main()
{
	CLEAR;
	/* ====================================================================== */
	/* ------------------------------- VECTOR ------------------------------- */
	/* ====================================================================== */

	/* .................................................. */
	/* ............... EMPTY VECTOR TESTS ............... */
	/* .................................................. */

	title("Default construct");
	NS::vector<int> v1;
	print_vector(v1);

	///////////////////////////////

	title("Copy construct");
	NS::vector<int> v2(v1);
	print_vector(v2);

	///////////////////////////////

	title("Assignation operator");
	NS::vector<int> v3;
	v3 = v2;
	print_vector(v3);

	///////////////////////////////

	title("Clear empty vector");
	v1.clear();
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
	v1.swap(v2);

	std::cout << Gre << "# VECTOR A" << RCol <<std::endl;
	std::cout << Gre << "##########" << RCol <<std::endl;
	print_vector(v1);
	std::cout << Gre << "# VECTOR B" << RCol <<std::endl;
	std::cout << Gre << "##########" << RCol <<std::endl;
	print_vector(v2);

	/* .................................................. */
	/* . CONSTRUCT / AASSIGNATION OF NON EMPTY VECTORS .. */
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
	print_vector(range_vector);

	std::cout << "Original vector content was :" << std::endl;
	print_vector(v1);

	/* .................................................. */
	/* ..................... INSERT ..................... */
	/* .................................................. */

	//title("Insert"); // TODO SEGFAULT HERE
	//VECTOR::iterator iter = v1.begin();
	////v1.insert(iter, 424242);
	//(++(++(iter)));
	////v1.insert(iter, 424242);
	//iter += 2;
	////v1.insert(iter, 424242);
	//print_vector(v1);


	/* .................................................. */
	/* ..................... ERASE ...................... */
	/* .................................................. */

	//title("Single erase"); // TODO problem here
	//v1.erase(iter);
	//--(--(iter));
	//v1.erase(iter);
	//print_vector(v1);

	//title("Range erase");
	//v1.erase(--iter, v1.begin());
	//print_vector(v1);


	/* .................................................. */
	/* ................ REVERSE ITERATOR ................ */
	/* .................................................. */

	title("Reverse iterators");
	VECTOR::reverse_iterator rit = v1.begin(); // TODO problem
	rit++;
	std::cout << *(rit) << std::endl;


	/* .................................................. */
	/* ..................... CLEAR ...................... */
	/* .................................................. */

	title("Clear all vectors");
	v1.clear();
	new_vector.clear();
	another_new_vector.clear();
	print_vector(v1);
	print_vector(new_vector);
	print_vector(another_new_vector);

}

