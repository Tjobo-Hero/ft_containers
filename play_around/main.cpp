/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 16:32:05 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/04/15 13:44:25 by timvancitte   ########   odam.nl         */
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
	std::list<int>	hoi;

	// int sum = 5;
	
	for (int i = 0; i < 10; ++i)
	{
		hoi.push_back(i);
		// sum += 5;
	}
	
	print(hoi);


	std::list<int>::iterator it = hoi.begin();
	++it;
	++it;
	
	it = hoi.erase(it);

	std::cout << "return: " << *it << std::endl;

	print(hoi);
  
  return 0;
}