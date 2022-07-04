#ifndef ITERATOR_H
#define ITERATOR_H

#include "../utils/utils.hpp"
#include "../utils/allocator.hpp"

namespace ft
{
     ///  Marking input iterators.
    struct input_iterator_tag { };

    ///  Marking output iterators.
    struct output_iterator_tag { };

    /// Forward iterators support a superset of input iterator operations.
    struct forward_iterator_tag : public input_iterator_tag { };

    /// Bidirectional iterators support a superset of forward iterator
    /// operations.
    struct bidirectional_iterator_tag : public forward_iterator_tag { };

    /// Random-access iterators support a superset of bidirectional
    /// iterator operations.
    struct random_access_iterator_tag : public bidirectional_iterator_tag { };

    template <class T>
	class random_acces_iterator
	{		
    public:
        typedef T   					                        value_type;
        typedef T*   					                        pointer;
        typedef T&   					                        reference;
        typedef ft::random_access_iterator_tag                  iterator_category;
        typedef ptrdiff_t          	                            difference_type;

		protected:
            template <class U> friend class random_acces_iterator;
			pointer	 ptr;
		
		public:
		//CONSTRUCTEURS
			random_acces_iterator() : ptr()
			{
			}
			random_acces_iterator(pointer const p) : ptr(p)
			{
			}
		//CONSTRUCTEURS PAR COPIE
            template <class R>
			random_acces_iterator(random_acces_iterator<R> const & cop) : ptr(cop.ptr)
			{
			}

///////////////////////////////////////////////////

		//OPERATEUR MATHEMATIQUE

  	// Forward iterator requirements
		reference 	operator*() const
		{
			return *ptr;
		}

		pointer		operator->() const
		{
			return ptr;
		}

		random_acces_iterator&	operator++()
		{
			++ptr;
			return *this;
		}

		random_acces_iterator	operator++(int)
		{
			return random_acces_iterator(ptr++);
		}

		// Bidirectional iterator requirements
		random_acces_iterator&	operator--()
		{
			--ptr;
			return *this;
		}

		random_acces_iterator	operator--(int)
		{
			return random_acces_iterator(ptr--);
		}

		// Random access iterator requirements
		reference	operator[](const int n) const
		{
			return ptr[n];
		}

		random_acces_iterator&	operator+=(const int n)
		{
			ptr += n;
			return *this;
		}

		random_acces_iterator	operator+(const int n) const
		{
			return random_acces_iterator(ptr + n);
		}

		random_acces_iterator&	operator-=(const int n)
		{
			ptr -= n;
			return *this;
		}

		difference_type		operator-(const random_acces_iterator x) const
		{
			return ptr - x.ptr;
		}

        random_acces_iterator		operator-(difference_type n) const
		{
            random_acces_iterator ret(*this);
            ret -= n;
			return ret;
		}

		const pointer	base() const
		{
			return ptr;
		}

//////////////////////////////////////////////////////

		
	//OPRATEUR DE COMPARAISON
	
		friend bool		operator!= (const ft::random_acces_iterator<value_type> &lhs, const ft::random_acces_iterator<value_type> &rhs)
		{
			return !(lhs == rhs);
		}
		friend bool operator==(const ft::random_acces_iterator<value_type> &lhs, const ft::random_acces_iterator<value_type> &rhs)
		{
			return lhs.base() == rhs.base();
		}
		friend bool operator<(const ft::random_acces_iterator<value_type> &lhs, const ft::random_acces_iterator<value_type> &rhs)
		{
			return lhs.base() < rhs.base();
		}
		friend bool operator<=(const ft::random_acces_iterator<value_type> &lhs, const ft::random_acces_iterator<value_type> &rhs)
		{
			return !(rhs < lhs);
		}
		friend bool operator>(const ft::random_acces_iterator<value_type> &lhs, const ft::random_acces_iterator<value_type> &rhs)
		{
			return lhs.base() > rhs.base();
		}
		friend bool operator>=(const ft::random_acces_iterator<value_type> &lhs, const ft::random_acces_iterator<value_type> &rhs)
		{
			return !(lhs < rhs);
		}

	};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


