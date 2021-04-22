/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_Map.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 14:06:12 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/04/22 10:35:26 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP

# include <iostream>
# include "ft_BiDirectionalIterator.hpp"
# include "Type_Traits.hpp"
# include "ft_Pair.hpp"

namespace ft
{
	template < class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T> > > 
	class map
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;
			typedef mapNode<T>										Node;
			typedef T&												reference;
			typedef const T&										const_reference;
			typedef T*												pointer;
			typedef const T*										const_pointer;
			typedef bidirectional_iterator< T, Node >				iterator;
			typedef const_bidirectional_iterator< T, Node >			const_iterator;
			typedef reverse_bidirectional_iterator< T, Node >		reverse_iterator;
			typedef const_reverse_bidirectional_iterator< T, Node >	const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef size_t											size_type;

		private:

			Node*		whatthehow;
			
		public:

		/* ------------ NESTED COMPARE CLASS ------------ */
		/* Returns a comparison object that can be used to 
		compare two elements to get whether the key of the 
		first one goes before the second. */
		class value_compare
		{
			friend class map;
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		}; // end of VALUE_COMPARE CLASS

		/* ------------ MEMBER FUNCTIONS ------------ */
		/* EMPTY CONSTRUCTOR--> Constructs an empty 
		container, with no elements. */
		// explicit map (const key_compare& comp = key_compare(),
		// const allocator_type& alloc = allocator_type());

		/* RANGE CONSTRUCTOR--> Constructs a container 
		with as many elements as the range [first,last), 
		with each element constructed from its corresponding 
		element in that range. */
		// template <class InputIterator>
		// map (InputIterator first, InputIterator last,
		// 	const key_compare& comp = key_compare(),
		// 	const allocator_type& alloc = allocator_type());

		/* COPY CONSTRUCTOR--> Constructs a container with 
		a copy of each of the elements in x. */
		// map (const map& x);

		/* MAP DESTRUCTOR--> Destroys the container object. */
		// ~map();

		/* COPY CONTAINER CONTENT--> Assigns new contents to
		the container, replacing its current content. */
		// map& operator= (const map& x);
		
		/* ------------ ITERATORS ------------ */
		/* BEGIN--> Returns an iterator referring to the first 
		element in the map container.

		Because map containers keep their elements 
		ordered at all times, begin points to the element 
		that goes first following the container's sorting criterion.

		If the container is empty, the returned iterator 
		value shall not be dereferenced. */
		// iterator begin();
		// const_iterator begin() const;

		/* END--> Returns an iterator referring to the 
		past-the-end element in the map container.

		The past-the-end element is the theoretical
		element that would follow the last element in
		the map container. It does not point to any element,
		and thus shall not be dereferenced.

		Because the ranges used by functions of the
		standard library do not include the element
		pointed by their closing iterator, this function 
		is often used in combination with map::begin to 
		specify a range including all the elements in the container.

		If the container is empty, this function returns 
		the same as map::begin. */
		// iterator end();
		// const_iterator end() const;

		/* RBEGIN--> Returns a reverse iterator pointing 
		to the last element in the container (i.e., its reverse beginning).

		Reverse iterators iterate backwards: increasing 
		them moves them towards the beginning of the container.

		rbegin points to the element preceding the one 
		that would be pointed to by member end. */
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;

		/* REND--> Returns a reverse iterator pointing 
		to the theoretical element right before the first 
		element in the map container (which is considered its reverse end).

		The range between map::rbegin and map::rend 
		contains all the elements of the container (in reverse order).*/
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;

		/* ------------ CAPACITY ------------ */
		/* EMPTY--> Returns whether the map 
		ontainer is empty (i.e. whether its size is 0).

		This function does not modify the container 
		in any way. To clear the content of a map 
		container, see map::clear. */
		// bool empty() const;

		/* SIZE--> Returns the number of 
		elements in the map container. */
		// size_type size() const;

		/* MAX_SIZE--> Returns the maximum number of 
		elements that the map container can hold.

		This is the maximum potential size the 
		container can reach due to known system or 
		library implementation limitations, but the 
		container is by no means guaranteed to be 
		able to reach that size: it can still fail 
		to allocate storage at any point before that 
		size is reached. */
		// size_type max_size() const;

		/* ------------ ELEMENT ACCESS ------------ */
		/* OPERATOR[]--> If k matches the key of an 
		element in the container, the function 
		returns a reference to its mapped value.

		If k does not match the key of any element 
		in the container, the function inserts a new 
		element with that key and returns a reference to its 
		mapped value. Notice that this always 
		increases the container size by one, even 
		if no mapped value is assigned to the element 
		(the element is constructed using its default constructor).

		A similar member function, map::at, has the same 
		behavior when an element with the key exists, 
		but throws an exception when it does not. */
		// mapped_type& operator[] (const key_type& k);

		/* ------------ MODIFIERS ------------ */
		/* INSERT--> Extends the container 
		by inserting new elements, effectively 
		increasing the container size by the number 
		of elements inserted.

		Because element keys in a map are unique, 
		the insertion operation checks whether each 
		inserted element has a key equivalent to the 
		one of an element already in the container, 
		and if so, the element is not inserted, 
		returning an iterator to this existing element 
		(if the function returns a value).

		Internally, map containers keep all their elements 
		sorted by their key following the criterion specified 
		by its comparison object. The elements are always 
		inserted in its respective position following this ordering. */

		/* Single Element*/
		// pair<iterator,bool> insert (const value_type& val);
		
		/* With Hint */	
		// iterator insert (iterator position, const value_type& val);
		
