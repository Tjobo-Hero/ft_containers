/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 16:32:05 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/03/26 14:44:49 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>


int main ()
{
	std::vector<int> tim(10);

	for (int i = 0; i < 10; i++)
		tim[i] = rand() % 20;
		
	std::vector<int>::iterator it = tim.begin();
	std::vector<int>::iterator ite = tim.end();

	ite--;
	std::cout << std::boolalpha;
	std::cout << *it << " " << *ite << std::endl;
	bool result = it <= ite;
	std::cout << result << std::endl;

  return 0;
}