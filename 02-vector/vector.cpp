#include "vector.hpp"

Vector::Vector()
{
    capacity = 10;
    size = 0;
}

Vector::~Vector()
{
    free(this->buffer);
}

int Vector::Size()
{
    return this->size;
}

void Vector::push_back(int element)
{
    if(size == 0)
    {
        size++;
        this->buffer = (int *) malloc(sizeof(int) * capacity);
        this->buffer[size - 1] = element;
    }
    else if(size < capacity)
    {
        buffer[size] = element; //size starts at 0, and increments from there
        size++;        
    }
    else
    {
        size++;
        capacity *= 2;
        this->buffer = (int *) realloc(this->buffer, sizeof(int) * capacity);
        this->buffer[size - 1] = element;
    }
}

int &Vector::operator[](int index)
{
    return buffer[index];
}


int main(void)
{
    Vector myVector;
    
    std::cout << "pushing 10 elements into Vector \n";
    
    for(int i = 0; i < 10; i++)
    {
        int temp = rand();
        std::cout << "Add Element " << temp << " to vector\n";
        myVector.push_back(temp);
    }
    
        std::cout << "printing 10 elements from Vector \n";
        
    for(int i = 0; i < 10; i++)
    {
        std::cout << "Element " << i << ": " << myVector[i] << "\n";
    }
    
    std::cout << "pushing 5 more elements into vector \n";
    
        for(int i = 0; i < 5; i++)
    {
        int temp = rand();
        std::cout << "Add Element " << temp << " to vector\n";
        myVector.push_back(temp);
    }
    
        std::cout << "printing 15 elements from Vector \n";
        
    for(int i = 0; i < 15; i++)
    {
        std::cout << "Element " << i << ": " << myVector[i] << "\n";
    }


    return 0;
}