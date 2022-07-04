#ifndef LIST_HPP
# define LIST_HPP

#include "../utils/iterator.hpp"
#ifndef NULL
# define NULL 0
#endif

namespace ft
{
    template < class T, class Alloc = ft::allocator<T> > 
    class list
    {
        public:

            typedef T					                                        value_type;
            typedef Alloc					                                    allocator_type;
            typedef typename allocator_type::reference		                    reference;
            typedef typename allocator_type::const_reference	                const_reference;
            typedef typename allocator_type::pointer			                pointer;
            typedef typename allocator_type::const_pointer  	                const_pointer;
            typedef s_node<T>                                                    *node_pointer;
            typedef ft::list_iterator<T, node_pointer>                           iterator;
            typedef ft::list_iterator<const T, node_pointer>                     const_iterator;
            typedef ft::reverse_iterator<iterator>		                        reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>	                    const_reverse_iterator;
            typedef typename allocator_type::difference_type					difference_type;
            typedef size_t                                                      size_type;
            

        protected:
            node_pointer        m_node;
            allocator_type      m_alloc;
            size_t              m_size;

           void     init_node()
           {
               if (!m_node)
               {
                    m_node = new s_node<value_type>;
                    m_node->data = m_alloc.allocate(1);
               }
                m_node->prev = m_node;
                m_node->next = m_node;
           }

        public:

        //CONSTRUCTEUR

        explicit list (const allocator_type& alloc = allocator_type()) : m_node(), m_alloc(alloc), m_size(0)
        {
            init_node();
        }

        explicit list (size_type n, const value_type& val = value_type(),
        const allocator_type& alloc = allocator_type()) : m_node(), m_alloc(alloc), m_size(0)
        {
            init_node();
            insert(m_node, n, val);
        }

        template <class InputIterator>
        list (InputIterator first, InputIterator last,
        const allocator_type& alloc = allocator_type(),
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
         : m_node(), m_alloc(alloc), m_size(0)
        {
            init_node();
            insert(m_node, first, last);
        }
             
        // CONSTRUCTEUR DE COPY

        list (const list& li) : m_node(), m_alloc(li.m_alloc), m_size(0)
        {
            init_node();
            insert(m_node, li.begin(), li.end());
        }

        // DESTRUCTEUR

        ~list()
        {
            clear();
            m_alloc.deallocate(m_node->data, sizeof(value_type));
            delete m_node;
        }

        //ASSIGNATION
         list& operator= (const list& x)
         {
            clear();
            insert(m_node, x.begin(), x.end());
            return *this;
         }

    // FONCTIONS MEMBRE

        //ITERATOR

        iterator begin()
        {
            return m_node->next;
        }

        const_iterator begin() const
        {
            return m_node->next;
        }

        iterator end()
        {
            return m_node;
        }

        const_iterator end() const
        {
            return  m_node;
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(end());
        }

        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(begin());
        }

        //CAPACITY

        bool empty() const
        {
            return m_size == 0;
        }

        size_type size() const
        {
            return m_size;
        }

        size_type max_size() const
        {
            return m_alloc.max_size();
        }

        //ELEMENT ACCESS

        reference front()
        {
            return *m_node->next->data;
        }

        const_reference front() const
        {
            return *m_node->next->data;
        }

        reference back()
        {
            return *m_node->prev->data;
        }

        const_reference back() const
        {
            return *m_node->prev->data;
        }

        //MODIFIERS

        void assign (size_type n, const value_type& val)
        {
            clear();
            while (n-- > 0)
                push_back(val);
        }

