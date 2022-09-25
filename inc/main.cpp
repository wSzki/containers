








#include "map.hpp"

#include "pair.hpp"






int main (int ac, char **av)
{

	ft::map<int, int> m;
	ft::pair <int, int> p(1, 42);

	m.insert(p);
	m.clear();

}

