/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 14:57:16 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/03/29 14:59:37 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
// #include <iostream>
// #include <vector>
// #include "ft_vector.hpp"

// int main(void)
// {
// 	std::cout << "\n***********************CONSTRUCTOR***********************\n" << std::endl;
// 	// ft::vector<int> own(5, 3);
// 	// std::vector<int> real(5, 3);

// 	// ft::vector<int> own_empty;
// 	// std::vector<int> real_empty;
	

// 	// for (size_t i = 0; i < 5 ; i++)
// 	// 	std::cout << "tim i: " << i << ":  " << own[i] << std::endl;
	

// 	// for (size_t i = 0; i < real.size() ; i++)
// 	// 	std::cout << "Real: " << i << ":  " << real[i] << std::endl;
	
// 	// std::cout << "\n*********************** ITERATORS ***********************\n" << std::endl;
// 	// ft::vector<int> tim(10);

// 	// for (int i = 0; i < 10; i++)
// 	// 	tim[i] = rand() % 20;
		
// 	// ft::vector<int>::iterator it = tim.begin();
// 	// ft::vector<int>::iterator ite = tim.end();

// 	// ite--;
// 	// std::cout << std::boolalpha;
// 	// std::cout << *it << " " << *ite << std::endl;
// 	// bool result = it < ite;
// 	// std::cout << result << std::endl;
// 	// // std::cout << "\n***********************CAPACITY***********************\n" << std::endl;
// 	// // std::cout << "-----------------\nSIZE" << std::endl;
// 	// // std::cout << "Own: " << own.size() << std::endl;
// 	// // std::cout << "Real: " << real.size() << std::endl;
	
// 	// // std::cout << "-----------------\nMAX_SIZE" << std::endl;
// 	// // std::cout << "Own: " << own.max_size() << std::endl;
// 	// // std::cout << "Real: " << real.max_size() << std::endl;

// 	// std::cout << "-----------------\nRESIZE" << std::endl;
// 	// for (size_t i = 0; i < real.size() ; i++)
// 	// 	std::cout << "Real: " << i << ":  " << real[i] << std::endl;
// 	// std::cout << "Size: " << real.size() << std::endl;
// 	// real.resize(5);
// 	// std::cout << "Size: " << real.size() << std::endl;
// 	// std::cout << "\n\n";
// 	// real.resize(8, 100);
// 	// for (size_t i = 0; i < real.size() ; i++)
// 	// 	std::cout << "Real: " << i << ":  " << real[i] << std::endl;
// 	// std::cout << "Size-->" << real.size() << std::endl;
// 	// real.resize(12);
// 	// for (size_t i = 0; i < real.size() ; i++)
// 	// 	std::cout << "Real: " << i << ":  " << real[i] << std::endl;
// 	// std::cout << "Size: " << real.size() << "\n\n" << std::endl;
// 	// for (size_t i = 0; i < real.size() ; i++)
// 	// 	std::cout << "Own: " << i << ":  " << real[i] << std::endl;
	
// 	// std::cout << "\n\n";
	
// 	// for (size_t i = 0; i < own.size() ; i++)
// 	// 	std::cout << "Own: " << i << ":  " << own[i] << std::endl;
// 	// own.resize(2);
// 	// std::cout << "After resize" << std::endl;
// 	// for (size_t i = 0; i < own.size() ; i++)
// 	// 	std::cout << "Own: " << i << ":  " << own[i] << std::endl;
// 	// std::cout << "\n";
// 	// own.resize(8, 100);
// 	// own.resize(12);
// 	// // own.resize(12);
// 	// // std::cout <<"Size: " << own.size() << std::endl;
// 	// for (size_t i = 0; i < own.size() ; i++)
// 	// 	std::cout << "Own: " << i << ":  " << own[i] << std::endl;
	

// 	// std::cout << "-----------------\nCAPACITY" << std::endl;
// 	// std::cout << "Own: " << own.capacity() << std::endl;
// 	// std::cout << "Real: " << real.capacity() << std::endl;

