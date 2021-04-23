/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_Queue.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 15:17:00 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/23 10:43:34 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_HPP
# define FT_QUEUE_HPP

# include <iostream>
# include <deque>
# include "ft_List.hpp"

namespace ft
{
	template <class T, class Container = std::deque<T> > 
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
		
		/* EMPTY CONTAINER CONSTRUCTOR--> Constructs an empty 
		container, with no elements. */
		explicit queue(const container_type& ctnr = container_type()) : _container(ctnr) { return; }
		
		/*EMPTY--> Returns whether the queue is empty: 
		i.e. whether its size is zero.

		This member function effectively calls member 
		empty of the underlying container object. */
		bool empty() const { return _container.empty(); }
	
		/* SIZE--> Returns the number of elements 
		in the queue.

		This member function effectively calls 
		member size of the underlying container 
		object. */
		size_type size() const { return _container.size(); }
		
		/* FRONT--> Returns a reference to the next element 
		in the queue.

		The next element is the "oldest" element 
		in the queue and the same element that is 
		popped out from the queue when queue::pop is 
		called.

		This member function effectively calls member 
		front of the underlying container object. */
		T& front() { return _container.front(); }
		const T& front() const { return _container.front(); }

		/* Returns a reference to the last element 
		in the queue. This is the "newest" element 
		in the queue (i.e. the last element pushed 
		into the queue).

		This member function effectively calls member 
		back of the underlying container object. */
		T& back() { return _container.back(); }
		const T& back() const { return _container.back(); }

		/* PUSH--> Inserts a new element at the end of 
		the queue, after its current last element. 
		The content of this new element is initialized 
		to val.

		This member function effectively calls the member 
		function push_back of the underlying container 
		object. */
		void push(const value_type& val) { _container.push_back(val); return;}

		/* POP--> Removes the next element in the queue, 
		effectively reducing its size by one.

		The element removed is the "oldest" element in 
		the queue whose value can be retrieved by calling 
		member queue::front.

		This calls the removed element's destructor.

		This member function effectively calls the 
		member function pop_front of the underlying 
		container object. */
		void pop() { _container.pop_front(); return; }

		/* ------------ RELATIONAL OPERATORS ------------ */
		template <class value_type2, class ctnr2>
		friend bool operator==(const queue<value_type2, ctnr2>& lhs, const queue<value_type2, ctnr2>& rhs);
		
		template <class value_type2, class ctnr2>
		friend bool operator<(const queue<value_type2, ctnr2>& lhs, const queue<value_type2, ctnr2>& rhs);
	}; // end of QUEUE class
	
	/* ------------ NON-MEMBER FUNCTION OVERLOADS ------------ */
	template <class value_type, class ctnr>
	bool operator==(const queue<value_type, ctnr>& lhs, const queue<value_type, ctnr>& rhs)
	{
		return (lhs._container == rhs._container);
	}
	
	template <class value_type, class ctnr>
	bool operator<(const queue<value_type, ctnr>& lhs, const queue<value_type, ctnr>& rhs)
	{
		return (lhs._container < rhs._container);
	}
	template <class value_type, class ctnr>
	bool operator!=(const queue<value_type, ctnr>& lhs, const queue<value_type, ctnr>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class value_type, class ctnr>
	bool operator<=(const queue<value_type, ctnr>& lhs, const queue<value_type, ctnr>& rhs)
	{
		return !(rhs < lhs);
	}
	
	template <class value_type, class ctnr>
	bool operator>(const queue<value_type, ctnr>& lhs, const queue<value_type, ctnr>& rhs)
	{
		return (rhs < lhs);
	}
	
	template <class value_type, class ctnr>
	bool operator>=(const queue<value_type, ctnr>& lhs, const queue<value_type, ctnr>& rhs)
	{
		return !(lhs < rhs);
	}

} // end of namespace ft

#endif
