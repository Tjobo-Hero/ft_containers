/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 16:32:05 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/03/24 17:03:22 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> real(5, 3);

 for (size_t i = 0; i < real.size() ; i++)
		std::cout << "real: " << i << ":  " << real[i] << std::endl;
	real.resize(2);
	std::cout << "After resize" << std::endl;
	for (size_t i = 0; i < real.size() ; i++)
		std::cout << "real: " << i << ":  " << real[i] << std::endl;
	std::cout << "\n";
	real.resize(8, 100);
    real.resize(12);
	// real.resize(12);
	// std::cout <<"Size: " << real.size() << std::endl;
	for (size_t i = 0; i < real.size() ; i++)
		std::cout << "real: " << i << ":  " << real[i] << std::endl;

  return 0;
}