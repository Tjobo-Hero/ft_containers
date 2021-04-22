/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_RandomAccessIterator.hpp                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 12:11:16 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/22 14:47:22 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOMACCESSITERATOR_HPP
# define FT_RANDOMACCESSITERATOR_HPP

# include "Type_Traits.hpp"

namespace ft
{
	template< typename T >
	class random_access_iterator
	{
		public:

			typedef	std::random_access_iterator_tag		iterator_category;
			typedef	T									value_type;
			typedef	std::ptrdiff_t						difference_type;
			typedef	T									*pointer;
			typedef	T									&reference;
			typedef	const T								*const_pointer;
			typedef	const T								&const_reference;
			
		private:

			T*		_ptr;

		public:
		
		/* ------------MEMBER FUNCTIONS------------ */
		/* CONSTRUCTOR */
		random_access_iterator() : _ptr(NULL) { return; }
		explicit random_access_iterator(T* it) : _ptr(it) { return; }
		random_access_iterator(const random_access_iterator& src) { *this = src; return; }
		
		/* DESTRUCTOR--> Vector Destructor */ 
		~random_access_iterator() { return; }
		
		/* OPERATOR= FUNCTION --> Assign content */ 
		random_access_iterator&		operator=(const random_access_iterator &obj)
		{
			if (this != &obj)
				this->_ptr = obj._ptr;
			return *this;
		}
		
		/* OPERATOR[] FUNCTION --> Returns reference of pointer to the n'th object */ 
		T&							operator[](const std::ptrdiff_t& n) { return _ptr[n]; }
		
		/* OPERATOR* FUNCTION --> Return reference */ 
		T&							operator*() { return *_ptr; }

		/* OPERATOR-> FUNCTION --> Return pointer */ 
		T*							operator->() { return _ptr; }
		
		/* OPERATOR++ FUNCTION --> pluses the pointer */ 
		random_access_iterator& 	operator++() { _ptr++; return *this; }
		random_access_iterator		operator++(int)
		{
			random_access_iterator tmp(*this);

			++(*this);
			return tmp;
		}

		/* OPERATOR-- FUNCTION --> minus the pointer */ 
		random_access_iterator& 	operator--() { _ptr--; return *this; }
		random_access_iterator		operator--(int)
		{
			random_access_iterator tmp(*this);

			--(*this);
			return tmp;
		}
		
		/* OPERATOR+ FUNCTION --> pointer + diff */ 
		random_access_iterator		operator+(const std::ptrdiff_t& n) { return random_access_iterator<T>(_ptr + n); }
		std::ptrdiff_t				operator+(const random_access_iterator& obj) { return _ptr + obj._ptr; }
	
		/* OPERATOR- FUNCTION --> pointer - diff */ 
		random_access_iterator		operator-(const std::ptrdiff_t& n) { return random_access_iterator<T>(_ptr - n); }
		std::ptrdiff_t				operator-(const random_access_iterator& obj) { return _ptr - obj._ptr; }
	
		/* OPERATOR+= FUNCTION --> Pluses the pointer with n */ 
		random_access_iterator		operator+=(const std::ptrdiff_t& n) { _ptr += n; return *this; }
	
		/* OPERATOR+= FUNCTION --> Minisus the pointer with n */ 
		random_access_iterator		operator-=(const std::ptrdiff_t& n) { _ptr -= n; return *this; }

		/* ------------ RELATIONAL OPERATORS------------ */
		template< typename T2>
		friend bool		operator<(const random_access_iterator<T2> &lhs, const random_access_iterator<T2> &rhs) { return (lhs._ptr < rhs._ptr); }
		
		template< typename T2>
		friend bool		operator<=(const random_access_iterator<T2> &lhs, const random_access_iterator<T2>  &rhs) { return !(lhs._ptr < rhs._ptr); }
		
		template< typename T2>
		friend bool		operator>(const random_access_iterator<T2> &lhs, const random_access_iterator<T2>  &rhs) { return (lhs._ptr > rhs._ptr); }
		
		template< typename T2>
		friend bool		operator>=(const random_access_iterator<T2> &lhs, const random_access_iterator<T2>  &rhs) { return !(lhs._ptr > rhs._ptr); }
		
		template< typename T2>
		friend bool		operator!=(const random_access_iterator<T2> &lhs, const random_access_iterator<T2>  &rhs) { return (lhs._ptr != rhs._ptr); }
		
		template< typename T2>
		friend bool		operator==(const random_access_iterator<T2> &lhs, const random_access_iterator<T2>  &rhs) { return (lhs._ptr == rhs._ptr); }
		
		/*GETTER*/
		T* get_ptr() const { return _ptr; };
	};
	
	template<typename T >
	class const_random_access_iterator
	{
		public:

			typedef	std::random_access_iterator_tag		iterator_category;
			typedef	T									value_type;
			typedef	std::ptrdiff_t						difference_type;
			typedef	T									*pointer;
			typedef	T									&reference;
			typedef	const T								*const_pointer;
			typedef	const T								&const_reference;
			
		private:

			T*		_ptr;

		public:

		/* ------------MEMBER FUNCTIONS------------ */
		/* CONSTRUCTOR */
		const_random_access_iterator() : _ptr(NULL) { return; }
		explicit const_random_access_iterator(T* it) : _ptr(it) { return; }
		const_random_access_iterator(const const_random_access_iterator& src) { *this = src; return; }
		const_random_access_iterator(const random_access_iterator<T> &it) { _ptr = it.get_ptr(); }
		
		/* DESTRUCTOR--> Vector Destructor */ 
		~const_random_access_iterator() { return; }
		
		/* OPERATOR= FUNCTION --> Assign content */ 
		const_random_access_iterator&		operator=(const const_random_access_iterator &obj)
		{
			if (this != &obj)
				this->_ptr = obj._ptr;
			return *this;
		}
		
		/* OPERATOR[] FUNCTION --> Returns reference of pointer to the n'th object */ 
		const T&							operator[](const std::ptrdiff_t& n) { return _ptr[n]; }
		
		/* OPERATOR* FUNCTION --> Return reference */ 
		const T&							operator*() const { return *_ptr; } // Moet dit const zijn?

		/* OPERATOR-> FUNCTION --> Return pointer */ 
		const T*							operator->() const { return _ptr; } // Moet dit const zijn?
		
		/* OPERATOR++ FUNCTION --> pluses the pointer */ 
		const_random_access_iterator& 		operator++() { _ptr++; return *this; }
		const_random_access_iterator		operator++(int)
		{
			const_random_access_iterator tmp(*this);

			++(*this);
			return tmp;
		}

		/* OPERATOR-- FUNCTION --> minus the pointer */ 
		const_random_access_iterator& 		operator--() { _ptr--; return *this; }
		const_random_access_iterator		operator--(int)
		{
			const_random_access_iterator tmp(*this);

			--(*this);
			return tmp;
		}
		
		/* OPERATOR+ FUNCTION --> pointer + diff */ 
		const_random_access_iterator		operator+(const std::ptrdiff_t& n) { return const_random_access_iterator<T>(_ptr + n); }
		std::ptrdiff_t						operator+(const const_random_access_iterator& obj) { return _ptr + obj._ptr; }
	
		/* OPERATOR- FUNCTION --> pointer - diff */ 
		const_random_access_iterator		operator-(const std::ptrdiff_t& n) { return const_random_access_iterator<T>(_ptr - n); }
		std::ptrdiff_t						operator-(const const_random_access_iterator& obj) { return _ptr - obj._ptr; }
	
		/* OPERATOR+= FUNCTION --> Pluses the pointer with n */ 
		const_random_access_iterator		operator+=(const std::ptrdiff_t& n) { _ptr += n; return *this; }
	
		/* OPERATOR+= FUNCTION --> Minisus the pointer with n */ 
		const_random_access_iterator		operator-=(const std::ptrdiff_t& n) { _ptr -= n; return *this; }

		/* ------------ RELATIONAL OPERATORS------------ */
		template< typename T2>
		friend bool		operator<(const const_random_access_iterator<T2> &lhs, const const_random_access_iterator<T2> &rhs) { return (lhs._ptr < rhs._ptr); }
		
		template< typename T2>
		friend bool		operator<=(const const_random_access_iterator<T2> &lhs, const const_random_access_iterator<T2>  &rhs) { return !(lhs._ptr < rhs._ptr); }
		
		template< typename T2>
		friend bool		operator>(const const_random_access_iterator<T2> &lhs, const const_random_access_iterator<T2>  &rhs) { return (lhs._ptr > rhs._ptr); }
		
		template< typename T2>
		friend bool		operator>=(const const_random_access_iterator<T2> &lhs, const const_random_access_iterator<T2>  &rhs) { return !(lhs._ptr > rhs._ptr); }
		
		template< typename T2>
		friend bool		operator!=(const const_random_access_iterator<T2> &lhs, const const_random_access_iterator<T2>  &rhs) { return (lhs._ptr != rhs._ptr); }
		
		template< typename T2>
		friend bool		operator==(const const_random_access_iterator<T2> &lhs, const const_random_access_iterator<T2>  &rhs) { return (lhs._ptr == rhs._ptr); }
		/*GETTER*/
		const T& get_ptr() const { return _ptr; };
	};

	template< typename T >
	class reverse_random_access_iterator
	{
		public:

