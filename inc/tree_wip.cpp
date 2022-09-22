


#include <iostream>
#include <cstddef>
#include <memory>
#include <functional>



/* ========================================================================== */
/* ---------------------------------- NODE ---------------------------------- */
/* ========================================================================== */
template <typename T>
struct node {
	T      data;
	node * left;
	node * right;
	node * parent;
	node (
			T      data_   = 0,
			node * parent_ = NULL,
			node * left_   = NULL,
			node * right_  = NULL
		 )
	{
		data   = data_   ;
		parent = parent_ ;
		left   = left_   ;
		right  = right_  ;
	};
};

/* ========================================================================== */
/* ---------------------------------- TREE ---------------------------------- */
/* ========================================================================== */
template <typename Key, typename T>
//template <typename Pair>
class tree
{
	public:

		/* .................. TYPEDEFS .................. */
		typedef node <T>  node_t;
		typedef node_t * nodePtr;
		typedef typename std::allocator<node<T> > Alloc;

	protected:
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
				T       val    = 0,
				nodePtr parent = NULL,
				nodePtr left   = NULL,
				nodePtr right  = NULL
				)
		{
			if (parent == NULL) parent = node_current;
			if (left   == NULL) left   = end;
			if (right  == NULL) right  = end;
			nodePtr new_node = alloc.allocate(1);
			alloc.construct(new_node, node_t(val, parent, left, right));
			return new_node;
		}

		/* ............ DEFAULT CONSTRUCTOR ............. */
		tree (void) {
			node_current  = NULL; // initializing current to NULL for parent in allocate_node;
			node_root     = allocate_node(0);
			node_current  = node_root; // current points to only existing node, root
			end           = nodePtr(); // Generating a dummy node pointer as a delimiter
			number_leaves = 0;
		};

		/* ................. DESTRUCTOR ................. */
		void chop_tree(nodePtr n = NULL)
		{
			if (n == end ) return;
			if (n == NULL) n = node_root;
			chop_tree(n->left);
			chop_tree(n->right);
			alloc.destroy(n);
			alloc.deallocate(n, 1);
		}
		~tree() { chop_tree(node_root); }

		/* ................... INSERT ................... */
		void insert_left   (T i) { node_current->left  = allocate_node(i); number_leaves++; }
		void insert_right  (T i) { node_current->right = allocate_node(i); number_leaves++; }

		/* ............... TREE MOVEMENT ................ */
		void go_root  (void) { node_current = node_root;            }
		void go_up    (void) { node_current = node_current->parent; }
		void go_left  (void) { node_current = node_current->left;   }
		void go_right (void) { node_current = node_current->right;  }

		/* .................... FIND .................... */
		nodePtr	find_key (const Key & k, const nodePtr n = NULL) const {
			if (n == end) return ;
			if (n == NULL) n = node_root;
			// TODO
		}

		nodePtr	find     (const T   & data,  nodePtr n = NULL) {
			if (n == end) return ;
			if (n == NULL) n = node_root;
			// TODO
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
		nodePtr get_node_current (void)      { return        node_current; }
		void    set_node_root    (nodePtr n) { node_root    = n;           }
		void    set_node_current (nodePtr n) { node_current = n;           }

		/* ================================================================== */
		/* ------------------------------ TODO ------------------------------ */
		/* ================================================================== */
		void    clear    (void); // like chop tree?
		void    swap     (tree        & t); // can i just swap content
		void	insert   (const T     & data); // insert single data
		void	erase    (const T     & data); // erase single data


		void	infixe     (nodePtr ptr) const ; // wtf isinfix
		nodePtr	successeur (nodePtr ptr) const ; // wtf is successeur
		void	toDelete   (nodePtr ptr) ; // delete a node


};

int main ()
{
	tree <int, int> t;

	std::cout << t.get_node_root()->data << std::endl;
	std::cout << t.get_node_current()->data << std::endl;


	t.insert_left(21);
	t.insert_right(42);


	//t.get_node_current() = t.get_node_current()->left;

	//std::cout << t.get_node_root->data << std::endl;
	std::cout << t.get_node_current()->left->data << std::endl;
	std::cout << t.get_node_current()->right->data << std::endl;
	//t.insert_right(42);
	t.set_node_current(t.get_node_current()->left);
	t.insert_left(1);
	t.insert_right(2);
	std::cout << t.get_node_current()->left->data << std::endl;
	std::cout << t.get_node_current()->right->data << std::endl;
	t.go_root();
	std::cout << t.get_node_current()->left->data << std::endl;
	std::cout << t.get_node_current()->right->data << std::endl;
	std::cout << t.getMin()->data << std::endl;

}

