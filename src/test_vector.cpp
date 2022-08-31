/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:20:10 by wszurkow          #+#    #+#             */
/*   Updated: 2022/08/31 12:11:26 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "palette.hpp"
#include "containers_definitions.hpp"
#include <vector>


std::string IS_OK(int to_evaluate) { return (to_evaluate ? _OK : _KO); }



void test_vector_getters_full(void)
{
	ft::vector<int>   _ft(42, 21);
	std::vector<int> _std(42, 21);

	PRINT("vector.size()     : " << IS_OK(_ft.size()     == _std.size()));
	PRINT("vector.max_size() : " << IS_OK(_ft.max_size() == _std.max_size()));
	PRINT("vector.capacity() : " << IS_OK(_ft.capacity() == _std.capacity()));
	PRINT("vector.empty()    : " << IS_OK(_ft.empty()    == _std.empty()));
	NEWLINE;
}

void test_vector_getters_empty(void)
{
	ft::vector<int>  _ft;
	std::vector<int> _std;

	PRINT("vector.size()     : " << IS_OK(_ft.size()     == _std.size()));
	PRINT("vector.max_size() : " << IS_OK(_ft.max_size() == _std.max_size()));
	PRINT("vector.capacity() : " << IS_OK(_ft.capacity() == _std.capacity()));
	PRINT("vector.empty()    : " << IS_OK(_ft.empty()    == _std.empty()));
	NEWLINE;
}


void test_vector(void)
{

	test_vector_getters_empty();
	test_vector_getters_full();


}
