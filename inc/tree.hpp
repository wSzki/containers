/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:41:06 by wszurkow          #+#    #+#             */
/*   Updated: 2022/09/17 21:51:21 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include <cstddef>

// http://carl.seleborg.free.fr/cpp/cours/chap2/arbres.html
// https://cours.etsmtl.ca/SEG/FHenri/inf145/Suppl%C3%A9ments/arbres%20binaires.htm

//https://fr.wikipedia.org/wiki/Arbre_bicolore
//https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/
//https://miashs-www.u-ga.fr/prevert/Prog/Java/CoursJava/arbresRougeNoir.html
//https://cours.etsmtl.ca/SEG/FHenri/inf145/Suppl%C3%A9ments/arbres%20binaires.htm
//
//
//On peut décrire le premier arbre binaire de la figure 1 ainsi :
// A = {1, {5, {0, Ø, Ø }, {3, Ø, Ø }}, {2, Ø, Ø }}
// Et le second de la façon suivante :
// A = {5, Ø, Ø}

namespace ft
{



	// NOTE destruction of node is handled by the tree
	template <typename T>
		class node
		{
			public:
				T data;
				node *parent;
				node *left;
				node *right;

				// Default Constructor
			public:
				node () : data(42), parent(NULL), left(NULL), right(NULL){};

				// Copy Constructor
				node (
						T data,
						node *parent = NULL,
						node *left = NULL,
						node *right = NULL
					 ):
					data(data),
					parent(parent),
					left(left),
					right(right) {};
		};

	template <typename Key, typename T>
		class tree
		{
			public :
				node<T> * root;
				node<T> * current;
				size_t    nb_nodes;

				// NOTE Disables copy - why?
				tree(const tree &);
				tree & operator = (const tree &);

			public :

				typedef node<T> node_type;
				typedef node<T>* node_ptr;
				typedef node<T>& node_reference;

				/* ---------------------- CONSTRUCTORS ---------------------- */
				tree (void) : root(NULL), current(NULL), nb_nodes(0) {};
				~tree(void) {};

				void insert(T val)
				{
					if (root == NULL)
						root = node_type(val);
					current = root;
				}

				/* ------------------------- ADDERS ------------------------- */
				int add_left  (const node_type & n) { current->left  = n; };
				int add_right (const node_type & n) { current->right = n; };

				/* ------------------------- MOVERS ------------------------- */
				int goto_root  (void) {current = current->root;}
				int goto_left  (void) {current = current->left;}
				int goto_right (void) {current = current->right;}

				/* ------------------------- CLEAR -------------------------- */
				void clear(void); // TODO flushes tree

				/* ------------------------ GETTERS ------------------------- */

				// NOTE Get content of current node
				T current_data (T &)  const {return current->data;}
				// NOTE get number of elements in tree
				size_t leaves       (void) const; // TODO
				size_t size         (void) const {return nb_nodes;}
				bool   empty        (void) const {return (size() == 0);}


				// Offre de parcours en modification.

				//inline void prefix(void (*f) (T &))
				//{ parcours_prefixe(racine, f);}

				//inline void infix(void (*f) (T &))
				//{ parcours_infixe(racine, f);}

				//inline void suffix(void (*f) (T &))
				//{ parcours_suffixe(racine, f);}

				//// METHODES DE CONSULTATION

				//// Offre de parcours en consultation.

				//inline void prefix(void (*f) (const T &)) const
				//{ parcours_prefixe(racine, f);}

				//inline void infix(void (*f) (const T &)) const
				//{ parcours_infixe(racine, f);}

				//inline void suffix(void (*f) (const T &)) const
				//{ parcours_suffixe(racine, f);}


				//inline int count_leaves() const     // Nombre de feuilles.
				//{ return compter_feuilles_arbre(racine);}

				//inline int depth() const  // Profondeur de l'arbre.
				//{ return profondeur_arbre(racine);}

		};
}
#endif
