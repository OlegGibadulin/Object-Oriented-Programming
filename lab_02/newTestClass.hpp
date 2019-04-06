//
//  newTestClass.hpp
//  lab_02
//
//  Created by Mac-HOME on 06/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#ifndef newTestClass_hpp
#define newTestClass_hpp

#include <iostream>

class A
{
public:
    virtual void showMsg() = 0;
};

class B : public A
{
public:
    void showMsg();
};

class C : public A
{
public:
    void showMsg();
};

class D
{
private:
    int count;
public:
    D();
    friend int operator+(D firstParam, D secondParam)
    {
        int sum = firstParam.count + secondParam.count;
        return sum;
    }
    friend int operator+(int count, D secondParam)
    {
        int sum = count + secondParam.count;
        return sum;
    }
    void funcOut();
};

class TestStaticClass
{
private:
    static int count;
public:
    void funcOut();
    void func();
    // static void testFunc();
};

// оператор присваивания

class SomeTestClass
{
private:
    int x;
public:
    SomeTestClass() : x(10) {};
    SomeTestClass& operator = (const SomeTestClass& a);
    void funcOut();
};

// конструктор копирования

class SomeTestClassA
{
private:
    int x;
public:
    SomeTestClassA() : x(10) {};
    SomeTestClassA(const SomeTestClassA& a);
    void funcOut();
};

#endif /* newTestClass_hpp */
