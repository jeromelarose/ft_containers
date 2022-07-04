#ifndef QUEUE_H
#define QUEUE_H

#include <deque>

namespace ft 
{
    template <class T, class Container = std::deque<T> >
    class queue
    {
    public:
        typedef typename	Container::value_type		value_type;
        typedef	            Container			        container_type;
        typedef typename	Container::size_type		size_type;

    protected:
        Container c;

    public:

    // MEMBER FUNCTION

        // CONSTRUCTOR
        explicit queue (const container_type& ctnr = container_type()) : c(ctnr)
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

        value_type& front()
        {
            return c.front();
        }

        const value_type& front() const
        {
            return c.front();
        }

        value_type& back()
        {
            return c.back();
        }

        const value_type& back() const
        {
            return c.back();
        }

        void push (const value_type& val)
        {
            c.push_back(val);
        }

        void pop()
        {
            c.pop_front();
        }
    };

    //NON-MEMBER FUNCTION OVERLOADS

    template <class T, class Container>
    bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return lhs.c == rhs.c;
    }

    /// Based on operator==
    template <class T, class Container>
    bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Container>
    bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return lhs.c < rhs.c;
    }

    /// Based on operator<
    template <class T, class Container>
    bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return !(rhs < lhs);
    }

    /// Based on operator<
    template <class T, class Container>
    bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return rhs < lhs;
    }

    /// Based on operator<
    template <class T, class Container>
    bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
    {
        return !(lhs < rhs);
    }
} // namespace

#endif /* QUEUE_H */
