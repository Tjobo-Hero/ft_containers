/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map_test.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/23 10:10:11 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/27 12:41:57 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "catch.hpp"
#include <map>
#include <iostream>

#include "../INCLUDES/ft_Map.hpp"
#include "../INCLUDES/ft_BiDirectionalIterator.hpp"

TEST_CASE("map-Empty container constructor", "[map]")
{
	ft::map<int, int>	own;
	std::map<int, int>	real;

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	own.insert(ft::pair<int, int>(6, 8));
	own.print_tree(own.getRoot());
	own.insert(ft::pair<int, int>(4, 10));
	own.print_tree(own.getRoot());
	

	own.insert(ft::pair<int, int>(10, 10));
	own.print_tree(own.getRoot());

	own.insert(ft::pair<int, int>(7, 10));
	own.print_tree(own.getRoot());
	own.insert(ft::pair<int, int>(2, 10));
	own.print_tree(own.getRoot());
	own.insert(ft::pair<int, int>(4, 10));
	own.print_tree(own.getRoot());
	own.insert(ft::pair<int, int>(20, 10));
	own.print_tree(own.getRoot());
	own.insert(ft::pair<int, int>(3, 10));
	own.insert(ft::pair<int, int>(36, 10));
	own.insert(ft::pair<int, int>(24, 10));
	own.insert(ft::pair<int, int>(21, 10));
	own.print_tree(own.getRoot());


	



	// own.print_tree()t;
}