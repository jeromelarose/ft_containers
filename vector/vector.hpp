#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../utils/iterator.hpp"
#include "../utils/allocator.hpp"
#include <iostream>

namespace ft
{
    template < class T, class Alloc = ft::allocator<T> >
    class vector
    {
    public:
        typedef T					                                        value_type;
        typedef Alloc					                                    allocator_type;
        typedef typename allocator_type::reference		                    reference;
        typedef typename allocator_type::const_reference	                const_reference;
        typedef typename allocator_type::pointer			                pointer;
        typedef typename allocator_type::const_pointer  	                const_pointer;
        typedef ft::random_acces_iterator<value_type>                       iterator;
        typedef ft::random_acces_iterator<const value_type>                 const_iterator;
        typedef ft::reverse_iterator<iterator>		                        reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>	                    const_reverse_iterator;
        typedef typename allocator_type::difference_type					difference_type;
        typedef size_t					                                    size_type;
    
    protected:
        Alloc       m_alloc;
        pointer     m_start;
        pointer     m_end;
        pointer     m_capacity;

    public:
        //CONSTRURCTEUR
        explicit vector (const allocator_type& alloc = allocator_type())
        : m_alloc(alloc), m_start(NULL), m_end(NULL), m_capacity(NULL)
        {
        }

        explicit vector (size_type n, const value_type& val = value_type(),
        const allocator_type& alloc = allocator_type())
        : m_alloc(alloc), m_start(NULL), m_end(NULL), m_capacity(NULL)
        {
            m_start = m_alloc.allocate(n);
            m_capacity = m_start + n;
            m_end = m_start;
            while (n--)
            {
                m_alloc.construct(m_end, val);
                m_end++;
            }
        }

        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
        : m_alloc(alloc), m_start(NULL), m_end(NULL), m_capacity(NULL)
        {
            difference_type n = last - first;
            m_start = m_alloc.allocate(n);
            m_capacity = m_start + (n);
            m_end = m_start;
            while (first != last)
            {
                m_alloc.construct(m_end, *first);
                first++;
                m_end++;
            }
        }

        //CONSTRUCTEUR DE COPIE
        vector(vector const & x)
        {
            if (this != &x)
            {
                m_alloc = x.m_alloc;
                difference_type n = x.m_capacity - x.m_start;
                m_start = m_alloc.allocate(n);
                m_capacity = m_start + n;
                m_end = m_start;

                pointer start = x.m_start;
                pointer end = x.m_end;
                while (start != end)
                {
                    m_alloc.construct(m_end, *start++);
                    m_end++;
                }
            }
        }

        //DESTRUCTEUR
        ~vector()
        {
            clear();
            m_alloc.deallocate(m_start, capacity());
        }

        //OPERATEUR D'ASSIGNATION
        vector& operator=(const vector &x)
        {
            if (this != &x)
            {
                clear();
                m_alloc.deallocate(m_start, capacity());
                m_alloc = x.m_alloc;
                difference_type n = x.m_capacity - x.m_start;
                m_start = m_alloc.allocate(n);
                m_capacity = m_start + n;
                m_end = m_start;
                pointer start = x.m_start;
                pointer end = x.m_end;
                while (start != end)
                {
                    m_alloc.construct(m_end, *start++);
                    m_end++;
                }
            }
            return *this;
        }

        //ITERATORS
        iterator begin()
        {
            return iterator(m_start);
        }

        const_iterator begin() const
        {
            return const_iterator(m_start);
        }

        iterator end()
        {
            return iterator(m_end);
        }

        const_iterator end() const
        {
            return const_iterator(m_end);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(iterator(m_end));
        }

        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(const_iterator(m_end));
        }

        reverse_iterator rend()
        {
            return reverse_iterator(iterator(m_start));
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(const_iterator(m_start));
        }

        //CAPACITE
        size_type size() const
        {
            return m_end - m_start;
        }

        size_type max_size() const
        {
            return m_alloc.max_size();
        }

