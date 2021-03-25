/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 16:32:05 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/03/25 14:32:50 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main ()
{
	std::vector<int> test(10);

	for (int i = 0; i < 10; i++)
		test[i] = rand() % 20;	
	
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test[i] << std::endl;
	
	std::vector<int>::iterator it = test.begin();
	std::vector<int>::iterator it2 = it - 5;
	// std::vector<int>::iterator it3 = 

	std::vector<int>::difference_type 	diff = 5;
	// std::vector<int>::difference_type 	diff2;

	it = it + diff;
	std::cout << "\nasdf:" << *it << std::endl;
	std::cout << "\n\nIT: " << *it2 << std::endl;

  return 0;
}