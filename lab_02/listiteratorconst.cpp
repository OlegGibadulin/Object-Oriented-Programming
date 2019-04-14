
//
//  listiteratorconst.cpp
//  lab_02
//
//  Created by Mac-HOME on 13/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#include "listiteratorconst.hpp"

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
void ListIterBase <typeData>::next()
{
    this->curPtr = this->curPtr->getNext();
}

template <typename typeData>
bool ListIterBase <typeData>::isInRange()
{
    return (this->ptrCur == nullptr) ? false : true;
}

template <typename typeData>
typeData ListIterBase <typeData>::getCur()
{
    return this->ptrCur->getData;
}
