//
//  listiterator.cpp
//  lab_02
//
//  Created by Mac-HOME on 13/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#include "listiterator.hpp"

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
ListIter <typeData>& ListIter <typeData>::operator * () const
{
    return *this->ptrCur;
}

template <typename typeData>
ListIter <typeData>& ListIter <typeData>::operator -> () const
{
    return this->ptrCur;
}
