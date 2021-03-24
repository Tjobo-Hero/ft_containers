/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 14:57:16 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/03/23 17:36:51 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "ft_vector.hpp"

int main(void)
{
	ft::vector<int> tim(5, 3);
	ft::vector<int> tim2(tim);

	for (size_t i = 0; i < 5 ; i++)
		std::cout << "tim i: " << i << ":  " << tim[i] << std::endl;
	
	std::cout << "Size: [" << tim.size() << "]" << std::endl;

	for (size_t i = 0; i < 5 ; i++)
		std::cout << "tim2 i: " << i << ":  " << tim2[i] << std::endl;
	
	return (0);
}