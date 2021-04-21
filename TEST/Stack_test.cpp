/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Stack_test.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 12:44:15 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/21 08:43:28 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "catch.hpp"
#include <stack>

#include "../INCLUDES/ft_Stack.hpp"

/*-----------------MEMBER FUNCTIONS-----------------*/

TEST_CASE("stack-Empty container constructor", "[stack]")
{
	std::vector<int> real_vector(3, 100);
	ft::vector<int> own_vector(3, 100);

	std::list<int> real_list(5, 100);
	ft::list<int> own_list(5, 100);
	

	std::stack<int> real1;
	std::stack<int> real2;
	std::stack<int,std::vector<int> > real3;
	std::stack<int,std::vector<int> > real4(real_vector);	
	std::stack<int,std::list<int> > real5(real_list);


	ft::stack<int> own1;
	ft::stack<int> own2;	
	ft::stack<int,ft::vector<int> > own3;
	ft::stack<int,ft::vector<int> > own4(own_vector);
	std::stack<int,ft::list<int> > own5(real_list);
	
	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
	REQUIRE(own5.size() == real5.size());
	REQUIRE(own5.top() == real5.top());
	REQUIRE(own5.back() == real5.back());
}

TEST_CASE("stack-copy constructor", "[stack]")
{
	std::vector<int> real_vector(3, 100);
	ft::vector<int> own_vector(3, 100);

	std::list<int> real_list(5, 100);
	ft::list<int> own_list(5, 100);
	

	std::stack<int> real1;
	std::stack<int> real2;
	std::stack<int,std::vector<int> > real3;
	std::stack<int,std::vector<int> > real4(real_vector);	
	std::stack<int,std::list<int> > real5(real_list);


	ft::stack<int> own1;
	ft::stack<int> own2;	
	ft::stack<int,ft::vector<int> > own3;
	ft::stack<int,ft::vector<int> > own4(own_vector);
	std::stack<int,ft::list<int> > own5(real_list);
	
	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
	REQUIRE(own5.size() == real5.size());
	REQUIRE(own5.top() == real5.top());
	REQUIRE(own5.back() == real5.back());
}

TEST_CASE("stack-empty function", "[stack]")
{
	std::vector<int> real_vector;
	ft::vector<int> own_vector;

	std::list<int> real_list;
	ft::list<int> own_list;
	

	std::stack<int> real1;
	std::stack<int> real2;
	std::stack<int,std::vector<int> > real3;
	std::stack<int,std::vector<int> > real4(real_vector);	
	std::stack<int,std::list<int> > real5(real_list);


	ft::stack<int> own1;
	ft::stack<int> own2;	
	ft::stack<int,ft::vector<int> > own3;
	ft::stack<int,ft::vector<int> > own4(own_vector);
	std::stack<int,ft::list<int> > own5(real_list);
	
	REQUIRE(own1.empty() == real1.empty());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own3.empty() == real3.empty());
	REQUIRE(own4.empty() == real4.empty());
	REQUIRE(own5.empty() == real5.empty());

	own1.push(1);
	own2.push(1);
	own3.push(1);
	own4.push(1);
	own5.push(1);
	real1.push(1);
	real2.push(1);
	real3.push(1);
	real4.push(1);
	real5.push(1);

	REQUIRE(own1.empty() == real1.empty());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own3.empty() == real3.empty());
	REQUIRE(own4.empty() == real4.empty());
	REQUIRE(own5.empty() == real5.empty());

	own1.pop();
	own2.pop();
	own3.pop();
	own4.pop();
	own5.pop();
	real1.pop();
	real2.pop();
	real3.pop();
	real4.pop();
	real5.pop();

	REQUIRE(own1.empty() == real1.empty());
	REQUIRE(own2.empty() == real2.empty());
	REQUIRE(own3.empty() == real3.empty());
	REQUIRE(own4.empty() == real4.empty());
	REQUIRE(own5.empty() == real5.empty());
}

