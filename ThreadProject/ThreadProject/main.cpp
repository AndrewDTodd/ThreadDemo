//
//  main.cpp
//  ThreadProject
//
//  Created by Andrew Todd on 4/15/19.
//  Copyright © 2019 Andrew Todd. All rights reserved.
//

#ifndef DEBUG
#define DEBUG
#endif

#include <iostream>
#include <future>
#include <stdlib.h>
#include <time.h>

#include "LinkedList.h"

struct Vector2
{
    float x=0;
    float y=0;
    
    Vector2()
    {
        this->x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        this->y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        x*=255;
        y*=255;
    }
    Vector2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    
    
    friend std::ostream& operator<<(std::ostream& stream, const Vector2 vec)
    {
        return stream << "(" << vec.x << "," << vec.y << ")" << std::endl;
    }
    
    bool operator==(const Vector2& other)
    {
        if(this->x == other.x && this->y == other.y)
            return true;
        
        else
            return false;
    }
    
    void operator=(const Vector2& other)
    {
        this->x = other.x;
        this->y = other.y;
    }
};

//simple swap shuffle function
//used to shuffle the Card::deck
template<typename Type>
void ShuffleArray(Type* array, uint8_t&& length)
{
    srand((int)time(nullptr));
    
    for(uint8_t i = 0; i < length; i++)
    {
        Type holder = array[i];
        
        uint8_t index = rand() % length;
        
        array[i] = array[index];
        array[index] = holder;
    }
}

int main(int argc, const char * argv[])
{
    srand((int)time(nullptr));
    
    Vector2* vectors = new Vector2[100];
    Vector2 vecTarget(1.0f,1.0f);
    
    vectors[99] = vecTarget;
    //std::cout << vectors[99] << std::endl;
    
    ShuffleArray<Vector2>(vectors, 100);
    LinkedList<Vector2> list(vectors, 100);
    
    //std::cout << list << std::endl;
    
    bool itemFound = false;
    
    //Node<Vector2>* item = list.searchForward(vecTarget, &itemFound);
    
    //std::cout << *item->m_Element << std::endl;
    
    //auto forwardSearch = std::async(&LinkedList<Vector2>::searchForward, &list, vecTarget, &itemFound);
    auto backSearch = std::async(&LinkedList<Vector2>::searchBackward, &list, vecTarget, &itemFound);
    
    //Node<Vector2>* forwardNode = forwardSearch.get();
    Node<Vector2>* backNode = backSearch.get();
    /*
    std::cout << "Address returned by searchForward: " << forwardNode << std::endl;
    if(forwardNode)
        std::cout << "forwardSearch found " << *forwardNode->m_Element << std::endl;
    */
    
    std::cout << "Address returned by searchBackward: " << backNode << std::endl;
    if(backNode)
        std::cout << "forwardSearch found " << *backNode->m_Element << std::endl;
    
    std::cout << list << std::endl;
}
