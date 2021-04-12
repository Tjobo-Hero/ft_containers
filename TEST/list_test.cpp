/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_test.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/09 13:31:52 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/12 12:51:48 by timvancitte   ########   odam.nl         */
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
	REQUIRE(own.empty() == real.empty());
}

TEST_CASE("Fill constructor", "[list]")
{
	ft::list<int>	own(5, 100);
	std::list<int>	real(5, 100);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

// TEST_CASE("Range constructor", "[list]")
// {
	
// }

// TEST_CASE("Copy constructor", "[list]")
// {
// 	ft::list<int>		own(6, 100);
// 	ft::list<int>		own2(own);
// 	std::list<int>		real(6, 100);
// 	std::list<int>		real2(real);


	
// 	REQUIRE(own2.size() == real2.size());
// 	REQUIRE(own2.empty() == real2.empty());
// 	REQUIRE(own2.front() == real2.front());
// 	REQUIRE(own2.back() == real2.back());
// }

// TEST_CASE("Assign content", "[list]")
// {
// 	ft::list<int>		own(6, 100);
// 	ft::list<int>		own2;
// 	std::list<int>		real(6, 100);
// 	std::list<int>		real2;

// 	own2 = own;
// 	real = real2;
	
// 	REQUIRE(own2.size() == real2.size());
// 	REQUIRE(own2.empty() == real2.empty());
// 	REQUIRE(own2.front() == real2.front());
// 	REQUIRE(own2.back() == real2.back());
// 	REQUIRE(own2.get_allocator() == real2.get_allocator());
	
// }

/* ------------ ITERATORS ------------ */

/* ------------ CAPACITY ------------ */

TEST_CASE("empty function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	REQUIRE(own.empty() == real.empty());
	
	ft::list<int>	own2(5, 100);
	std::list<int>	real2(5, 100);

	real2.clear();
	own2.clear();
	
	REQUIRE(own.empty() == real.empty());
}

TEST_CASE("size function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	REQUIRE(own.size() == real.size());
	
	ft::list<int>	own2(5, 100);
	std::list<int>	real2(5, 100);

	REQUIRE(own.size() == real.size());

	real2.clear();
	own2.clear();
	
	REQUIRE(own.size() == real.size());
}

TEST_CASE("max_size function", "[list]")
{
	ft::list<int>	own(2, 100);
	std::list<int>	real(2, 100);

	// REQUIRE(own.get_allocator.max_size() == real.get_allocator.max_size());
	REQUIRE(own.max_size() == real.max_size());
}

TEST_CASE("front function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	int sum = 40;

	
	for (int i  = 0; i < 5; ++i)
	{
		own.push_back(sum);
		real.push_back(sum);
		sum += 10;
	}
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}