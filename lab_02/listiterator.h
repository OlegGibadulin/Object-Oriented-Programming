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
    explicit ListIterBase(ListIterBase& listIter);
    explicit ListIterBase(ListNode <typeData>& node);
    virtual ~ListIterBase();
    
    void next();
    bool isInRange() const; // check
    
    ListIterBase<typeData>& operator ++ ();
    ListIterBase operator ++ (int);
    
    bool operator == (const ListIterBase& listIter) const;
    bool operator != (const ListIterBase& listIter) const;
protected:
    ListNode <typeData>* ptrCur; // smart ptr
};

template <typename typeData>
class ListIter : public ListIterBase <typeData>
{
public:
    ListIter();
    ListIter(const ListIter& listIter);
    ListIter(const ListNode <typeData>& node);
    
    ListIter& operator = (ListIter& listIter);
    ListIter& operator = (ListNode <typeData>& node);
    
    typeData getCur() const;
    // const typeData& operator * () const; // const data
    typeData& operator *() const;
    typeData* operator -> () const;
};

template <typename typeData>
class ConstListIter : public ListIterBase <typeData>
{
public:
    ConstListIter();
    ConstListIter(const ConstListIter& ClistIter);
    ConstListIter(const ListNode <typeData>& node);
    
    ConstListIter& operator = (ConstListIter& listIter);
    ConstListIter& operator = (ListNode <typeData>& node);
    
    const typeData getCur() const;
    const ConstListIter& operator * () const;
    const ConstListIter& operator -> () const;
};

#endif /* listiterator_h */
