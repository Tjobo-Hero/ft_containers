/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_test.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 13:05:30 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/03/29 15:47:04 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "catch.hpp"
#include <vector>

#include "../INCLUDES/ft_vector.hpp"

/*-----------------CONSTRUCTORS-----------------*/
TEST_CASE("vector-default constructor", "[vector]")
{
	ft::vector<int> own;
	std::vector<int> real;
	
	REQUIRE(own.size() == real.size());
}

TEST_CASE("vector-size and value constructor", "[vector]")
{
	ft::vector<int> own(5, 3);
	std::vector<int> real(5, 3);

	REQUIRE(own.size() == real.size());
	REQUIRE(own[2] == real[2]);
}

// TEST_CASE("vector-iterator instanciation", "[vector]")
// {
	
// }

TEST_CASE("vector-copy constructor", "[vector]")
{
	ft::vector<int> own1(5, 5);
	std::vector<int> real1(5, 5);

	ft::vector<int> own2(own1);
	std::vector<int> real2(real1);

	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2[2] == real2[2]);
}

TEST_CASE("operator= function", "[vector]")
{
	ft::vector<int> own1(5, 5);
	std::vector<int> real1(5, 5);

	ft::vector<int> own2;
	std::vector<int> real2;

	own2 = own1;
	real2 = real1;

	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2[2] == real2[2]);
}


/*-----------------ITERATORS-----------------*/
TEST_CASE("vector-begin function", "[vector]")
{
	ft::vector<int> own(4, 3);
	std::vector<int> real(4, 3);
	
	ft::vector<int>::iterator own_it = own.begin();
	std::vector<int>::iterator real_it = real.begin();

	REQUIRE(*own_it == *real_it);
}

TEST_CASE("vector-const begin function", "[vector]")
{
	ft::vector<int> own(4, 3);
	std::vector<int> real(4, 3);
	
	ft::vector<int>::const_iterator own_it = own.begin();
	std::vector<int>::const_iterator real_it = real.begin();

	REQUIRE(*own_it == *real_it);
}

TEST_CASE("vector-end function", "[vector]")
{
	ft::vector<int> own(4, 3);
	std::vector<int> real(4, 3);
	
	ft::vector<int>::iterator own_ite = own.end();
	std::vector<int>::iterator real_ite = real.end();

	own_ite--;
	real_ite--;
	REQUIRE(*own_ite == *real_ite);
}

TEST_CASE("vector-const end function", "[vector]")
{
	ft::vector<int> own(4, 3);
	std::vector<int> real(4, 3);
	
	ft::vector<int>::const_iterator own_ite = own.end();
	std::vector<int>::const_iterator real_ite = real.end();

	own_ite--;
	real_ite--;
	REQUIRE(*own_ite == *real_ite);
}

TEST_CASE("vector-rbegin function", "[vector]")
{
	ft::vector<int> own(4, 3);
	std::vector<int> real(4, 3);
	
	ft::vector<int>::reverse_iterator own_rite = own.rbegin();
	std::vector<int>::reverse_iterator real_rite = real.rbegin();

	own_rite++;
	real_rite++;
	REQUIRE(*own_rite == *real_rite);
}
/*-----------------Capcity-----------------*/