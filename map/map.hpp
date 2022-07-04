#ifndef  MAP_HPP
# define MAP_HPP

#include "../utils/utils.hpp"
#include "../utils/allocator.hpp"
#include "../utils/iterator.hpp"

#define NOIR 0
#define ROUGE 1

#include <iostream>

namespace ft
{
	template < class Key, class T, class Compare = less<Key>, class Alloc = allocator< pair <const Key,T> > >
	class map
	{
	public:

		typedef Key														key_type;
		typedef T														mapped_type;
		typedef ft::pair<const Key, T>									value_type;
		typedef Compare													key_compare;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference		                reference;
        typedef typename allocator_type::const_reference	            const_reference;
        typedef typename allocator_type::pointer			            pointer;
        typedef typename allocator_type::const_pointer  	            const_pointer;
        typedef s_node_map<value_type>                          		*node_pointer;
		typedef ft::map_iterator<value_type, node_pointer>     			iterator;
		typedef ft::map_iterator<const value_type, node_pointer>     	const_iterator;
        typedef ft::reverse_iterator<iterator>		                    reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>	                const_reverse_iterator;
        typedef typename allocator_type::difference_type				difference_type;
        typedef size_t					                                size_type;


		class value_compare
		{
			friend class map;

			protected:
				Compare comp;
			value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};

	protected:

		key_compare					m_comp;
		allocator_type				m_alloc;
		node_pointer				m_root;
		node_pointer				m_feuille;
		size_t						m_size;
		
	public:

		// CONSTRUCTEUR
		
		explicit map (const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type()) : m_comp(comp), m_alloc(alloc), m_root(NULL), m_feuille(NULL), m_size(0)
		{
			m_feuille = new s_node_map<value_type>();
			m_feuille->data = m_alloc.allocate(1);
			m_alloc.construct(m_feuille->data, ft::make_pair(key_type(), mapped_type()));
			m_feuille->parent = m_feuille;
			m_feuille->gauche = m_feuille;
			m_feuille->droit = m_feuille;
			m_feuille->couleur = 0;
			m_root = m_feuille;
		}

