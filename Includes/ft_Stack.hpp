/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_Stack.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 15:14:08 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/20 12:43:36 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_HPP
# define FT_LIST_HPP

# include <iostream>
# include "ft_List.hpp"

namespace ft
{
	template <class T, class Container = list<T> > 
	class stack
	{
		public:
			typedef T				value_type;
			typedef size_t			size_type;
			typedef Container		container_type;
		
		private:
			
			Container	_container;

		public:

		/* ------------ MEMBER FUNCTIONS ------------ */
		
		/* EMPTY CONTAINER CONSTRUCTOR--> Constructs an empty 
		container, with no elements. */
		explicit stack(const container_type& ctnr = container_type()) : _container(ctnr) { return; }
	}; // end of STACK class
	
} // end of namespace ft
#endif