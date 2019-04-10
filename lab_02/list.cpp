//
//  list.cpp
//  lab_02
//
//  Created by Mac-HOME on 08/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#include "list.hpp"

template <typename typeData>
ListNode <typeData>* List <typeData>::initNode(typeData data, ListNode<typeData> *ptrNode)
{
    ListNode <typeData>* newNode = new ListNode <typeData>;
    if (!newNode)
        throw MemoryError();
    newNode->setData(data);
    newNode->setNext(ptrNode);
    this->sizeList += 1;
    
    return newNode;
}

template <typename typeData>
List <typeData>::List()
{
    this->head = nullptr;
    this->sizeList = 0;
}

template <typename typeData>
List <typeData>::List(const typeData data, const size_t countData)
{
    ListNode <typeData>* newHead = new ListNode <typeData>;
    if (!newHead)
        throw MemoryError();
    newHead->setData(data);
    newHead->setNext(nullptr);
    this->head = newHead;
    
    ListNode <typeData> *cur = this->head;
    
    for (size_t i = 1; i < countData; ++i, cur = cur->getNext())
    {
        ListNode <typeData>* newNode = new ListNode <typeData>;
        if (!newNode)
            throw MemoryError();
        newNode->setData(data);
        newNode->setNext(nullptr);
        cur->setNext(newNode);
    }
    this->sizeList = countData;
}

template <typename typeData>
List <typeData>::List(const List <typeData>& someList)
{
    if (!someList.head)
    {
        this->head = nullptr;
    }
    else
    {
        ListNode <typeData>* newHead = new ListNode <typeData>;
        if (!newHead)
            throw MemoryError();
        newHead->setData(someList.head->getData());
        newHead->setNext(someList.head->getNext());
        this->head = newHead;
        this->sizeList += 1;
        
        ListNode <typeData> *cur = someList.head->getNext();
        
        for (; cur; cur = cur->getNext())
        {
            ListNode <typeData>* newNode = new ListNode <typeData>;
            if (!newNode)
                throw MemoryError();
            newNode->setData(cur->getData());
            newNode->setNext(cur->getNext());
            this->sizeList += 1;
        }
    }
}

template <typename typeData>
List <typeData>::List(const typeData* arr, const size_t sizeArr)
{
    if (arr == nullptr)
        throw DataError();
    
    ListNode <typeData>* newHead = new ListNode <typeData>;
    if (!newHead)
        throw MemoryError();
    newHead->setData(arr[0]);
    newHead->setNext(nullptr);
    this->head = newHead;
    
    ListNode <typeData> *cur = this->head;
    
    for (size_t i = 1; i < sizeArr; ++i, cur = cur->getNext())
    {
        ListNode <typeData>* newNode = new ListNode <typeData>;
        if (!newNode)
            throw MemoryError();
        newNode->setData(arr[i]);
        newNode->setNext(nullptr);
        cur->setNext(newNode);
    }
    this->sizeList = sizeArr;
}

template <typename typeData>
List <typeData>::~List()
{
    if (this->head)
    {
        ListNode <typeData>* next;
        for (; this->head; this->head = next)
        {
            next = this->head->getNext();
            delete this->head;
        }
    }
    this->head = nullptr;
    this->sizeList = 0;
}

template <typename typeData>
size_t List <typeData>::size() const
{
    return sizeList;
}

template <typename typeData>
bool List <typeData>::isEmpty() const
{
    return (sizeList == 0) ? true : false;
}

template <typename typeData>
void List <typeData>::append(typeData data)
{
    ListNode <typeData>* newNode = initNode(data);
    
    if (this->isEmpty())
    {
        this->head = newNode;
    }
    else
    {
        ListNode <typeData> *cur = this->head;
        for (; cur->getNext(); cur = cur->getNext());
        cur->setNext(newNode);
    }
}

template <typename typeData>
void List <typeData>::insert(typeData data, size_t position)
{
    ;
}

template <typename typeData>
void List <typeData>::extend(const List& ListToAdd)
{
    ;
}

template <typename typeData>
void List <typeData>::remove(typeData dataToSearch)
{
    ;
}

template <typename typeData>
typeData List <typeData>::pop(size_t position)
{
    ;
}

template <typename typeData>
void List <typeData>::clear()
{
    ;
}

template <typename typeData>
void List <typeData>::index(typeData dataToSearch) const
{
    ;
}

template <typename typeData>
size_t List <typeData>::count(typeData dataToSearch) const
{
    ;
}

template <typename typeData>
void List <typeData>::reverse()
{
    ;
}

template <typename typeData>
void List <typeData>::sort(bool reverse)
{
    ;
}

template <typename typeData>
List <typeData>* List <typeData>::copy() const
{
    ;
}
