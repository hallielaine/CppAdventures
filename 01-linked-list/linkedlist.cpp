#include "linkedlist.hpp"

Node::Node(int n): data(n) { }; //This takes n and puts it into data

Node::Node(int n, Node* node): data(n), next(node) { };

int Node::GetData()
{
    return this->data;
}

Node* Node::GetNext()
{
    return this->next;
}

void Node::SetNext(Node *head)
{
    this->next = head;
}

void LinkedList::Add(Node *node)    //adds node to the end of list
{
    //node->SetNext(head);
    
    Node* temp = head;
    
    while(temp->GetNext() != NULL)
    {
        temp = temp->GetNext();
    }
    
    temp->SetNext(node);        //is there a way to do this without setting next?
}

void LinkedList::PrintList()
{
    Node* temp = head;
    
    std::cout << temp->GetData(); "\n";
    
    while(temp->GetNext() != NULL)
    {
        temp = temp->GetNext();
        std::cout << temp->GetData(); "\n";
    }
}

int main()
{
    std::cout << "Hello, world!\n";
}