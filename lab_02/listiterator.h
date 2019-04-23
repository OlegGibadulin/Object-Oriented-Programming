//
//  listiterator.hpp
//  lab_02
//
//  Created by Mac-HOME on 13/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

// h
// hpp

#ifndef listiterator_h
#define listiterator_h

#include "listnode.h"

template <typename typeData>
class ListIterBase
{
public:
    ListIterBase();
    ListIterBase(const ListIterBase<typeData>& listIter);
    ListIterBase(ListNode<typeData>* node);
    virtual ~ListIterBase();
    
    ListIterBase<typeData>& operator=(const ListIterBase<typeData>& listIter);
    
    void next();
    ListIterBase<typeData>& operator++();
    ListIterBase<typeData> operator++(int);
    
    bool checkRange() const;
    
    bool operator==(const ListIterBase<typeData>& listIter) const;
    bool operator!=(const ListIterBase<typeData>& listIter) const;
protected:
    std::shared_ptr <ListNode<typeData>> ptrCur;
};

template <typename typeData>
class ListIter : public ListIterBase <typeData>
{
public:
    ListIter();
    ListIter(const ListIter<typeData>& listIter);
    ListIter(std::shared_ptr<ListNode<typeData>> node);
    
    ListIter& operator=(ListIter<typeData>& listIter);
    
    typeData& getCur();
    const typeData& getCur() const;
    
    typeData& operator*();
    const typeData& operator*() const;
    
    typeData* operator->();
    const typeData* operator->() const;
};

template <typename typeData>
class ConstListIter : public ListIterBase <typeData>
{
public:
    ConstListIter();
    ConstListIter(const ConstListIter<typeData>& ClistIter);
    ConstListIter(ListNode<typeData>* node);
    
    ConstListIter<typeData>& operator=(ConstListIter<typeData>& listIter);
    
    const typeData& getCur() const;
    const typeData& operator*() const;
    const typeData* operator->() const;
};

#endif /* listiterator_h */