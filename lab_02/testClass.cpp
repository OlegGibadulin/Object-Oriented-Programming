//
//  testClass.cpp
//  lab_02
//
//  Created by Mac-HOME on 06/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#include "testClass.hpp"

const double TestClass::pi = 3.14;

TestClass::TestClass(int x) : c1(x), c2(10)
{
    std::cout << "string" << std::endl;
}

TestClass::TestClass() : c1(10), c2(10)
{
    std::cout << "const string" << std::endl;
}

TestClass::~TestClass()
{
    std::cout << "~string" << std::endl;
}

void TestClass::funcOut() const
{
    std::cout << c1 <<  " " << c2 << std::endl;
}

/*void TestClass::operator++()
{
    ++c1;
}*/

TestClass TestClass::operator++()
{
    ++c1;
    /*TestClass obj;
    obj.c1 = c1;
    return obj;*/
    return TestClass (c1);
}

TestClass TestClass::operator++(int)
{
    c1++;
    return TestClass (c1);
}

/*int TestClass::operator+(TestClass secondObj)
{
    return c1 + secondObj.c1;
}

int TestClass::operator+(int secondDigit)
{
    return c1 + secondDigit;
}*/

TestClass TestClass::operator+(TestClass secondObj) const
{
    int sum = c1 + secondObj.c1;
    return TestClass (sum);
}

void TestClass::operator+=(int x)
{
    c1 += x;
}

void TestClass::stringOut() const
{
    std::cout << someStr[0] << std::endl;
}

char& TestClass::operator[](const int n)
{
    return someStr[n];
}

TestClass::operator double()
{
    return pi;
}

SubTestClass::SubTestClass() : TestClass()
{
    std::cout << "sub string" << std::endl;
}

SubTestClass::SubTestClass(int x) : TestClass(x)
{
    std::cout << "sub string" << std::endl;
}

SubTestClass::~SubTestClass()
{
    std::cout << "~ sub string" << std::endl;
}

void SubTestClass::funcOut()
{
    std::cout << "sub string" << " " << c1 << " " << c2 << std::endl;
}

void AnotherTestClass::funcOut()
{
    obj.funcOut();
    std::cout << "another string" << std::endl;
}

void SubAnotheTestClass::showMsg()
{
    std::cout << "msg" << std::endl;
}
