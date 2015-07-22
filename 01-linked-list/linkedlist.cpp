#include "linkedlist.hpp"

Node::Node(): data(0), next(NULL) { };

Node::Node(int n): data(n) , next(NULL) { }; //This takes n and puts it into data

Node::Node(int n, Node* node): data(n), next(node) { };

Node::~Node()
{
    
}

Node::Node(const Node& ref): data(ref.data), next(ref.next) { };

Node& Node::operator=(const Node & ref) 
{
    if (this != &ref)
    {
        //deallocate, allocate new space, copy values
        this->data = ref.GetData();
        if (ref.GetNext() != NULL)
        {    
            this->next = new Node(*ref.GetNext());
        }
    }
    
    return *this;
};

int Node::GetData() const
{
    return this->data;
}

void Node::SetData(int data)
{
    this->data = data;
}

Node* Node::GetNext() const
{
    return this->next;
}

void Node::SetNext(Node *newNode)
{
    this->next = newNode;
}

LinkedList::LinkedList()
{
    this->empty = true;
    this->head.SetNext(new Node(0));
    this->head.SetData(0);
}


LinkedList::LinkedList(const LinkedList& ref) 
{    
    this->head = ref.head;
    Node *placeHolder;
    Node *temp;
    
    if (ref.head.GetNext() != NULL)
    {
        this->head.SetNext(new Node(*ref.head.GetNext()));
        
        //temp = placeHolder;
        placeHolder = this->head.GetNext();
        temp = placeHolder;

        while(placeHolder->GetNext() != NULL)
        {
            temp = new Node(*temp->GetNext());
            placeHolder->SetNext(temp);
            placeHolder = placeHolder->GetNext();
        }
    }
}

LinkedList::~LinkedList()
{
    
}

bool LinkedList::isEmpty() const
{
    return this->empty;
}

//Now that head is no longer a pointer, we need a way to determine
//if we are adding 1st or 2nd node
void LinkedList::Add(Node *node)    //adds node to the end of list
{
    Node *placeHolder = new Node(this->head);

    if(this->empty)
    {
        this->head = *node;
        this->head.SetNext(NULL);
        this->empty = false;
    }
    else if (this->head.GetNext() == NULL)
    {
        this->head.SetNext(node);
    }
    else
    {
        while(placeHolder->GetNext() != NULL)
        {
            placeHolder = placeHolder->GetNext();
        }
        
        placeHolder->SetNext(node);
    }     
}

void LinkedList::PrintList()
{
    Node *temp = new Node(this->head);
        
    std::cout << temp->GetData() << "\n";
    
    while(temp->GetNext() != NULL)
    {
        temp = temp->GetNext();
        std::cout << temp->GetData() << "\n";
    }
}

Node LinkedList::GetHead()
{
    return this->head;
}

int main()
{
    //LinkedList myList;
    Node myNode(rand());
    LinkedList myList;
    Node n1(rand()), n2(rand()), n3(rand()), n4(rand()), n5(rand());
    LinkedList *copytest;
    
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
    
    std::cout << "Testing Linked List Copy Constructor \n";
    
    copytest = new LinkedList(myList);
    
    std::cout << "Printing list: \n";

    copytest->PrintList();    
    
    return 0;
}