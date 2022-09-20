







#include <iostream>
#include "./tree.hpp"

using namespace ft;

int main (int ac, char **av)
{

	node<int> n;
	tree<int, int> t;

	std::cout << t.root << std::endl;
	std::cout << &t << std::endl;
	std::cout << t.root << std::endl;

	t.insert(42);
	std::cout << t.root << std::endl;

}

