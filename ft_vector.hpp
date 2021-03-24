/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vector.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 14:57:13 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/03/24 13:45:46 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <memory>
#include <vector>
#include <stdexcept>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > 
	class vector
	{
		private:

			T*		_data;
			size_t	_capacity;
			size_t	_size;
			Alloc	_allocator;
		
		public:
		 
		/* ------------Member Functions------------ */
		 
		// Constructor--> Construct Vector
		explicit vector (const Alloc& alloc = Alloc()) : 
			_data(NULL), 
			_capacity(0),
			_size(0), 
			_allocator(alloc) {}
		
		explicit vector (size_t n, const T& val = T(), const Alloc& alloc = Alloc()) : 
			_capacity(n), 
			_size(n), 
			_allocator(alloc)
		{
			_data = _allocator.allocate(n);
			for (size_t i = 0; i < n ; i++)
				_data[i] = val;
		} 
				 
		// template <class InputIterator>
        // vector (InputIterator first, InputIterator last,
        //          const Alloc& alloc = Alloc());
				 
		vector (const vector& x) : 
			_capacity(x._capacity), 
			_size(x._size), 
			_allocator(x._allocator) 
		{
			this->_data = _allocator.allocate(x._capacity);
			for (size_t i = 0; i < x._size; i++)
				this->_data[i] = x._data[i];
		}
		// Destructor--> Vector Destructor
		~vector()
		{
			std::cout << "Vector destructed" << std::endl;
			_allocator.deallocate(_data, _capacity);
			return;
		}
		// Assignation operator function --> Assign content
		
		/* ------------ITERATORS------------ */
		// begin--> Return Iterator to beginning
		// end--> Return iterator to end
		// rbegin--> Return reverse iterator to reverse beginning
		// rbegin--> Return reverse iterator to reverse end
		// cbegin--> Return const_iterator to beginning
		// cend--> Return const_iterator to end
		// crbegin --> Return const_reverse_iterator to reverse beginning
		// crend--> Return const_reverse_iterator to reverse end
		
		/* ------------CAPACITY------------ */
		
		/* SIZE--> Return Size */
		size_t size() const
		{
			return this->_size;	
		}
		/* MAX_SIZE--> Return maximum size */
		size_t max_size() const
		{
			return _allocator.max_size();
		}
		/* RESIZE--> Change size */
		// void resize (size_t n, T val = value_type())
		// {
			
		// }
		/* CAPACITY--> Return size of allocated storage capacity */
		size_t capacity() const
		{
			return this->_capacity;
		}
		
		/* EMPTY--> Test whether vector is empty */
		bool empty() const
		{
			if (this->_size == 0)
				return true;
			else
				return false;
			
		}
		/* RESERVE--> Request a change in capacity */
		
		/* ------------Element access------------ */
		
		/*OPERATOR[]--> Access element */
		T& operator[] (size_t n)
		{
			return this->_data[n];
		}
		/* AT--> Access element */
		T& at (size_t n)
		{
			if (n <= _size)
				return this->_data[n];
			else
				throw out_of_range();
			
		}
		const T& at (size_t n) const
		{
			if (n <= _size)
				return this->_data[n];
			else
				throw out_of_range();
		}
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
		
		/*Exceptions */

		class out_of_range : public std::exception
		{
			virtual const char*	what() const throw() 
			{
				return "vector";
			}
		};
	};
}

#endif