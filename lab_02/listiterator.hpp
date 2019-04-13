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
    ListIter(const ListIter& listIter);
    
    ListIter& operator * ();
    ListIter& operator -> ();
};

#endif /* listiterator_hpp */
