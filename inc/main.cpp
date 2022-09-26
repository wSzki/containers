








#include "map.hpp"

#include "pair.hpp"






int main (int ac, char **av)
{

	ft::map<int, int> m;
	ft::pair<int, int> p1(1, 42);
	ft::pair<int, int> p2(2, 42);
	ft::pair<int, int> p3(3, 42);
	ft::pair<int, int> p4(4, 42);

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
	//m.clear();
	std::cout << "Size = "<< m.size() << std::endl;
	std::cout << "Is empty = "<<m.empty() << std::endl;

}