TEST_CASE("stack-copy constructor", "[stack]")
{
	std::vector<int> real_vector(3, 100);
	ft::vector<int> own_vector(3, 100);

	std::list<int> real_list(5, 100);
	ft::list<int> own_list(5, 100);
	

	std::stack<int> real1;
	std::stack<int> real2;
	std::stack<int,std::vector<int> > real3;
	std::stack<int,std::vector<int> > real4(real_vector);	
	std::stack<int,std::list<int> > real5(real_list);


	ft::stack<int> own1;
	ft::stack<int> own2;	
	ft::stack<int,ft::vector<int> > own3;
	ft::stack<int,ft::vector<int> > own4(own_vector);
	std::stack<int,ft::list<int> > own5(real_list);
	
	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
	REQUIRE(own5.size() == real5.size());
	REQUIRE(own5.top() == real5.top());
	REQUIRE(own5.back() == real5.back());
}

TEST_CASE("stack-size function", "[stack]")
{
	std::vector<int> real_vector(10, 3);
	ft::vector<int> own_vector(10, 3);

	std::list<int> real_list(4, 100);
	ft::list<int> own_list(4, 100);
	

	std::stack<int> real1;
	std::stack<int> real2;
	std::stack<int,std::vector<int> > real3;
	std::stack<int,std::vector<int> > real4(real_vector);	
	std::stack<int,std::list<int> > real5(real_list);


	ft::stack<int> own1;
	ft::stack<int> own2;	
	ft::stack<int,ft::vector<int> > own3;
	ft::stack<int,ft::vector<int> > own4(own_vector);
	std::stack<int,ft::list<int> > own5(real_list);
	
	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
	REQUIRE(own5.size() == real5.size());

	own1.push(1);
	own2.push(1);
	own3.push(1);
	own4.push(1);
	own5.push(1);
	real1.push(1);
	real2.push(1);
	real3.push(1);
	real4.push(1);
	real5.push(1);

	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
	REQUIRE(own5.size() == real5.size());

	own1.pop();
	own2.pop();
	own3.pop();
	own4.pop();
	own5.pop();
	real1.pop();
	real2.pop();
	real3.pop();
	real4.pop();
	real5.pop();

	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
	REQUIRE(own5.size() == real5.size());
}

TEST_CASE("stack-top function", "[stack]")
{
	std::vector<int> real_vector(10, 3);
	ft::vector<int> own_vector(10, 3);

	std::list<int> real_list(4, 100);
	ft::list<int> own_list(4, 100);
	

	std::stack<int> real1(real_vector);
	std::stack<int> real2(real_list);
	std::stack<int,std::vector<int> > real3(own_vector);
	std::stack<int,std::vector<int> > real4(real_vector);	
	std::stack<int,std::list<int> > real5(real_list);


	ft::stack<int> own1(own_vector);
	ft::stack<int> own2(own_list);	
	ft::stack<int,ft::vector<int> > own3(own_vector);
	ft::stack<int,ft::vector<int> > own4(own_vector);
	std::stack<int,ft::list<int> > own5(real_list);
	
	REQUIRE(own1.top() == real1.top());
	REQUIRE(own2.top() == real2.top());
	REQUIRE(own3.top() == real3.top());
	REQUIRE(own4.top() == real4.top());
	REQUIRE(own5.top() == real5.top());

	own1.push(1);
	own2.push(1);
	own3.push(1);
	own4.push(1);
	own5.push(1);
	real1.push(1);
	real2.push(1);
	real3.push(1);
	real4.push(1);
	real5.push(1);

	REQUIRE(own1.top() == real1.top());
	REQUIRE(own2.top() == real2.top());
	REQUIRE(own3.top() == real3.top());
	REQUIRE(own4.top() == real4.top());
	REQUIRE(own5.top() == real5.top());

	own1.pop();
	own2.pop();
	own3.pop();
	own4.pop();
	own5.pop();
	real1.pop();
	real2.pop();
	real3.pop();
	real4.pop();
	real5.pop();

	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
	REQUIRE(own5.size() == real5.size());
}