        template <class InputIterator>
        void assign (InputIterator first, InputIterator last,
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
        {
            clear();
            while (first != last)
            {
                push_back(*first);
                first++;
            }
        }

        void push_front (const value_type& val)
        {
            node_pointer    tmp;
            tmp = new s_node<value_type>;
            tmp->data = m_alloc.allocate(1);
            m_alloc.construct(tmp->data, val);

            if (m_size == 0)
            {
                tmp->next = m_node;
                tmp->prev = m_node;
                m_node->next = tmp;
                m_node->prev = tmp;
            }
            else
            {
                tmp->next = m_node->next;
                tmp->prev = m_node;
                m_node->next->prev = tmp;
                m_node->next = tmp;
            }
            
            ++m_size;
        }

        void pop_front()
        {
            node_pointer tmp = m_node->next;
            m_node->next = m_node->next->next;
            m_node->next->prev = m_node;
            m_alloc.destroy(tmp->data);
            m_alloc.deallocate(tmp->data, sizeof(value_type));            
            delete tmp;
            --m_size;
        }

        void push_back (const value_type& val)
        {
            node_pointer    tmp;
            tmp = new s_node<value_type>;
            tmp->data = m_alloc.allocate(1);
            m_alloc.construct(tmp->data, val);

            if (m_size == 0)
            {
                m_node->prev = tmp;
                m_node->next = tmp;
                tmp->next = m_node;
                tmp->prev = m_node;
            }
            else
            {
                tmp->next = m_node;
                tmp->prev = m_node->prev;
                m_node->prev->next = tmp;
                m_node->prev = tmp;
            }
            ++m_size;
        }

        void pop_back()
        {
            node_pointer tmp = m_node->prev;
            m_node->prev = m_node->prev->prev;
            m_node->prev->next = m_node;

            m_alloc.destroy(tmp->data);
            m_alloc.deallocate(tmp->data, sizeof(value_type));            
            delete tmp;
            --m_size;
        }
	
        iterator insert (iterator position, const value_type& val)
        {
            node_pointer    tmp;
            tmp = new s_node<value_type>;
            tmp->data = m_alloc.allocate(1);
            m_alloc.construct(tmp->data, val);

            tmp->next = position.m_node;
            tmp->prev = position.m_node->prev;
            tmp->prev->next = tmp;
            tmp->next->prev = tmp;
            ++m_size;
            return tmp;
        }

        void insert (iterator position, size_type n, const value_type& val)
        {
            while (n-- > 0)
            {
                position = insert(position, val);
            }
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last,
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
        {
            while (first != last)
            {
                insert(position, *first);
                first++;
            }
        }


        iterator erase (iterator position)
        {
            iterator    ret(position.m_node->next);
            position.m_node->next->prev = position.m_node->prev;
            position.m_node->prev->next = position.m_node->next;
            m_alloc.destroy(position.m_node->data);
            m_alloc.deallocate(position.m_node->data, sizeof(value_type));
            delete position.m_node;
            --m_size;
            return ret;
        }

        iterator erase (iterator first, iterator last)
        {
            while (first != last)
                erase(first++);
            return last;
        }


        void swap (list& x)
        {
            node_pointer    tmp = x.m_node;
            x.m_node = m_node;
            m_node = tmp;
            size_t  size_tmp = x.m_size;
            x.m_size = m_size;
            m_size = size_tmp;
        }

        void resize (size_type n, value_type val = value_type())
        {
            if (n > 0)
            {
                if (n > m_size)
                {
                    while (m_size < n)
                        push_back(val);
                }
                else if (n < m_size)
                {
                    node_pointer    tmp = m_node->next;
                    while (n-- > 0)
                        tmp = tmp->next;
                    erase(tmp, m_node);
                }                
            }
            else
                clear();
        }

        void clear()
        {
            erase(iterator(m_node->next), iterator(m_node));
            init_node();
            m_size = 0;
        }

        //OPERATIONS

        void splice (iterator position, list& x)
        {
            position.m_node->prev->next = x.begin().m_node;
            x.begin().m_node->prev = position.m_node->prev;
            position.m_node->prev = x.end().m_node->prev;
            x.end().m_node->prev->next = position.m_node;
            m_size += x.m_size;
            x.m_size = 0;
            x.init_node();
        }

        void splice (iterator position, list& x, iterator i)
        {
            i.m_node->prev->next = i.m_node->next;
            i.m_node->next->prev = i.m_node->prev;

            i.m_node->prev = position.m_node->prev;
            i.m_node->next = position.m_node;
            position.m_node->prev->next = i.m_node;
            position.m_node->prev = i.m_node;
            ++m_size;
            --x.m_size;
        }

        void splice (iterator position, list& x, iterator first, iterator last)
        {
            while (first != last)
                splice (position, x, first++);
        }

        void remove (const value_type& val)
        {
            node_pointer    first = m_node->next;
            while (first != m_node)
            {
                node_pointer    tmp = first->next;
                if (*first->data == val)
                    erase(first);
                first = tmp;
            }
        }

        template <class Predicate>
        void remove_if (Predicate pred)
        {
            node_pointer    first = m_node->next;
            while (first != m_node)
            {
                node_pointer    tmp = first->next;
                if (pred(*first->data))
                    erase(first);
                first = tmp;
            }
        }

        void unique ()
        {
            node_pointer    first = m_node->next->next;
            while (first != m_node)
            {
                node_pointer    tmp = first->next;
                if (*first->data == *first->prev->data)
                    erase(first);
                first = tmp;
            }
        }

        template <class BinaryPredicate>
        void unique (BinaryPredicate binary_pred)
        {
            node_pointer    first = m_node->next->next;
            while (first != m_node)
            {
                node_pointer    tmp = first->next;
                if (binary_pred(*first->data, *first->prev->data))
                    erase(first);
                first = tmp;
            }   
        }

        void merge (list& x)
        {
            node_pointer    first = m_node->next;   
            node_pointer    last = m_node;   
            node_pointer    xfirst = x.m_node->next;
            node_pointer    xlast = x.m_node;

            while (xfirst != xlast)
            {
                if (first == last || *xfirst->data < *first->data)
                {
                    node_pointer    tmp = xfirst->next;
                    xfirst->prev->next = tmp;
                    xfirst->next->prev = xfirst->prev;

                    xfirst->prev = first->prev;
                    xfirst->next = first;
                    first->prev->next = xfirst;
                    first->prev = xfirst;
                    xfirst = tmp;
                    ++m_size;
                }
                else if (first != last)
                    first = first->next;
            }

        }

        template <class Compare>
        void merge (list& x, Compare comp)
        {
            node_pointer    first = m_node->next;   
            node_pointer    last = m_node;   
            node_pointer    xfirst = x.m_node->next;
            node_pointer    xlast = x.m_node;

            while (xfirst != xlast)
            {
                if (first == last || comp(*xfirst->data, *first->data))
                {
                    node_pointer    tmp = xfirst->next;
                    xfirst->prev->next = tmp;
                    xfirst->next->prev = xfirst->prev;

                    xfirst->prev = first->prev;
                    xfirst->next = first;
                    first->prev->next = xfirst;
                    first->prev = xfirst;
                    xfirst = tmp;
                    ++m_size;
                
                }
                else if (first != last)
                    first = first->next;
            }
        }
    
         void sort()
        {
            // Tri de la liste par ordre croissant du champ nombre
            int recommencer;
            do {
                // commence au début de la liste
                node_pointer    precedent = m_node;
                node_pointer    element = precedent->next;
                node_pointer    suivant = element->next;
                recommencer = 0;
                while( suivant != m_node)
                {
                    if( *suivant->data < *element->data)
                    {
                        // si le classement de l'élément et de son suivant est incorrect :

                        // la liste devra être re-parcourue
                        recommencer = 1;

                        // inverse l'élément courant et son suivant
                        //if( precedent == m_node )
                        //  premier = suivant;

                        precedent->next = suivant;
                        suivant->prev = precedent;
                        element->next = suivant->next;
                        suivant->next->prev = element;
                        suivant->next = element;
                        element->prev = suivant;

                        precedent = suivant;
                        suivant = element->next;
                    } 
                    else
                    {
                        precedent = element;      // nouveau précédent = ancien élément
                        element = element->next; // nouvel élément = ancien suivant
                        suivant = element->next; // nouveau suivant = suivant du nouvel élémen
                    }
                }
            } while( recommencer );
        }

        template <class Compare>
        void sort (Compare comp)
        {
            // Tri de la liste par ordre croissant du champ nombre
            int recommencer;
            do {
                // commence au début de la liste
                node_pointer    precedent = m_node;
                node_pointer    element = precedent->next;
                node_pointer    suivant = element->next;
                recommencer = 0;
                while( suivant != m_node)
                {
                    if(comp(*suivant->data, *element->data))
                    {
                        // si le classement de l'élément et de son suivant est incorrect :

                        // la liste devra être re-parcourue
                        recommencer = 1;

                        // inverse l'élément courant et son suivant
                        //if( precedent == m_node )
                          //  premier = suivant;

                        precedent->next = suivant;
                        suivant->prev = precedent;
                        element->next = suivant->next;
                        suivant->next->prev = element;
                        suivant->next = element;
                        element->prev = suivant;

                        precedent = suivant;
                        suivant = element->next;
                    } 
                    else
                    {
                        precedent = element;      // nouveau précédent = ancien élément
                        element = element->next; // nouvel élément = ancien suivant
                        suivant = element->next; // nouveau suivant = suivant du nouvel élémen
                    }
                }
            } while( recommencer );
        }

        void reverse()
        {
            node_pointer    start = m_node->next;
            node_pointer    end = m_node->prev;
            size_t  half  = m_size / 2;
            node_pointer    prev;
            node_pointer    next;
            node_pointer    tmp;
            
            for (size_t i = 0; i < half; ++i)
            {
                
                tmp = end;
                prev = end->prev;
                next = end->next;

                start->prev->next = end;
                start->next->prev = end;
                end->next->prev = start;
                end->prev->next = start;
                end->prev = start->prev;
                end->next = start->next;
                start->prev = prev;
                start->next = next;


                end = start;
                start = tmp;

                start = start->next;
                end = end->prev;
            }
        }

    };

    //NON-MEMBER FUNCTION OVERLOAD

    template <class T, class Alloc>
    bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        if (&lhs == &rhs)
            return (true);
        if (lhs.size() == rhs.size())
        {
            typename ft::list<T>::const_iterator lit = lhs.begin();
            typename ft::list<T>::const_iterator rit = rhs.begin();
            while (lit != lhs.end() && rit != rhs.end())
            {
                if (*lit != *rit)
                  return (false);
                ++lit;
                ++rit;
            }
            return true;
        }
        return(false);
    }

    template <class T, class Alloc>
    bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        if (&lhs == &rhs || lhs.size() > rhs.size())
            return (false);
        
        if (lhs.size() == rhs.size())
        {
            typename ft::list<T>::const_iterator lit = lhs.begin();
            typename ft::list<T>::const_iterator rit = rhs.begin();
            while (lit != lhs.end() && rit != rhs.end())
            {
                if (*lit < *rit)
                  return (true);
                if (*lit > *rit)
                  return (false);
                ++lit;
                ++rit;
            }
            return false;
        }
        return(true);
    }

    template <class T, class Alloc>
    bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return !(rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return rhs < lhs;
    }

    template <class T, class Alloc>
    bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return !(lhs < rhs);
    }

    template <class T, class Alloc>
    void swap (list<T,Alloc>& x, list<T,Alloc>& y)
    {
        x.swap(y);
    }

}

#endif