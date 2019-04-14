//
//  listiteratorbase.hpp
//  lab_02
//
//  Created by Mac-HOME on 13/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#ifndef listiteratorbase_hpp
#define listiteratorbase_hpp

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
    bool isInRange();
    typeData getCur();
    
    ListIterBase& operator = (ListIterBase& listIter);
    ListIterBase& operator = (ListNode <typeData>& node);
    ListIterBase& operator ++ ();
    ListIterBase& operator ++ (int);
    
    bool operator == (const ListIterBase& listIter) const;
    bool operator != (const ListIterBase& listIter) const;
protected:
    ListNode <typeData>* ptrCur;
};

#endif /* listiteratorbase_hpp */
