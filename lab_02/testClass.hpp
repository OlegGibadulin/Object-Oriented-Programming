//
//  testClass.hpp
//  lab_02
//
//  Created by Mac-HOME on 06/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#ifndef testClass_hpp
#define testClass_hpp

#include <stdio.h>
#include "iostream"

class TestClass
{
private:
    static const double pi;
    enum { SZ = 10 };
    char someStr[SZ] = "string";
protected:
    int c1, c2;
public:
    TestClass(int x);
    TestClass();
    ~TestClass();
    void funcOut() const;
    // void operator++();
    TestClass operator++();
    TestClass operator++(int);
    /*int operator+(TestClass secondObj);
    int operator+(int secondDigit);*/
    TestClass operator+(TestClass secondObj) const;
    void operator+=(int x);
    void stringOut() const;
    char& operator[](const int n);
    operator double();
};

class SubTestClass : public TestClass
{
public:
    SubTestClass();
    SubTestClass(int x);
    ~SubTestClass();
    void funcOut();
};

class AnotherTestClass
{
private:
    TestClass obj;
public:
    void funcOut();
};

class SubAnotheTestClass : public TestClass, public AnotherTestClass
{
public:
    void showMsg();
};

#endif /* testClass_hpp */
