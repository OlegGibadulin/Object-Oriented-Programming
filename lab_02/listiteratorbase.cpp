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
    this->ptrCur = nullptr;
}

template <typename typeData>
ListIterBase <typeData>::ListIterBase(ListIterBase <typeData>& listIter)
{
    this->ptrCur = listIter.ptrCur;
}

template <typename typeData>
ListIterBase <typeData>::ListIterBase(ListNode <typeData>& node)
{
    this->ptrCur = &node;
}

template <typename typeData>
void ListIterBase <typeData>::next()
{
    ptrCur = ptrCur->getNext();
}

template <typename typeData>
bool ListIterBase <typeData>::isInRange()
{
    return (this->ptrCur == nullptr) ? false : true;
}

template <typename typeData>
typeData ListIterBase <typeData>::getCur()
{
    return ptrCur->getData();
}

template <typename typeData>
ListIterBase <typeData>::~ListIterBase()
{
    this->ptrCur = nullptr;
}

template <typename typeData>
ListIterBase <typeData>& ListIterBase <typeData>::operator = (ListIterBase& listIter)
{
    if (this != &listIter)
        this->ptrCur = listIter.ptrCur;
    
    return *this;
}

template <typename typeData>
ListIterBase <typeData>& ListIterBase <typeData>::operator = (ListNode <typeData>& node)
{
    this->ptrCur = &node;
    return *this;
}

template <typename typeData>
ListIterBase <typeData>& ListIterBase <typeData>::operator ++ ()
{
    this->next();
    return *this;
}

template <typename typeData>
ListIterBase <typeData>& ListIterBase <typeData>::operator ++ (int)
{
    ListIterBase <typeData> tmp(this);
    this->next();
    return tmp;
}

template <typename typeData>
bool ListIterBase <typeData>::operator == (const ListIterBase <typeData>& listIter) const
{
    return this->ptrCur == listIter.ptrCur;
}

template <typename typeData>
bool ListIterBase <typeData>::operator != (const ListIterBase <typeData>& listIter) const
{
    return this->ptrCur != listIter.ptrCur;
}
