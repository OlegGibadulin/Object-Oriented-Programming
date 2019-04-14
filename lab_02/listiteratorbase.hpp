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
    ListIterBase(ListIterBase& listIter);
    ListIterBase(ListNode <typeData>& node);
    
    virtual ~ListIterBase();
    
    void next();
    bool isInRange();
    typeData getCur();
    
    ListIterBase& operator = (const ListIterBase& listIter);
    ListIterBase& operator ++ ();
    ListIterBase& operator ++ (int);
    
    bool operator == (const ListIterBase& listIter) const;
    bool operator != (const ListIterBase& listIter) const;
private:
protected:
    ListNode <typeData>* ptrCur;
};

#endif /* listiteratorbase_hpp */
