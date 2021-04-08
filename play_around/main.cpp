/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 16:32:05 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/04/08 13:08:48 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>


int main ()
{
	std::vector<int> 	test;
	
	std::vector<int>::iterator it;
	int sum = 0;
	for (int i = 0; i < 10; ++i)
	{
		test.push_back(sum);
		sum += 1;
	}
	for (size_t i = 0; i < test.size(); ++i)
		std::cout << " " << test[i];
	std::cout << "\n";

	it = test.erase(test.begin() + 4);
	std::cout << "IT:" << *it << std::endl;
	for (size_t i = 0; i < test.size(); ++i)
		std::cout << " " << test[i];
	std::cout << "\n";

		it = test.erase(test.begin(), test.end() - 4);
	std::cout << "IT:" << *it << std::endl;
	for (size_t i = 0; i < test.size(); ++i)
		std::cout << " " << test[i];
	std::cout << "\n";

  return 0;
}