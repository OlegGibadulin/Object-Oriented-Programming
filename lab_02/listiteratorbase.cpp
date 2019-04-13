//
//  listiteratorbase.cpp
//  lab_02
//
//  Created by Mac-HOME on 13/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#include "listiteratorbase.hpp"

template <typename typeData>
ListIterBase <typeData>::ListIterBase()
{
    this->ptr = nullptr;
}

template <typename typeData>
ListIterBase <typeData>::ListIterBase(const ListIterBase <typeData>& listIter)
{
    this->ptr = listIter->ptr;
}

template <typename typeData>
ListIterBase <typeData>::ListIterBase(const typeData* ptr)
{
    this->ptr = ptr;
}

template <typename typeData>
void ListIterBase <typeData>::begin()
{
    ;
}

template <typename typeData>
void ListIterBase <typeData>::end()
{
    ;
}

template <typename typeData>
void ListIterBase <typeData>::next()
{
    ;
}

template <typename typeData>
void ListIterBase <typeData>::isInRange()
{
    ;
}

template <typename typeData>
ListIterBase <typeData>::~ListIterBase()
{
    this->ptr = nullptr;
}

template <typename typeData>
ListIterBase <typeData>& ListIterBase <typeData>::operator = (const ListIterBase& listIter)
{
    if (this != &listIter)
        this->ptr = listIter->ptr;
    
    return *this;
}

template <typename typeData>
ListIterBase <typeData>& ListIterBase <typeData>::operator ++ ()
{
    ++(this->ptr);
    return *this;
}

template <typename typeData>
ListIterBase <typeData>& ListIterBase <typeData>::operator ++ (int)
{
    ListIterBase <typeData> tmp(this);
    this->operator++();
    return tmp;
}

template <typename typeData>
ListIterBase <typeData>& ListIterBase <typeData>::operator -- ()
{
    --(this->ptr);
    return *this;
}

template <typename typeData>
ListIterBase <typeData>& ListIterBase <typeData>::operator -- (int)
{
    ListIterBase <typeData> tmp(this);
    this->operator--();
    return tmp;
}

template <typename typeData>
bool ListIterBase <typeData>::operator == (const ListIterBase <typeData>& listIter) const
{
    return this->ptr == listIter.ptr;
}

template <typename typeData>
bool ListIterBase <typeData>::operator != (const ListIterBase <typeData>& listIter) const
{
    return this->ptr != listIter.ptr;
}
