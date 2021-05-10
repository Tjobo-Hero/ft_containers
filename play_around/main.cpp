/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 16:32:05 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/05/10 12:31:11 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

int 	main()
{
	std::map<int, int>	test;
	std::map<int, int> 	test2;
	int sum = 1;
	for (int i = 0; i < 6; ++i)
	{
		test.insert(std::pair<int, int>(sum, sum));
		sum += 1;
	}

	sum = 1;
	for (int i = 0; i < 3; ++i)
	{
		test2.insert(std::pair<int, int>(sum, sum));
		sum += 1;
	}

	test2.insert(test.begin(), test.end());
	std::map<int, int>::iterator	it;
	for (it = test.begin(); it != test.end(); ++it)
		std::cout << " " << it->first;
	std::cout << "\n";

	// std::map<int, int>	test2(test);
	for (it = test2.begin(); it != test2.end(); ++it)
		std::cout << " " << it->first;
	std::cout << "\n";
}