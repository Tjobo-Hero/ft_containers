/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vector.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 14:57:13 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/03/29 13:43:57 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <memory>
#include <vector>
#include "RandomAccessIterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > 
	class vector
	{
		public:

			typedef random_access_iterator<T>				iterator;
			typedef const_random_access_iterator<T>			const_iterator;
			typedef reverse_random_access_iterator<T>		reverse_iterator;
			typedef const_reverse_random_access_iterator<T>	const_reverse_iterator;
			
		private:

			T*		_data;
			size_t	_capacity;
			size_t	_size;
			Alloc	_allocator;
		
		public:
		 
		/* ------------ Member Functions ------------ */
		 
		/* Constructor--> Construct Vector */
		explicit vector(const Alloc& alloc = Alloc()) : 
			_data(NULL), 
			_capacity(0),
			_size(0), 
			_allocator(alloc) {}
		
		explicit vector(size_t n, const T& val = T(), const Alloc& alloc = Alloc()) : 
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
				 
		vector(const vector& x) : 
			_capacity(x._capacity), 
			_size(x._size), 
			_allocator(x._allocator) 
		{
			this->_data = _allocator.allocate(x._capacity);
			for (size_t i = 0; i < x._size; i++)
				this->_data[i] = x._data[i];
		}
		
		/* DESTRUCTOR--> Vector Destructor */ 
		~vector()
		{
			_allocator.deallocate(_data, _capacity);
			return;
		}
		/* OPERATOR= FUNCTION --> Assign content */ 
		vector& operator= (const vector& obj)
		{
			if (this != &obj)
			{
				this->clear();
				this->_allocator = obj._allocator;
				this->assign(obj.begin(), obj.end());
			}
			return *this;
		}
		/* ------------ ITERATORS ------------ */
		
		/* BEGIN--> Return Iterator to beginning of array */ 
		iterator begin() { return iterator(_data); }
		// const_iterator begin() const { return const_iterator(_data); }
		
		// /* END--> Return Iterator to end */
		iterator end() { return iterator(&_data[_size]); }
		// const_iterator end() const { return const_iterator(_data[_size]); }
		
		// /* RBEGIN--> rbegin points to the element right before the one that would be pointed to by member end. */
		// reverse_iterator rbegin() { return reverse_iterator(_data[_size - 1]); }										// Checken of het geen reference moet zijn
		// const_reverse_iterator rbegin() const {return const_reverse_iterator(_data[_size - 1]); }						// Checken of het geen reference moet zijn
		
		// /* REND--> Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector */ 
		// reverse_iterator rend() { return reverse_iterator(&_data - 1); } 												// Checken of dit goed is 
		// const_reverse_iterator rend() const { return const_reverse_iterator(&_data - 1); }								// Checken of dit goed is 
		
		/* ------------ CAPACITY ------------ */
		
		/* SIZE--> Return Size */
		size_t size() const { return this->_size; }
		
		/* MAX_SIZE--> Return maximum size */
		size_t max_size() const { return _allocator.max_size(); }

		/* RESIZE--> Change size */
		void resize (size_t n, T val = T ())
		{
			if (n < this->_size)
			{
				for(; n < this->_size; this->_size--)
					_allocator.destroy(&_data[_size]);

			}
			else if (n > this->_size)
			{
				reserve(n);
				for (; n > this->_size; _size++)
						_data[_size] = val;
			}
		}
		/* CAPACITY--> Return size of allocated storage capacity */
		size_t capacity() const { return this->_capacity; }
		
		/* EMPTY--> Test whether vector is empty */
		bool empty() const
		{
			if (this->_size == 0)
				return true;
			else
				return false;
			
		}
		/* RESERVE--> Request a change in capacity */
		void reserve(size_t n)
		{
			if (n > max_size())
				throw length_error();
			else if (n > this->_capacity)
			{
				T* tmp;
				
				tmp = _allocator.allocate(n + 1);
				if (_size > 0)
				{
					for (size_t i = 0; i < this->_size; i++)
						tmp[i]  = _data[i];
					tmp[n] = T ();
					_allocator.deallocate(_data, _capacity);
				}
				_data = tmp;
				_capacity = n;
			}
			else
				return;
		}
		
		/* ------------ ELEMENT ACCESS ------------ */
		
		/*OPERATOR[]--> Access element */
		T& operator[](size_t n) { return this->_data[n]; }
		const T& operator[] (size_t n) const { return this->_data[n]; };
				
		/* AT--> Access element */
		T& at(size_t n)
		{
			if (n < _size)
				return this->_data[n];
			else
				throw out_of_range();
			
		}
		const T& at(size_t n) const
		{
			if (n < _size)
				return this->_data[n];
			else
				throw out_of_range();
		}
		/* FRONT--> Access first element*/
		T& front() { return _data[0]; }
		const T& front() const { return _data[0]; }
		
		/* BACK--> Acces last element*/ 
		T& back() { return _data[_size - 1]; }
		const T& back() const { return _data[_size - 1]; }
		
		/* ------------ MODIFIERS ------------ */
		
		/* ASSIGN--> Assign vector content */ 
		// template <class InputIterator>
  		// void assign (InputIterator first, InputIterator last);

		void assign (size_t n, const T& val)
		{
			this->clear();
			this->reserve(n);
			this->_size = n;
			for (size_t i = 0; i < this->size(); i++)
				this->_data[i] = val;
		}
		
		// push_back--> Add element at the end
		// pop_back--> Delete last element
		// insert--> Insert elements
		// erase--> Erase elements
		// swap--> Swap content
		/*CLEAR--> Clear content */
		void clear()
		{
			for (size_t i = 0; i < this->size(); i++)
				_allocator.destroy(&this->_data[i]);
			this->_size = 0;
		}

		/* ------------ RELATIONAL OPERATORS ------------ */
		// template <class T, class Alloc>
		// bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		// template <class T, class Alloc>
		// bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		// template <class T, class Alloc>
		// bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		// template <class T, class Alloc>
		// bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		// template <class T, class Alloc>
		// bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		// template <class T, class Alloc>
		// bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		
		/*Exceptions */

		class out_of_range : public std::exception
		{
			virtual const char*	what() const throw() 
			{
				return "vector";
			}
		};
		
		class length_error : public std::exception
		{
			virtual const char*	what() const throw() 
			{
				return "'n' exceeds maximum supported size";
			}
		};
	};
}

#endif