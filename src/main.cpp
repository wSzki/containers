#include "random_access_iterator.hpp"
#include "palette.hpp"

//using namespace ft;

//#include "vector.hpp"
#include <vector>
#include <iostream>
#include <iterator>

#define PRINT(input)  std::cout << input << RCol << std::endl
#define PRINTR(input) PRINT(Red << input)
#define PRINTB(input) PRINT(Blu << input)
#define PRINTG(input) PRINT(Gre << input)
#define PRINTY(input) PRINT(Yel << input)
#define NEWLINE       PRINT("")

#define RAI           random_access_iterator

void test_random_access_iterator_comparaison(void)
{
	ft::RAI<int> it1;
	ft::RAI<int> it2;

	PRINTY("## Random access iterator - comparaison overload test ");
	PRINTR("Address of it1        = " << &it1);
	PRINTB("Address of it2        = " << &it2);
	PRINTR("Value   of it1._ptr   = NULL (default constructor)");
	PRINTB("Value   of it2._ptr   = NULL (default constructor)");
	PRINTG("Result  of it1 <  it2 = " << (it1 <  it2));
	PRINTG("Result  of it1 >  it2 = " << (it1 >  it2));
	PRINTG("Result  of it1 <= it2 = " << (it1 <= it2));
	PRINTG("Result  of it1 >= it2 = " << (it1 >= it2));
	PRINTG("Result  of it1 == it2 = " << (it1 == it2));
	PRINTG("Result  of it1 != it2 = " << (it1 != it2));
	NEWLINE;
}

void test_random_access_iterator_comparaison_different_type(void)
{
	ft::RAI<int> it1;
	std::vector<char>::iterator it2;

	PRINTY("## Random access iterator - comparaison overload test on different types of iterators ");
	PRINTR("Address of it1        = " << &it1);
	PRINTB("Address of it2        = " << &it2);
	PRINTR("Value   of it1._ptr   = NULL (default constructor)");
	PRINTB("Value   of it2._ptr   = NULL (default constructor)");
	PRINTG("Result  of it1 <  it2 = " << (it1 <  it2));
	PRINTG("Result  of it1 >  it2 = " << (it1 >  it2));
	PRINTG("Result  of it1 <= it2 = " << (it1 <= it2));
	PRINTG("Result  of it1 >= it2 = " << (it1 >= it2));
	PRINTG("Result  of it1 == it2 = " << (it1 == it2));
	PRINTG("Result  of it1 != it2 = " << (it1 != it2));
	NEWLINE;
}

void test_random_access_iterator(void)
{
	test_random_access_iterator_comparaison();
	test_random_access_iterator_comparaison_different_type();
}



int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	test_random_access_iterator();




	//std::vector <int> hector;
	//vector      <int> vector;

	//hector.push_back(42);
	//vector.push_back(42);

	//std::cout << *(hector.begin()) << std::endl;
	//std::cout << *(vector.begin()) << std::endl;



	return (0);
}