		template <class InputIterator>
  		map (InputIterator first, InputIterator last,
    	const key_compare& comp = key_compare(),
       	const allocator_type& alloc = allocator_type(),
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		: m_comp(comp), m_alloc(alloc), m_root(NULL), m_feuille(NULL), m_size(0)
		{
			m_feuille = new s_node_map<value_type>();
			m_feuille->data = m_alloc.allocate(1);
			m_alloc.construct(m_feuille->data, value_type(0, 0));
			m_feuille->parent = m_feuille;
			m_feuille->gauche = m_feuille;
			m_feuille->droit = m_feuille;
			m_feuille->couleur = 0;
			m_root = m_feuille;

			this->insert(first, last);
		}

		// CONSTRUCTOR COPY

		map (const map& x) :  m_comp(x.m_comp), m_alloc(x.m_alloc), m_root(NULL), m_feuille(NULL), m_size(0)
		{
			m_feuille = new s_node_map<value_type>();
			m_feuille->data = m_alloc.allocate(1);
			m_alloc.construct(m_feuille->data, value_type(0, 0));
			m_feuille->parent = m_feuille;
			m_feuille->gauche = m_feuille;
			m_feuille->droit = m_feuille;
			m_feuille->couleur = 0;
			m_root = m_feuille;

			this->insert(x.begin(), x.end());
		}

		// DESTRUCTEUR

		~map()
		{
			clear();
			m_alloc.destroy(m_feuille->data);
			m_alloc.deallocate(m_feuille->data, sizeof(value_type));
			delete m_feuille;
		}

		// ASSIGNATION

		map & operator=(const map & x)
		{
			this->clear();
			m_feuille->parent = m_feuille;
			m_feuille->gauche = m_feuille;
			m_feuille->droit = m_feuille;
			m_root = m_feuille;
			m_size = 0;
			if (x.m_size > 0)
				this->insert(x.begin(), x.end());
			return *this;
		}

		// ITERATORS

		iterator begin()
		{
			if (m_root == m_feuille || !m_root)
				return (iterator(m_feuille, m_feuille));
			node_pointer	tmp = m_root;
			while (tmp->droit != m_feuille)
				tmp = tmp->droit;
			m_feuille->droit = tmp;
			m_feuille->gauche = tmp;

			tmp = m_root;
			while (tmp->gauche != m_feuille)
				tmp = tmp->gauche;
			tmp->gauche = m_feuille;
            m_feuille->parent = m_feuille;

			return (iterator(tmp, m_feuille));
		}

		const_iterator begin() const
		{
			if (m_root == m_feuille || !m_root)
				return (const_iterator(m_feuille, m_feuille));
			node_pointer	tmp = m_root;
			while (tmp->droit != m_feuille)
				tmp = tmp->droit;
			m_feuille->droit = tmp;
			m_feuille->gauche = tmp;

			tmp = m_root;
			while (tmp->gauche != m_feuille)
				tmp = tmp->gauche;
			tmp->gauche = m_feuille;
            m_feuille->parent = m_feuille;

			return const_iterator(tmp, m_feuille);
		}

		iterator end()
		{
			if (m_root == m_feuille || !m_root)
				return (iterator(m_feuille, m_feuille));
			node_pointer	tmp = m_root;
			
			while (tmp->droit != m_feuille)
				tmp = tmp->droit;
			tmp->droit = m_feuille;
			m_feuille->droit = tmp;
			m_feuille->gauche = tmp;
            m_feuille->parent = m_feuille;
			
			return iterator(m_feuille, m_feuille);
		}

		const_iterator end() const
		{
			if (m_root == m_feuille || !m_root)
				return (const_iterator(m_feuille, m_feuille));

			node_pointer	tmp = m_root;
			
			while (tmp->droit != m_feuille)
				tmp = tmp->droit;
			tmp->droit = m_feuille;
			m_feuille->droit = tmp;
			m_feuille->gauche = tmp;
            m_feuille->parent = m_feuille;
			
			return const_iterator(m_feuille, m_feuille);
		}

		reverse_iterator rbegin()
		{
			if (m_root == m_feuille)
				return (reverse_iterator(iterator(m_feuille, m_feuille)));
			node_pointer	tmp = m_root;

			end();
			tmp = m_root;
			while (tmp->gauche != m_feuille)
				tmp = tmp->gauche;
			tmp->gauche = m_feuille;
            m_feuille->gauche = tmp;
            m_feuille->parent = m_feuille->droit;
			return reverse_iterator(iterator(m_feuille, m_feuille));
		}

		const_reverse_iterator rbegin() const
		{
			return rbegin();
		}

		reverse_iterator rend()
		{
			if (m_root == m_feuille)
				return (reverse_iterator(iterator(m_feuille, m_feuille)));
			node_pointer	tmp = m_root;

			begin();
			tmp = m_root;
			while (tmp->gauche != m_feuille)
				tmp = tmp->gauche;
			tmp->gauche = m_feuille;
            m_feuille->gauche = tmp;
            m_feuille->parent = m_feuille->droit;
			return reverse_iterator(iterator(m_feuille->gauche, m_feuille));
		}

		const_reverse_iterator rend() const
		{
			return rend();
		}

		// CAPACITY

		bool empty() const
		{
			if (m_size == 0)
				return true;
			return false;
		}

		size_type size() const
		{
			return m_size;
		}

		size_type max_size() const
		{
			return m_alloc.max_size();
		}

		// ELEMENT ACCESS

		mapped_type& operator[](const key_type& k)
		{
			return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
		}

		// MODIFIERS

		iterator insert (iterator position, const value_type& val)
		{
			(void)position;
			return insert(val).first;
		}

		ft::pair<iterator,bool> insert(const value_type& val)
		{
			// Insertion d'un nouveau nœud dans l'arbre
			node_pointer n = new s_node_map<value_type>();
			n->data = m_alloc.allocate(1);
			m_alloc.construct(n->data, val);
			node_pointer ret;

			ret = insertion_recursif(m_root, n);
			if (ret != m_feuille && !m_comp(ret->data->first, n->data->first) && !m_comp(n->data->first, ret->data->first))
			{
				m_alloc.destroy(n->data);
				m_alloc.deallocate(n->data, sizeof(value_type));
				delete n;
				return (pair<iterator, bool>(iterator(ret, m_feuille), false));
			}
			// Réparation de l'arbre au cas où les propriétés rouge-noir seraient violées
			insertion_repare_arbre(n);

			// Recherche de la nouvelle m_root à renvoyer
			m_root = n;
			
			while (parent(m_root) != m_feuille)
				m_root = parent(m_root);
			++m_size;
			return ft::pair<iterator, bool>(iterator(n, m_feuille), true);
		}

		template <class InputIterator>
  		void insert (InputIterator first, InputIterator last,
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			while (first != last)
				insert(*first++);
		}

		void erase (iterator first, iterator last)
		{	
			while (first != last)
				erase(first++);
		}

		size_type erase (const key_type& k)
		{
			iterator ret = find(k);

			if (ret == this->end())
				return 0;
			erase(ret);

			return (1);
		}

		void erase (iterator position)
		{
			node_pointer z = position.m_node;
			node_pointer y, x;

			if (z == m_feuille)
				return;
			if(z->gauche == m_feuille || z->droit == m_feuille)
			{
				y = z;
			}
			else
				y = arbreSuccesseur(z);
			if(y->gauche != m_feuille)
				x = y->gauche;
			else
				x = y->droit;
			x->parent = y->parent;
			if(y->parent == m_feuille)
			{
				m_root = x;
			}
			else
			{
				if( y == y->parent->gauche)
					y->parent->gauche = x;
				else
					y->parent->droit = x;
			}
			if (y->couleur == NOIR)
				reOrganiserSuppression( x );
			if (z != y)
			{
				if (z->parent != m_feuille)
				{
					if (z->parent->gauche == z)
						z->parent->gauche = y;
					if (z->parent->droit == z)
						z->parent->droit = y;
				}
				if(z->droit != m_feuille)
					z->droit->parent = y;
				if (z->gauche != m_feuille)
					z->gauche->parent = y;
				node_pointer tmp;
				int	c = y->couleur;
				y->couleur = z->couleur;
				z->couleur = c;

				tmp = y->parent;
				y->parent = z->parent;
				z->parent = tmp;

				tmp = y->gauche;
				y->gauche = z->gauche;
				z->gauche = tmp;

				tmp = y->droit;
				y->droit = z->droit;
				z->droit = tmp;

				if (y && y != m_feuille)
					m_root = y;
				while (m_root && m_root != m_feuille && m_root && m_root->parent != m_feuille)
					m_root = m_root->parent;
			}
			m_alloc.destroy(z->data);
			m_alloc.deallocate(z->data, sizeof(value_type));
			delete z;
			--m_size;
		}

		void swap (map& x)
		{
			key_compare	tmpk = m_comp;
			m_comp = x.m_comp;
			x.m_comp = tmpk;

			allocator_type tmpa = m_alloc;
			m_alloc = x.m_alloc;
			x.m_alloc = tmpa;

			node_pointer	tmpn = m_root;
			m_root = x.m_root;
			x.m_root = tmpn;

			tmpn = m_feuille;
			m_feuille = x.m_feuille;
			x.m_feuille = tmpn;
			
			size_t tmps = m_size;
			m_size = x.m_size;
			x.m_size = tmps;
		}

		void clear()
		{
			node_pointer	tmp; 
			node_pointer	last = end().m_node;
			node_pointer 	first = begin().m_node;
			
			while (first != last)
			{				

				if (first->droit != m_feuille)
				{
					first = first->droit;
					while (first->gauche != m_feuille && first->droit != first->parent)
					{
						first = first->gauche;
					}
				}
				else
				{
					while (first->parent != m_feuille && first->parent->droit == first)
					{
						tmp = first;
						first = first->parent;
						m_alloc.destroy(tmp->data);
						m_alloc.deallocate(tmp->data, sizeof(value_type));
						delete tmp;
					}
					tmp = first;
					first = first->parent;
					m_alloc.destroy(tmp->data);
					m_alloc.deallocate(tmp->data, sizeof(value_type));
					delete tmp;
					if (!first)
						break;
				}
			}
			m_root = m_feuille;
			m_size = 0;
		}

		key_compare key_comp() const
		{
			return m_comp;
		}

		value_compare value_comp() const
		{
			return value_compare(m_comp);
		}
		
		iterator find (const key_type& k)
		{
			node_pointer	tmp = m_root;

			if (tmp == m_feuille)
				return end(); // Pas trouvé
			while (tmp != m_feuille)
			{
				if (m_comp(tmp->data->first, k))
					tmp = tmp->droit;
				else if (m_comp(k, tmp->data->first))
					tmp = tmp->gauche;
				else
					return iterator(tmp, m_feuille);
			}
			return end();
		}

		const_iterator find (const key_type& k) const
		{
			node_pointer	tmp = m_root;

			if (tmp == m_feuille)
				return end(); // Pas trouvé
			while (tmp != m_feuille)
			{
				if (m_comp(tmp->data->first, k))
					tmp = tmp->droit;
				else if (m_comp(k, tmp->data->first))
					tmp = tmp->gauche;
				else
					return const_iterator(tmp, m_feuille);
			}
			return end();
		}

		size_type count (const key_type& k) const
		{
			if (find(k).m_node == this->end().m_node)
				return 0;
			return 1;
		}

		iterator lower_bound (const key_type& k)
		{
			iterator it = begin();
			iterator it2 = end();
			if (m_size == 0)
				return iterator(m_feuille, m_feuille);
			while (it != it2 && m_comp(it->first, k))
				++it;
			return (it);
		}

		const_iterator lower_bound (const key_type& k) const
		{
			return lower_bound(k);
		}

		iterator upper_bound (const key_type& k)
		{
			iterator it = begin();
			iterator it2 = end();
			if (m_size == 0)
				return iterator(m_feuille, m_feuille);
			while (it != it2 && !m_comp(k, it->first))
				++it;
			return (it);
		}

		const_iterator upper_bound (const key_type& k) const
		{
			return this->upper_bound(k);
		}

		pair<iterator,iterator>             equal_range (const key_type& k)
		{
			return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
		}

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return this->equal_range(k);
		}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// OTHER FUNCTIONS

