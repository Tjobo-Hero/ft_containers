/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 16:32:05 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/04/16 11:04:50 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>       // std::cout
#include <string>         // std::string
#include <list>

void	print(std::list<int> hoi)
{
	std::list<int>::iterator it = hoi.begin();
	while (it != hoi.end())
	{
		std::cout << " " << *it;
		++it;
	}
	std::cout << std::endl;
}
int main ()
{
	
	std::list<int>	real;
	std::list<int>	real2(5, 100);

	for (int i = 1; i < 5; ++i) real.push_back(i);

	std::list<int>::iterator it = real.end();
	std::list<int>::iterator ite = real.begin();


	// real.splice(it, real);
	// print(real);
	// ++it;
	--it;
	real.splice(it, real2, ite);

	print(real);
	return(0);
}