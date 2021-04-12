/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_test.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/09 13:31:52 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/12 14:54:36 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "catch.hpp"
#include <list>

#include "../INCLUDES/ft_list.hpp"

/*-----------------CONSTRUCTORS-----------------*/
TEST_CASE("list-Empty container constructor", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
}

TEST_CASE("list-Fill constructor", "[list]")
{
	ft::list<int>	own(5, 100);
	std::list<int>	real(5, 100);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

// TEST_CASE("list-Range constructor", "[list]")
// {
	
// }

// TEST_CASE("list-Copy constructor", "[list]")
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

// TEST_CASE("list-Assign content", "[list]")
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
// TEST_CASE("list-list-begin function", "[list]")
// {
// 	ft::list<int> 	own(4, 3);
// 	std::list<int> 	real(4, 3);
	
// 	ft::list<int>::iterator own_it = own.begin();
// 	std::list<int>::iterator real_it = real.begin();

// 	REQUIRE(*own_it == *real_it);
// }

// TEST_CASE("list-list-const begin function", "[list]")
// {
// 	ft::list<int> 	own(4, 3);
// 	std::list<int> 	real(4, 3);
	
// 	ft::list<int>::const_iterator own_it = own.begin();
// 	std::list<int>::const_iterator real_it = real.begin();

// 	REQUIRE(*own_it == *real_it);
// }

// TEST_CASE("list-list-end function", "[list]")
// {
// 	ft::list<int> 	own(4, 3);
// 	std::list<int> 	real(4, 3);
	
// 	ft::list<int>::iterator own_ite = own.end();
// 	std::list<int>::iterator real_ite = real.end();

// 	own_ite--;
// 	real_ite--;
// 	REQUIRE(*own_ite == *real_ite);
// }

// TEST_CASE("list-list-const end function", "[list]")
// {
// 	ft::list<int> 	own(4, 3);
// 	std::list<int> 	real(4, 3);
	
// 	ft::list<int>::const_iterator own_ite = own.end();
// 	std::list<int>::const_iterator real_ite = real.end();

// 	own_ite--;
// 	real_ite--;
// 	REQUIRE(*own_ite == *real_ite);
// }

// TEST_CASE("list-list-rbegin function", "[list]")
// {
// 	int sum = 0;
// 	ft::list<int>		own(5);
// 	std::list<int>	real(5);

// 	for(int i = 0; i < 5; i++)
// 	{
// 		real.push_back(sum);
// 		own.push_back(sum);
// 		sum += 1;
// 	}
	
// 	ft::list<int>::reverse_iterator own_rit = own.rbegin();
// 	ft::list<int>::reverse_iterator old_own_rit;
// 	std::list<int>::reverse_iterator real_rit = real.rbegin();
// 	std::list<int>::reverse_iterator old_real_rit;

// 	++own_rit;
// 	++real_rit;
// 	REQUIRE(*own_rit == *real_rit);
	
// 	old_own_rit = own_rit++;
// 	old_real_rit = real_rit++;
// 	REQUIRE(*old_real_rit == *old_own_rit);
// }

// TEST_CASE("list-list-const rbegin function", "[list]")
// {
// 	int sum = 0;
// 	ft::list<int>		own(5);
// 	std::list<int>	real(5);

// 	for(int i = 0; i < 5; i++)
// 	{
// 		real.push_back(sum);
// 		own.push_back(sum);
// 		sum += 1;
// 	}
	
// 	ft::list<int>::const_reverse_iterator own_rit = own.rbegin();
// 	ft::list<int>::const_reverse_iterator old_own_rit;
// 	std::list<int>::const_reverse_iterator real_rit = real.rbegin();
// 	std::list<int>::const_reverse_iterator old_real_rit;

// 	++own_rit;
// 	++real_rit;
// 	REQUIRE(*own_rit == *real_rit);
	
// 	old_own_rit = own_rit++;
// 	old_real_rit = real_rit++;
// 	REQUIRE(*old_real_rit == *old_own_rit);
// }

// TEST_CASE("list-list-rend function", "[list]")
// {
// 	int sum = 0;
// 	ft::list<int>		own(5);
// 	std::list<int>	real(5);

// 	for(int i = 0; i < 5; i++)
// 	{
// 		real.push_back(sum);
// 		own.push_back(sum);
// 		sum += 1;
// 	}
	
// 	ft::list<int>::reverse_iterator own_rite = own.rend();
// 	ft::list<int>::reverse_iterator old_own_rite;
// 	std::list<int>::reverse_iterator real_rite = real.rend();
// 	std::list<int>::reverse_iterator old_real_rite;

// 	--own_rite;
// 	--real_rite;
// 	REQUIRE(*own_rite == *real_rite);
	
// 	old_own_rite = own_rite--;
// 	old_real_rite = real_rite--;
// 	REQUIRE(*old_real_rite == *old_own_rite);
// }

// TEST_CASE("list-list-const rend function", "[list]")
// {
// 	int sum = 0;
// 	ft::list<int>		own(5);
// 	std::list<int>		real(5);

// 	for(int i = 0; i < 5; i++)
// 	{
// 		real.push_back(sum);
// 		own.push_back(sum);
// 		sum += 1;
// 	}
	
// 	ft::list<int>::const_reverse_iterator own_rite = own.rend();
// 	ft::list<int>::const_reverse_iterator old_own_rite;
// 	std::list<int>::const_reverse_iterator real_rite = real.rend();
// 	std::list<int>::const_reverse_iterator old_real_rite;

// 	--own_rite;
// 	--real_rite;
// 	REQUIRE(*own_rite == *real_rite);
	
// 	old_own_rite = own_rite--;
// 	old_real_rite = real_rite--;
// 	REQUIRE(*old_real_rite == *old_own_rite);
// }



/* ------------ CAPACITY ------------ */

TEST_CASE("list-empty function", "[list]")
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

TEST_CASE("list-size function", "[list]")
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

TEST_CASE("list-max_size function", "[list]")
{
	ft::list<int>	own(2, 100);
	std::list<int>	real(2, 100);

	REQUIRE(own.max_size() == real.max_size());
}

/* ------------ ELEMENT ACCESS ------------ */

TEST_CASE("list-front function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	int sum = 40;
	const int tim = 100;
	
	
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

	own.push_front(tim);
	real.push_front(tim);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

TEST_CASE("list-back function", "[list]")
{
	ft::list<int>	own;
	std::list<int>	real;

	const int tim = 100;
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

	own.push_back(tim);
	real.push_back(tim);

	REQUIRE(own.size() == real.size());
	REQUIRE(own.empty() == real.empty());
	REQUIRE(own.front() == real.front());
	REQUIRE(own.back() == real.back());
}

	/* ------------ MODIFIERS ------------ */

	// TEST_CASE("list-assign with iterators", "[list]")
	// {
		
	// }

	TEST_CASE("list-assign size n and type val")
	{
		ft::list<int>	own;
		std::list<int>	real;

		own.assign(6, 100);
		real.assign(6, 100);

		REQUIRE(own.size() == real.size());
		REQUIRE(own.empty() == real.empty());
		REQUIRE(own.front() == real.front());
		REQUIRE(own.back() == real.back());
	}

	TEST_CASE("list-push_front function", "[list]")
	{
		ft::list<int>	own;
		std::list<int>	real;

		int sum = 10;
		for (int i = 0; i < 10; ++i)
		{
			own.push_front(sum);
			real.push_front(sum);
			sum += 11;
		}

		REQUIRE(own.size() == real.size());
		REQUIRE(own.empty() == real.empty());
		REQUIRE(own.front() == real.front());
		REQUIRE(own.back() == real.back());
	}

	TEST_CASE("list-push_back function", "[list]")
	{
		ft::list<int>	own;
		std::list<int>	real;

		int sum = 10;
		for (int i = 0; i < 10; ++i)
		{
			own.push_back(sum);
			real.push_back(sum);
			sum += 11;
		}

		REQUIRE(own.size() == real.size());
		REQUIRE(own.empty() == real.empty());
		REQUIRE(own.front() == real.front());
		REQUIRE(own.back() == real.back());
	}
	
	TEST_CASE("list-pop_back function", "[list]")
	{
		ft::list<int>	own;
		std::list<int>	real;

		int sum = 10;
		for (int i = 0; i < 10; ++i)
		{
			own.push_back(sum);
			real.push_back(sum);
			sum += 11;
		}
		
		for (int i = 0; i < 5; ++i)
		{
			REQUIRE(own.back() == real.back());
			REQUIRE(own.size() == real.size());

			own.pop_back();
			real.pop_back();
		}
		
		own.push_back(2000);
		real.push_back(2000);
		REQUIRE(own.back() == real.back());
		REQUIRE(own.size() == real.size());

		own.pop_back();
		real.pop_back();
		
		REQUIRE(own.back() == real.back());
		REQUIRE(own.size() == real.size());
		
	}

	// TEST_CASE("list-insert single element", "[list]")
	// {
		
	// }

	// TEST_CASE("list-insert fill", "[list]")
	// {
		
	// }

	// TEST_CASE("list-insert range", "[list]")
	// {
		
	// }

	// TEST_CASE("list-erase single element", "[list]")
	// {
		
	// }

	// TEST_CASE("list-erase range element", "[list]")
	// {
		
	// }

	TEST_CASE("list-swap ", "[list]")
	{
		
	}