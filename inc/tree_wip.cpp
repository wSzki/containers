


#include <iostream>
#include <cstddef>
#include <memory>
#include <functional>



/* ========================================================================== */
/* ---------------------------------- NODE ---------------------------------- */
/* ========================================================================== */
template <typename Key, typename Data>
struct node {

	Key    key;
	Data      data;
	node * left;
	node * right;
	node * parent;

	node (
			Key    key_    = 0,
			Data      data_   = 0,
			node * parent_ = NULL,
			node * left_   = NULL,
			node * right_  = NULL
		 )
	{
		key    = key_;
		data   = data_   ;
		parent = parent_ ;
		left   = left_   ;
		right  = right_  ;
	};
};

/* ========================================================================== */
/* ---------------------------------- TREE ---------------------------------- */
/* ========================================================================== */
template <typename Key, typename Data>
class tree
{
	public:

		/* .................. TYPEDEFS .................. */
		typedef node <Key, Data>  node_t;
		typedef node_t * nodePtr;
		typedef typename std::allocator<node_t> Alloc;

	public:
		/* ............. VARIABLE  MEMBERS .............. */
		node_t * node_root;
		node_t * node_current;
		node_t * end;
		Alloc    alloc;
		size_t   number_leaves;
		std::less<Key> compare; // equivalent to '<' ,(compare(a, b))

	public:
		/* ............... NODE ALLOCATOR ............... */
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
			alloc.construct(new_node, node_t(key, data, parent, left, right));
			return new_node;
		}

		/* ............ DEFAULT CONSTRUCTOR ............. */
		// NOTE default tree() constructor inits key & value to 0, not good?
		tree (void) {
			end           = allocate_node(0, 0, NULL, NULL, NULL); // Generating a dummy node pointer as a delimiter
			//node_current  = NULL;
			node_root     = NULL;
			number_leaves = 0;
		};

		/* ................. DESTRUCTOR ................. */
		~tree() { chop_tree(node_root); alloc.destroy(end); alloc.deallocate(end, 1); }
		void chop_tree(nodePtr n = NULL)
		{
			if (n == end ) return;
			if (n == NULL) n = node_root;
			chop_tree(n->left);
			chop_tree(n->right);
			alloc.destroy(n);
			alloc.deallocate(n, 1);
		}

		/* ................... INSERT ................... */
		// NOTE Does nothing if key already exists
		// NOTE & is needed to modify the node pointer's address within the function
		// NOTE node == NULL if tree has just been initialized
		void insert (Key key, Data data) { insert(key, data, node_root, end);}
		void insert (Key key, Data data, nodePtr & node, nodePtr node_parent)
		{
			if   (node == end || node == NULL)
			{
				node = allocate_node(key, data, node_parent);
				number_leaves++;
				return ;
			}
			if   (key  == node->key) return ;
			if   (key  <  node->key) insert(key, data, node->left, node);
			else                     insert(key, data, node->right, node);
		}
		// NOTE insert wrapper, insert always starts from root

		//void insert_left   (Data data) { node_current->left  = allocate_node(data); number_leaves++; }
		//void insert_right  (Data data) { node_current->right = allocate_node(data); number_leaves++; }

		/* ............... TREE MOVEMENT ................ */
		//void go_root  (void) { node_current = node_root;            }
		//void go_up    (void) { node_current = node_current->parent; }
		//void go_left  (void) { node_current = node_current->left;   }
		//void go_right (void) { node_current = node_current->right;  }

		/* .................... FIND .................... */
		// NOTE returns nodePtr * end if nothing found
		nodePtr	find_key (const Key k, nodePtr n = NULL) const {
			if (n == end)    return (end) ;
			if (n == NULL)   n = node_root;
			if (k == n->key) return (n);
			if (k <  n->key) return (find_key(k, n->left));
			else             return (find_key(k, n->right));
		}

		nodePtr	find_data (const Data d, nodePtr n = NULL) const {
			if (n == end)     return (end) ;
			if (n == NULL)    n = node_root;
			if (d == n->data) return (n);
			if (d <  n->data) return (find_data(d, n->left));
			else              return (find_data(d, n->right));
		}

		/* ................... UTILS .................... */
		size_t size     () const {return (number_leaves);}
		bool   empty    () const {return (size() == 0);}
		size_t max_size () const {return (alloc.max_size());}

		/* .................. MIN/MAX ................... */
		nodePtr		getMin (nodePtr n = NULL) const	{
			if     (n == NULL)      n = node_root;
			while  (n->left != end) n = n->left;
			return (n);
		}

		nodePtr		getMax (nodePtr n = NULL) const	{
			if     (n == NULL)      n = node_root;
			while  (n->right != end) n = n->right;
			return (n);
		}

		/* ............. GETTERS / SETTERS .............. */
		nodePtr get_node_root    (void)      { return        node_root;    }
		void    set_node_root    (nodePtr n) { node_root    = n;           }
		//nodePtr get_node_current (void)      { return        node_current; }
		//void    set_node_current (nodePtr n) { node_current = n;           }

		/* ================================================================== */
		/* ------------------------------ TODO ------------------------------ */
		/* ================================================================== */
		void    clear    (void); // like chop tree?
		void    swap     (tree        & t); // can i just swap content
		void	insert   (const Data     & data); // insert single data
		void	erase    (const Data     & data); // erase single data

		//void	infixe     (nodePtr ptr) const ; // wtf isinfix
		nodePtr	successeur (nodePtr ptr) const ; // wtf is successeur
		void	toDelete   (nodePtr ptr) ; // delete a node

		void		infixe(nodePtr ptr) const {
			if (ptr == end || !ptr) {return ;}
			infixe(ptr->left);
			std::cout << "ptr  : " << ptr << " - " << ptr->left << " - " << ptr->right  ;
			std::cout << " - KEY : " << ptr->data << " - T : " << ptr->data << "\n";
			std::cout << "papa : " << ptr->parent <<  std::endl << std::endl;
			infixe(ptr->right);
		}
};

int main ()
{
	tree <int, int> t;

	std::cout << "tree size : "<< t.size() << std::endl;

	t.insert(1, 42 );
	t.insert(2, 43 );
	t.insert(5, 48 );
	std::cout << "tree size : "<< t.size() << std::endl;
	std::cout << t.node_root->data << std::endl;
	std::cout << t.node_root->right->data << std::endl;
	std::cout << t.node_root->right->right->data << std::endl;

	std::cout << t.getMin()->key << std::endl;
	std::cout << t.getMax()->key << std::endl;
	//t.insert_left(-42);
	//t.insert_right(42);


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
}

