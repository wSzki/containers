/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_wip.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 06:24:42 by wszurkow          #+#    #+#             */
/*   Updated: 2022/09/25 21:35:23 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstddef>
#include <memory>
#include <functional>

/* ========================================================================== */
/* ---------------------------------- NODE ---------------------------------- */
/* ========================================================================== */
template <typename Key, typename Data>
struct node {

	Key    first;
	Data   second;
	node * left; 
	node * right;
	node * parent;
	node * end;

	node (
			Key    key_    = 0,
			Data   data_   = 0,
			node * parent_ = NULL,
			node * left_   = NULL,
			node * right_  = NULL,
			node * end_    = NULL
		 )
	{
		first    = key_    ;
		second   = data_   ;
		parent   = parent_ ;
		left     = left_   ;
		right    = right_  ;
		end      = end_    ;
	};
};

/* ========================================================================== */
/* ---------------------------------- TREE ---------------------------------- */
/* ========================================================================== */
template <typename Key, typename Data>
class tree
{
	/* .............................................. */
	/* .................. TYPEDEFS .................. */
	/* .............................................. */
	public:
		typedef node<Key,Data>                  node_t;
		typedef node_t *                        nodePtr;
		typedef typename std::allocator<node_t> Alloc;

		/* .............................................. */
		/* ............. VARIABLE  MEMBERS .............. */
		/* .............................................. */
	protected:
		node_t * node_root;
		node_t * node_current;
		node_t * node_last_inserted;
		node_t * end;
		Alloc    alloc;
		size_t   number_leaves;
		std::less<Key> compare; // equivalent to '<' ,(compare(a, b))

	public:

		/* .............................................. */

		/* .............................................. */
		nodePtr allocate_node (
				Key     key    = 0,
				Data    data   = 0,
				nodePtr parent = NULL,
				nodePtr left   = NULL,
				nodePtr right  = NULL
				)
		{
			if (left   == NULL) left   = end;
			if (right  == NULL) right  = end;
			nodePtr new_node = alloc.allocate(1);
			alloc.construct(new_node, node_t(key, data, parent, left, right, end));
			return new_node;
		}

		/* .............................................. */
		/* ................. CONSTUCTOR ................. */
		/* .............................................. */
		tree (void) {
			end           = NULL;
			end           = allocate_node(0, 0, NULL, NULL, NULL); // Generating a dummy node pointer as a delimiter
			node_root     = NULL;
			number_leaves = 0;
		};

		/* .............................................. */
		/* ................. DESTRUCTOR ................. */
		/* .............................................. */
		~tree() { chop_tree(node_root); alloc.destroy(end); alloc.deallocate(end, 1); end = NULL ;}
		void clear() { chop_tree(node_root); alloc.destroy(end); alloc.deallocate(end, 1); end = NULL; }
		void chop_tree(nodePtr n)
		{
			// NOTE check for NULL if there is only node end in tree
			if (n == end || n == NULL) return;
			chop_tree(n->left);
			chop_tree(n->right);
			alloc.destroy(n);
			alloc.deallocate(n, 1);
		}

		/* .............................................. */
		/* ................... INSERT ................... */
		/* .............................................. */
		// NOTE Does nothing if key already exists
		// NOTE & is needed to modify the node pointer's address within the function
		// NOTE node == NULL if tree has just been initialized

		nodePtr insert (const Key key, Data data) {
			node_last_inserted = NULL;
			insert(key, data, node_root, end);
			return node_last_inserted;
		}
		void insert (const Key key, Data data, nodePtr & node, nodePtr node_parent)
		{
			if   (node == end || node == NULL)
			{
				node = allocate_node(key, data, node_parent);
				node_last_inserted = node;
				number_leaves++;
				return ;
			}
			if   (key  == node->first) return ;
			if   (key  <  node->first) insert(key, data, node->left, node);
			else                     insert(key, data, node->right, node);
		}

		/* .............................................. */
		/* .................... FIND .................... */
		/* .............................................. */
		// NOTE returns nodePtr * end if nothing found
		nodePtr	find_key (const Key k, nodePtr n = NULL) const {
			//if (n == end || n == NULL) return (end) ;
			if (n == NULL)   n = node_root;
			if (n == end)    return (end) ;
			if (k == n->first) return (n);
			if (k <  n->first) return (find_key(k, n->left));
			else             return (find_key(k, n->right));
		}

		nodePtr	find_data (const Data d, nodePtr n = NULL) const {
			//if (n == end || n == NULL) return (end) ;
			if (n == NULL)    n = node_root;
			if (n == end)     return (end) ;
			if (d == n->data) return (n);
			if (d <  n->data) return (find_data(d, n->left));
			else              return (find_data(d, n->right));
		}

