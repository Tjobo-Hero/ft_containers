/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_MapNode.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/23 08:46:00 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/30 12:08:05 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAPNODE_HPP
# define FT_MAPNODE_HPP

namespace ft
{
	template< typename T >
	class mapNode
	{
		public:

			mapNode*	left;
			mapNode*	right;
			mapNode*	parent;
			T			data;
		
		explicit mapNode() : left(NULL), right(NULL), parent(NULL), data() { return; }
		explicit mapNode(const T &data) : left(NULL), right(NULL), parent(NULL), data(data) { return; }
		~mapNode() { return; }
		mapNode(const mapNode &src) : left(src.left), right(src.right), parent(src.parent), data(src.data) { return *this; }
		
		mapNode&		operator=(const mapNode &obj)
		{
			if (this != &obj)
			{
				this->left = obj.left;
				this->right = obj.right;
				this->parent = obj.parent;
				this->data = obj.data;
			}
			return *this;
		}
		
		mapNode*		getNext()
		{
			mapNode* next = this;
			mapNode* tmp = next->parent;			
			if (next->right)
			{
				next = next->right;
				// std::cout << "Data: " << next->data.first << std::endl;
				// if (next->data.first == 6)
				// {
					// std::cout << "LE " << next->right->data.first << std::endl;
				// }
				while (next->left)
				{
					next = next->left;
					// std::cout << "TEST3" << std::endl;
				}
				return next;	
			}
			while (tmp && next == tmp->right)
			{
				tmp = tmp->parent;
				next = next->parent;
				// std::cout << "TEST5" << std::endl;
			}
			// std::cout << "TEST" << std::endl;
			return tmp; // what if !tmp in which case does this exist
		}
		// maybe getters

	}; // end op MAPNODE class
} // end of namespace ft
#endif