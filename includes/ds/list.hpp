#ifndef LIST_H
#define LIST_H
#include <ds/node.hpp>


namespace AN
{

    template <class T>
    class List;
    template <class T>
    class ListNode : public Node
    {
    public:
        T _val;

    public:
        ListNode(T val);
        friend class List<T>;
    };

    template <class T>
    class List
    {
    private:
        ListNode<T> *header;

        ListNode<T> *win;

        int _length;

    public:
        List<T>();
        ~List<T>();

        /*
        Function insert inserts a new item
        after the window and returns the item
        */
        T insert(T);

        /*
        insert a new item at the beginning
        */
        T prepend(T);

        /*
        insert a new item at the end
        */
        T append(T);

        /*
        append a list to the end
        of this list
        */
        List *append(List *);

        /*
        removes the item in the window
        */
        T remove();

        /*
        replaces the item currently
        in the window
        */
        void val(T);

        /*
        returns the item in the window
        */
        T val();

        /*
        move the window to the next position
        */
        T next();
        /*
        move the window to the previous position
        */
        T prev();

        /*
        reset the window to the first position,
        */
        T first();

        /*
        reset the window to the last position,
        */
        T last();

        /*
        returns the length of this list
        */
        int length();

        /*
        return TRUE just if the window
        is in the first position,
        */
        bool isFirst();

        /*
        return TRUE just if the window
        is in the last position,            
        */
        bool isLast();

        /*
        return TRUE just if the window
        is in the head position,
        */
        bool isHead();

        /*
        loads the n items in array a into a list,
        and returns the list
        */
        static List<T> *arrayToList(T[], int);

        /*
        returns the smallest item in list
        */
        static T leastItem(List<T> &s, int (*cmp)(T, T));
    };

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

#endif