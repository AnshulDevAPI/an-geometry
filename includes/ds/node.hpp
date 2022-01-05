// #pragma once

#ifndef NODE_H
#define NODE_H

namespace AN{
    class Node{
        Node *_next; // link to previous pointer
        Node *_prev; // link to predecessor node

        public:
            Node(void);
            virtual ~Node(void);
            Node* next(void);
            Node* prev(void);
            Node* insert(Node*);
            Node *remove(void);
            void splice(Node*);
    };


}

#endif