#ifndef NODE_HPP
# define NODE_HPP

namespace ft
{
   // typedef struct node s_node;

    template < class T> 
    struct s_node
    {
        public:
            s_node      *next;
            s_node      *prev;

        protected:
          template < class U, class Alloc > friend class list;
            template<class T3, class Pt> friend class list_iterator;
            T           *data;
    };

    template < class T> 
	struct s_node_map
	{
		public:
			struct s_node_map *gauche; //Pointeur vers fils gauche
			struct s_node_map *droit; //Pointeur vers fils droit 
			struct s_node_map *parent; //Pointeur vers père
			int couleur; // ROUGE ou NOIR
		protected:
	    template < class Key, class T2, class Compare, class Alloc > friend class map;
        template<class T3, class Pt> friend class map_iterator;
			T               *data;

	};

    template <class T>
    struct less
    {
        typedef T       first_argument_type;
        typedef T       second_argument_type;
        typedef bool    result_type;

        bool operator() (const T& x, const T& y) const
        {
            return x < y;
        }
    };

    template <class T1, class T2> struct pair
    {
    
        typedef T1      first_type;
        typedef T2      second_type;

        first_type      first;
        second_type     second;

        //CONSTRUCTEUR

        pair() : first(), second()
        {
        }

        pair (const first_type& a, const second_type& b) : first(a), second(b)
        {
        }

        //CONSTRUCTEUR DE COPY

        template<class U, class V> pair (const pair<U,V>& pr) : first(pr.first), second(pr.second)
        {
        }

        //ASSIGNATION

        pair& operator= (const pair& pr)
        {
            first = pr.first;
            second = pr.second;
            return *this;
        }

        //SWAP
        void    swap(pair<T1, T2>& x)
        {
            pair<T1, T2> tmp;
            tmp = first; 
            first = x.first;
            x.first = tmp;

            tmp = second; 
            second = x.second;
            x.second = tmp;
        }

    };

    template <class T1, class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return ( ft::pair<T1,T2>(x,y) );
    };

    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return lhs.first==rhs.first && lhs.second==rhs.second;
    }

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(lhs==rhs);
    }

    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
    }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(rhs<lhs);
    }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return rhs<lhs; }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(lhs<rhs);
    }

}

#endif