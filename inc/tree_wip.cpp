


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
	node * parent;
	node * left;
	node * right;
	node (
			T      data   = 0,
			node * parent = NULL,
			node * left   = NULL,
			node * right  = NULL
		 ):
		data   (data),
		parent (parent),
		left   (left),
		right  (right)
	{};
};

/* ========================================================================== */
/* ---------------------------------- TREE ---------------------------------- */
/* ========================================================================== */
template <typename Key, typename T>
class tree
{
	public:

		/* .................. TYPEDEFS .................. */
		typedef node <T>  node_t;
		typedef node_t * nodePtr;
		typedef typename std::allocator<node<T> > Alloc;

		/* ............. VARIABLE  MEMBERS .............. */
		node_t * node_root;
		node_t * node_current;
		Alloc    alloc;
		size_t   number_leaves;

		/* ............... NODE ALLOCATOR ............... */
		nodePtr allocate_node (T val)
		{
			nodePtr new_node = alloc.allocate(1);
			alloc.construct(new_node, node_t(val));
			return new_node;
		}

		/* ............ DEFAULT CONSTRUCTOR ............. */
		tree (void) {
			node_root    = allocate_node(0);
			node_current = node_root;
			number_leaves  = 0;
		};


		void chop_tree(nodePtr n)
		{
			if (n == NULL) return;

			chop_tree(n->left);
			chop_tree(n->right);
			alloc.destroy(n);
			alloc.deallocate(n, 1);
		}

		~tree()
		{
			chop_tree(node_root);

		}

		/* ................... INSERT ................... */

		void insert_left  (T i) {
			node_current->left         = allocate_node(i);
			node_current->left->parent = node_current;
			number_leaves++;
		}

		void insert_right  (T i) {
			node_current->right         = allocate_node(i);
			node_current->right->parent = node_current;
			number_leaves++;
		}


		/* ............... TREE MOVEMENT ................ */
		void go_root  (void) { node_current = node_root;            }
		void go_up    (void) { node_current = node_current->parent; }
		void go_left  (void) { node_current = node_current->left;   }
		void go_right (void) { node_current = node_current->right;  }

		/* ................... UTILS .................... */
		size_t size    () const {return (number_leaves);}
		bool   empty   () const {return (size() == 0);}
		size_t max_size() const {return (alloc.max_size());}
};

int main ()
{
	tree <int, int> t;

	std::cout << t.node_root->data << std::endl;
	std::cout << t.node_current->data << std::endl;


	t.insert_left(21);
	t.insert_right(42);


	//t.node_current = t.node_current->left;

	//std::cout << t.node_root->data << std::endl;
	std::cout << t.node_current->left->data << std::endl;
	std::cout << t.node_current->right->data << std::endl;
	//t.insert_right(42);
	t.node_current = t.node_current->left;
	t.insert_left(1);
	t.insert_right(2);
	std::cout << t.node_current->left->data << std::endl;
	std::cout << t.node_current->right->data << std::endl;
	t.go_root();
	std::cout << t.node_current->left->data << std::endl;
	std::cout << t.node_current->right->data << std::endl;

}

