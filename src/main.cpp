


#include "vector.hpp"

#include <vector>

using namespace ft;

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	std::vector <int> hector;
	vector      <int> vector;


	hector.push_back(42);
	vector.push_back(42);

	std::cout << *(hector.begin()) << std::endl;
	std::cout << *(vector.begin()) << std::endl;



	return (0);
}