    template<class T, class Pt>
    class list_iterator
    {
    public:
        typedef T   					                        value_type;
        typedef T*   					                        pointer;
        typedef T&   					                        reference;
        typedef Pt                                              pointer_node;
        typedef ft::bidirectional_iterator_tag                  iterator_category;
        typedef ptrdiff_t          	                            difference_type;

        pointer_node    m_node;

    
    // CONSTRUCTEUR

        list_iterator() : m_node()
        {
        }

        list_iterator(pointer_node node) : m_node(node)
        {
        }

    // CONSTRUCTEUR DE COPY

        list_iterator(list_iterator const & copy)
        {
            m_node = copy.m_node;
        }

///////////////////////////////////////////////////

	//OPERATEUR MATHEMATIQUE

        // Forward iterator requirements
        reference   operator*()
        {
            return *m_node->data;
        }

        pointer     operator->() const
        {
            return m_node->data;
        }

        list_iterator&  operator++()
        {
            m_node = m_node->next;
            return *this;
        }

        list_iterator   operator++(int)
        {
            list_iterator ret = *this;
            ++(*this);
            return ret;
        }

        //Bidirectional iterator requirements
        list_iterator&  operator--()
        {
            m_node = m_node->prev;
            return *this;
        }

        list_iterator   operator--(int)
        {
            list_iterator ret = *this;
            m_node = m_node->prev;
            return ret;
        }

        bool		operator==(const list_iterator &x) const
		{
			return m_node == x.m_node;
		}

        bool		operator!=(const list_iterator &x) const
		{
			return m_node != x.m_node;
		}

    };


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

template<class T, class Pt>
    class map_iterator
    {
    public:
        typedef T   					                        value_type;
        typedef T*   					                        pointer;
        typedef T&   					                        reference;
        typedef Pt                                              pointer_node;
        typedef ft::bidirectional_iterator_tag                  iterator_category;
        typedef ptrdiff_t          	                            difference_type;

        pointer_node    m_node;

    protected:
        pointer_node    m_feuille;
        pointer_node    m_gauche;
        pointer_node    m_droit;
        pointer_node    m_parent;
        
    public:
    // CONSTRUCTEUR

        map_iterator()
        {
        }

        map_iterator(pointer_node node, pointer_node feuille)
        : m_node(node), m_feuille(feuille), m_gauche(feuille->gauche),
        m_droit(feuille->droit), m_parent(feuille->parent)
        {
        }

    // CONSTRUCTEUR DE COPY

        map_iterator(map_iterator const & copy)
        {
            m_node = copy.m_node;
            m_feuille = copy.m_feuille;
            m_droit = copy.m_droit;
            m_gauche = copy.m_gauche;
            m_parent = copy.m_parent;
        }

///////////////////////////////////////////////////

	//OPERATEUR MATHEMATIQUE

        // Forward iterator requirements
        reference   operator*()
        {
            return *m_node->data;
        }

        pointer     operator->() const
        {
            return m_node->data;
        }

        map_iterator&  operator++()
        {
            m_feuille->parent = m_parent;
            m_feuille->gauche = m_gauche;
            m_feuille->droit = m_droit;
            if (m_node == m_feuille)
            {
                m_node = m_gauche;

            }
            else if (m_node->droit != m_feuille)
            {
                m_node = m_node->droit;
                while (m_node->gauche != m_feuille && m_node->droit != m_node->parent)
                {
                    m_node = m_node->gauche;
                }
            }
            else
            {
                while (m_node->parent != m_feuille &&
                m_node->parent->droit == m_node && m_node != m_parent)
                    m_node = m_node->parent;
                m_node = m_node->parent;
            }
            return *this;
        }

        map_iterator   operator++(int)
        {
            map_iterator ret = *this;
            ++(*this);
            return ret;
        }

