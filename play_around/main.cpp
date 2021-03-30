/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 16:32:05 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/03/30 17:03:29 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>


int main ()
{
	int sum = 0;
	std::vector<int> tim(10);

	for (int i = 0; i < 10; i++)
	{
		tim[i] = sum;
		sum += 1;
	}		
	std::vector<int>::iterator it = tim.begin();
	// std::vector<int>::iterator ite = tim.end();
	for (size_t i = 0; i < tim.size(); ++i)
		std::cout << ' ' << tim[i];
	std::cout << "\nSIZE: " << tim.size() << std::endl;
	std::cout << "Position: " << *it << std::endl;
	++it;
	++it;
	std::cout << "Position: " << *it << std::endl;

	std::vector<int>::iterator it2 = tim.insert(it, 5, 2);
	std::cout << *it2 << std::endl;
	// ++it2; ++it2; ++it2; ++it2; ++it2; ++it2;
	--it2;
	std::cout << *it2 << std::endl;

	std::cout << "AFTER INSERT" << std::endl;
	for (size_t i = 0; i < tim.size(); ++i)
		std::cout << ' ' << tim[i];
	std::cout << '\n';
	std::cout << "SIZE: " << tim.size() << std::endl;


  return 0;
}