        void resize(size_type n, value_type val = value_type())
        {
            if (n != capacity())
            {
                vector<value_type> v(n, val);
                size_t  s = (size() <= v.size()) ? size() : v.size();
                for (size_t i = 0; i < s; ++i)
                    *(v.m_start + i) = *(m_start + i); 
                *this = v;
            }
        }

        size_type capacity() const
        {
            return m_capacity - m_start;
        }

        bool empty() const
        {
            if (size() == 0)
                return true;
            return false;
        }

        void reserve (size_type n)
        {
            if (n > max_size())
                throw (std::length_error(" Reserve demade une taille superieur a taille max "));
            else if (n > capacity())
            {
                allocator_type alloc;
                pointer start = alloc.allocate(n);
                size_t  s = size();
                for (size_t i = 0; i < s; ++i)
                    *(start + i) = *(m_start + i);
                m_alloc.deallocate(m_start, capacity());
                m_alloc = alloc;
                m_start = start;
                m_end = m_start + s;
                m_capacity = m_start + n;
            }
        }
    
        //ACCES AU ELEMENTS
        reference operator[](size_type n)
        {
            return *(m_start + n);
        }

        const_reference operator[](size_type n) const
        {
            return *(m_start + n);
        }


        reference at(size_type n)
        {
            if (n >= size())
                throw :: std::out_of_range("'n' n'est pas dans le vecteur");
            else
                return *(m_start + n);
        }

        const_reference at(size_type n) const
        {
            if (n >= size())
                throw :: std::out_of_range("'n' n'est pas dans le vecteur");
            else
                return *(m_start + n);
        }

        reference front()
        {
            return *m_start;
        }

        const_reference front() const
        {
            return *m_start;
        }
    
        reference back()
        {
            return *(m_end - 1);
        }

        const_reference back() const
        {
            return *(m_end - 1);
        }

        //MODIFIER
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last,
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
        {
            clear();
            if (capacity() < (size_t)(last - first))
            {
                m_alloc.deallocate(m_start, capacity());
                m_start = m_alloc.allocate(last - first);
                m_capacity = m_start + (last - first);
            }
            m_end = m_start + (last - first);
            pointer start = m_start;
            for (;first != last; ++start, ++first)
                *start = *first;
        }

        void    assign(size_type n, const value_type& val)
        {
            clear();
            if (capacity() < n)
            {
                m_alloc.deallocate(m_start, capacity());
                m_start = m_alloc.allocate(n);
                m_capacity = m_start + (n);
            }
            m_end = m_start + (n);
            pointer start = m_start;
            for (; n; --n, ++start)
                *start = val;
        }

        void push_back (const value_type& val)
        {
            if (capacity() == size())
            {
                pointer start = m_start;
                pointer end = m_end;
                size_t  s = size();
                clear();
                if (!s)
                {
                    m_start = m_alloc.allocate(1);
                    m_capacity = m_start + (1);
                    m_end = m_start + 1;
                }
                else
                {
                    m_start = m_alloc.allocate(s * 2);
                    m_capacity = m_start + (s * 2);
                    m_end = m_start + s;
                }
                assign(start, end);
                m_alloc.deallocate(start, s);
            }
            *m_end++ = val;
        }

        void pop_back ()
        {
            m_alloc.destroy(&(back()));
            --m_end;
        }

        iterator insert (iterator position, const value_type& val)
        {
            size_t nb = &(*position) - m_start;
            if (capacity() == size())
            {
                pointer start = m_start;
                pointer end = m_end;
                size_t  s = size();
                clear();
                m_start = m_alloc.allocate(s * 2);
                m_capacity = m_start + (s * 2);
                m_end = m_start + s;
                assign(start, end);
                m_alloc.deallocate(start, s);
            }
            pointer end = m_end++;
            pointer pos = m_start + nb;
            for (; end != pos; --end)
                *end = *(end - 1);
            m_alloc.construct(end, val);
            return (iterator(pos));
        }

