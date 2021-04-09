/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/09 09:33:13 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/09 10:48:01 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_HPP
# define FT_LIST_HPP

# include <iostream>
# include <string>
# include <memory>
# include <algorithm>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > 
	class list
	{
		public:
			typedef T                        value_type;
        	typedef Alloc                    allocator_type;
        	typedef T&                       reference;
        	typedef const T&                 const_reference;
        	typedef T*                       pointer;
        	typedef const T*                 const_pointer;
			typedef std::ptrdiff_t           difference_type;
			typedef size_t                   size_type;
			typedef listNode<T>				 node_pointer;
			
			
		private:
			
		public:
			

			
	}; // end of list class
}

#endif // end of ft namespace