        //Bidirectional iterator requirements
        map_iterator&  operator--()
        {
            m_feuille->parent = m_parent;
            m_feuille->gauche = m_gauche;
            m_feuille->droit = m_droit;
            if (m_node == m_feuille)
            {
                m_node = m_droit;

            }
            else if (m_node->gauche != m_feuille)
            {
                m_node = m_node->gauche;
                while (m_node != m_feuille && m_node->droit != m_feuille && m_node != m_node->droit->droit)
                {
                    m_node = m_node->droit;
                }
            }
            else
            {
                while (m_node != m_feuille && m_node->parent != m_feuille && m_node->parent->gauche == m_node)
                    m_node = m_node->parent;
                m_node = m_node->parent;
            }
            return *this;
        }

        map_iterator   operator--(int)
        {
            map_iterator ret = *this;
            --(*this);
            return ret;
        }

        bool operator==(const map_iterator &x) const
        {
            return m_node == x.m_node;
        }

        bool operator!=(const map_iterator &x) const
        {
            return m_node != x.m_node;
        }

    };


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


    template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator    iterator_type;
		typedef typename    iterator_type::iterator_category iterator_category;
		typedef typename    iterator_type::value_type value_type;
		typedef typename    iterator_type::difference_type difference_type;
		typedef typename    iterator_type::pointer pointer;
		typedef typename    iterator_type::reference reference;

	private:
		iterator_type m_it;

	public:
		reverse_iterator() {}

		explicit reverse_iterator(iterator_type it) : m_it(--it)
        {
        }

		template<class IteratorType>
		reverse_iterator(const reverse_iterator<IteratorType> &rev) : m_it(rev.base())
        {
        }

		bool operator==(const reverse_iterator &x) const
		{
			return m_it == x.m_it;
		}

		bool operator!=(const reverse_iterator &x) const
		{
			return m_it != x.m_it;
		}

		iterator_type base() const
		{
			return m_it;
		}

		reference operator*()
		{
			return m_it.operator*();
		}

		pointer operator->()
		{
			return &(operator*());
		}

		reverse_iterator &operator++()
		{
			--m_it;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			m_it--;
			return *this;
		}

		reverse_iterator &operator--()
		{
			++m_it;
			return *this;
		}

		reverse_iterator operator--(int)
		{
			m_it++;
			return *this;
		}

		reverse_iterator operator+(difference_type n) const
		{
			return reverse_iterator(m_it - n);
		}

		reverse_iterator &operator+=(difference_type n)
		{
			m_it -= n;
			return *this;
		}

		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(m_it + n);
		}

		reverse_iterator &operator-=(difference_type n)
		{
			m_it += n;
			return *this;
		}

		reference operator[](difference_type n) const
		{
			return *(*this + n);
		}
	};


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
    
    template <bool Cond, class  T = void>
    struct  enable_if
    {
    };
    
    template <class  T>
    struct  enable_if <true ,T>
    {
        typedef T type;
    };

    template <bool cond, typename T>
    struct is_integral_stock
    {
        typedef T type;
        static const bool value = cond;
    };

    template <typename>
        struct is_integral_type : public is_integral_stock<false, bool> {};

    template <>
        struct is_integral_type<bool> : public is_integral_stock<true, bool> {};

    template <>
        struct is_integral_type<char> : public is_integral_stock<true, char> {};

    template <>
        struct is_integral_type<signed char> : public is_integral_stock<true, signed char> {};

    template <>
        struct is_integral_type<short int> : public is_integral_stock<true, short int> {};
    
    template <>
        struct is_integral_type<int> : public is_integral_stock<true, int> {};

    template <>
        struct is_integral_type<long int> : public is_integral_stock<true, long int> {};

    template <>
        struct is_integral_type<long long int> : public is_integral_stock<true, long long int> {};

    template <>
        struct is_integral_type<unsigned char> : public is_integral_stock<true, unsigned char> {};

    template <>
        struct is_integral_type<unsigned short int> : public is_integral_stock<true, unsigned short int> {};

    template <>
        struct is_integral_type<unsigned int> : public is_integral_stock<true, unsigned int> {};

    template <>
        struct is_integral_type<unsigned long int> : public is_integral_stock<true, unsigned long int> {};
    
    template <>
        struct is_integral_type<unsigned long long int> : public is_integral_stock<true, unsigned long long int> {};

    template <typename T>
    struct is_integral : public is_integral_type<T>
    {
    };
    
} // namespace

#endif
