//
//  listiteratorconst.hpp
//  lab_02
//
//  Created by Mac-HOME on 13/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#ifndef listiteratorconst_hpp
#define listiteratorconst_hpp

#include "listiteratorbase.cpp"

template <typename typeData>
class ConstListIter
{
public:
    ConstListIter();
    ConstListIter(const ConstListIter& ClistIter);
    ConstListIter(const ListNode <typeData>& node);
    
    const ConstListIter& operator * () const;
    const ConstListIter& operator -> () const;
};

#endif /* listiteratorconst_hpp */
