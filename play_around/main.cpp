/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 16:32:05 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/04/19 12:32:51 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>       // std::cout
#include <string>         // std::string
#include <list>

void	print(std::list<double> hoi)
{
	std::list<double>::iterator it = hoi.begin();
	while (it != hoi.end())
	{
		std::cout << " " << *it;
		++it;
	}
	std::cout << std::endl;
}

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

int main ()
{
	
	
	std::list<double> first, second;

  first.push_back (3.1);
  first.push_back (2.2);
  first.push_back (2.9);

  second.push_back (3.7);
  second.push_back (7.1);
  second.push_back (1.4);

  first.sort();
  second.sort();

  first.merge(second);

  // (second is now empty)
  print(first);
  second.push_back (3.4);

  first.merge(second,mycomparison);

  std::cout << "first contains:";
  for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}