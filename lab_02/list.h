//
//  list.hpp
//  lab_02
//
//  Created by Mac-HOME on 08/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#ifndef list_h
#define list_h

#include "errors.h"
#include "listnode.h"
#include "listiterator.h"

#include <iostream>
#include <stdarg.h>

class BaseList
{
public:
    BaseList();
    virtual ~BaseList();
    
    size_t size() const;
protected:
    size_t sizeList;
};

template <typename typeData>
class List : public BaseList
{
public:
    List();
    List(const size_t countNodes, ...);
    explicit List(const List<typeData>& someList);
    List(List<typeData>&& someList);
    List(const typeData& data, const size_t countData = 1);
    List(const std::initializer_list<typeData>& someList);
    virtual ~List();
    
    List<typeData>& operator=(const List<typeData>& someList);
    List<typeData>& operator=(List<typeData>&& someList);
    
    List<typeData>& append(const typeData& data);
    List<typeData>& operator+=(const typeData& data);
    friend List<typeData>& operator+(const List<typeData>& list, const typeData& data);
    
    List<typeData>& insert(const typeData& data, ListIter<typeData>& iter);
    friend List<typeData>& operator+(const typeData& data, const List<typeData>& list);
    
    void extend(const List& ListToAdd);
    List<typeData>& operator += (const List<typeData>& someList);
    List<typeData>& operator+(const List<typeData>& list);
    
    typeData& pop();
    List<typeData>& operator--();
    List<typeData> operator--(int);
    
    typeData& remove(const typeData& data, ListIter<typeData>& iter);
    List<typeData>& operator-=(const typeData& dataToPop);
    
    void clear();
    
    bool operator == (const List<typeData>& someList) const;
    bool operator != (const List<typeData>& someList) const;
    
    ListIter<typeData> begin();
    ListIter<typeData> end();
    ConstListIter<typeData> begin() const;
    ConstListIter<typeData> end() const;
private:
    ListNode<typeData>* head;
    ListNode<typeData>* tail;
    
    ListNode<typeData>* initNode(const typeData& data, ListNode<typeData>* ptrNode = nullptr);
    void deleteNode(ListNode<typeData>* cur, ListNode<typeData>* tmp);
    void addList(const List<typeData>& ListToAdd);
    bool isNodesEqual(const List<typeData>& someList) const;
    bool isEmpty() const;
protected:
};

#endif /* list_h */
