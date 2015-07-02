#include "stack.hpp"

Stack::Stack()
{
    size = 0;
}

Stack::~Stack()
{
    if(size > 0)
    {
        free(this->data);
    }
}

bool Stack::Empty()
{
    return (this->size == 0);
}

int Stack::Size()
{
    return this->size;
}

int Stack::Top()
{
    if(this->size > 0)
    {
        return this->data[this->size - 1];
    }
    else
    {
        std::cout << "\nSize is zero, no Top\n";
        return -1;
    }
}

void Stack::Push(int value)
{
    if(this->size > 0)
    {
        this->size++;
        realloc(this->data, (sizeof(int) * this->size) );\
        this->data[size - 1] = value;
    }
    else
    {
        this->size++;
        this->data = (int *) malloc(this->size);
        this->data[size - 1] = value;          
    }        
}

int Stack::Pop()
{
    int temp;
    
    if(size == 0)
    {
           std::cout << "size is 0, cannot pop \n";
           return -1;
    }
 
    
    this->size--;
    temp = this->data[this->size];
    if(size > 0)
    {
        realloc(this->data, (sizeof(int) * size));
    }
    else
    {
        free(this->data);
    }
    
    return temp;
}

int main(void)
{
    Stack mystack;
    
    std::cout << "pushing 10 elements into stack \n";
    
    for(int i=0; i < 10; i++)
    {
        mystack.Push(rand());
        std::cout << "Top is now:" << mystack.Top() << "\n";
        std::cout << "Size is now:" << mystack.Size() << "\n";
    }
    
    std::cout << "\n popping until empty \n";
    
    while(!mystack.Empty())
    {
        mystack.Pop();
        std::cout << "Top is now:" << mystack.Top() << "\n";
        std::cout << "Size is now:" << mystack.Size() << "\n";

    }
    

    
}

