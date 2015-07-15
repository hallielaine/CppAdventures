#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 

class Node {                            //might use this later
    public:
        Node();
        Node(int data);
        Node(int data, Node *next);
        Node(const Node& ref);                  //copy constructor, not included in spec
        Node& operator = (const Node& ref);     // overload operator, not included in spec
        ~Node();

        int GetData();
        void SetData(int data);
        Node *GetNext();
        void SetNext(Node *nextNode);               // not in spec, this doesn't seem legal
    private:
        int data;
        Node *next;
};

class LinkedList {                 // a list of integers
    public:
        LinkedList();              // constructor; initialize the list to be empty
        LinkedList(const LinkedList& ref);
        LinkedList& operator = (const LinkedList& ref);
        ~LinkedList();

        void Add(Node *node);
        void PrintList();
    private:
        Node *head;
    };
