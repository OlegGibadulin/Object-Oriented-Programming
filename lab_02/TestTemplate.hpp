//
//  TestTemplate.hpp
//  lab_02
//
//  Created by Mac-HOME on 06/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#ifndef TestTemplate_hpp
#define TestTemplate_hpp

#include <iostream>

template <class T>
T abs(T a)
{
    return (a < 0) ? -a : a;
}

template <class aType, class bType>
int findElem(aType* arr, aType elem, bType size)
{
    for (unsigned int i = 0; i < size; ++i)
    {
        if (arr[i] == elem)
            return i;
    }
    
    return -1;
}

const int sz = 10;

template <class Type>
class StackTest
{
private:
    Type arr[sz];
    int top;
public:
    StackTest();
    void push(Type var);
    Type pop();
};

template <class Type>
StackTest<Type>::StackTest()
{
    top = 0;
}

template <class Type>
void StackTest<Type>::push(Type var)
{
    arr[top++] = var;
}

template <class Type>
Type StackTest<Type>::pop()
{
    return arr[--top];
}

#endif /* TestTemplate_hpp */
