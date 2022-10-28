#include <iostream>
#include "palette.hpp"
#include "../inc/vector.hpp"

#define NS ft
#define VECTOR_SIZE std::cout << "Vector size : " << _vector.size() << std::endl;
#define T int
#define VECTOR NS::vector<T>

void print_vector(VECTOR &v)
{
	std::cout << "=================================" << std::endl;
	std::cout << "Vector log" << std::endl;
	std::cout << "=================================" << std::endl;
	std::cout << "empty   " << " : " << Yel <<  v.empty()    << RCol << std::endl;
	std::cout << "size    " << " : " << Yel <<  v.size()     << RCol << std::endl;
	std::cout << "capacity" << " : " << Yel <<  v.capacity() << RCol << std::endl;
	std::cout << "max_size" << " : " << Yel <<  v.max_size() << RCol << std::endl;

	std:: cout << "---------------------------------" << std::endl;
	VECTOR::iterator it = v.begin();
	VECTOR::iterator ite = v.end();
	std::cout  << "Vector content :" << std::endl;
	if (it == ite)
		std::cout << Yel << "[EMPTY]" << RCol << std::endl;
	else
		while (it != ite)
			std::cout << Yel << *it++ << RCol << std::endl;
}

int main()
{
	/* ====================================================================== */
	/* ------------------------------- VECTOR ------------------------------- */
	/* ====================================================================== */

	NS::vector<int> v1;
	print_vector(v1);
	NS::vector<int> v2(v1);
	print_vector(v2);
	NS::vector<int> v3;
	v3 = v2;
	print_vector(v3);

	//NS::vector<int> _vector;
	//std::cout << "EMPTY VECTOR CREATED\n";
	//VECTOR_SIZE;
	//std::cout << "Pushing back 10 element to vector\n";
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	for (int i = 10; i < 20; i++)
		v1.push_back(i);
	print_vector(v1);

	for (int i = 0; i < 5 ; i++)
		v1.pop_back();
	print_vector(v1);


	//P("Vector size : "); PNL(_vector.size());
	//"NS"::vector<int>::iterator it = _vector.begin();
	//NS::vector<int>::iterator ite = _vector.end();
	//while (it != ite)
	//{
	//std::cout << *it << std::endl;
	//it++;
	//}



}

