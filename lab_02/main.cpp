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
    cout << "Тестировние списка одностороннего доступа" << endl;
    
    /*List <int> list0(5, 0, 1, 2, 3, 4);
    List <int> list1(list0);
    List <int> list2 = {0, 1, 2, 3, 4};
    int a = 10;
    List <int> list3 = {a};*/
    
    /*ListIterBase<int> iter;
    ListNode<int> node(10);
    ListIterBase<int> iter0(node);*/
    
    ListNode <int> node0;
    ListNode <int> node1(1);
    ListNode <int> node2(node1);
    ListNode <int>* ptrNode = new ListNode<int>;
    ListNode <int> node3(3, ptrNode);
    
    cout << node2.getData() << endl;
    node1.setNext(ptrNode);
    
    try
    {
        cout << "\n\nКонстуркторы" << endl;
        
        /*int a = 10;
        List <int> list3 = {a};
        list3.clear();*/
        
        /*List <int> list0;
        List <int> list1(0, 10);
        List <int> list2(list1);
        List <double> list3(3, 0.1, 0.2, 0.4);
        
        cout << "\n * Констурктор по умолчанию" << endl;
        cout << list0 << endl;
        
        cout << "\n * Констуркторы с параметрами" << endl;
        cout << list1 << endl;
        cout << list2 << endl;
        cout << list3 << endl;
        
        cout << "\n * Констурктор копирования" << endl;
        list0 = list1;
        cout << list0 << endl;
        
        cout << "\n\nДобавления элементов" << endl;
        
        List <int> list4;
        List <int> list5;
        List <int> list6;
        
        cout << "\n * append(data)" << endl;
        cout << list4 << endl;
        list4.append(11);
        cout << list4 << endl;
        list4.append(12);
        cout << list4 << endl;
        
        cout << "\n * insert(data, pos)" << endl;
        cout << list5 << endl;
        list5.insert(11);
        cout << list5 << endl;
        list5.insert(12);
        cout << list5 << endl;
        list5.insert(13, 2);
        cout << list5 << endl;
        list5.insert(14, -1);
        cout << list5 << endl;
        
        cout << "\n * extend(list)" << endl;
        cout << list6 << endl;
        list6.extend(list6);
        cout << list6 << endl;
        list6.extend(list4);
        cout << list6 << endl;
        list6.extend(list6);
        cout << list6 << endl;
        
        cout << "\n\nПоиск" << endl;
        cout << "\n * index(data)" << endl;
        cout << list4.index(11) << endl;
        cout << list6.index(12) << endl;
        
        cout << "\n * count(data)" << endl;
        cout << list4.count(13) << endl;
        cout << list4.count(12) << endl;
        cout << list6.count(11) << endl;
        
        cout << "\n\nСортировка" << endl;
        list6.extend(list5);
        List <int> list7(list6);
        cout << list7 << endl;
        
        list7.sort();
        cout << list7 << endl;
        list7.sort(true);
        cout << list7 << endl;
        list7 = list6;
        
        cout << "\n\nПереворот" << endl;
        cout << list6 << endl;
        list6.reverse();
        cout << list6 << endl;
        
        cout << "\n\nУдаление элементов" << endl;
        cout << list7 << endl;
        
        cout << "\n * remove(data)" << endl;
        list7.remove(14);
        cout << list7 << endl;
        
        cout << "\n * pop(pos)" << endl;
        list7.pop();
        cout << list7 << endl;
        list7.pop(4);
        cout << list7 << endl;
        list7.pop(-2);
        cout << list7 << endl;
        
        cout << "\n * clear()" << endl;
        
        cout << "\n\nДругие методы" << endl;
        cout << list6.size() << endl;
        cout << list7.size() << endl;
        if (list7.isEmpty())
            cout << "list7 is empty" << endl;
        if (list6 != list7)
            cout << "list6 not equal list7" << endl;
        list7 += list6;
        cout << list7 << endl;
        list7 += 15;
        cout << list7 << endl;
        list7 -= 15;
        cout << list7 << endl;
        
        list7.clear();
        list7.pop();*/
    }
    catch(ErrorBase& error)
    {
        cout << error.what() << endl;
    }
    
    return 0;
}
