//
//  listiterator.cpp
//  lab_02
//
//  Created by Mac-HOME on 13/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#include "listiterator.hpp"

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
    ptrCur = this->ptrCur->getNext();
}

template <typename typeData>
bool ListIterBase <typeData>::isInRange() const
{
    return (this->ptrCur == nullptr) ? false : true;
}

template <typename typeData>
ListIterBase <typeData>::~ListIterBase()
{
    this->ptrCur = nullptr;
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

// ListIter

template <typename typeData>
ListIter <typeData>::ListIter()
{
    this->ptrCur = nullptr;
}

template <typename typeData>
ListIter <typeData>::ListIter(const ListIter <typeData>& listIter)
{
    this->ptrCur = listIter.ptrCur;
}

template <typename typeData>
ListIter <typeData>::ListIter(const ListNode <typeData>& node)
{
    this->ptrCur = node;
}

template <typename typeData>
ListIter <typeData>& ListIter <typeData>::operator = (ListIter& listIter)
{
    if (this != &listIter)
        this->ptrCur = listIter.ptrCur;
    
    return *this;
}

template <typename typeData>
ListIter <typeData>& ListIter <typeData>::operator = (ListNode <typeData>& node)
{
    this->ptrCur = &node;
    return *this;
}

template <typename typeData>
typeData ListIter <typeData>::getCur() const
{
    return this->ptrCur->getData();
}

template <typename typeData>
ListIter <typeData>& ListIter <typeData>::operator * () const
{
    return *this->ptrCur;
}

template <typename typeData>
ListIter <typeData>& ListIter <typeData>::operator -> () const
{
    return this->ptrCur;
}

// ConstListIter

template <typename typeData>
ConstListIter <typeData>::ConstListIter()
{
    this->ptrCur = nullptr;
}

template <typename typeData>
ConstListIter <typeData>::ConstListIter(const ConstListIter <typeData>& ClistIter)
{
    this->ptrCur = ClistIter.ptrCur;
}

template <typename typeData>
ConstListIter <typeData>::ConstListIter(const ListNode <typeData>& node)
{
    this->ptrCur = node;
}

template <typename typeData>
ConstListIter <typeData>& ConstListIter <typeData>::operator = (ConstListIter& listIter)
{
    if (this != &listIter)
        this->ptrCur = listIter.ptrCur;
    
    return *this;
}

template <typename typeData>
ConstListIter <typeData>& ConstListIter <typeData>::operator = (ListNode <typeData>& node)
{
    this->ptrCur = &node;
    return *this;
}

template <typename typeData>
const typeData ConstListIter <typeData>::getCur() const
{
    return this->ptrCur->getData();
}

template <typename typeData>
const ConstListIter <typeData>& ConstListIter <typeData>::operator * () const
{
    return *this->ptrCur;
}

template <typename typeData>
const ConstListIter <typeData>& ConstListIter <typeData>::operator -> () const
{
    return this->ptrCur;
}