// 	// std::cout << "-----------------\nEMPTY" << std::endl;
// 	// std::cout << std::boolalpha;
// 	// std::cout << "Own: " << own.empty() << std::endl;
// 	// std::cout << "Real: " << real.empty() << std::endl;

// 	// std::cout << "\nOwn: " << own_empty.empty() << std::endl;
// 	// std::cout << "Real: " << real_empty.empty() << std::endl;

// 	// std::cout << "-----------------\nRESERVE" << std::endl;
// 	// std::cout << "Real: "<< real.capacity() << std::endl;
// 	// real.reserve(100);
// 	// std::cout << "Real: "<< real.capacity() << std::endl;
// 	// for (size_t i = 0; i < 10 ; i++)
// 	// 	std::cout << "Real " << i << ":  " << real[i] << std::endl;
		
// 	// std::cout << "\nOwn: " << own.capacity() << std::endl;
// 	// own.reserve(100);
// 	// std::cout << "Own: " << own.capacity() << std::endl;
// 	// for (size_t i = 0; i < 10 ; i++)
// 	// 	std::cout << "own " << i << ":  " << own[i] << std::endl;

// 	// real.reserve(46116860184273879034);


// 	// std::cout << "\n***********************ELEMENT ACCESS***********************\n" << std::endl;
// 	// std::cout << "-----------------\nOPERATOR[]" << std::endl;
// 	// std::cout << "Own: " << own[4] << std::endl;
// 	// std::cout << "Real: " << own[4] << std::endl;
// 	// std::cout << "-----------------\nAT" << std::endl;
// 	// std::cout << real.at(4) << std::endl;
// 	// std::cout << own.at(4) << std::endl;
// 	// std::cout << "-----------------\nFRONT" << std::endl;
// 	// std::cout << "Own: " << own.front() << std::endl;
// 	// std::cout << "Real: " << real.front() << std::endl;
	
// 	// own[own.size() - 1] = 100;
// 	// real[real.size() - 1] = 100;
// 	// std::cout << "-----------------\nBACK" << std::endl;
// 	// std::cout << "Own: " << own.back() << std::endl;
// 	// std::cout << "Real: " << real.back() << std::endl;
// 	// std::cout << "\n*********************** MODIFIERS ***********************\n" << std::endl;
// 	// for (size_t i = 0; i < real.size() ; i++)
// 	// 	std::cout << "Real: " << i << ":  " << real[i] << std::endl;
// 	// std::cout << "Capacity: "<< real.capacity() << std::endl;
// 	// real.assign(10, 100);
// 	// std::cout << "Capacity: "<< real.capacity() << std::endl;
// 	// real.assign(5, 200);
// 	// std::cout << "Capacity: "<< real.capacity() << std::endl;
// 	// std::cout << "\nAFTER ASSIGN\n" << std::endl;
// 	// for (size_t i = 0; i < real.size() ; i++)
// 	// 	std::cout << "Real: " << i << ":  " << real[i] << std::endl;
	
// 	// std::cout << "\n\n";
	
// 	// for (size_t i = 0; i < own.size() ; i++)
// 	// 	std::cout << "own: " << i << ":  " << own[i] << std::endl;
// 	// std::cout << "Capacity: "<< own.capacity() << std::endl;
// 	// own.assign(10, 100);
// 	// std::cout << "Capacity: "<< own.capacity() << std::endl;
// 	// own.assign(5, 200);
// 	// std::cout << "Capacity: "<< own.capacity() << std::endl;
// 	// std::cout << "\nAFTER ASSIGN\n" << std::endl;
// 	// for (size_t i = 0; i < own.size() ; i++)
// 	// 	std::cout << "own: " << i << ":  " << own[i] << std::endl;
	
// 	// std::cout << "\n_____DESTRUCTOR_____" << std::endl;
// 	return (0);
// }