		/* Range */	
		// template <class InputIterator>
		// void insert (InputIterator first, InputIterator last);

		/* INSERT--> Removes from the map container either 
		a single element or a range of elements ([first,last)).

		This effectively reduces the container size by 
		the number of elements removed, which are destroyed. */
		
		/* Version 1 */
		// void erase (iterator position);

		/* Version 2 */
		// size_type erase (const key_type& k);

		/* Version 3 */
		// void erase (iterator first, iterator last);

		/* SWAP--> Exchanges the content of the container 
		by the content of x, which is another map of 
		the same type. Sizes may differ.

		After the call to this member function, the elements 
		in this container are those which were in x before 
		the call, and the elements of x are those which were 
		in this. All iterators, references and pointers remain 
		valid for the swapped objects.

		Notice that a non-member function exists with the 
		same name, swap, overloading that algorithm with 
		an optimization that behaves like this member function. */
		// void swap (map& x);

		/* CLEAR--> Removes all elements from the map 
		container (which are destroyed), leaving the 
		container with a size of 0. */
		// void clear();

		/* ------------ OBSERVERS ------------ */
		/* KEY_COMP--> Returns a copy of the comparison 
		object used by the container to compare keys.

		The comparison object of a map object is 
		set on construction. Its type (member key_compare) 
		is the third template parameter of the map template. 
		By default, this is a less object, which returns 
		the same as operator<.

		This object determines the order of the elements 
		in the container: it is a function pointer or a 
		function object that takes two arguments of the 
		same type as the element keys, and returns true 
		if the first argument is considered to go before 
		the second in the strict weak ordering it defines, 
		and false otherwise.

		Two keys are considered equivalent if key_comp 
		returns false reflexively (i.e., no matter the 
		order in which the keys are passed as arguments). */
		// key_compare key_comp() const;

		/* VALUE_COMP--> Returns a comparison object that 
		can be used to compare two elements to get whether 
		the key of the first one goes before the second.

		The arguments taken by this function object 
		are of member type value_type (defined in map 
		as an alias of pair<const key_type,mapped_type>), 
		but the mapped_type part of the value is not taken 
		into consideration in this comparison. */
		// value_compare value_comp() const;

		/* ------------ OPERATIONS ------------ */
		/* FIND--> Searches the container for an 
		element with a key equivalent to k and 
		returns an iterator to it if found, otherwise 
		it returns an iterator to map::end.

		Two keys are considered equivalent if the 
		container's comparison object returns false 
		reflexively (i.e., no matter the order in 
		which the elements are passed as arguments).

		Another member function, map::count, can be 
		used to just check whether a particular key 
		exists. */
		// iterator find (const key_type& k);
		// const_iterator find (const key_type& k) const;

		/* COUNT--> Searches the container for elements 
		with a key equivalent to k and returns the number 
		of matches.

		Because all elements in a map container are 
		unique, the function can only return 1 
		(if the element is found) or zero (otherwise).

		Two keys are considered equivalent if the 
		container's comparison object returns false 
		reflexively (i.e., no matter the order 
		in which the keys are passed as arguments). */
		// size_type count (const key_type& k) const;

		/* LOWER_BOUND--> Returns an iterator pointing 
		to the first element in the container whose 
		key is not considered to go before k 
		(i.e., either it is equivalent or goes after).

		The function uses its internal comparison 
		object (key_comp) to determine this, returning 
		an iterator to the first element for which 
		key_comp(element_key,k) would return false.

		If the map class is instantiated with the 
		default comparison type (less), the function 
		returns an iterator to the first element whose 
		key is not less than k.

		A similar member function, upper_bound, has 
		the same behavior as lower_bound, except in 
		the case that the map contains an element 
		with a key equivalent to k: In this case, 
		lower_bound returns an iterator pointing 
		to that element, whereas upper_bound returns 
		an iterator pointing to the next element. */
		// iterator lower_bound (const key_type& k);
		// const_iterator lower_bound (const key_type& k) const;

		/* UPPER_BOUND--> Returns an iterator pointing 
		to the first element in the container whose key 
		is considered to go after k.

		The function uses its internal comparison 
		object (key_comp) to determine this, returning 
		an iterator to the first element for which 
		key_comp(k,element_key) would return true.

		If the map class is instantiated with the 
		default comparison type (less), the function 
		returns an iterator to the first element 
		whose key is greater than k.

		A similar member function, lower_bound, 
		has the same behavior as upper_bound, 
		except in the case that the map contains 
		an element with a key equivalent to k: 
		In this case lower_bound returns an iterator 
		pointing to that element, whereas upper_bound 
		returns an iterator pointing to the next element. */
		// iterator upper_bound (const key_type& k);
		// const_iterator upper_bound (const key_type& k) const;
		
		/* EQUAL_RANGE--> Returns the bounds of a range 
		that includes all the elements in the container 
		which have a key equivalent to k.

		Because the elements in a map container have 
		unique keys, the range returned will contain 
		a single element at most.

		If no matches are found, the range returned 
		has a length of zero, with both iterators 
		pointing to the first element that has a key 
		considered to go after k according to the 
		container's internal comparison object (key_comp).

		Two keys are considered equivalent if the container's 
		comparison object returns false reflexively 
		(i.e., no matter the order in which the keys 
		are passed as arguments). */
		// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
		// pair<iterator,iterator>             equal_range (const key_type& k);
		
		/* ------------ ALLOCATOR ------------ */
		/* GET_ALLOCATOR--> Returns a copy of 
		the allocator object associated with the map. */
		// allocator_type get_allocator() const;
		
	}; // end of MAP class

} // end of namespace ft

#endif