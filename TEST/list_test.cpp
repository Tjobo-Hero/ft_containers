/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_test.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/09 13:31:52 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/09 14:01:12 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "catch.hpp"
#include <list>

#include "../INCLUDES/ft_list.hpp"

/*-----------------CONSTRUCTORS-----------------*/
TEST_CASE("Empty container constructor", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	REQUIRE(own.size() == real.size());
}