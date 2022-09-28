




#include "map.hpp"
#include "utils/pair.hpp"

int main ()
{

	ft::map<int, int> m;
	ft::pair<int, int> p1(1, 42);
	ft::pair<int, int> p2(2, 42);
	ft::pair<int, int> p3(3, 42);
	ft::pair<int, int> p4(4, 89);


	//ft::map<int, int>::nodePtr node;
	//ft::map<int, int>::iterator<node> node;


	std::cout << "Size = "<< m.size() << std::endl;
	std::cout << "Is empty = "<<m.empty() << std::endl;
	m.insert(p1);
	//
	std::cout << "Size = "<< m.size() << std::endl;
	std::cout << "Is empty = "<<m.empty() << std::endl;
	m.insert(p1);
	m.insert(p2);
	m.insert(p3);
	m.insert(p4);
	m.insert(p4);
	m.insert(p4);
	m.insert(p4);
	//m.clear();


	std::cout << "Size = "<<     m.size()                << std::endl;
	std::cout << "MaxSize = "<<  m.max_size()            << std::endl;
	std::cout << "Is empty = "<< m.empty()               << std::endl;
	std::cout << "begin: "<<     m.begin()._node->second << std::endl;
	std::cout << "end  : "<<     m.end()._node->second   << std::endl;
	std::cout << "count 1: "<<   m.count(1)              << std::endl;
	std::cout << "count 42: "<<  m.count(42)             << std::endl;



	ft::map<int, int>::iterator it = m.end();

	//m.find(4)->second; // TODO why find return pointer


	ft::map<int, int> m1;
	ft::map<int, int> m2;

	m1.swap(m2);
	std::cout << "swap 1 ok" << std::endl;

	m.clear();
}

