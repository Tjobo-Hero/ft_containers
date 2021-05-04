/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 16:32:05 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/05/04 12:35:38 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

int 	main()
{
	std::map<int, int>	test;
	int sum = 1;
	for (int i = 0; i < 6; ++i)
	{
		test.insert(std::pair<int, int>(sum, sum));
		sum += 1;
	}
	std::map<int, int>::iterator	it;
	for (it = test.begin(); it != test.end(); ++it)
		std::cout << " " << it->first;
	std::cout << "\n";

	std::map<int, int>	test2(test);
	for (it = test2.begin(); it != test2.end(); ++it)
		std::cout << " " << it->first;
	std::cout << "\n";
}