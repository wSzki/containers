/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:11:44 by wszurkow          #+#    #+#             */
/*   Updated: 2022/10/30 02:11:45 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "palette.hpp"
#include "../inc/vector.hpp"
#include "../inc/stack.hpp"

#define P(a)  std::cout << a << std::endl
#define PP(a) std::cout << a;

void test_vector(std::string step);
void test_stack (std::string step);
void test_map   (std::string step);

int main (int ac, char **av)
{
	std::string v    = "n";
	std::string s    = "n";
	std::string m    = "n";
	std::string step = "n";
	bool interactive = false;

	if (ac > 1)
		if (av[1][0] == '-' || av[1][1] == 'i')
			interactive = true;
	if (interactive == true)
	{
		CLEAR;
		P("======================");
		P(" 42 Containers tester ");
		P("======================");
		P("");

		P("Select tests to launch - (y/n)");
		PP("- Vector : "); std::cin >> v;
		PP("- Stack  : "); std::cin >> s;
		PP("- Map    : "); std::cin >> m;
		if (v == "y" || s == "y" || m == "y")
		{
			P("Would you like to activate breakpoints? (y/n)");
			std::cin >> step;
		}
		if (v == "y")
			test_vector(step);
		if (v == "y")
			test_stack(step);
	}
	else if (interactive == false)
	{
		test_vector(step);
		test_stack(step);
	}
}
