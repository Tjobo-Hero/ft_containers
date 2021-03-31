/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_test.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 13:05:30 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/03/31 12:31:51 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "catch.hpp"
#include <vector>

#include "../INCLUDES/ft_vector.hpp"

/*-----------------CONSTRUCTORS-----------------*/
TEST_CASE("vector-default constructor", "[vector]")
{
	ft::vector<int> 	own;
	std::vector<int> 	real;
	
	REQUIRE(own.size() == real.size());
}

TEST_CASE("vector-size and value constructor", "[vector]")
{
	ft::vector<int> 	own(5, 3);
	std::vector<int> 	real(5, 3);

	REQUIRE(own.size() == real.size());
	REQUIRE(own[2] == real[2]);
}

// TEST_CASE("vector-iterator instanciation", "[vector]")
// {
	
// }

TEST_CASE("vector-copy constructor", "[vector]")
{
	ft::vector<int> 	own1(5, 5);
	std::vector<int> 	real1(5, 5);

	ft::vector<int> 	own2(own1);
	std::vector<int> 	real2(real1);

	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2[2] == real2[2]);
}

TEST_CASE("operator= function", "[vector]")
{
	ft::vector<int> 	own1(5, 5);
	std::vector<int> 	real1(5, 5);
	
	ft::vector<int> own2;
	std::vector<int> real2;

	own2 = own1;
	real2 = real1;

	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2[2] == real2[2]);
	REQUIRE(own2.capacity() == real2.capacity());
}


/*-----------------ITERATORS-----------------*/
TEST_CASE("vector-begin function", "[vector]")
{
	ft::vector<int> 	own(4, 3);
	std::vector<int> 	real(4, 3);
	
	ft::vector<int>::iterator own_it = own.begin();
	std::vector<int>::iterator real_it = real.begin();

	REQUIRE(*own_it == *real_it);
}

TEST_CASE("vector-const begin function", "[vector]")
{
	ft::vector<int> 	own(4, 3);
	std::vector<int> 	real(4, 3);
	
	ft::vector<int>::const_iterator own_it = own.begin();
	std::vector<int>::const_iterator real_it = real.begin();

	REQUIRE(*own_it == *real_it);
}

TEST_CASE("vector-end function", "[vector]")
{
	ft::vector<int> 	own(4, 3);
	std::vector<int> 	real(4, 3);
	
	ft::vector<int>::iterator own_ite = own.end();
	std::vector<int>::iterator real_ite = real.end();

	own_ite--;
	real_ite--;
	REQUIRE(*own_ite == *real_ite);
}

TEST_CASE("vector-const end function", "[vector]")
{
	ft::vector<int> 	own(4, 3);
	std::vector<int> 	real(4, 3);
	
	ft::vector<int>::const_iterator own_ite = own.end();
	std::vector<int>::const_iterator real_ite = real.end();

	own_ite--;
	real_ite--;
	REQUIRE(*own_ite == *real_ite);
}

TEST_CASE("vector-rbegin function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	ft::vector<int>::reverse_iterator own_rit = own.rbegin();
	ft::vector<int>::reverse_iterator old_own_rit;
	std::vector<int>::reverse_iterator real_rit = real.rbegin();
	std::vector<int>::reverse_iterator old_real_rit;

	++own_rit;
	++real_rit;
	REQUIRE(*own_rit == *real_rit);
	
	old_own_rit = own_rit++;
	old_real_rit = real_rit++;
	REQUIRE(*old_real_rit == *old_own_rit);
}

TEST_CASE("vector-const rbegin function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	ft::vector<int>::const_reverse_iterator own_rit = own.rbegin();
	ft::vector<int>::const_reverse_iterator old_own_rit;
	std::vector<int>::const_reverse_iterator real_rit = real.rbegin();
	std::vector<int>::const_reverse_iterator old_real_rit;

	++own_rit;
	++real_rit;
	REQUIRE(*own_rit == *real_rit);
	
	old_own_rit = own_rit++;
	old_real_rit = real_rit++;
	REQUIRE(*old_real_rit == *old_own_rit);
}

TEST_CASE("vector-rend function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	ft::vector<int>::reverse_iterator own_rite = own.rend();
	ft::vector<int>::reverse_iterator old_own_rite;
	std::vector<int>::reverse_iterator real_rite = real.rend();
	std::vector<int>::reverse_iterator old_real_rite;

	--own_rite;
	--real_rite;
	REQUIRE(*own_rite == *real_rite);
	
	old_own_rite = own_rite--;
	old_real_rite = real_rite--;
	REQUIRE(*old_real_rite == *old_own_rite);
}

TEST_CASE("vector-const rend function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	ft::vector<int>::const_reverse_iterator own_rite = own.rend();
	ft::vector<int>::const_reverse_iterator old_own_rite;
	std::vector<int>::const_reverse_iterator real_rite = real.rend();
	std::vector<int>::const_reverse_iterator old_real_rite;

	--own_rite;
	--real_rite;
	REQUIRE(*own_rite == *real_rite);
	
	old_own_rite = own_rite--;
	old_real_rite = real_rite--;
	REQUIRE(*old_real_rite == *old_own_rite);
}


/*-----------------Capcity-----------------*/
TEST_CASE("vector-size function", "[vector]")
{
	ft::vector<int> 	own(6, 3);
	std::vector<int> 	real(6, 6);

	REQUIRE(own.size() == real.size());
}

