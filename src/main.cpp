#include "random_access_iterator.hpp"
#include "palette.hpp"
#include "containers_definitions.hpp"
#include "vector.hpp"

//using namespace ft;

//#include "vector.hpp"
#include <vector>
#include <iostream>
#include <iterator>
#include <cstdio> // getchar


void test_random_access_iterator(void);


int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	//test_random_access_iterator();


	ft::vector<int> vect(5, 42);
	//ft::vector<int>::iterator it(vect.begin());

	PRINT(vect.max_size());


	//PRINT(vect.capacity());
	//PRINT(&it);



	return (0);
}
