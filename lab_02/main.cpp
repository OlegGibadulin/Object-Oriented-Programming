//
//  main.cpp
//  lab_02
//
//  Created by Mac-HOME on 05/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.

#include "main.hpp"

void func()
{
    TestStaticClass objS1;
    objS1.func();
}

int main(int argc, const char * argv[])
{
    // TestClass
    
    /*TestClass obj(10);
    obj.funcOut();
    
    TestClass obj1(obj);
    obj1.funcOut();
    
    TestClass obj2 = obj1;
    obj2.funcOut();
    
    const TestClass obj3;
    obj3.funcOut();
    
    TestClass obj4;
    TestClass obj5 = ++obj4;
    TestClass obj6 = obj4++;
    obj5++;
    obj4.funcOut();
    obj5.funcOut();
    obj6.funcOut();
    
    TestClass obj7 = obj4 + obj5 + obj6;
    obj7.funcOut();
    
    TestClass obj8;
    obj8 += 10;
    obj8.funcOut();
    
    TestClass obj9;
    obj9.stringOut();
    obj9[0] = 'a';
    obj9.stringOut();
    
    double piLocal = obj9;
    std::cout << piLocal << std::endl;*/
    
    // sub and multi sub
    
    /*SubTestClass obj10;
    obj10.funcOut();
    
    SubTestClass obj11(10);
    obj11.funcOut();
    
    SubAnotheTestClass obj12;
    obj12.AnotherTestClass::funcOut();*/
    
    // virtual functions
    
    /*B b;
    C c;
    A* ptr = &b;
    ptr->showMsg();
    ptr = &c;
    ptr->showMsg();*/
    
    // friend operator functions
    
    /*D objD1;
    D objD2;
    D objD3;
    std::cout << objD1 + objD2 + objD3 << std::endl;*/
    
    // static variable
    
    /*TestStaticClass objS1;
    objS1.func();
    objS1.funcOut();
    func();
    objS1.funcOut();*/
    
    // оператор присваивания
    
    /*SomeTestClass a;
    SomeTestClass b;
    b = a;
    b.funcOut();*/
    
    // конструктор копирования
    
    /*SomeTestClassA a1;
    SomeTestClassA b1(a1);
    SomeTestClassA c1 = b1;
    a1.funcOut();
    b1.funcOut();
    c1.funcOut();*/
    
    /*int tmp1 = 10;
    double tmp2 = 10.01;
    
    std::cout << abs(tmp1) << " " << abs(tmp2) << std::endl;
    
    double arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    double elem = 3;
    long size = 10;
    std::cout << findElem(arr, elem, size) << std::endl;*/
    
    // template
    
    /*StackTest <int> stackTest;
    stackTest.push(10);
    std::cout << stackTest.pop() << std::endl;*/
    
    return 0;
}