TEST_CASE("vector-max_size function", "[vector]")
{
	ft::vector<int> 	own(6, 3);
	std::vector<int> 	real(6, 6);

	own.clear();
	real.clear();
	
	REQUIRE(own.size() == real.size());
	REQUIRE(own.max_size() == real.max_size());
}

TEST_CASE("vector-resize function", "[vector]")
{
	ft::vector<int> 	own(8, 5);
	std::vector<int> 	real(8, 5);

	own.resize(2, 2);
	real.resize(2, 2);

	REQUIRE(own.size() == real.size());
	REQUIRE(own[1] == real[1]);
}

TEST_CASE("vector-capacity function", "[vector]")
{
	ft::vector<int> own(8, 5);
	std::vector<int> real(8, 5);

	own.resize(2, 2);
	real.resize(2, 2);

	REQUIRE(own.capacity() == real.capacity());
}

TEST_CASE("vector-empty function", "[vector]")
{
	ft::vector<int> 	own(5, 3);
	std::vector<int>	real(5, 3);
	
	ft::vector<int> 	empty_own;
	std::vector<int>	empty_real;

	own.clear();
	real.clear();

	REQUIRE(own.empty() == real.empty());
	REQUIRE(empty_own.empty() == empty_real.empty());
}

TEST_CASE("vector-reserve function", "[vector]")
{
	ft::vector<int>		own(6, 10);
	std::vector<int>	real(6, 10);

	own.reserve(100);
	real.reserve(100);
	
	REQUIRE(own.capacity() == real.capacity());

	// try
	// {
	// 	own.reserve(own.max_size() + 1);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	// try
	// {
	// 	real.reserve(real.max_size() + 1);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}



/*-----------------Element Access-----------------*/
TEST_CASE("vector-operator[] function")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real[i] = sum;
		own[i] = sum;
		sum += 1;
	}
	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);
	REQUIRE(own[2] == real[2]);
	REQUIRE(own[3] == real[3]);
}

TEST_CASE("vector-at function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	REQUIRE(own.at(0) == real.at(0));
	REQUIRE(own.at(1) == real.at(1));
	REQUIRE(own.at(2) == real.at(2));
	REQUIRE(own.at(3) == real.at(3));
	// try
	// {
	// 	own.at(6);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	// try
	// {
	// 	real.at(6);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}

TEST_CASE("vector-front function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	REQUIRE(own.front() == real.front());
}

TEST_CASE("vector-back function", "[vector]")
{
	int sum = 0;
	ft::vector<int>		own(5);
	std::vector<int>	real(5);

	for(int i = 0; i < 5; i++)
	{
		real.at(i) = sum;
		own.at(i) = sum;
		sum += 1;
	}
	
	REQUIRE(own.back() == real.back());
}


/*-----------------Modifiers-----------------*/

TEST_CASE("vector-assign fucntion with itarators", "[vector]")
{
	ft::vector<int>		own1(5, 100);
	ft::vector<int>		own2;
	std::vector<int>	real1(5, 100);
	std::vector<int>	real2;

	ft::vector<int>::iterator own_it = own1.begin();
	ft::vector<int>::iterator own_ite = own1.begin() + 3;
	std::vector<int>::iterator real_it = real1.begin();
	std::vector<int>::iterator real_ite = real1.begin() + 3;

	own2.assign(own_it, own_ite);
	real2.assign(real_it, real_ite);

	REQUIRE(own2.capacity() == real2.capacity());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own2[0] == real2[0]);
	REQUIRE(own2[1] == real2[1]);
	REQUIRE(own2[2] == real2[2]);
}

TEST_CASE("vector-assign function with n and val", "[vector]")
{
	ft::vector<int>		own;
	std::vector<int>	real;

	own.assign(20, 20);
	real.assign(20 , 20);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
	REQUIRE(own.at(3) == real.at(3));
	REQUIRE(own.capacity() == real.capacity());
}

TEST_CASE("vector-push_back function", "[vector]")
{
	int sum = 10;
	ft::vector<int>		own;
	std::vector<int>	real;
	
	for(int i = 0; i < 4; ++i)
	{	
		own.push_back(sum);
		real.push_back(sum);
		sum += 10;
	}
	REQUIRE(own[0] == real[0]);
	REQUIRE(own[1] == real[1]);
	REQUIRE(own[2] == real[2]);
}

TEST_CASE("vector-pop_back function", "[vector]")
{
	int sum = 10;
	ft::vector<int>		own;
	std::vector<int>	real;
	
	for(int i = 0; i < 4; ++i)
	{	
		own.push_back(sum);
		real.push_back(sum);
		sum += 10;
	}
	REQUIRE(own.size() == real.size());
	own.pop_back();
	real.pop_back();
	REQUIRE(own.size() == real.size());
	REQUIRE(own[2] == real[2]);
}

TEST_CASE("vector-insert function", "[vector]")
{
	
}
// TEST_CASE("vector-erase function", "[vector]")
// TEST_CASE("vector-swap function", "[vector]")

TEST_CASE("vector-clear function", "[vector]")
{
	ft::vector<int>		own(10, 100);
	std::vector<int>	real(10, 100);

	own.clear();
	real.clear();

	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.size() == real.size());
	REQUIRE(own.capacity() == real.capacity());
}

/*-----------------Relational Operators-----------------*/
// TEST_CASE("vector-operation overloaders", "[vector]")
// {
	
// }
