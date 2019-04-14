//
//  listiterator.hpp
//  lab_02
//
//  Created by Mac-HOME on 13/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#ifndef listiterator_hpp
#define listiterator_hpp

#include "listiteratorbase.hpp"

template <typename typeData>
class ListIter : public ListIterBase <typeData>
{
public:
    ListIter(const ListIter& listIter);
    // ListIter(const ListNode <typeData>& node);
    
    ListIter& operator * ();
    ListIter& operator -> ();
};

#endif /* listiterator_hpp */
