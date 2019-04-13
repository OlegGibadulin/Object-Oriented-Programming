//
//  listiterator.cpp
//  lab_02
//
//  Created by Mac-HOME on 13/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#include "listiterator.hpp"

template <typename typeData>
ListIter <typeData>& ListIter <typeData>::operator * ()
{
    return *this->ptr;
}

template <typename typeData>
ListIter <typeData>& ListIter <typeData>::operator -> ()
{
    return this->ptr;
}
