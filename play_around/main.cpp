/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 16:32:05 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/04/22 14:23:47 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


// #include <iostream>       // std::cout
// #include <string>         // std::string
// #include <list>

// void	print(std::list<double> hoi)
// {
// 	std::list<double>::iterator it = hoi.begin();
// 	while (it != hoi.end())
// 	{
// 		std::cout << " " << *it;
// 		++it;
// 	}
// 	std::cout << std::endl;
// }

// // compare only integral part:
// bool mycomparison (double first, double second)
// { return ( int(first)<int(second) ); }

#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;  // 5 default-constructed ints


	for (int i = 0; i < 6; ++i) myvector.push_back(i);
  std::vector<int>::reverse_iterator rit = myvector.rend();
	std::cout << "*RIT: " << *rit << std::endl;
	--rit;
	--rit;

	std::cout << "*RIT: " << *rit << std::endl;

	for (size_t i = 0; i < myvector.size(); ++i)
	{
		std::cout << " " << myvector[i];
	}
//   int i=0;
//   for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
//     *rit = ++i;

//   std::cout << "myvector contains:";
//   for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

  return 0;
}