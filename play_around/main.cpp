/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 16:32:05 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/03/31 11:55:10 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>


int main ()
{
	// 	ft::vector<int>		own1(5, 100);
	// ft::vector<int>		own2;
	std::vector<int>	real1(5, 100);
	std::vector<int>	real2;

	// ft::vector<int>::iterator own_it = own1.begin();
	// ft::vector<int>::iterator own_ite = own1.end();
	std::vector<int>::iterator real_it = real1.begin();
	std::vector<int>::iterator real_ite = real1.end() -1;

	// own2.assign(own_it, own_ite);
	real2.assign(real_it, real_ite);

	for(size_t i = 0; i < real2.size(); i++)
		std::cout << " " << real2[i];
	std::cout << "\n";

	// REQUIRE(own2.capacity() == real2.capacity());
	// REQUIRE(own2.size() == real2.size());
	// REQUIRE(own2[0] == real2[0]);
	// REQUIRE(own2[1] == real2[1]);
	// REQUIRE(own2[2] == real2[2]);

  return 0;
}