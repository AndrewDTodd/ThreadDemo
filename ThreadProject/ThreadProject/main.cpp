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
#include <thread>
#include <stdlib.h>
#include <time.h>

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
}
