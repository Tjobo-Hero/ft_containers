/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Stack_test.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 12:44:15 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/20 12:48:22 by timvancitte   ########   odam.nl         */
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

	std::stack<int> real1;
	std::stack<int> real2;
	std::stack<int,std::vector<int> > real3;
	std::stack<int,std::vector<int> > real4(real_vector);	

	ft::stack<int> own1;
	ft::stack<int> own2;	
	ft::stack<int,ft::vector<int> > own3;
	ft::stack<int,ft::vector<int> > own4(own_vector);	
	
	REQUIRE(own1.size() == real1.size());
	REQUIRE(own2.size() == real2.size());
	REQUIRE(own3.size() == real3.size());
	REQUIRE(own4.size() == real4.size());
}