/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_BiDirectionalIterator.hpp                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 11:50:10 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/05/13 10:58:12 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIDIRECTIONALITTERATOR_HPP
# define FT_BIDIRECTIONALITTERATOR_HPP

# include "Type_Traits.hpp"

namespace ft
{
	template< typename T, typename Node >
	class bidirectional_iterator
	{
		public:

			typedef	std::bidirectional_iterator_tag		iterator_category;
			typedef	T									value_type;
			typedef	std::ptrdiff_t						difference_type;
			typedef	T									*pointer;
			typedef	T									&reference;
			typedef Node								*iterator_type;

		private:
			
			Node*		_ptr;
			
		public:

		/* ------------MEMBER FUNCTIONS------------ */
		/* CONSTRUCTOR */
		bidirectional_iterator() : _ptr(NULL) { return; }
		explicit bidirectional_iterator(Node* it) : _ptr(it) { return; }
		bidirectional_iterator(const bidirectional_iterator &src) { *this = src; return; }

		/* DESTRUCTOR--> Vector Destructor */ 
		~bidirectional_iterator() { return; }

		/* OPERATOR= FUNCTION --> Assign content */ 
		bidirectional_iterator&		operator=(const bidirectional_iterator &obj)
		{
			if (this != &obj)
				this->_ptr = obj._ptr;
			return *this;
		}

		/* OPERATOR* FUNCTION --> Assign content */ 
		T&		operator*() { return this->_ptr->data; }
		
		/* OPERATOR-> FUNCTION --> Assign content */ 
		T*		operator->() { return &this->_ptr->data; }

		/* OPERATOR++ FUNCTION --> pluses the pointer */
		bidirectional_iterator&		operator++() { this->_ptr = this->_ptr->getNext(); return (*this); }
		bidirectional_iterator		operator++(int) 
		{ 
			bidirectional_iterator tmp(*this);
			++(*this);
			return (tmp);
		}

		/* OPERATOR-- FUNCTION --> minus the pointer */ 
		bidirectional_iterator&		operator--() { this->_ptr = this->_ptr->getPrevious(); return (*this); }
		bidirectional_iterator		operator--(int) 
		{ 
			bidirectional_iterator tmp(*this);
			--(*this);
			return (tmp);
		}

		/* ------------ RELATIONAL OPERATORS------------ */
		bool	operator==(const bidirectional_iterator &rhs) const { return (this->_ptr == rhs.get_ptr()); }
		bool	operator!=(const bidirectional_iterator&rhs) const { return !(*this == rhs); }
		
		Node* get_ptr() const { return (this->_ptr); };
	};

	template< typename T, typename Node >
	class const_bidirectional_iterator
	{
		public:

			typedef	std::bidirectional_iterator_tag		iterator_category;
			typedef	T									value_type;
			typedef	std::ptrdiff_t						difference_type;
			typedef	T									*pointer;
			typedef	T									&reference;
			typedef Node								*iterator_type;
			typedef	const T								*const_pointer;
			typedef	const T								&const_reference;

		private:
			
			Node*		_ptr;
			
		public:

		/* ------------MEMBER FUNCTIONS------------ */
		/* CONSTRUCTOR */
		const_bidirectional_iterator() : _ptr(NULL) { return; }
		explicit const_bidirectional_iterator(Node* it) : _ptr(it) { return; }
		const_bidirectional_iterator(const const_bidirectional_iterator &src) { *this = src; return; }
		const_bidirectional_iterator(const bidirectional_iterator< T, Node > &it) { this->_ptr = it.get_ptr(); return; }

		/* DESTRUCTOR--> Vector Destructor */ 
		~const_bidirectional_iterator() { return; }

		/* OPERATOR= FUNCTION --> Assign content */ 
		const_bidirectional_iterator&		operator=(const const_bidirectional_iterator &obj)
		{
			if (this != &obj)
				this->_ptr = obj._ptr;
			return *this;
		}

		/* OPERATOR* FUNCTION --> Assign content */ 
		T&		operator*() { return this->_ptr->data; }
		
		/* OPERATOR-> FUNCTION --> Assign content */ 
		T*		operator->() { return &this->_ptr->data; }

		/* OPERATOR++ FUNCTION --> pluses the pointer */
		const_bidirectional_iterator&		operator++() { this->_ptr = this->_ptr->getNext(); return (*this); }
		const_bidirectional_iterator		operator++(int) 
		{ 
			const_bidirectional_iterator tmp(*this);
			++(*this);
			return (tmp);
		}

		/* OPERATOR-- FUNCTION --> minus the pointer */ 
		const_bidirectional_iterator&		operator--() { this->_ptr = this->_ptr->getPrevious(); return (*this); }
		const_bidirectional_iterator		operator--(int) 
		{ 
			const_bidirectional_iterator tmp(*this);
			--(*this);
			return (tmp);
		}

		/* ------------ RELATIONAL OPERATORS------------ */
		bool	operator==(const const_bidirectional_iterator &rhs) const { return (this->_ptr == rhs.get_ptr()); }
		bool	operator!=(const const_bidirectional_iterator &rhs) const { return !(*this == rhs); }

		const Node* get_ptr() const { return (this->_ptr); };
	};

	template< typename T, typename Node >
	class reverse_bidirectional_iterator
	{
		public:

			typedef	std::bidirectional_iterator_tag		iterator_category;
			typedef	T									value_type;
			typedef	std::ptrdiff_t						difference_type;
			typedef	T									*pointer;
			typedef	T									&reference;
			typedef Node								*iterator_type;

		private:

			Node*		_ptr;

		public:

		/* ------------MEMBER FUNCTIONS------------ */
		/* CONSTRUCTOR */
		reverse_bidirectional_iterator() : _ptr(NULL) { return; }
		explicit reverse_bidirectional_iterator(Node* it) : _ptr(it) { return; }
		reverse_bidirectional_iterator(const reverse_bidirectional_iterator &src) { *this = src; return; }

		/* DESTRUCTOR--> Vector Destructor */ 
		~reverse_bidirectional_iterator() { return; }

		/* OPERATOR= FUNCTION --> Assign content */ 
		reverse_bidirectional_iterator&		operator=(const reverse_bidirectional_iterator &obj)
		{
			if (this != &obj)
				this->_ptr = obj._ptr;
			return *this;
		}

		/* OPERATOR* FUNCTION --> Assign content */ 
		T&		operator*() { return this->_ptr->data; }
		
		/* OPERATOR-> FUNCTION --> Assign content */ 
		T*		operator->() { return &this->_ptr->data; }

		/* OPERATOR++ FUNCTION --> pluses the pointer */
		reverse_bidirectional_iterator&		operator++() { this->_ptr = this->_ptr->getPrevious(); return (*this); }
		reverse_bidirectional_iterator		operator++(int) 
		{ 
			reverse_bidirectional_iterator tmp(*this);
			++(*this);
			return (tmp);
		}

		/* OPERATOR-- FUNCTION --> minus the pointer */ 
		reverse_bidirectional_iterator&		operator--() { this->_ptr = this->_ptr->getNext(); return (*this); }
		reverse_bidirectional_iterator		operator--(int) 
		{ 
			reverse_bidirectional_iterator tmp(*this);
			--(*this);
			return (tmp);
		}

		/* ------------ RELATIONAL OPERATORS------------ */
		bool	operator==(const reverse_bidirectional_iterator &rhs) const { return (this->_ptr == rhs.get_ptr()); }
		bool	operator!=(const reverse_bidirectional_iterator &rhs) const { return !(*this == rhs); }

		Node* get_ptr() const { return (this->_ptr); };
	};

	template< typename T, typename Node >
	class const_reverse_bidirectional_iterator
	{
		public:
			
			typedef	std::bidirectional_iterator_tag		iterator_category;
			typedef	T									value_type;
			typedef	std::ptrdiff_t						difference_type;
			typedef	T									*pointer;
			typedef	T									&reference;
			typedef Node								*iterator_type;
			typedef	const T								*const_pointer;
			typedef	const T								&const_reference;
			
		private:
			
			Node*		_ptr;
			
		public:

		/* ------------MEMBER FUNCTIONS------------ */
		/* CONSTRUCTOR */
		const_reverse_bidirectional_iterator() : _ptr(NULL) { return; }
		explicit const_reverse_bidirectional_iterator(Node* it) : _ptr(it) { return; }
		const_reverse_bidirectional_iterator(const const_reverse_bidirectional_iterator &src) { *this = src; return; }
		const_reverse_bidirectional_iterator(const reverse_bidirectional_iterator< T, Node > &it) { _ptr = it.get_ptr(); return; }
		
		/* DESTRUCTOR--> Vector Destructor */ 
		~const_reverse_bidirectional_iterator() { return; }

		/* OPERATOR= FUNCTION --> Assign content */ 
		const_reverse_bidirectional_iterator&		operator=(const const_reverse_bidirectional_iterator &obj)
		{
			if (this != &obj)
				this->_ptr = obj._ptr;
			return *this;
		}

		/* OPERATOR* FUNCTION --> Assign content */ 
		T&		operator*() { return this->_ptr->data; }
		
		/* OPERATOR-> FUNCTION --> Assign content */ 
		T*		operator->() { return &this->_ptr->data; }

		/* OPERATOR++ FUNCTION --> pluses the pointer */
		const_reverse_bidirectional_iterator&		operator++() { this->_ptr = this->_ptr->getPrevious(); return (*this); }
		const_reverse_bidirectional_iterator		operator++(int) 
		{ 
			const_reverse_bidirectional_iterator tmp(*this);
			++(*this);
			return (tmp);
		}
		
		/* OPERATOR-- FUNCTION --> minus the pointer */ 
		const_reverse_bidirectional_iterator&		operator--() { this->_ptr = this->_ptr->getNext(); return (*this); }
		const_reverse_bidirectional_iterator		operator--(int) 
		{ 
			const_reverse_bidirectional_iterator tmp(*this);
			--(*this);
			return (tmp);
		}

		/* ------------ RELATIONAL OPERATORS------------ */
		bool	operator==(const const_reverse_bidirectional_iterator &rhs) const { return (this->_ptr == rhs.get_ptr()); }
		bool	operator!=(const const_reverse_bidirectional_iterator &rhs) const { return !(*this == rhs); }

		const Node* get_ptr() const { return (this->_ptr); };

	}; // end of bidirectional_iterator class

} // end ft namespace

#endif