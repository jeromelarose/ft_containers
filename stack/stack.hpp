#ifndef STACK_H
#define STACK_H

#include <deque>

namespace ft
{
    template <class T, class Container = std::deque<T> >
    class stack
    {
    public:
        typedef typename Container::value_type		    value_type;
        typedef	Container			                    container_type;
        typedef typename Container::size_type		    size_type;

    protected:
        Container c;

    public:

    //  MEMBER FUNCTIONS
    
        // CONSTRUCTEUR

        explicit stack (const container_type& ctnr = container_type()) : c(ctnr)
        {
        }

        bool empty() const
        {
            return c.empty();
        }

        size_type size() const
        {
            return c.size();
        }


        value_type& top()
        {
            return c.back();
        }

        const value_type& top() const
        {
            return c.back();
        }

        void push(const value_type& __x)
        {
            c.push_back(__x);
        }

        void pop()
        {
            c.pop_back();
        }
    };

    //NON-MEMBER FUNCTION OVERLOADS

    template <class T, class Container>
    bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return lhs.c == rhs.c;
    }

    /// Based on operator==
    template <class T, class Container>
    bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Container>
    bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return lhs.c < rhs.c;
    }

    /// Based on operator<
    template <class T, class Container>
    bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return !(rhs < lhs);
    }

    /// Based on operator<
    template <class T, class Container>
    bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return rhs < lhs;
    }

    /// Based on operator<
    template <class T, class Container>
    bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return !(lhs < rhs);
    }
} // namespace

#endif /* STACK_H */
