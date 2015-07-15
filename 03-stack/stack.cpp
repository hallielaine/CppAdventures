#include "stack.hpp"

Stack::Stack()
{
    size = 0;
    capacity = 10;
    this->data = (int *) malloc(capacity);
}

Stack::~Stack()
{
        free(this->data);
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
    if(this->size == this->capacity)
    {
        this->capacity *= 2;
        this->data = (int *) realloc(this->data, (sizeof(int) * this->capacity) );
    }
    
    this->data[size] = value;
    this->size++;
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
        
    return temp;
}

int main(void)
{
    Stack mystack;
    
    std::cout << "pushing 10 elements into stack \n";
    
    for(int i=0; i < 10; i++)
    {
        mystack.Push(rand());
        std::cout << "Top is now: " << mystack.Top() << "\n";
        std::cout << "Size is now: " << mystack.Size() << "\n";
    }
    
    std::cout << "\n popping until empty \n";
    
    while(!mystack.Empty())
    {
        std::cout << "Popped: " << mystack.Pop() << "\n";
        std::cout << "Top is now: " << mystack.Top() << "\n";
        std::cout << "Size is now: " << mystack.Size() << "\n";
    }
    
    std::cout << "\n pushing 20 elements into stack \n";
    
    for(int i=0; i < 20; i++)
    {
        mystack.Push(rand());
        std::cout << "Top is now: " << mystack.Top() << "\n";
        std::cout << "Size is now: " << mystack.Size() << "\n";
    }
    
    std::cout << "\n popping 5 elements from stack \n";

    for(int i=0; i < 5; i++)
    {
        std::cout << "Popped: " << mystack.Pop() << "\n";
        std::cout << "Top is now: " << mystack.Top() << "\n";
        std::cout << "Size is now: " << mystack.Size() << "\n";
    }
    
    std::cout << "\n popping until empty \n";
    
    while(!mystack.Empty())
    {
        std::cout << "Popped: " << mystack.Pop() << "\n";
        std::cout << "Top is now: " << mystack.Top() << "\n";
        std::cout << "Size is now: " << mystack.Size() << "\n";
    }

    
    return 0;
}