        void insert (iterator position, size_type n, const value_type& val)
        {
            size_t nb = &(*position) - m_start;
            if (!size() || capacity() < size() + n)
            {
                pointer start = m_start;
                pointer end = m_end;
                size_t  s = size();
                clear();
                m_start = m_alloc.allocate(s * 2 + n);
                m_capacity = m_start + (s * 2);
                m_end = m_start + s;
                if (size())
                {
                    assign(start, end);
                    m_alloc.deallocate(start, s);
                }
            }
            m_end += n;
            pointer end = m_end - 1;
            pointer pos = m_start + nb;
            for (; end >= pos + n; --end)
                *end = *(end - n);
            for (; end >= pos; --end)
                m_alloc.construct(end, val);
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last,
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
        {
            size_t nb = &(*position) - m_start;
            size_t n = (last - first);
            if (!size() || capacity() < size() + n)
            {
                pointer start = m_start;
                pointer end = m_end;
                size_t  s = size();
                clear();
                m_start = m_alloc.allocate(s * 2 + n);
                m_capacity = m_start + (s * 2);
                m_end = m_start + s;
                assign(start, end);
                m_alloc.deallocate(start, s);
            }
            m_end += n;
            pointer end = m_end - 1;
            pointer pos = m_start + nb;
            for (; end >= pos + n; --end)
                *end = *(end - n);
            for (; first != last; --end)
                m_alloc.construct(end, *--last);
        }

        iterator erase (iterator position)
        {
            pointer pos = &(*position);
            if (pos == m_end - 1)
                pop_back();
            else
            {
                m_alloc.destroy(pos);
                for (; pos != m_end - 1; ++pos)
                    *pos = *(pos + 1);
                m_alloc.destroy(pos);
                --m_end;
            }
            return (position);
        }

        iterator erase (iterator first, iterator last)
        {
            pointer pos = &(*first);
            pointer pos_last = &(*last);
            pointer ret = pos_last;
            difference_type dist = last - first;
            if (pos == m_end - 1 && dist == 1)
                pop_back();
            else
            {
                for (; pos !=  pos_last; ++pos)
                {
                    m_alloc.destroy(pos);
                    if (pos + dist < m_end)
                        *pos = *(pos + dist);
                    else if (pos + dist == m_end)
                        ret = pos;
                } 
                for (; pos < m_end; ++pos)
                {
                    if (pos + dist < m_end)
                        *pos = *(pos + dist);
                    else if (pos + dist == m_end)
                        ret = pos;
                    else
                        m_alloc.destroy(pos);
                }
                m_end -= dist;
            }
            return (iterator(ret));
        }

        void swap (vector& x)
        {
            if (this != &x)
            {
                allocator_type  alloc = m_alloc;
                pointer         start = m_start;
                pointer         end = m_end;
                pointer         capa = m_capacity;

                m_alloc = x.m_alloc;
                m_start = x.m_start;
                m_end = x.m_end;
                m_capacity = x.m_capacity;

                x.m_alloc = alloc;
                x.m_start = start;
                x.m_end = end;
                x.m_capacity = capa;
            }
        }

        void clear()
        {
            pointer start = m_start;
            pointer end = m_end;
            while (start && start != end)
                m_alloc.destroy(start++);
            m_end = m_start;
        }
    };

  //OPERATOR
    template <class T, class Alloc>
    bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (&lhs == &rhs)
            return true;
        if (lhs.size() != rhs.size())
            return false;

        typename vector<T>::const_iterator it = lhs.begin();
        typename vector<T>::const_iterator it2 = rhs.begin();
        for (; it != lhs.end(); ++it, ++it2)
        {
            if (it2 == rhs.end() || *it != *it2)
                return false;
        }
        return (true);
    }

    template <class T, class Alloc>
    bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T, class Alloc>
    bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (&lhs == &rhs)
            return false;
        typename vector<T>::const_iterator it = lhs.begin();
        typename vector<T>::const_iterator it2 = rhs.begin();
        for (; it != lhs.end(); ++it, ++it2)
        {

            if (it2 == rhs.end() || *it2 < *it)
                return false;
            else if (*it < *it2)
            {

                return true;
            }
        }
        return (it == lhs.end() && it2 != rhs.end());
    }

    template <class T, class Alloc>
    bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(rhs < lhs));
    }

    template <class T, class Alloc>
    bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }

  //SWAP
    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }

}

#endif