			typedef	std::random_access_iterator_tag		iterator_category;
			typedef	T									value_type;
			typedef	std::ptrdiff_t						difference_type;
			typedef	T									*pointer;
			typedef	T									&reference;
			typedef	const T								*const_pointer;
			typedef	const T								&const_reference;
			
		private:

			T*		_ptr;

		public:

		/* ------------MEMBER FUNCTIONS------------ */
		/* CONSTRUCTOR */		
		reverse_random_access_iterator() : _ptr(NULL) { return; }
		explicit reverse_random_access_iterator(T* it) : _ptr(it) { return; }
		reverse_random_access_iterator(const reverse_random_access_iterator& src) { *this = src; return; }
		
		/* DESTRUCTOR--> Vector Destructor */ 
		~reverse_random_access_iterator() { return; }
		
		/* OPERATOR= FUNCTION --> Assign content */ 
		reverse_random_access_iterator&		operator=(const reverse_random_access_iterator &obj)
		{
			if (this != &obj)
				this->_ptr = obj._ptr;
			return *this;
		}
		
		/* OPERATOR[] FUNCTION --> Returns reference of pointer to the n'th object */ 
		T&							operator[](const std::ptrdiff_t& n) { return _ptr[n]; }
		
		/* OPERATOR* FUNCTION --> Return reference */ 
		T&							operator*() { return *_ptr; }

		/* OPERATOR-> FUNCTION --> Return pointer */ 
		T*							operator->() { return _ptr; }
		
		/* OPERATOR++ FUNCTION --> pluses the pointer */ 
		reverse_random_access_iterator& 	operator++() { _ptr--; return *this; }
		reverse_random_access_iterator		operator++(int)
		{
			reverse_random_access_iterator tmp(*this);

			++(*this);
			return tmp;
		}

		/* OPERATOR-- FUNCTION --> minus the pointer */ 
		reverse_random_access_iterator& 	operator--() { _ptr++; return *this; }
		reverse_random_access_iterator		operator--(int)
		{
			reverse_random_access_iterator tmp(*this);

			--(*this);
			return tmp;
		}
		
		/* OPERATOR+ FUNCTION --> pointer + diff */ 
		reverse_random_access_iterator		operator+(const std::ptrdiff_t& n) { return reverse_random_access_iterator<T>(_ptr - n); }
		std::ptrdiff_t						operator+(const reverse_random_access_iterator& obj) { return _ptr - obj._ptr; }
	
		/* OPERATOR- FUNCTION --> pointer - diff */ 
		reverse_random_access_iterator		operator-(const std::ptrdiff_t& n) { return reverse_random_access_iterator<T>(_ptr + n); }
		std::ptrdiff_t						operator-(const reverse_random_access_iterator& obj) { return _ptr + obj._ptr; }
	
		/* OPERATOR+= FUNCTION --> Pluses the pointer with n */ 
		reverse_random_access_iterator		operator+=(const std::ptrdiff_t& n) { _ptr -= n; return *this; }
	
		/* OPERATOR+= FUNCTION --> Minisus the pointer with n */ 
		reverse_random_access_iterator		operator-=(const std::ptrdiff_t& n) { _ptr += n; return *this; }

		/* ------------ RELATIONAL OPERATORS------------ */
		template< typename T2>
		friend bool		operator<(const reverse_random_access_iterator<T2> &lhs, const reverse_random_access_iterator<T2> &rhs) { return (lhs._ptr < rhs._ptr); }
		
		template< typename T2>
		friend bool		operator<=(const reverse_random_access_iterator<T2> &lhs, const reverse_random_access_iterator<T2>  &rhs) { return !(lhs._ptr < rhs._ptr); }
		
		template< typename T2>
		friend bool		operator>(const reverse_random_access_iterator<T2> &lhs, const reverse_random_access_iterator<T2>  &rhs) { return (lhs._ptr > rhs._ptr); }
		
		template< typename T2>
		friend bool		operator>=(const reverse_random_access_iterator<T2> &lhs, const reverse_random_access_iterator<T2>  &rhs) { return !(lhs._ptr > rhs._ptr); }
		
		template< typename T2>
		friend bool		operator!=(const reverse_random_access_iterator<T2> &lhs, const reverse_random_access_iterator<T2>  &rhs) { return (lhs._ptr != rhs._ptr); }
		
		template< typename T2>
		friend bool		operator==(const reverse_random_access_iterator<T2> &lhs, const reverse_random_access_iterator<T2>  &rhs) { return (lhs._ptr == rhs._ptr); }
		
		/*GETTER*/
		T* get_ptr() const { return (_ptr); };
	};

	template< typename T >
	class const_reverse_random_access_iterator
	{
		public:

			typedef	std::random_access_iterator_tag		iterator_category;
			typedef	T									value_type;
			typedef	std::ptrdiff_t						difference_type;
			typedef	T									*pointer;
			typedef	T									&reference;
			typedef	const T								*const_pointer;
			typedef	const T								&const_reference;
		
		private:

			T*		_ptr;

		public:

		/* ------------MEMBER FUNCTIONS------------ */
		/* CONSTRUCTOR */
		const_reverse_random_access_iterator() : _ptr(NULL) { return; }
		explicit const_reverse_random_access_iterator(T* it) : _ptr(it) { return; }
		const_reverse_random_access_iterator(const const_reverse_random_access_iterator& src) { *this = src; return; }
		const_reverse_random_access_iterator(const reverse_random_access_iterator<T> &it) { _ptr = it.get_ptr();  return; }
		
		/* DESTRUCTOR--> Vector Destructor */ 
		~const_reverse_random_access_iterator() { return; }
		
		/* OPERATOR= FUNCTION --> Assign content */ 
		const_reverse_random_access_iterator&		operator=(const const_reverse_random_access_iterator &obj)
		{
			if (this != &obj)
			{
				this->_ptr = obj._ptr;
			}
			return *this;
		}
		
		/* OPERATOR[] FUNCTION --> Returns reference of pointer to the n'th object */ 
		T&							operator[](const std::ptrdiff_t& n) { return _ptr[n]; }
		
		/* OPERATOR* FUNCTION --> Return reference */ 
		T&							operator*() { return *_ptr; }

		/* OPERATOR-> FUNCTION --> Return pointer */ 
		T*							operator->() { return _ptr; }
		
		/* OPERATOR++ FUNCTION --> pluses the pointer */ 
		const_reverse_random_access_iterator& 	operator++() { _ptr--; return *this; }
		const_reverse_random_access_iterator	operator++(int)
		{
			const_reverse_random_access_iterator tmp(*this);

			++(*this);
			return tmp;
		}

		/* OPERATOR-- FUNCTION --> minus the pointer */ 
		const_reverse_random_access_iterator& 	operator--() { _ptr++; return *this; }
		const_reverse_random_access_iterator	operator--(int)
		{
			const_reverse_random_access_iterator tmp(*this);

			--(*this);
			return tmp;
		}
		
		/* OPERATOR+ FUNCTION --> pointer + diff */ 
		const_reverse_random_access_iterator	operator+(const std::ptrdiff_t& n) { return const_reverse_random_access_iterator<T>(_ptr - n); }
		std::ptrdiff_t							operator+(const const_reverse_random_access_iterator& obj) { return _ptr - obj._ptr; }
	
		/* OPERATOR- FUNCTION --> pointer - diff */ 
		const_reverse_random_access_iterator	operator-(const std::ptrdiff_t& n) { return const_reverse_random_access_iterator<T>(_ptr + n); }
		std::ptrdiff_t							operator-(const const_reverse_random_access_iterator& obj) { return _ptr + obj._ptr; }
	
		/* OPERATOR+= FUNCTION --> Pluses the pointer with n */ 
		const_reverse_random_access_iterator	operator+=(const std::ptrdiff_t& n) { _ptr -= n; return *this; }
	
		/* OPERATOR+= FUNCTION --> Minisus the pointer with n */ 
		const_reverse_random_access_iterator	operator-=(const std::ptrdiff_t& n) { _ptr += n; return *this; }

		/* ------------ RELATIONAL OPERATORS------------ */
		template< typename T2>
		friend bool		operator<(const random_access_iterator<T2> &lhs, const random_access_iterator<T2> &rhs) { return (lhs._ptr < rhs._ptr); }
		
		template< typename T2>
		friend bool		operator<=(const random_access_iterator<T2> &lhs, const random_access_iterator<T2>  &rhs) { return !(lhs._ptr < rhs._ptr); }
		
		template< typename T2>
		friend bool		operator>(const random_access_iterator<T2> &lhs, const random_access_iterator<T2>  &rhs) { return (lhs._ptr > rhs._ptr); }
		
		template< typename T2>
		friend bool		operator>=(const random_access_iterator<T2> &lhs, const random_access_iterator<T2>  &rhs) { return !(lhs._ptr > rhs._ptr); }
		
		template< typename T2>
		friend bool		operator!=(const random_access_iterator<T2> &lhs, const random_access_iterator<T2>  &rhs) { return (lhs._ptr != rhs._ptr); }
		
		template< typename T2>
		friend bool		operator==(const random_access_iterator<T2> &lhs, const random_access_iterator<T2>  &rhs) { return (lhs._ptr == rhs._ptr); }
		/*GETTER*/
		const T* &get_ptr() const { return (_ptr); };
	};
}
#endif