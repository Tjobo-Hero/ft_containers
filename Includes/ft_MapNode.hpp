/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_MapNode.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/23 08:46:00 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/23 15:58:50 by timvancitte   ########   odam.nl         */
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
			size_t		height;
			T			data;
		
		explicit mapNode() : left(NULL), right(NULL), parent(NULL), height(0), data() { return; }
		explicit mapNode(const T &data) : left(NULL), right(NULL), parent(NULL){ 
			data = ft::make_pair(data);
			return; }
		~mapNode() { return; }
		mapNode(const mapNode &src) : left(src.left), right(src.right), parent(src.parent), data(src.data), height(0) { return *this; }
		
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

		// maybe getters

	}; // end op MAPNODE class
} // end of namespace ft
#endif