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

//https://cours.etsmtl.ca/SEG/FHenri/inf145/Suppl%C3%A9ments/arbres%20binaires.htm

namespace ft
{



	// NOTE destruction of node is handled by the tree
	template <typename T>
		class node
		{
			T data;
			node *parent;
			node *left;
			node *right;

			// NOTE Constructor
			node () : data(0), left(NULL), right(NULL){};
		};

	template <typename Key, typename T>
		class tree
		{
			private :
				node<T> * root;
				node<T> * current;
				size_t    nb_nodes;

				// NOTE Disables copy - why?
				tree(const tree &);
				tree & operator = (const tree &);

			public :

				/* ---------------------- CONSTRUCTORS ---------------------- */
				tree (void) : root(NULL), current(NULL), nb_nodes(0) {};
				~tree(void) {};

				/* ------------------------- ADDERS ------------------------- */
				int add_left  (const T &); // TODO
				int add_right (const T &); // TODO

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

       inline void prefix(void (*f) (T &))
       { parcours_prefixe(racine, f);}

       inline void infix(void (*f) (T &))
       { parcours_infixe(racine, f);}

       inline void suffix(void (*f) (T &))
       { parcours_suffixe(racine, f);}

       // METHODES DE CONSULTATION

       // Offre de parcours en consultation.

       inline void prefix(void (*f) (const T &)) const
       { parcours_prefixe(racine, f);}

       inline void infix(void (*f) (const T &)) const
       { parcours_infixe(racine, f);}

       inline void suffix(void (*f) (const T &)) const
       { parcours_suffixe(racine, f);}


       inline int count_leaves() const     // Nombre de feuilles.
       { return compter_feuilles_arbre(racine);}

       inline int depth() const  // Profondeur de l'arbre.
       { return profondeur_arbre(racine);}

		};
}
#endif