	private:

		node_pointer parent(node_pointer n)
		{
			return n->parent;
		}

		node_pointer grandparent(node_pointer n)
		{
			node_pointer p = parent(n);
			if (p == m_feuille)
				return m_feuille; // Un node_pointer sans parent n'a pas de grand-parent
			return parent(p);
		}

		node_pointer frere(node_pointer n)
		{
			node_pointer p = parent(n);
			if (p == m_feuille)
				return 0; // Un node_pointer sans parent n'a pas de frere
			if (n == p->gauche)
				return p->droit;
			else
				return p->gauche;
		}

		//Renvoie le frère du père
		node_pointer oncle(node_pointer enfant)
		{
			node_pointer p = parent(enfant);
			node_pointer g = grandparent(enfant);
			if (g == m_feuille)
				return m_feuille; // Pas de grand parent, donc pas d'oncle
			return frere(p);
		}

		void rotationGauche( node_pointer n)
		{
			node_pointer y = n->droit;
			n->droit = y->gauche;
			if(y->gauche != m_feuille)
				y->gauche->parent = n;// on ne change pas le parent de la sentinelle
			y->parent = n->parent;
			if (n->parent==m_feuille)
				m_root = y;
			else
				if( n->parent->gauche == n )
					n->parent->gauche = y;
				else
					n->parent->droit = y;
			y->gauche = n;
			n->parent = y;
		}
		void rotationDroite( node_pointer n)
		{
			node_pointer y = n->gauche;
			n->gauche = y->droit;
			if(y->droit != m_feuille)
				y->droit->parent = n; // on ne change pas le parent de la sentinelle
			y->parent = n->parent;
			if (n->parent==m_feuille)
				m_root = y;
			else
				if( n->parent->droit == n)
					n->parent->droit = y;
				else
					n->parent->gauche = y;
			y->droit = n;
			n->parent = y;
		}
			
