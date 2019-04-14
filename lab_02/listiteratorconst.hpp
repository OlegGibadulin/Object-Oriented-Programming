//
//  listiteratorconst.hpp
//  lab_02
//
//  Created by Mac-HOME on 13/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#ifndef listiteratorconst_hpp
#define listiteratorconst_hpp

#include "listiteratorbase.hpp"

template <typename typeData>
class ConstListIter
{
public:
    ConstListIter();
    ConstListIter(const ConstListIter& ClistIter);
    ConstListIter(const ListNode <typeData>& node);
    
    void next();
    bool isInRange();
    typeData getCur();
private:
    ListNode <typeData>* ptrCur;
};

#endif /* listiteratorconst_hpp */
