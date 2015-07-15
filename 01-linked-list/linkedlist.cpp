#include "linkedlist.hpp"

Node::Node(int n): data(n) { }; //This takes n and puts it into data

Node::Node(int n, Node* node): data(n), next(node) { };

int Node::GetData()
{
    return this->data;
}#include "linkedlist.hpp"

Node::Node(int n): data(n) , next(NULL) { }; //This takes n and puts it into data

Node::Node(int n, Node* node): data(n), next(node) { };

Node::~Node()
{
    
}

int Node::GetData()
{
    return this->data;
}

void Node::SetData(int data)
{
    this->data = data;
}

Node* Node::GetNext()
{
    return this->next;
}

void Node::SetNext(Node *newNode)
{
    this->next = newNode;
}

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList()
{
    
}

LinkedList::LinkedList(const LinkedList& ref) 
{    
    if(ref.head == NULL)
    {
        // nothing to copy, get out of here
    }
    else
    {
        //make a new node with this->head.G
        //ref.head = new node;  //Do I need a copy constructor for node?
    
        //while(temp->GetNext() != NULL)
        {
            
        }
    }
}

void LinkedList::Add(Node *node)    //adds node to the end of list
{
    Node* temp;
    
    if(head == NULL)
    {
        this->head = node;
        this->head->SetNext(NULL);
    }
    else
    {
        temp = this->head; 

        while(temp->GetNext() != NULL)
        {
            temp = temp->GetNext();
        }
        
        temp->SetNext(node);
    }
    
}

void LinkedList::PrintList()
{
    Node* temp = this->head;
    
    std::cout << temp->GetData() << "\n";
    
    while(temp->GetNext() != NULL)
    {
        temp = temp->GetNext();
        std::cout << temp->GetData() << "\n";
    }
}

int main()
{
    //LinkedList myList;
    Node myNode(rand());
    LinkedList myList;
    Node n1(rand()), n2(rand()), n3(rand()), n4(rand()), n5(rand()); 
    
    std::cout << "Node has: " << myNode.GetData() << "\n";
    std:: cout << "Adding 1st Node to List\n";    
    
    myList.Add(&myNode);    
    
    std::cout << "Adding 5 more elements to Linked List\n";
    
    myList.Add(&n1);
    myList.Add(&n2);    
    myList.Add(&n3);    
    myList.Add(&n4);    
    myList.Add(&n5);   

        
    std::cout << "Printing list: \n";
    
    myList.PrintList();
        
    return 0;
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