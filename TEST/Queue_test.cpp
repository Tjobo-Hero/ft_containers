/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Queue_test.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 11:34:26 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/20 12:58:31 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "catch.hpp"
#include <queue>
#include <deque>
#include <list>

#include "../INCLUDES/ft_Queue.hpp"

/*-----------------MEMBER FUNCTIONS-----------------*/

TEST_CASE("queue-Empty container constructor", "[queue]")
{
	std::list<int> real_list;
	ft::list<int> own_list;

	std::queue<int> real1;                 // empty queue
	std::queue<int> real2;       // queue initialized to copy of deque	
	std::queue<int,std::list<int> > real3; // empty queue with list as underlying container
	std::queue<int,std::list<int> > real4(real_list);	

	ft::queue<int> own1;                 // empty queue
	ft::queue<int> own2;       // queue initialized to copy of deque	
	ft::queue<int,ft::list<int> > own3; // empty queue with list as underlying container
	ft::queue<int,ft::list<int> > own4(own_list);	
	
	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
}

TEST_CASE("queue-Copy Constructor", "[queue]")
{
	std::list<int> 					real_list1(2,200);         // list with 2 elements
	ft::list<int> 					own_list1(2,200);         // list with 2 elements

	std::queue<int,std::list<int> > real1(real_list1);
	ft::queue<int,ft::list<int> >	own1(own_list1);
	
	REQUIRE(own1.size() == real1.size());
	REQUIRE(own1.front() == real1.front());
	REQUIRE(own1.back() == real1.back());
}

TEST_CASE("queue-empty function", "[queue]")
{
	std::queue<int> real_queue;
	ft::queue<int> own_queue;

	std::queue<int,std::list<int> > real1; // empty queue with list as underlying container	
	ft::queue<int,ft::list<int> > own1; // empty queue with list as underlying container

	REQUIRE(own_queue.empty() == real_queue.empty());
	REQUIRE(own1.empty() == real1.empty());
	
	real_queue.push(1);
	own_queue.push(1);
	own1.push(1);
	real1.push(1);
	
	REQUIRE(own_queue.empty() == real_queue.empty());
	REQUIRE(own1.empty() == real1.empty());

	while (!own_queue.size())
	{
		own_queue.pop();
		real_queue.pop();
	}
	while (!own1.size())
	{
		own1.pop();
		real1.pop();
	}
	REQUIRE(own_queue.empty() == real_queue.empty());
	REQUIRE(own1.empty() == real1.empty());
}

TEST_CASE("queue-size function", "[queue]")
{
	std::queue<int> real_queue;
	ft::queue<int> own_queue;

	std::queue<int,std::list<int> > real1; // empty queue with list as underlying container	
	ft::queue<int,ft::list<int> > own1; // empty queue with list as underlying container

	REQUIRE(own_queue.size() == real_queue.size());
	REQUIRE(own1.size() == real1.size());
	
	real_queue.push(1);
	own_queue.push(1);
	own1.push(1);
	real1.push(1);
	
	REQUIRE(own_queue.size() == real_queue.size());
	REQUIRE(own1.size() == real1.size());
}

TEST_CASE("queue-front function", "[queue]")
{
	std::queue<int> real_queue;
	ft::queue<int> own_queue;

	std::queue<int,std::list<int> > real1; // empty queue with list as underlying container	
	ft::queue<int,ft::list<int> > own1; // empty queue with list as underlying container

	real_queue.push(100);
	own_queue.push(100);
	own1.push(100);
	real1.push(100);
	
	REQUIRE(own_queue.front() == real_queue.front());
	REQUIRE(own1.front() == real1.front());
	
	real_queue.push(1);
	own_queue.push(1);
	own1.push(1);
	real1.push(1);
	
	REQUIRE(own_queue.front() == real_queue.front());
	REQUIRE(own1.front() == real1.front());
}

TEST_CASE("queue-back function", "[queue]")
{
	std::queue<int> real_queue;
	ft::queue<int> own_queue;

	std::queue<int,std::list<int> > real1; // empty queue with list as underlying container	
	ft::queue<int,ft::list<int> > own1; // empty queue with list as underlying container

	real_queue.push(100);
	own_queue.push(100);
	own1.push(100);
	real1.push(100);
	
	REQUIRE(own_queue.back() == real_queue.back());
	REQUIRE(own1.back() == real1.back());
	
	real_queue.push(1);
	own_queue.push(1);
	own1.push(1);
	real1.push(1);
	
	REQUIRE(own_queue.back() == real_queue.back());
	REQUIRE(own1.back() == real1.back());
}

TEST_CASE("queue-push function", "[queue]")
{
	std::queue<int> real_queue;
	ft::queue<int> own_queue;

	std::queue<int,std::list<int> > real1; // empty queue with list as underlying container	
	ft::queue<int,ft::list<int> > own1; // empty queue with list as underlying container

	int sum = 10;

	for (int i = 0; i < 10; ++i)
	{
		own_queue.push(sum);
		real_queue.push(sum);
		own1.push(sum);
		real1.push(sum);
		sum += 13;
	}
	REQUIRE(own_queue.back() == real_queue.back());
	REQUIRE(own1.back() == real1.back());
	REQUIRE(own_queue.front() == real_queue.front());
	REQUIRE(own1.front() == real1.front());
	REQUIRE(own_queue.size() == real_queue.size());
	REQUIRE(own1.size() == real1.size());

	while (!own_queue.size())
	{
		REQUIRE(own_queue.front() == real_queue.front());
		REQUIRE(own1.front() == real1.front());
		own_queue.pop();
		real_queue.pop();
		own1.pop();
		real1.pop();
	}
	REQUIRE(own_queue.empty() == real_queue.empty());
	REQUIRE(own1.empty() == real1.empty());
}

/* ------------ RELATIONAL OPERATORS ------------ */
