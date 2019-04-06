//
//  newTestClass.cpp
//  lab_02
//
//  Created by Mac-HOME on 06/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#include "newTestClass.hpp"

void B::showMsg()
{
    std::cout << "B" << std::endl;
}

void C::showMsg()
{
    std::cout << "C" << std::endl;
}

D::D() : count(10)
{
    ;
}

void D::funcOut()
{
    std::cout << count << std::endl;
}

int TestStaticClass::count = 0;

void TestStaticClass::funcOut()
{
    std::cout << "string static " << count << std::endl;
}

void TestStaticClass::func()
{
    count += 1;
}

/*void TestStaticClass::testFunc()
{
    count += 1;
}*/

SomeTestClass& SomeTestClass::operator = (const SomeTestClass& a)
{
    x = a.x;
    std::cout << "string = " << std::endl;
    return *this;
}

void SomeTestClass::funcOut()
{
    std::cout << x << std::endl;
}

SomeTestClassA::SomeTestClassA(const SomeTestClassA& a)
{
    x = a.x;
    std::cout << "string copy " << std::endl;
}

void SomeTestClassA::funcOut()
{
    std::cout << x << std::endl;
}
