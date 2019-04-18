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

//#define OVERLAP
#define SHUFFLE

#include <iostream>
#include <thread>
#include <stdlib.h>
#include <time.h>

#include "LinkedList.h"

struct Vector2
{
    float x=0;
    float y=0;
    
    Vector2();

    Vector2(float x, float y);
    
    
    friend std::ostream& operator<<(std::ostream& stream, const Vector2 vec)
    {
        return stream << "(" << vec.x << "," << vec.y << ")" << std::endl;
    }
    
    bool operator==(const Vector2& other);
    
    void operator=(const Vector2& other);
};

//simple swap shuffle function
template<typename Type>
void ShuffleArray(Type* array, uint16_t&& length);

int main(int argc, const char * argv[])
{
    srand((int)time(nullptr));
    
    Vector2* vectors = new Vector2[10000];
    Vector2 vecTarget(300.0f,300.0f);
    
    vectors[9500] = vecTarget;
    //std::cout << vectors[99] << std::endl;
    
#ifdef SHUFFLE
    ShuffleArray<Vector2>(vectors, 10000);
#endif
    LinkedList<Vector2> list(vectors, 10000);
    
    //std::cout << list << std::endl;
    
    bool itemFound = false;
    
    Node<Vector2>* forwardSearchResult = nullptr;
    Node<Vector2>* backSearchResult = nullptr;
    
    int counter = 0;
    
    std::thread first(&LinkedList<Vector2>::searchForward, &list, vecTarget, &itemFound, &forwardSearchResult);
    std::thread second (&LinkedList<Vector2>::searchBackward, &list, vecTarget, &itemFound, &backSearchResult);
    
    while(!forwardSearchResult && !backSearchResult)
    {
#ifdef OVERLAP
        std::cout << "waithing for other threads" << std::endl;
#endif
        counter++;
    }
    
    first.join();
    second.join();
    
    std::cout << "counter incremented to: " << counter << std::endl;

    
    std::cout << "Address returned by searchForward: " << forwardSearchResult << std::endl;
    if(forwardSearchResult)
        std::cout << "forwardSearch found " << *forwardSearchResult->m_Element << std::endl;
    
    
    std::cout << "Address returned by searchBackward: " << backSearchResult << std::endl;
    if(backSearchResult)
        std::cout << "backSearch found " << *backSearchResult->m_Element << std::endl;
    
    //std::cout << list << std::endl;
}

    
Vector2::Vector2()
    {
        this->x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        this->y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        x*=255;
        y*=255;
    }
Vector2::Vector2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    
bool Vector2::operator==(const Vector2& other)
    {
        if(this->x == other.x && this->y == other.y)
            return true;
        
        else
            return false;
    }
    
void Vector2::operator=(const Vector2& other)
    {
        this->x = other.x;
        this->y = other.y;
    }

//simple swap shuffle function
//used to shuffle the Card::deck
template<typename Type>
void ShuffleArray(Type* array, uint16_t&& length)
{
    srand((int)time(nullptr));
    
    for(uint16_t i = 0; i < length; i++)
    {
        Type holder = array[i];
        
        uint8_t index = rand() % length;
        
        array[i] = array[index];
        array[index] = holder;
    }
}
