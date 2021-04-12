/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/09 09:33:13 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/12 13:00:23 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_HPP
# define FT_LIST_HPP

# include <iostream>
# include <string>
# include <memory>
# include <algorithm>
# include "../INCLUDES/ft_listNode.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > 
	class list
	{
		public:
			typedef T						value_type;
			typedef Alloc					allocator_type;
			typedef T&						reference;
			typedef const T&				const_reference;
			typedef T*						pointer;
			typedef const T*				const_pointer;
			typedef std::ptrdiff_t			difference_type;
			typedef size_t					size_type;
			typedef listNode<T>			 	node;
			
		private:
			node*		_head;
			node*		_tail;
			Alloc		_allocator;
			size_t		_size;
			
		public:
			
		/* ------------ MEMBER FUNCTIONS ------------ */

		/* EMPTY CONTAINER CONSTRUCTOR--> Constructs an empty 
		container, with no elements. */
		explicit list (const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(0)
		{
			_head = new listNode<T>();
			_tail = new listNode<T>();
			this->_head->next = this->_tail;
			this->_tail->prev = this->_head;
			return;
		}
		/* FILL CONSTRUCTOR--> Constructs a container 
		with n elements. Each element is a copy of val. */
		explicit list (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(0)
		{
			_head = new listNode<T>();
			_tail = new listNode<T>();
			this->_head->next = this->_tail;
			this->_tail->prev = this->_head;
			assign(n, val);
		}
		
		/* RANGE CONSTRUCTOR--> Constructs a container with 
		as many elements as the range [first,last), with each 
		element constructed from its corresponding element in that 
		range, in the same order.*/
		// template <class InputIterator>
  		// list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		  
		/* COPY CONSTRUCTOR--> Constructs a container with a 
		copy of each of the elements in x, in the same order. */
		// list (const list& x)
		// {
		// 	_head = new listNode<T>();
		// 	_tail = new listNode<T>();
		// 	this->_head->next = this->_tail;
		// 	this->_tail->prev = this->_head;
		// 	assign(x.begin(), x.end());
		// }
		
		/* LIST DESTRUCTOR--> Destroys the container object. */
		~list()
		{
			this->clear();
			delete this->_tail;
			delete this->_head;
			return; 
		}

		/* ASSIGN content--> Assigns new contents to the 
		container, replacing its current contents, 
		and modifying its size accordingly. */
		list&		operator=(const list &x)
		{
			if (this != x)
			{
				this->_allocator = x.get_allocator();
				assign(x.begin(), x.end());
			}
			return(*this);
		}

		/* ------------ ITERATORS ------------ */
		
		/* BEGIN--> Returns an iterator pointing 
		to the first element in the list container. */
		// iterator begin();
		// const_iterator begin() const;

		/* END--> Returns an iterator referring 
		to the past-the-end element in the list container. */
		// iterator end();
		// const_iterator end() const;

		/* RBEGIN--> Returns a reverse iterator pointing 
		to the last element in the container (i.e., its 
		reverse beginning). */
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;

		/* REND--> Returns a reverse iterator pointing 
		to the theoretical element preceding the first 
		element in the list container (which is considered 
		its reverse end). */
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;

		/* ------------ CAPACITY ------------ */
		
		/* EMPTY--> Returns whether the list 
		container is empty (i.e. whether its size is 0). */
		bool empty() const
		{
			if (this->_size == 0)
				return true;
			else
				return false;
		}
		
		/* SIZE--> Returns the number of elements in 
		the list container. */
		size_type size() const { return this->_size; }
		
		/* MAX_SIZE--> Returns the number of elements in 
		the list container. */
		size_type max_size() const { return((std::numeric_limits<size_t>::max() / sizeof(listNode<T>))); };

		/* ------------ ELEMENT ACCESS ------------ */
		
		/* FRONT--> Returns a reference to the first 
		element in the list container. */
		T& front() { return this->_head->next->data; }
		const T& front() const { return this->_head->next->data; }

		/* BACK--> Returns a reference to 
		the last element in the list container. */
		reference back() { return this->_tail->prev->data; }
		const_reference back() const { return this->_tail->prev->data; }
		
		/* ------------ MODIFIERS ------------ */

		/* ASSIGN--> Assigns new contents to the 
		list container, replacing its current contents, 
		and modifying its size accordingly. */
		// template <class InputIterator>
  		// void assign (InputIterator first, InputIterator last);
	
		void assign (size_type n, const value_type& val)
		{
			this->clear();
			while (n)
			{
				this->push_back(val);
				n--;
			}
		}
		
		/* PUSH_FRONT--> Inserts a new element at the beginning 
		of the list, right before its current first element. 
		The content of val is copied (or moved) to the inserted element.
		
		This effectively increases the container size by one. */
		void push_front (const value_type& val)
		{
			node*		new_node = new listNode<T>(val);

			new_node->prev = _head;
			this->_head->next->prev = new_node;
			new_node->next = this->_head->next;
			this->_head->next = new_node;
			this->_size += 1;
		}

		/* PUSH_BACK--> Adds a new element at the end of the 
		list container, after its current last element. 
		The content of val is copied (or moved) to the new element.
		
		This effectively increases the container size by one. */
		void push_back (const T& val)
		{
			node*	new_node = new listNode<T>(val);
			
			new_node->next = _tail;
			this->_tail->prev->next = new_node;
			new_node->prev = this->_tail->prev;
			this->_tail->prev = new_node;
			this->_size += 1;			
		}
		

		/* POP_BACK--> Removes the last element in the list container, 
		effectively reducing the container size by one.
		
		This destroys the removed element. */
		void pop_back()
		{
			if (this->_size)
			{
				node*	back_node = this->_tail->prev;
				
				this->_tail->prev->prev->next = this->_tail;
				this->_tail->prev = this->_tail->prev->prev;
				this->_size -= 1;
				delete back_node;
			}	
		}

		/* INSERT--> The container is extended by 
		inserting new elements before the element at 
		the specified position.
		
		This effectively increases the list size by 
		the amount of elements inserted. */

		/* Single Element */
		// iterator insert (iterator position, const value_type& val);

		/* Fill */
		// void insert (iterator position, size_type n, const value_type& val);

		/* Range */
		// template <class InputIterator>
    	// void insert (iterator position, InputIterator first, InputIterator last);

		/* ERASE--> Removes from the list container 
		either a single element (position) or a range of 
		elements ([first,last)).

		This effectively reduces the container size 
		by the number of elements removed, which are destroyed. */
		// iterator erase (iterator position);
		// iterator erase (iterator first, iterator last);

		/* SWAP--> Exchanges the content of the container 
		by the content of x, which is another list of the 
		same type. Sizes may differ. */
		// oid swap (list& x);

		/* RESIZE--> Resizes the container so that it 
		contains n elements.

		If n is smaller than the current container size, 
		the content is reduced to its first n elements, 
		removing those beyond (and destroying them).

		If n is greater than the current container size, 
		the content is expanded by inserting at the end as 
		many elements as needed to reach a size of n. If val 
		is specified, the new elements are initialized as 
		copies of val, otherwise, they are value-initialized. */
		// void resize (size_type n, value_type val = value_type());

		/* CLEAR--> Removes all elements from the list container 
		(which are destroyed), and leaving the container with a 
		size of 0. */
		void clear()
		{
			while (this->_size)
				pop_back();
			return;
		}

		/* ------------ OPERATIONS ------------ */
		
		/* SPLICE--> Transfers elements from x into the container, 
		inserting them at position.

		This effectively inserts those elements into the container 
		and removes them from x, altering the sizes of both containers. 
		The operation does not involve the construction or destruction 
		of any element. They are transferred, no matter whether x is 
		an lvalue or an rvalue, or whether the value_type supports 
		move-construction or not. */
		
		/* Version 1: transfers all the elements of x into the container. */
		// void splice (iterator position, list& x);
		
		/* Version 2: transfers only the element pointed by i from x 
		into the container. */
		// void splice (iterator position, list& x, iterator i);

		/* Version 3: transfers the range [first,last) from x 
		into the container. */
		// void splice (iterator position, list& x, iterator first, iterator last);

		/* REMOVE--> Removes from the container all the elements 
		that compare equal to val. This calls the destructor of 
		these objects and reduces the container size by the 
		number of elements removed. */
		// void remove (const value_type& val);

		/* REMOVE_IF--> Removes from the container all the elements 
		for which Predicate pred returns true. This calls the destructor 
		of these objects and reduces the container size by the number 
		of elements removed. 
		
		The function calls pred(*i) for each element 
		(where i is an iterator to that element). Any of the elements in 
		the list for which this returns true, are removed from the container. */
		// template <class Predicate>
  		// void remove_if (Predicate pred);

		/* UNIQUE--> The version with no parameters (1), 
		removes all but the first element from every consecutive group of 
		equal elements in the container.

		Notice that an element is only removed from the list container 
		if it compares equal to the element immediately preceding it. 
		Thus, this function is especially useful for sorted lists.

		The second version (2), takes as argument a specific comparison 
		function that determine the "uniqueness" of an element. In fact, 
		any behavior can be implemented (and not only an equality comparison), 
		but notice that the function will call binary_pred(*i,*(i-1)) 
		for all pairs of elements (where i is an iterator to an element, 
		starting from the second) and remove i from the list if the predicate returns true.

		The elements removed are destroyed. */

		/* Version 1 */
		// void unique();

		/* Version 2 */
		// template <class BinaryPredicate>
  		// void unique (BinaryPredicate binary_pred);

		/* MERGE--> Merges x into the list by transferring all of its 
		elements at their respective ordered positions into the container 
		(both containers shall already be ordered).

		This effectively removes all the elements in x (which becomes empty), 
		and inserts them into their ordered position within container (which 
		expands in size by the number of elements transferred). 
		The operation is performed without constructing nor destroying 
		any element: they are transferred, no matter whether x is an 
		lvalue or an rvalue, or whether the value_type supports 
		move-construction or not.

		The template versions with two parameters (2), 
		have the same behavior, but take a specific predicate (comp) 
		to perform the comparison operation between elements. 
		This comparison shall produce a strict weak ordering of the 
		elements (i.e., a consistent transitive comparison, 
		without considering its reflexiveness).

		This function requires that the list containers have 
		their elements already ordered by value (or by comp) 
		before the call. For an alternative on unordered lists, 
		see list::splice.

		Assuming such ordering, each element of x is inserted at 
		the position that corresponds to its value according to 
		the strict weak ordering defined by operator< or comp. 
		The resulting order of equivalent elements is stable 
		(i.e., equivalent elements preserve the relative order 
		they had before the call, and existing elements precede 
		those equivalent inserted from x).

		The function does nothing if (&x == this). */

		/* Version 1 */
		// void merge (list& x);

		/* Version 2 */
		// template <class Compare>
  		// void merge (list& x, Compare comp);

		/* SORT--> Sorts the elements in the list, altering their 
		position within the container.

		The sorting is performed by applying an algorithm that uses 
		either operator< (in version (1)) or comp (in version (2)) 
		to compare elements. This comparison shall produce a strict 
		weak ordering of the elements (i.e., a consistent transitive 
		comparison, without considering its reflexiveness).

		The resulting order of equivalent elements is stable: i.e., 
		equivalent elements preserve the relative order they had 
		before the call. */

		/* Version 1 */
		// void sort();

		/* Version 2 */
		// template <class Compare>
  		// void sort (Compare comp);

		/* REVERSE--> Reverses the order of the elements 
		in the list container. */
		// void reverse();

		/* ------------ OBSERVERS ------------ */

		/* GET_ALLOCATOR--> Returns a copy of the 
		allocator object associated with the list 
		container. */
		allocator_type get_allocator() const { return this->_allocator; }
		
	}; // end of list class

	/* ------------ RELATIONAL OPERATORS ------------ */

	// template <class T, class Alloc>
  	// void swap (list<T,Alloc>& x, list<T,Alloc>& y);
	  
	// template <class T, class Alloc>
  	// bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
  	// bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
  	// bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	
	// template <class T, class Alloc>
 	// bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	 	
	// template <class T, class Alloc>
  	// bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	
	// template <class T, class Alloc>
  	// bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
}

#endif // end of ft namespace