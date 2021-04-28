/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map_test.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/23 10:10:11 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/28 13:16:58 by timvancitte   ########   odam.nl         */
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