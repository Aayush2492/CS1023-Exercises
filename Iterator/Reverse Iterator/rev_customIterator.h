#pragma once
#include <iterator>
#include <vector>

template <typename T>
class customDS_iterator;

template <typename T>
class customDS_node
{
    T val;

public:
    customDS_node<T> *next;
    customDS_node()
    {
        next = nullptr;
    }
    customDS_node(const T &_val)
    {
        val = _val;
    }

    customDS_node<T> *getNext()
    {
        return next;
    }

    T getValue()
    {
        return val;
    }

    friend class customDS_iterator<T>;
};

template <typename T>
class customDS_iterator : public std::iterator<std::forward_iterator_tag, T>
{
    customDS_node<T> *ptr;

public:
    customDS_iterator()
    {
        ptr = nullptr;
    }

    customDS_iterator(customDS_node<T> *nd)
    {
        ptr = nd;
    }

    void operator=(const customDS_iterator<T> &it)
    {
        ptr = it.ptr;
    }

    //Pre increment operator overloading
    customDS_iterator<T> &operator++()
    {
        if (ptr != nullptr)
        {
            ptr = ptr->next;
        }
        return (*this);
    }

    template <typename T1>
    friend bool operator==(const customDS_iterator<T1> &, const customDS_iterator<T1> &);
    template <typename T1>
    friend bool operator!=(const customDS_iterator<T1> &, const customDS_iterator<T1> &);

    T &operator*()
    {
        return ptr->val;
    }
};

template <typename T>
bool operator==(const customDS_iterator<T> &it1, const customDS_iterator<T> &it2)
{
    return (it1.ptr == it2.ptr);
}

template <typename T>
bool operator!=(const customDS_iterator<T> &it1, const customDS_iterator<T> &it2)
{
    return (it1.ptr != it2.ptr);
}

template <typename T>
class customDS
{
    customDS_node<T> *head;

public:
    customDS<T>()
    {
        head = nullptr;
    }

    void push_value(const T &val)
    {
        auto p = new customDS_node<T>(val);
        p->next=head;
        head = p;
    }

    customDS_iterator<T> &begin()
    {
        return *(new customDS_iterator<T>(head));
    }

    customDS_iterator<T> &end()
    {
        return *(new customDS_iterator<T>());
    }

    unsigned size()
    {
        unsigned sz = 0;
        auto start = this->begin();
        auto stop = this->end();
        while (start != stop)
        {
            sz++;
            ++start;
        }
        return sz;
    }
};