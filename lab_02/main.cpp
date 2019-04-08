//
//  main.cpp
//  lab_02
//
//  Created by Mac-HOME on 08/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#include "main.hpp"

int main()
{
    cout << "Тестировние списка одностороннего доступа\n" << endl;
    
    ListNode <int> A;
    ListNode <int> B(10);
    ListNode <int> C(B);
    ListNode <int> D(B.getData(), C);
    ListNode <int> E = D;
    ListNode <float> F(10.0);
    
    C = D;
    C.delNext();
    if (C.getNext() == &B)
        cout << "saklfjaslk" << endl;
    
    cout << A.getData() << " " << B.getData() << " " << C.getData() << " " << D.getData() << " " << endl;
    
    cout << E.getData() << endl;
    
    if (E == D)
        cout << "!" << endl;
    
    /*try
    {
        cout << "Констурктуры" << endl;
        
        cout << "Добавления элементов" << endl;
        
        cout << "Удаление элементов" << endl;
        
        cout << "Сортировка по возрастанию" << endl;
        
        cout << "Сортировка по убыванию" << endl;
        
        cout << "Переворот" << endl;
        
        cout << "Склейка" << endl;
        
        cout << "" << endl;
    }
    catch(std::exception error)
    {
        cout << error.what() << endl;
    }*/
    
    return 0;
}
