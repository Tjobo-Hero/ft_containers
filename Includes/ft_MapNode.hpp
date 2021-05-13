/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_MapNode.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/23 08:46:00 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/05/13 10:51:18 by timvancitte   ########   odam.nl         */
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

			mapNode*		left;
			mapNode*		right;
			mapNode*		parent;
			T				data;

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
				while (next->left)
					next = next->left;
				return next;	
			}
			while (tmp && next == tmp->right)
			{
				tmp = tmp->parent;
				next = next->parent;
			}
			if (!tmp) 
			{
				while (next->left != NULL)
					next = next->left;
				tmp = next->left;
			}
			return tmp;
		}
		mapNode*		getPrevious()
		{
			mapNode* next = this;
			mapNode* tmp = next->parent;			
			if (next->left)
			{
				next = next->left;
				while (next->right)
					next = next->right;
				return next;	
			}
			while (tmp && next == tmp->left)
			{
				tmp = tmp->parent;
				next = next->parent;
			}
			if (!tmp) {
				while (next->right != NULL)
					next = next->right;
				tmp = next->right;
			}
			return tmp;
		}
		mapNode&	getNode()
		{
			return *this;
		}
	}; // end op MAPNODE class

} // end of namespace ft

#endif