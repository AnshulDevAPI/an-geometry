#include <ds/list.hpp>

namespace AN
{

    template <class T>
    ListNode<T>::ListNode(T val) : _val(val)
    {
    }

    template <class T>
    List<T>::List() : _length(0)
    {
        header = new ListNode<T>(nullptr);
        win = header;
    }

    template <class T>
    List<T>::~List()
    {
        while (length() > 0)
        {
            first();
            remove();
        }
        delete header;
    }

    template <class T>
    T List<T>::insert(T val)
    {
        win->insert(new ListNode<T>(val));
        ++_length;
        return val;
    }

    template <class T>
    T List<T>::prepend(T val)
    {
        header->insert(new ListNode<T>(val));
        ++_length;
        return val;
    }

    template <class T>
    T List<T>::append(T val)
    {
        header->prev()->insert(new ListNode<T>(val));
        ++_length;
        return val;
    }

    template <class T>
    List<T> *List<T>::append(List<T> *l)
    {
        ListNode<T> *a = (ListNode<T> *)header->prev();
        a->splice(l->header);
        _length += l->_length;
        l->header->remove();
        l->_length = 0;
        l->win = header;
        return this;
    }

    template <class T>
    T List<T>::remove(void)
    {
        if (win == header)
            return nullptr;
        T val = win->_val;
        win = (ListNode<T> *)win->prev();
        delete (ListNode<T> *)win->next()->remove();
        --_length;
        return val;
    }

    template <class T>
    void List<T>::val(T v)
    {
        if (win != header)
            win->_val = v;
    }

    template <class T>
    T List<T>::val(void)
    {
        return win->_val;
    }

    template <class T>
    T List<T>::next(void)
    {
        win = (ListNode<T> *)win->next();
        return win->_val;
    }

    template <class T>
    T List<T>::prev(void)
    {
        win = (ListNode<T> *)win->prev();
        return win->_val;
    }

    template <class T>
    T List<T>::first(void)
    {
        win = (ListNode<T> *)header->next();
        return win->_val;
    }

    template <class T>
    T List<T>::last(void)
    {
        win = (ListNode<T> *)header->prev();
        return win->_val;
    }

    template <class T>
    int List<T>::length(void)
    {
        return _length;
    }

    template <class T>
    bool List<T>::isFirst(void)
    {
        return ((win == header->next()) && (_length > 0));
    }

    template <class T>
    bool List<T>::isLast(void)
    {
        return ((win == header->prev()) && (_length > 0));
    }

    template <class T>
    bool List<T>::isHead(void)
    {
        return (win == header);
    }

    template <class T>
    List<T> *List<T>::arrayToList(T a[], int n)
    {
        List<T> *s = new List<T>;
        for (int i = 0; i < a; i++)
            s->append(a[i]);
        return s;
    }

    template <class T>
    T List<T>::leastItem(List<T> &s, int (*cmp)(T, T))
    {
        //int i;
        if (s.length() == 0)
            return nullptr;
        T v = s.first();
        for (s.next(); !s.isHead(); s.next())
            if (cmp(s.val(), v) < 0)
                v = s.val();
        return v;
    }
}
