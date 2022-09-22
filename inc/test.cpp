







#include <iostream>
#include "./tree.hpp"
#include "./map.hpp"

using namespace ft;

int main (int ac, char **av)
{


	map<int, int> m ;//{ {1, 10}, {2, 15}, {3, 20}, };
	tree<int, int> t;
	int  val = 42;


	std::cout << &t._root<< std::endl;
	std::cout << &t._current << std::endl;

	t.insert_left(t.getRoot(), 42);


	//node<int> n;
	//tree<int, int> t;

	//std::cout << t.root << std::endl;
	//std::cout << &t << std::endl;
	//std::cout << t.root << std::endl;

	//t.insert(42);
	//std::cout << t.root << std::endl;

}

