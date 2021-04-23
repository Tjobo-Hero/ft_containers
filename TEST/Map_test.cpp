/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map_test.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/23 10:10:11 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/23 15:54:16 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "catch.hpp"
#include <map>
#include <iostream>

#include "../INCLUDES/ft_Map.hpp"
#include "../INCLUDES/ft_BiDirectionalIterator.hpp"

TEST_CASE("map-Empty container constructor", "[map]")
{
	ft::map<int, char>	own;
	std::map<int, char>	real;

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	// own.insert(ft::pair<int, std::string>(6, "tim"));
	own.print_tree();
}