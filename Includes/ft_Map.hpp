/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_Map.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 14:06:12 by tvan-cit      #+#    #+#                 */
/*   Updated: 2021/04/21 14:59:32 by tvan-cit      ########   odam.nl         */
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
            typedef Key                                             key_type;
            typedef T                                               mapped_type;
            typedef Compare                                         key_compare;
            typedef Alloc                                           allocator_type;
            typedef ft::pair<const key_type, mapped_type>           value_type;
            typedef mapNode<T>                                      Node;
            typedef T&											    reference;
			typedef const T&									    const_reference;
			typedef T*											    pointer;
			typedef const T*									    const_pointer;
            typedef bidirectional_iterator< T, Node >				iterator;
			typedef const_bidirectional_iterator< T, Node >			const_iterator;
			typedef reverse_bidirectional_iterator< T, Node >		reverse_iterator;
			typedef const_reverse_bidirectional_iterator< T, Node >	const_reverse_iterator;
            typedef std::ptrdiff_t									difference_type;
            typedef size_t											size_type;
            
        private:

            ?
        
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
        
        
    }; // end of MAP class
} // end of namespace ft

#endif