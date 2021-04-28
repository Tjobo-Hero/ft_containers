/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_Map.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 14:06:12 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/04/28 13:46:11 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP
# define COUNT 10

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
			typedef Key															key_type;
			typedef T															mapped_type;
			typedef Compare														key_compare;
			typedef Alloc														allocator_type;
			typedef ft::pair<const key_type, mapped_type>						value_type;
			typedef mapNode<value_type>											Node;
			typedef T&															reference;
			typedef const T&													const_reference;
			typedef T*															pointer;
			typedef const T*													const_pointer;
			typedef bidirectional_iterator< value_type, Node >					iterator;
			typedef const_bidirectional_iterator< value_type, Node >			const_iterator;
			typedef reverse_bidirectional_iterator< value_type, Node >			reverse_iterator;
			typedef const_reverse_bidirectional_iterator< value_type, Node >	const_reverse_iterator;
			typedef std::ptrdiff_t												difference_type;
			typedef size_t														size_type;

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
		const allocator_type& alloc = allocator_type()) : _lastElement(new Node), _size(0), _alloc(alloc), _compare(comp) 
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

		/* 	RBEGIN--> Returns a reverse iterator pointing 
		*	to the last element in the container (i.e., its reverse beginning).
		*	
		* 	Reverse iterators iterate backwards: increasing 
		*	them moves them towards the beginning of the container.
		*
		*	rbegin points to the element preceding the one 
		*	that would be pointed to by member end. 
		*/
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;

		/* REND--> Returns a reverse iterator pointing 
		* to the theoretical element right before the first 
		* element in the map container (which is considered its reverse end).

		* The range between map::rbegin and map::rend 
		* contains all the elements of the container (in reverse order).
		*/
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

		/* Single Element*/
		ft::pair<iterator,bool> insert(const value_type& val)
		{
			Node*	checkifexist = searchNode(this->_root, val.first);
			
			if (checkifexist)
				return ft::make_pair(iterator(checkifexist), false);
			
			checkifexist = insertNode(this->_root, val);
			this->_size += 1;
			return ft::make_pair(iterator(checkifexist), true);
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
		
		/* ------------ PRIVATE MEMBER FUNCTIONS ------------ */

		/*
		*	FUNCTION: searchNode searches the key_value in the three and returns it
		*	if it will find the key.
		*/
		Node*					searchNode(Node* root, key_type key_value)
		{
			// Statement if we've reached a max or min node or a leaf node
			if (root == NULL || root == this->_lastElement)
				return 0;

			// Statement if the key_value are equal the key_value already exist in the tree
			if (root->data.first == key_value) 
				return root;
			// if (value_compare(root->data.first, key_value) == true && value_compare(key_value, root->data.first) == true)
			// 	return root;

			// Recursive loop that will go trough the whole tree
			if (root->data.first > key_value && root->left && root->left != this->_lastElement)
				return searchNode(root->left, key_value);
			if (root->data.first < key_value && root->left && root->left != this->_lastElement)
				return searchNode(root->right, key_value);
			return 0;
		
		}

		int					calheight(Node *root, int height)
		{
			// Reached NULL
			if (root == NULL || root == this->_lastElement)
				return height -1;
			
			// Goint trough the left side of the node and after that the right side
			int leftHeight = calheight(root->left, height + 1);
			int rightHeight = calheight(root->right, height +1);
			if (leftHeight > rightHeight)
				return leftHeight;
			else
				return rightHeight;
		}

		/*
		*	FUNCTION: balanceSubtrees Compares the heights of the left and right subtrees
		*/
		int		balanceSubtrees(Node* node)
		{
			if (node == NULL)
				return 0;
			return calheight(node->left, 1) - calheight(node->right, 1);
		}
		
		/*
		*	FUNCTION: leftRotation Rotates the subtree to the left. It will move node Y up and X
		*	down as shown below:
		*		
		*	Before:
		*			X					10X
		*		  /   \				   /  \
		*		A	   Y			  5A   15Y
		*			  / \				  /  \
		*			 B   C				13B    20C
		*   X = X < Y
		*	A = A < X
		*		A < Y
		*	Y = Y > X
		*	B = B > X
		*		B < Y
		*	C = C > X
		*		C > Y
		*	
		*	After:
		*			Y			   15Y	
		*		  /   \			  /   \	
		*		X      C		10X    20C
		*	   /  \	  		   /  \	  	
		*	  A	  B	 		  5A   13B	 	
		*
		*/
		void	leftRotation(Node* X)
		{
			std::cout << "Left rotation" << std::endl;

			Node*	Y = X->right;
			
			// Right X son becomes left Y son
			X->right = Y->left;

			// Statement Y left son is NULL to prevent Segfault
			if (Y->left)
				Y->left->parent = X;
			
			

			// Left Y son is now X
			Y->left = X;
			
			// Parent Y = Parent X
			Y->parent = X->parent;

			// Check if X has a parent (if not, X is root) and if that is the case, 
			// we need to determine if it's left son or right son. AFter that we need
			// to update X parent with his new son, Y node.
			if (X->parent && X->parent->left == X)
				X->parent->left = Y;
			else if (X->parent)
				X->parent->right = Y;
			
			// Parent of X is now Y
			X->parent = Y;

			// Update the root node if the rotation happend on Root
			if (Y->parent == NULL)
				this->_root = Y;
		}

		/*
		*	FUNCTION: leftRotation Rotates the subtree to the left. It will move node Y up and X
		*	down as shown below:
		*
		* 	Before
		*			X			   15X	
		*		  /   \			  /   \	
		*		Y      A		10Y    20A
		*	   /  \	  		   /  \	  	
		*	  C	  B	 		  5C   13B	 	
		*
		*   X = X < Y
		*	A = A > X
		*		A > Y
		*	Y = Y < X
		*	B = B < X
		*		B > Y
		*	C = C < X
		*		C < Y
		*	
		*	After:
		*			Y					10Y
		*		  /   \				   /  \
		*		C	   X			  5C   15X
		*			  / \				  /  \
		*			 B   A				13B    20A
		*
		*/
		void	rightRotation(Node* X)
		{
			std::cout << "Right rotation" << std::endl;
			Node*	Y = X->left;
			
			// Left X son becomes right Y son
			X->left = Y->right;

			// Statement Y right son is NULL to prevent Segfault
			if (Y->right)
				Y->right->parent = X;

			// Left Y son is now X
			Y->right = X;
			
			// Parent Y = Parent X
			Y->parent = X->parent;

			// Check if X has a parent (if not, X is root) and if that is the case, 
			// we need to determine if it's left son or right son. AFter that we need
			// to update X parent with his new son, Y node.
			if (X->parent && X->parent->left == X)
				X->parent->left = Y;
			else if (X->parent)
				X->parent->right = Y;
			
			// Parent of X is now Y
			X->parent = Y;

			// Update the root node if the rotation happend on Root
			if (Y->parent == NULL)
				this->_root = Y;
		}
		
		/*
		*	FUNCTION: balance_tree Starts from a node in the Tree. And will check
		*	for this node and all the parent's node until the root if their balance (so the height)
		*	is correct. If not a rotation (left or right) around the node will take place and will put
		*	the Tree back in balance.
		*/
		void					balance_tree(Node *node)
		{
			while(node)
			{
				int balancefactor;
				
				// R R case (right subtree is deeper, and right right subtree as well)
				if (((balancefactor = balanceSubtrees(node)) < -1) && balanceSubtrees(node->right) < 0)
					leftRotation(node);
				// R L case (if balance of the right node == 0), no difference between R
				// R case and R L case)
				else if (balancefactor < -1 && (balanceSubtrees(node->right) >= 0))
				{
					rightRotation(node->right);
					leftRotation(node);
				}
				// L L case (left subtree is depper and lef left subtree as well)
				else if (balancefactor > 1 && (balanceSubtrees(node->left) > 0))
					rightRotation(node);
				// L R case (if balance of the left node == 0), no difference between R R case en R L case)
				else if (balancefactor > 1 && (balanceSubtrees(node->left) <= 0))
				{
					leftRotation(node->left);
					rightRotation(node);
				}
				node = node->parent;
			}
		}

		/*
		*	FUNCTION: insertNode inserts a Node in the tree. After that
		*	balances the tree if necessary.
		*/
		Node*					insertNode(Node* move, const value_type &val)
		{
			// Statement for the first node of the tree
			if (this->_root == this->_lastElement)
			{
				this->_root = new Node(val);
				_root->left = this->_lastElement;
				_root->right = this->_lastElement;
				this->_lastElement->left = this->_root;
				this->_lastElement->right = this->_root;
				this->_size += 1;
				return this->_root;
			}
			
			// Statement to check if the key already exists
			if (move->data.first == val.first)
					return 0;					// does this generate a good iterator in insert? And necessary because we check befor in insert 
												// function with searchNode
			// Recursive loop that finds the position of the key_value in the tree
			// either as a new leaf node or lastElement
			if (move->data.first > val.first && move->left && move->left != this->_lastElement)
				return insertNode(move->left, val);
			else if (move->data.first < val.first && move->right && move->right != this->_lastElement)
				return insertNode(move->right, val);
			
			// When we arrive here the move pointer is at the position where we have to insert
			// the new node
			Node* new_node = new Node(val);
			
			// Check if the place where we insert is a leaf node
			// Left leaf node
			if (move->data.first > new_node->data.first && !move->left)
			{
				move->left = new_node;
				new_node->parent = move;
			}
			// Right Leaf node
			else if (move->data.first < new_node->data.first && !move->right)
			{
				move->right = new_node;
				new_node->parent = move;
			}
			// Check if the place where we insert is a lastElement node
			// Min lastElement
			else if (move->left && (move->data.first > new_node->data.first))
			{
				new_node->left = this->_lastElement;
				this->_lastElement->left = new_node; // changed to left
				move->left = new_node;
				new_node->parent = move;
			}
			// Max lastElement
			else if (move->right && (move->data.first < new_node->data.first))
			{
				new_node->right = this->_lastElement;
				this->_lastElement->right = new_node; // changed to right
				move->right = new_node;
				new_node->parent = move;
			}
			// Balance the tree from the new_node back to the root node
			
			balance_tree(new_node);
			return new_node;
		}
		
		/*
		*	FUNCTION: getMinNode returns node on the far most left side of the tree
		*	the lowest Key_value in the tree
		*/
		Node*		getMinNode(Node* root) const
		{
			if (root->left && root->left != this->_lastElement)
				getMinNode(root->left);
			return root;
		}

		/*
		*	FUNCTION: getMinNode returns node on the far most right side of the tree
		*	the highest Key_value in the tree
		*/
		Node*		getMaxNode(Node* root) const
		{
			if (root->right && root->right != this->_lastElement)
				getMaxNode(root->left);
			return root;
		}

		/*
		*	FUNCTION: deleteNode, deletes the matching keynote with the same key_value
		*	if no Node is found with the same key_value the function returns False.
		*	If a Node wit the same key_value is found the function deletes the node and 
		* 	balances the tree after that (if necessary).
		*/
		bool deleteNode(Node* deletePosition, key_type key_value)
		{
			// This tmpNode will point to the first node impacted by the deletion (if we
			// delete a node, it will be the parent node). if we delete root, it will act
			//  as one of it's sons). After that we will call the balanceTree funtion.
			Node*	tmpNode = NULL;

			// The Node to delete, looking from deletePosition until we match a key_value;
			Node* delNode = searchNode(deletePosition, key_value);
			
			// If no Node with the key_value is found there is nothing to delete
			if (delNode == NULL)
				return false;
			
			// The case were ROOT has to be deleted
			if (delNode->parent == NULL)
			{
				// Statement if there is only one Node in the tree
				if (delNode->left == this->_lastElement && delNode->right == this->_lastElement)
				{
					this->_root = this->_lastElement;
					this->_lastElement->left = this->_lastElement;
					this->_lastElement->right = this->_lastelement;
				}

				// Statement with only onse son (left or right)
				else if (delNode->left && delNode->right == this->_lastElement)
				{
					tmpNode = delNode->parent;
					this->_root = delNode->left;
					delNode->left->parent = NULL;
					this->_lastElement->left = delNode->left;
					delNode->left->right = this->_lastElement;
				}
				else if (delNode->right && delNode->left == this->_lastElement)
				{
					tmpNode = delNode->parent;
					this->_root = delNode->right;
					delNode->
				}
			}
		}

	
		/*
		*	FUNCTION: getRoot returns root
		*/
		Node*	getRoot()
		{
			return this->_root;
		}

		void print2DUtil(Node *root, int space) 
		{ 
			// Base case 
			if (root == NULL) 
				return; 
			if (root != NULL && root != this->_lastElement)
			{
				// Increase distance between levels 
				space += COUNT;			
				// Process right child first 
				print2DUtil(root->right, space);			
				// Print current node after space 
				// count 
				std::cout << std::endl; 
				for (int i = COUNT; i < space; i++) 
					std::cout<<" "; 
				std::cout<<root->data.first <<"\n";			
				// Process left child 
				print2DUtil(root->left, space); 
			}
		}
		
		void print_tree(Node* root)
		{
			// std::cout << "-----------------------------------" << std::endl;
			print2DUtil(root, 0);
			std::cout << "-----------------------------------" << std::endl;
		}
		
		void    print_node(std::string root_path) {
            Node* tmp = _root;
            std::cout << ".";
            for (int i = 0; root_path[i]; ++i){
                if (root_path[i] == 'L'){
                    if (tmp->left == NULL || tmp->left == this->_lastElement)
                        return ;
                    tmp = tmp->left;
                }
                if (root_path[i] == 'R'){
                    if (tmp->right == NULL || tmp->right == this->_lastElement)
                        return ;
                    tmp = tmp->right;
                }
            }
            if (tmp->data.first)
                std::cout << tmp->data.first << std::endl;
        }

        void    print_Tree() {
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