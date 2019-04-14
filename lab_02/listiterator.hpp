//
//  listiterator.hpp
//  lab_02
//
//  Created by Mac-HOME on 13/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#ifndef listiterator_hpp
#define listiterator_hpp

#include "listnode.hpp"

template <typename typeData>
class ListIterBase
{
public:
    ListIterBase();
    explicit ListIterBase(ListIterBase& listIter);
    explicit ListIterBase(ListNode <typeData>& node);
    
    virtual ~ListIterBase();
    
    void next();
    bool isInRange() const;
    
    ListIterBase& operator ++ ();
    ListIterBase& operator ++ (int);
    
    bool operator == (const ListIterBase& listIter) const;
    bool operator != (const ListIterBase& listIter) const;
protected:
    ListNode <typeData>* ptrCur;
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
    ListIter& operator * () const;
    ListIter& operator -> () const;
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

#endif /* listiterator_hpp */