		/* .............................................. */
		/* ................... ERASE .................... */
		/* .............................................. */
		void erase(const Key key) {
			nodePtr node = find_key(key, node_root);
			if (node == NULL ) return;
			prune(node); number_leaves--;
		}

		bool single_leaf   (void)         { return (number_leaves == 1) ;                                       }
		bool no_branches   (nodePtr node) { return (node->left == end && node->right == end) ? true : false;    }
		bool two_branches  (nodePtr node) { return (node->left != end && node->right != end) ? true : false;    }
		bool single_branch (nodePtr node) { return (no_branches(node) == false && two_branches(node) == false); }

		void prune(nodePtr & node)
		{
			nodePtr parent = node->parent;
			if      (single_leaf())       node_root = NULL;
			else if (no_branches(node))   parent->left == node ? parent->left = end : parent->right = end;
			else if (single_branch(node)) {
				nodePtr child = (node->left == end ? node->left : node->right);
				if      (node == node_root)     { node_root     = child; child->parent = NULL;   }
				else if (node == parent->left)  { parent->left  = child; child->parent = parent; }
				else if (node == parent->right) { parent->right = child; child->parent = parent; }
			}
			else if (two_branches(node))
			{
				// TODO
			}
			alloc.destroy(node);
			alloc.deallocate(node, 1);
		}

		/* .............................................. */
		/* ................... UTILS .................... */
		/* .............................................. */
		size_t size     () const {return (number_leaves);}
		bool   empty    () const {return (size() == 0);}
		size_t max_size () const {return (alloc.max_size());}

		nodePtr		getMin (nodePtr n = NULL) const	{
			if     (size() == 0)      return NULL;
			if     (n == NULL)      n = node_root;
			while  (n->left != end) n = n->left;
			return (n);
		}

		nodePtr		getMax (nodePtr n = NULL) const	{
			if     (size() == 0)     return NULL;
			if     (n == NULL)       n = node_root;
			while  (n->right != end) n = n->right;
			return (n);
		}

		/* ............. GETTERS / SETTERS .............. */
		nodePtr get_node_root    (void)      { return        node_root;    }
		void    set_node_root    (nodePtr n) { node_root    = n;           }
		nodePtr get_node_end     (void)  const    { return        end;    }

		void swap (tree & t) {
			nodePtr tmp_node_root     = node_root;
			nodePtr tmp_end           = end;
			Alloc   tmp_alloc         = alloc;
			size_t	tmp_number_leaves = number_leaves;

			node_root     = t.node_root;
			end           = t.end;
			alloc         = t.alloc;
			number_leaves = t.number_leaves;

			t.node_root     = tmp_node_root;
			t.end           = tmp_end;
			t.alloc         = tmp_alloc;
			t.number_leaves = tmp_number_leaves;
		};

		/* ================================================================== */
		/* ------------------------------ TODO ------------------------------ */
		/* ================================================================== */
		//void    clear    (void); // like chop tree?
		void	insert   (const Data     & data); // insert single data

		//void	infixe     (nodePtr ptr) const ; // wtf isinfix
		nodePtr	successeur (nodePtr ptr) const ; // wtf is successeur
		void	toDelete   (nodePtr ptr) ; // delete a node

};

//int main ()
//{
//tree <int, int> t;
//tree <int, int> t2;

//std::cout << "tree size : "<< t.size() << std::endl;

//t.insert(1, 42 );
//t.insert(2, 43 );
//t.insert(5, 48 );
//std::cout << "tree size : "<< t.size() << std::endl;
//std::cout << t.get_node_root()->data << std::endl;
//std::cout << t.get_node_root()->right->data << std::endl;
//std::cout << t.get_node_root()->right->right->data << std::endl;

//std::cout << t.getMin()->key << std::endl;
//std::cout << t.getMax()->key << std::endl;

//t.erase(5);
//std::cout <<	t.getMax()->data << std::endl;
////t.insert_left(-42);
////t.insert_right(42);


////t.get_node_current() = t.get_node_current()->left;

////std::cout << t.get_node_root->data << std::endl;
//std::cout << t.get_node_current()->left->data << std::endl;
//std::cout << t.get_node_current()->right->data << std::endl;
////t.insert_right(42);
//t.set_node_current(t.get_node_current()->left);
//t.insert_left(-56);
//t.insert_right(2);
//std::cout << t.get_node_current()->left->data << std::endl;
//std::cout << t.get_node_current()->right->data << std::endl;
//t.go_root();
//std::cout << t.get_node_current()->left->data << std::endl;
//std::cout << t.get_node_current()->right->data << std::endl;
//std::cout << t.getMin()->data << std::endl;

//node<int, int>* n;
//n = t.find_data(0);
//std::cout << n << std::endl;
//std::cout << n->data << std::endl;

//t.infixe(t.get_node_root());
//}

