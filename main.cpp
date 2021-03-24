/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 14:57:16 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/03/24 13:50:25 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "ft_vector.hpp"

int main(void)
{
	std::cout << "\n***********************CONSTRUCTOR***********************\n" << std::endl;
	ft::vector<int> own(5, 3);
	std::vector<int> real(5, 3);

	std::vector<int> own_empty;
	std::vector<int> real_empty;
	

	for (size_t i = 0; i < 5 ; i++)
		std::cout << "tim i: " << i << ":  " << own[i] << std::endl;
	

	for (size_t i = 0; i < 5 ; i++)
		std::cout << "tim2 i: " << i << ":  " << real[i] << std::endl;
	
	std::cout << "\n***********************CAPACITY***********************\n" << std::endl;
	std::cout << "-----------------\nMAX_SIZE" << std::endl;
	std::cout << "Own: " << own.max_size() << std::endl;
	std::cout << "Real: " << real.max_size() << std::endl;
	
	std::cout << "-----------------\nSIZE" << std::endl;
	std::cout << "Own: " << own.size() << std::endl;
	std::cout << "Real: " << real.size() << std::endl;

	std::cout << "-----------------\nCAPACITY" << std::endl;
	std::cout << "Own: " << own.capacity() << std::endl;
	std::cout << "Real: " << real.capacity() << std::endl;

	std::cout << "-----------------\nEMPTY" << std::endl;
	std::cout << std::boolalpha;
	std::cout << "Own: " << own.empty() << std::endl;
	std::cout << "Real: " << real.empty() << std::endl;

	std::cout << "\nOwn: " << own_empty.empty() << std::endl;
	std::cout << "Real: " << real_empty.empty() << std::endl;

	std::cout << "\n***********************ELEMENT ACCESS***********************\n" << std::endl;
	std::cout << "-----------------\nOPERATOR[]" << std::endl;
	std::cout << "Own: " << own[4] << std::endl;
	std::cout << "Real: " << own[4] << std::endl;
	std::cout << "-----------------\nAT" << std::endl;
	std::cout << real.at(4) << std::endl;
	std::cout << own.at(4) << std::endl;
	
	std::cout << "\n_____DESTRUCTOR_____" << std::endl;
	return (0);
}