TEST_CASE("stack-push function", "[stack]")
{
	std::vector<int> real_vector(10, 3);
	ft::vector<int> own_vector(10, 3);

	std::list<int> real_list(4, 100);
	ft::list<int> own_list(4, 100);
	

	std::stack<int> real1(real_vector);
	std::stack<int> real2(real_list);
	std::stack<int,std::vector<int> > real3(own_vector);
	std::stack<int,std::vector<int> > real4(real_vector);	
	std::stack<int,std::list<int> > real5(real_list);


	ft::stack<int> own1(own_vector);
	ft::stack<int> own2(own_list);	
	ft::stack<int,ft::vector<int> > own3(own_vector);
	ft::stack<int,ft::vector<int> > own4(own_vector);
	std::stack<int,ft::list<int> > own5(real_list);

	int sum = 22;
	
	REQUIRE(own1.top() == real1.top());
	REQUIRE(own2.top() == real2.top());
	REQUIRE(own3.top() == real3.top());
	REQUIRE(own4.top() == real4.top());
	REQUIRE(own5.top() == real5.top());

	for (int i = 0; i < 10; ++i)
	{
		own1.push(sum);
		own2.push(sum);
		own3.push(sum);
		own4.push(sum);
		own5.push(sum);
		real1.push(sum);
		real2.push(sum);
		real3.push(sum);
		real4.push(sum);
		real5.push(sum);
		sum += 14;
	}

	REQUIRE(own1.top() == real1.top());
	REQUIRE(own2.top() == real2.top());
	REQUIRE(own3.top() == real3.top());
	REQUIRE(own4.top() == real4.top());
	REQUIRE(own5.top() == real5.top());


	own1.pop();
	own2.pop();
	own3.pop();
	own4.pop();
	own5.pop();
	real1.pop();
	real2.pop();
	real3.pop();
	real4.pop();
	real5.pop();

	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
	REQUIRE(own5.size() == real5.size());
}

TEST_CASE("stack-pop function", "[stack]")
{
	std::vector<int> real_vector(10, 3);
	ft::vector<int> own_vector(10, 3);

	std::list<int> real_list(4, 100);
	ft::list<int> own_list(4, 100);
	

	std::stack<int> real1(real_vector);
	std::stack<int> real2(real_list);
	std::stack<int,std::vector<int> > real3(own_vector);
	std::stack<int,std::vector<int> > real4(real_vector);	
	std::stack<int,std::list<int> > real5(real_list);


	ft::stack<int> own1(own_vector);
	ft::stack<int> own2(own_list);	
	ft::stack<int,ft::vector<int> > own3(own_vector);
	ft::stack<int,ft::vector<int> > own4(own_vector);
	std::stack<int,ft::list<int> > own5(real_list);

	int sum = 22;
	
	REQUIRE(own1.top() == real1.top());
	REQUIRE(own2.top() == real2.top());
	REQUIRE(own3.top() == real3.top());
	REQUIRE(own4.top() == real4.top());
	REQUIRE(own5.top() == real5.top());

	for (int i = 0; i < 10; ++i)
	{
		own1.push(sum);
		own2.push(sum);
		own3.push(sum);
		own4.push(sum);
		own5.push(sum);
		real1.push(sum);
		real2.push(sum);
		real3.push(sum);
		real4.push(sum);
		real5.push(sum);
		sum += 14;
	}

	REQUIRE(own1.top() == real1.top());
	REQUIRE(own2.top() == real2.top());
	REQUIRE(own3.top() == real3.top());
	REQUIRE(own4.top() == real4.top());
	REQUIRE(own5.top() == real5.top());

	for (int i = 0; i < 5; ++i)
	{
		own1.pop();
		own2.pop();
		own3.pop();
		own4.pop();
		own5.pop();
		real1.pop();
		real2.pop();
		real3.pop();
		real4.pop();
		real5.pop();
	}

	REQUIRE(own1.top() == real1.top());
	REQUIRE(own2.top() == real2.top());
	REQUIRE(own3.top() == real3.top());
	REQUIRE(own4.top() == real4.top());
	REQUIRE(own5.top() == real5.top());

	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
	REQUIRE(own5.size() == real5.size());
}