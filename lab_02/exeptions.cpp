//
//  exeptions.cpp
//  lab_02
//
//  Created by Mac-HOME on 08/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#include "exeptions.hpp"

void TestExeption::func()
{
    int a;
    std::cin >> a;
    if (a == 0)
        throw ExeptionClass();
}
