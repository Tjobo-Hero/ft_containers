/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map_test.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/23 10:10:11 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/30 12:21:08 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "catch.hpp"
#include <map>
#include <iostream>

#include "../INCLUDES/ft_Map.hpp"
// #include "../INCLUDES/ft_BiDirectionalIterator.hpp"

TEST_CASE("map-Empty container constructor", "[map]")
{
	ft::map<int, int>	own;
	std::map<int, int>	real;

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	own.insert(ft::pair<int, int>(6, 8));
	own.print_tree(own.getRoot());
	own.insert(ft::pair<int, int>(5, 10));
	own.print_tree(own.getRoot());
	own.insert(ft::pair<int, int>(4, 10));
	own.print_tree(own.getRoot());
	own.insert(ft::pair<int, int>(3, 10));
	own.print_tree(own.getRoot());
	own.insert(ft::pair<int, int>(2, 10));
	own.print_tree(own.getRoot());
	own.insert(ft::pair<int, int>(1, 10));
	own.print_tree(own.getRoot());
}

TEST_CASE("map-iterator", "[map]")
{
	ft::map<int, int>	own;

	int sum = 1;

	for (int i = 0; i < 6; ++i)
	{
		own.insert(ft::pair<int, int>(sum, sum));
		sum += 1;
	}
	own.print_tree(own.getRoot());

	ft::map<int, int>::iterator it = own.begin();
	ft::map<int, int>::iterator ite = own.end();

	
	while (it != own.end())
	{
		std::cout << it->first << std::endl;
		++it;
	}
}

TEST_CASE("map-erase function version 2", "[map]")
{
	ft::map<int, int>	own;
	std::map<int, int>	real;

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());

	// Delete only root
	own.insert(ft::pair<int, int>(6, 8));
	real.insert(std::pair<int, int>(6, 8));
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	own.print_tree(own.getRoot());
	own.erase(6);
	real.erase(6);
	own.print_tree(own.getRoot());
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());

	// // Delete root with one right child
	own.insert(ft::pair<int, int>(6, 8));
	own.insert(ft::pair<int, int>(10, 8));
	real.insert(std::pair<int, int>(6, 8));
	real.insert(std::pair<int, int>(10, 8));
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	own.print_tree(own.getRoot());
	own.erase(6);
	real.erase(6);
	own.print_tree(own.getRoot());
	
	std::cout << "Root: " << own.getRoot()->data.first << std::endl;

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	own.erase(10);
	real.erase(10);

	// // Delete root with one left Child
	own.insert(ft::pair<int, int>(6, 8));
	real.insert(std::pair<int, int>(6, 8));
	own.insert(ft::pair<int, int>(4, 8));
	real.insert(std::pair<int, int>(4, 8));
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	own.print_tree(own.getRoot());
	own.erase(6);
	real.erase(6);
	own.print_tree(own.getRoot());

	std::cout << "Root: " << own.getRoot()->data.first << std::endl;

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	own.erase(4);
	real.erase(4);
	
	own.print_tree(own.getRoot());

	// // Delete Root with 2 children
	std::cout << "Delete Root with 2 children" << std::endl;
	own.insert(ft::pair<int, int>(15, 15));
	own.insert(ft::pair<int, int>(10, 10));
	own.insert(ft::pair<int, int>(20, 20));
	own.insert(ft::pair<int, int>(5, 5));
	own.insert(ft::pair<int, int>(19, 19));
	own.insert(ft::pair<int, int>(25, 25));
	own.insert(ft::pair<int, int>(13, 13));

	real.insert(std::pair<int, int>(15, 15));
	real.insert(std::pair<int, int>(10, 10));
	real.insert(std::pair<int, int>(20, 20));
	real.insert(std::pair<int, int>(5, 5));
	real.insert(std::pair<int, int>(19, 19));
	real.insert(std::pair<int, int>(25, 25));
	real.insert(std::pair<int, int>(13, 13));
	
	own.print_tree(own.getRoot());
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	own.erase(6);
	real.erase(6);
	own.print_tree(own.getRoot());

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());

	// Delete 
}