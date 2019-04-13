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
    
    /*ListNode <int> A;
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
        cout << "!" << endl;*/
    
    List <int> list0;
    List <int> list1(list0);
    List <int> list2(10, 10);
    List <int> list3(10);
    List <int> list4(10, 10);
    list4.append(10);
    List <int> list5(list3);
    List <int> list6;
    list4.extend(list6);
    list6.append(11);
    list6.append(11);
    list4.extend(list6);
    
    List <int> list7;
    list7.append(10);
    list7.showList();
    list7.clear();
    list7.showList();
    
    List <int> list8(list2);
    list8.extend(list6);
    list8.showList();
    
    List <int> list9(list2);
    list9.showList();
    list9.append(5);
    list9.showList();
    list9.remove(5);
    list9.showList();
    cout << list9.pop() << endl;
    list9.showList();
    list9.append(10);
    cout << list9.index(10) << endl;
    list9.showList();
    cout << list9.count(10) << endl;
    list9.showList();
    list9.reverse();
    list9.showList();
    // list9.append(-10);
    list9.showList();
    list9.sort();
    list9.showList();
    list9.sort(true);
    list9.showList();
    
    List <int> list10(list8);
    list10.showList();
    list10 = list9;
    list10.showList();
    list10 += list8;
    list10.showList();
    if (list10 == list10)
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;
    if (list10 == list9)
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;
    list10 += 10;
    list10.showList();
    --list10;
    list10.showList();
    list10 += 10;
    list10.showList();
    list10--;
    list10.showList();
    list10 += list10;
    list10.showList();
    list10 = list10;
    list10.showList();
    
    List <int> list11 = list10;
    list11.showList();
    list11 = list10;
    list11.showList();
    
    List <int> list12(10, 0);
    list12.showList();
    
    // cout << list12 << endl;
    
    /*List <int> list5(list3);
    list5.showList();
    list5.insert(0, 0);
    list5.showList();
    list5.insert(-1, -1);
    list5.showList();
    list5.insert(-10, -10);
    list5.showList();
    list5.insert(11, 11);
    list5.showList();
    list5.insert(2, 2);
    list5.showList();*/
    
    /*list0.showList();
    list1.showList();
    list2.showList();
    list3.showList();
    list4.showList();
    list5.showList();
    list6.showList();*/
    
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