		node_pointer arbreSuccesseur(node_pointer x)
		{
			// le node_pointer successseur de x dans l'arbre,
			// sentinelle si c'est le plus grand
			if(x->droit != m_feuille)
				return arbreMinimum(x->droit);
			node_pointer y = x->parent;
			while(y != m_feuille && x == y->droit)
			{ 
				x = y;
				y = x->parent;
			}
			return y;
		}

		node_pointer arbreMinimum(node_pointer x)
		{
			while(x->gauche != m_feuille)
				x = x->gauche;
			return x;
		}

		void reOrganiserSuppression( node_pointer n)
		{
			// re organisation de l'arbre, en remontant vers la m_root
			while(n != m_root && n->couleur == NOIR )
			{
				if(n == n->parent->gauche)
				{
					node_pointer y = n->parent->droit;
					if(y->couleur == ROUGE )
					{
						y->couleur = NOIR;
						n->parent->couleur = ROUGE;
						rotationGauche(n->parent);
						y = n->parent->droit;
					}
					if(y->gauche->couleur == NOIR && y->droit->couleur == NOIR)
					{
						y->couleur = ROUGE;
						n = n->parent;
					}
					else
					{
						if( y->droit->couleur == NOIR)
						{
							y->gauche->couleur = NOIR;
							y->couleur = ROUGE;
							rotationDroite(y);
							y = n->parent->droit;
						}
						y->couleur = n->parent->couleur;
						n->parent->couleur = NOIR;
						y->droit->couleur = NOIR;
						rotationGauche (n->parent);
						break;
					}
				}
				else
				{
					node_pointer y = n->parent->gauche;
					if( y->couleur == ROUGE )
					{
						y->couleur = NOIR;
						n->parent->couleur = ROUGE;
						rotationDroite(n->parent);
						y = n->parent->gauche;
					}

					if(y->droit->couleur == NOIR && y->gauche->couleur == NOIR)
					{
						y->couleur = ROUGE;
						n = n->parent;
					}
					else
					{
						if( y->gauche->couleur == NOIR)
						{
							y->droit->couleur = NOIR;
							y->couleur = ROUGE;
							rotationGauche (y);
							y = n->parent->gauche;
						}
						y->couleur = n->parent->couleur;
						n->parent->couleur = NOIR;
						y->gauche->couleur = NOIR;
						rotationDroite(n->parent);
						break;
					}
				}
			}
			n->couleur = NOIR;
		}

