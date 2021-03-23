/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vector.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 14:57:13 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/03/23 16:43:40 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <memory>
#include <vector>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > 
	class vector
	{
		private:

			T*		_data;
			size_t	_capacity;
			size_t	_current_size;
			Alloc	_allocate;
		
		public:
		 /* Member Functions */
		 
		// Constructor--> Construct Vector
		explicit vector (const allocator_type& alloc = allocator_type());
		
		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
				 
		template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());
				 
		vector (const vector& x);
		// Destructor--> Vector Destructor
		// Assignation operator function --> Assign content
		
		/* Iterators */
		// begin--> Return Iterator to beginning
		// end--> Return iterator to end
		// rbegin--> Return reverse iterator to reverse beginning
		// rbegin--> Return reverse iterator to reverse end
		// cbegin--> Return const_iterator to beginning
		// cend--> Return const_iterator to end
		// crbegin --> Return const_reverse_iterator to reverse beginning
		// crend--> Return const_reverse_iterator to reverse end
		
		/* Capacity */
		// size--> Return Size
		// max_size--> Return maximum size
		// resize--> Change size
		// capacity--> Return size of allocated storage capacity
		// empty--> Test whether vector is empty
		// reserve--> Request a change in capacity
		
		/* Element access */
		// operator[]--> Access element
		// at--> Access element
		// front--> Access first element
		// back--> Acces last element
		
		/* Modifiers */
		// assign--> Assign vector content
		// push_back--> Add element at the end
		// pop_back--> Delete last element
		// insert--> Insert elements
		// erase--> Erase elements
		// swap--> Swap content
		// clear--> Clear content 
		
	};
}

#endif