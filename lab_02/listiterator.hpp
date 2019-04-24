//
//  listiterator.cpp
//  lab_02
//
//  Created by Mac-HOME on 13/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#ifndef listiterator_hpp
#define listiterator_hpp

#include "listiterator.h"

template <typename typeData>
ListIterBase <typeData>::ListIterBase() : ptrCur(nullptr) {}

template <typename typeData>
ListIterBase <typeData>::ListIterBase(const ListIterBase <typeData>& listIter) : ptrCur(listIter.ptrCur) {}

template <typename typeData>
ListIterBase <typeData>::ListIterBase(const std::shared_ptr<ListNode<typeData>> node) : ptrCur(node) {}

template <typename typeData>
ListIterBase<typeData>::~ListIterBase() {}

template <typename typeData>
ListIterBase<typeData>& ListIterBase<typeData>::operator=(const ListIterBase<typeData>& listIter)
{
    this->ptrCur = listIter.ptrCur;
}

template <typename typeData>
void ListIterBase <typeData>::next()
{
    this->ptrCur = this->ptrCur->getNext();
}

template <typename typeData>
ListIterBase<typeData>& ListIterBase<typeData>::operator++()
{
    this->next();
    return *this;
}

template <typename typeData>
ListIterBase<typeData> ListIterBase<typeData>::operator++(int)
{
    ListIterBase<typeData> tmp(*this);
    this->operator++();
    return tmp;
}

template <typename typeData>
bool ListIterBase <typeData>::checkRange() const
{
    return (this->ptrCur == nullptr) ? false : true;
}

template <typename typeData>
bool ListIterBase<typeData>::operator==(const ListIterBase<typeData>& listIter) const
{
    return this->ptrCur == listIter.ptrCur;
}

template <typename typeData>
bool ListIterBase<typeData>::operator!=(const ListIterBase<typeData>& listIter) const
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
ListIter<typeData>::ListIter(const ListIter<typeData>& listIter)
{
    this->ptrCur = listIter.ptrCur;
}

template <typename typeData>
ListIter<typeData>::ListIter(const std::shared_ptr<ListNode<typeData>> node)
{
    this->ptrCur = node;
}

template <typename typeData>
ListIter<typeData>& ListIter <typeData>::operator=(const ListIter<typeData>& listIter)
{
    if (this != &listIter)
        this->ptrCur = listIter.ptrCur;
    
    return *this;
}

template <typename typeData>
typeData& ListIter <typeData>::getCur()
{
    return this->ptrCur->getPtrData();
}

template <typename typeData>
const typeData& ListIter <typeData>::getCur() const
{
    return this->ptrCur->getPtrData();
}

template <typename typeData>
typeData& ListIter <typeData>::operator * ()
{
    return this->ptrCur->getPtrData();
}

template <typename typeData>
const typeData& ListIter <typeData>::operator * () const
{
    return this->ptrCur->getPtrData();
}

template <typename typeData>
typeData* ListIter <typeData>::operator -> ()
{
    return &this->ptrCur->getPtrData();
}

template <typename typeData>
const typeData* ListIter <typeData>::operator -> () const
{
    return &this->ptrCur->getPtrData();
}

// ConstListIter

template <typename typeData>
ConstListIter <typeData>::ConstListIter()
{
    this->ptrCur = nullptr;
}

template <typename typeData>
ConstListIter <typeData>::ConstListIter(const ConstListIter <typeData>& listIter)
{
    this->ptrCur = listIter.ptrCur;
}

template <typename typeData>
ConstListIter<typeData>::ConstListIter(const std::shared_ptr<ListNode<typeData>> node)
{
    this->ptrCur = node;
}

template <typename typeData>
ConstListIter<typeData>& ConstListIter <typeData>::operator=(const ConstListIter<typeData>& listIter)
{
    if (this != &listIter)
        this->ptrCur = listIter.ptrCur;
    
    return *this;
}

template <typename typeData>
const typeData& ConstListIter<typeData>::getCur() const
{
    return this->ptrCur->getPtrData();
}

template <typename typeData>
const typeData& ConstListIter <typeData>::operator * () const
{
    return this->ptrCur->getPtrData();
}

template <typename typeData>
const typeData* ConstListIter <typeData>::operator -> () const
{
    return &this->ptrCur->getPtrData();
}

#endif /* listiterator_hpp */
