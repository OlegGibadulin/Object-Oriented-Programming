//
//  list.hpp
//  lab_02
//
//  Created by Mac-HOME on 08/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#ifndef list_hpp
#define list_hpp

#include "errors.hpp"
#include "listnode.hpp"
#include "listiterator.hpp"
#include <iostream>

template <typename typeData>
class List
{
public:
    List();
    List(const typeData data, const size_t countData = 1);
    List(const List& someList);
    virtual ~List();
    
    size_t size() const;
    bool isEmpty() const;
    
    void append(typeData data);
    void insert(typeData data, int posToAdd = 0);
    void extend(const List& ListToAdd);
    
    void remove(typeData dataToSearch);
    typeData pop(int posToDel = -1);
    void clear();
    
    size_t index(typeData dataToSearch) const;
    size_t count(typeData dataToSearch) const;
    
    void reverse();
    void sort(bool reverse = false);
    
    List& operator = (const List& someList);
    List& operator += (const List& someList);
    List& operator += (const typeData dataToAdd);
    List& operator -= (const typeData dataToAdd);
    
    bool operator == (const List& someList) const;
    bool operator != (const List& someList) const;
    
    void begin(ListIter <typeData>& iter);
    void end(ListIter <typeData>& iter);
    void begin(ConstListIter <typeData>& iter) const;
    void end(ConstListIter <typeData>& iter) const;
private:
    size_t sizeList;
    ListNode <typeData>* head;
    
    ListNode <typeData>* initNode(typeData data, ListNode <typeData>* ptrNode = nullptr);
    void deleteNode(ListNode <typeData>* cur, ListNode <typeData>* tmp);
    void addList(const List& ListToAdd);
    bool increaseCmp(typeData lData, typeData rData) const;
    bool decreaseCmp(typeData lData, typeData rData) const;
    bool isNodesEqual(const List& someList) const;
protected:
};

#endif /* list_hpp */