		node_pointer		insertion_recursif(node_pointer root, node_pointer n)
		{
			// Descente récursive dans l'arbre jusqu'à atteindre une m_feuille
			if (root != m_feuille && m_comp(n->data->first, root->data->first))
			{
				if (root->gauche != m_feuille)
				{
					return insertion_recursif(root->gauche, n);
				}
				else
					root->gauche = n;
			} 
			else if (root != m_feuille && m_comp(root->data->first, n->data->first))
			{
				if (root->droit != m_feuille)
				{
					return insertion_recursif(root->droit, n);
				}
				else
					root->droit = n;
			}
			// Insertion du nouveau node_pointer n
			n->parent = root;
			n->gauche = m_feuille; // NIL
			n->droit = m_feuille; // NIL
			n->couleur = ROUGE;
			return root;
		}

		void insertion_repare_arbre(node_pointer n)
		{
			if (parent(n) == m_feuille)
			{
				insertion_cas1(n);
			}
			else if (parent(n)->couleur == NOIR)
			{
				insertion_cas2();
			}
			else if (oncle(n) && oncle(n)->couleur == ROUGE)
			{
				insertion_cas3(n);
			}
			else
			{
				insertion_cas4(n);
			}
		}

		void insertion_cas1(node_pointer n)
		{
			if (parent(n) == m_feuille)
				n->couleur = NOIR;
		}

		void insertion_cas2()
		{
			return; /* Ne rien faire puisque l'arbre est bien un arbre rouge-noir */
		}

		void insertion_cas3(node_pointer n)
		{
			parent(n)->couleur = NOIR;
			oncle(n)->couleur = NOIR;
		
			node_pointer g = grandparent(n);
			g->couleur = ROUGE;
			insertion_repare_arbre(g);
		}

		void insertion_cas4(node_pointer n)
		{
			node_pointer p = parent(n);
			node_pointer g = grandparent(n);

			if (g->gauche && n == g->gauche->droit) {
				rotationGauche(p);
				n = n->gauche;
			}
			else if (g->droit && n == g->droit->gauche)
			{
				rotationDroite(p);
				n = n->droit; 
			}
			insertion_cas5(n);
		}

		void insertion_cas5(node_pointer n)
		{
			node_pointer p = parent(n);
			node_pointer g = grandparent(n);

			if (n == p->gauche)
				rotationDroite(g);
			else
				rotationGauche(g);
			
			p->couleur = NOIR;
			g->couleur = ROUGE;
		}

	};//map

}//ft

#endif