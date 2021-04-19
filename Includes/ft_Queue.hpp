/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_Queue.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 15:17:00 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/19 15:27:31 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_HPP
# define FT_QUEUE_HPP

# include <deque>
# include <iostream>
# include <ft_List.hpp>

namespace ft
{
	
	template <class T, class Container = list<T> > 
	class queue
	{
		public:
			typedef T				value_type;
			typedef size_t			size_type;
			typedef Container		container_type;
		
		private:

			Container	_container;
		
		public:

		/* ------------ MEMBER FUNCTIONS ------------ */

		explicit queue (const container_type& ctnr = container_type()) : _containter(ctnr) { return; }
		
			
		
	
	}; // end of QUEUE class

} // end of namespace ft
#endif