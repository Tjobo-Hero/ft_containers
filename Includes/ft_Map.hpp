/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_Map.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 14:06:12 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/04/26 14:48:35 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP

# include <iostream>
# include "ft_BiDirectionalIterator.hpp"
# include "Type_Traits.hpp"
# include "ft_Pair.hpp"
# include "ft_MapNode.hpp"


namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > > 
	class map
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;
			typedef mapNode<value_type>								Node;
			typedef T&												reference;
			typedef const T&										const_reference;
			typedef T*												pointer;
			typedef const T*										const_pointer;
			typedef bidirectional_iterator< value_type, Node >				iterator;
			typedef const_bidirectional_iterator< value_type, Node >			const_iterator;
			typedef reverse_bidirectional_iterator< value_type, Node >		reverse_iterator;
			typedef const_reverse_bidirectional_iterator< value_type, Node >	const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef size_t											size_type;

		private:

			Node*		_root;
			Node*		_lastElement;
			size_t		_size;
			Alloc		_alloc;
			Compare		_compare;

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
		explicit map (const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type()) : _root(new Node), _lastElement(new Node), _size(0), _alloc(alloc), _compare(comp) 
		{
			this->_root = this->_lastElement;
			this->_lastElement->left = this->_lastElement;
			this->_lastElement->right = this->_lastElement;
			return; 
		}

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
		bool empty() const { return this->size() == 0; }

		/* SIZE--> Returns the number of 
		elements in the map container. */
		size_type size() const { return this->_size; }

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
		
		void	set_limits()
		{
			Node*	tmp = this->_root;

			while (tmp->left != NULL)
				tmp = tmp->left;
			tmp->left = this->_first;
			this->_first->parent = tmp;
			
			tmp = this->_root;
			while (tmp->right != NULL)
				tmp = tmp->right;
			tmp->right = this->_last;
			this->_last->parent = tmp;
		}
		
		Node*	insert_left(const value_type &val, Node* position)
		{
			Node*	new_node = new Node(val);

			new_node->parent = position;
			position->left = new_node;
			this->set_limits();
			this->_size += 1;
			// new_node->height += 1;
			// new_node->height = calheight(new_node);
			return new_node;
		}

		Node*	insert_right(const value_type &val, Node* position)
		{
			Node*	new_node = new Node(val);

			new_node->parent = position;
			position->right = new_node;
			this->set_limits();
			this->_size += 1;
			// new_node->height += 1;
			// new_node->height = calheight(new_node);
			return new_node;
		}
		
		// size_t	calheight(Node *new_node)
		// {
		// 	if (new_node->left && new_node->right)
		// 	{
		// 		if (new_node->left->height < new_node->right->height)
		// 			return new_node->right->height + 1;
		// 		else
		// 			return new_node->left->height + 1;
		// 	}
		// 	else if (new_node->left && new_node->right == NULL)
		// 		return new_node->left->height + 1;
		// 	else if (new_node->left == NULL && new_node->right)
		// 		return new_node->right->height + 1;
		// 	return 0;
		// }

		// Node*		insert_recursive(Node*	move, const value_type& val)
		// {
		// 	if (move == NULL)
		// 	{
		// 		if (size() == 0)
		// 		{
		// 			delete this->_root;
		// 			this->_root = new Node(val);
		// 			this->set_limits();
		// 			this->_size += 1;
		// 			return this->_root;
		// 		}
		// 		Node*	new_node = new Node(val);
		// 		move = new_node;
		// 		move->left = NULL;
		// 		move->right = NULL;
		// 		move->height = 1;
		// 		this->_size += 1;
		// 		set_limits();
		// 		return move;
		// 	}
		// 	else if (move->data.first == val.first)
		// 	{
		// 		set_limits();
		// 		return NULL;
		// 	}
		// 	else
		// 	{
		// 		if (value_compare(this->_compare)(val, move->data) == true)
		// 		{
		// 			move->left = insert_recursive(move->left, val);
		// 			move->left->parent = move;
					
		// 		}
		// 		else
		// 		{
		// 			move->right = insert_recursive(move->right, val);
		// 			move->right->parent = move;
		// 		}

		// 	}
		// 	move->height = calheight(move);
		// 	set_limits();
		// 	return move;
		// }

		Node*					searchNode(Node* root, key_type key_value)
		{
			if (!root || root == this->_lastElement)
				return 0;
			if (!this->_compare(root->data.first, key_value) && !_comp(key_value, root->data.first))
				return root;

		
		}
		
		/* Single Element*/
		ft::pair<iterator,bool> insert (const value_type& val)
		{

			Node*	checkifexist = searchNode(this->_root, val.first);
			
				
				
			if (this->_root == this->_lastElement)
			{
				delete this->_root;
				this->_root = new Node(val);
				_root->left = this->_lastElement;
				_root->right = this->_lastElement;
				this->lastElement->left = this->_root;
				this->lastElement->right = this->_root;
				this->_size += 1;
				return ft::make_pair(iterator(this->_root), true);
			}
			if (move->data.first == val.first)
			{
					set_limits();
					return ft::make_pair(iterator(move), false);
			}
			Node*	move = this->_root;
			while (move->left || move->right)
			{
				if (move->data.first == val.first)
				{
					set_limits();
					return ft::make_pair(iterator(move), false);
				}
				if (value_compare(this->_compare)(val, move->data) == true)
				{
					if (move->left != NULL)
						move = move->left;
					else
						break ;
				}
				else
				{
					if (move->right != NULL)
						move = move->right;
					else
						break;
				}
			}
			if (value_compare(this->_compare)(val, move->data) == true)
				move = insert_left(val, move);
			else
				move = insert_right(val, move);
			
			
			return ft::make_pair(iterator(move), true);
		}
		
		/* With Hint */	
		// iterator insert (iterator position, const value_type& val);
		
		/* Range */	
		// template <class InputIterator>
		// void insert (InputIterator first, InputIterator last);

		/* ERASE--> Removes from the map container either 
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

		void    print_node(std::string root_path) {
            Node* tmp = _root;
            std::cout << ".";
            for (int i = 0; root_path[i]; ++i){
                if (root_path[i] == 'L'){
                    if (tmp->left == NULL)
                        return ;
                    tmp = tmp->left;
                }
                if (root_path[i] == 'R'){
                    if (tmp->right == NULL)
                        return ;
                    tmp = tmp->right;
                }
            }
            if (tmp->data.first)
                std::cout << tmp->data.first << std::endl;
        }
        void    print_tree() {
            std::string root_path;
            int layer = 0;
            root_path = "";
            int starting_tabs = 16;
            int starting_gap = 16;
            while (layer < 5)
            {
                root_path.clear();
                int tmp_tabs = starting_tabs;
                int tmp_gap = starting_gap;
                for (int tmp_layer = layer; tmp_layer; --tmp_layer)
                {
                    root_path.append("L");
                    tmp_gap = tmp_gap / 2;
                    tmp_tabs -= tmp_gap;
                }
                while (root_path.find('L') != std::string::npos){
                    if (root_path.find('R') == std::string::npos)
                        for (; tmp_tabs; --tmp_tabs)
                            std::cout << "   ";
                    else
                        for (int tmp_gap2 = tmp_gap * 2; tmp_gap2; --tmp_gap2)
                            std::cout << "   ";
                    print_node(root_path);
                    size_t L_found = root_path.find_last_of('L');
                    root_path[L_found] = 'R';
                    ++L_found;
                    for (;L_found != root_path.size(); ++L_found){
                        root_path[L_found] = 'L';
                    }
                }
                if (root_path.find('R') == std::string::npos)
                    for (; tmp_tabs; --tmp_tabs)
                        std::cout << "   ";
                else
                    for (int tmp_gap2 = tmp_gap * 2; tmp_gap2; --tmp_gap2)
                        std::cout << "   ";
               	print_node(root_path);
                std::cout << std::endl << std::endl << std::endl;
                layer++;
            }
        }
		
	}; // end of MAP class

} // end of namespace ft

#endif