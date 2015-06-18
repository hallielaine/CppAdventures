#include "vector.hpp"

int Vector::Size()
{
    return this->size;
}

void Vector::push_back(int element)
{
    if(size < capacity)
    {
        buffer[size] = element; //size starts at 0, and increments from there
        size++;        
    }
    else
    {
        //handle error, print out something?
    }
}

int &Vector::operator[](int index)
{
    return buffer[index];
}


int main(void)
{
    std::cout << "Hello, world!\n";
}