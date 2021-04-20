/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_Stack.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 15:14:08 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/20 17:18:37 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_HPP
# define FT_STACK_HPP

# include <iostream>
# include "ft_List.hpp"

namespace ft
{
	template <class T, class Container = std::deque<T> > 
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

		/* EMPTY--> Returns whether the stack is empty: 
		i.e. whether its size is zero.
		
		This member function effectively calls member 
		empty of the underlying container object. */
		bool empty() const { return _container.empty(); }

		/* SIZE--> Returns the number of elements in the stack.

		This member function effectively calls member 
		size of the underlying container object. */
		size_type size() const { return _cointainer.size(); }

		/* TOP--> Returns a reference to the top element in the stack. 

		Since stacks are last-in first-out containers, the top 
		element is the last element inserted into the stack.

		This member function effectively calls member back 
		of the underlying container object. */
		value_type& top() { return _contianer.back(); }
		const value_type& top() const { return _container.back(); }

		/* PUSH--> Inserts a new element at the top of the stack, 
		above its current top element. The content of this new 
		element is initialized to a copy of val.

		This member function effectively calls the member 
		function push_back of the underlying container object. */
		void push (const value_type& val) { _container.push_back(val); return; }

		/* Removes the element on top of the stack, effectively 
		reducing its size by one.

		The element removed is the latest element inserted 
		into the stack, whose value can be retrieved by 
		calling member stack::top.

		This calls the removed element's destructor.

		This member function effectively calls the member 
		function pop_back of the underlying container object. */
		void pop() { _container.pop_back(); return; }

		/* ------------ RELATIONAL OPERATORS ------------ */
		template <class value_type, class ctnr>
		friend bool operator==(const stack<value_type, ctnr>& lhs, const stack<value_type, ctnr>& rhs)
		{
			return (lhs._container == rhs._container);
		}
		
		template <class value_type, class ctnr>
		friend bool operator!=(const stack<value_type, ctnr>& lhs, const stack<value_type, ctnr>& rhs)
		{
			return (lhs._container != rhs._container);
		}
		
		template <class value_type, class ctnr>
		friend bool operator<(const stack<value_type, ctnr>& lhs, const stack<value_type, ctnr>& rhs)
		{
			return (lhs._container < rhs._container);
		}
	
		template <class value_type, class ctnr>
		friend bool operator<=(const stack<value_type, ctnr>& lhs, const stack<value_type, ctnr>& rhs)
		{
			return (lhs._container <= rhs._container);
		}
		
		template <class value_type, class ctnr>
		friend bool operator>(const stack<value_type, ctnr>& lhs, const stack<value_type, ctnr>& rhs)
		{
			return (lhs._container > rhs._container);
		}
		
		template <class value_type, class ctnr>
		friend bool operator>=(const stack<value_type, ctnr>& lhs, const stack<value_type, ctnr>& rhs)
		{
			return (lhs._container >= rhs._container);
		}
	}; // end of STACK class
	
} // end of namespace ft

#endif
