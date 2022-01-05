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

}

#endif