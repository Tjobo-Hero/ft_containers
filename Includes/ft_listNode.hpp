/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_listNode.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/09 10:48:34 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/09 14:03:14 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LISTNODE_HPP
# define FT_LISTNODE_HPP

namespace ft
{
	template< typename T >
	class listNode
	{
		public:

			listNode	*prev;
			listNode	*next;
			T			data;

		explicit listNode() : prev(NULL), next(NULL), data() { return; }
		explicit listNode(const T &data) : prev(NULL), next(NULL), data(data) { return; }
		~listNode() { return; }
		
		listNode(const listNode &src)
		{
			*this = src;
			return;
		}
		
		listNode&	operator=(const listNode &obj)
		{
			if (this != obj)
			{
				this->prev = obj.prev;
				this->next = obj.next;
				this->data = obj.data;
			}
			return *this;
		}

		listNode*	getPrevious() { return this->prev; }
		listNode*	getNext() { return this->next; }
		T&			getData() { return this->data; }
		
	};
	
} // end of namespace ft
#endif