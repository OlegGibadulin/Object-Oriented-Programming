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
void List <typeData>::deleteNode(ListNode<typeData> *cur, ListNode<typeData> *tmp)
{
    if (cur == this->head)
    {
        this->head = cur->getNext();
        delete(cur);
    }
    else
    {
        tmp->setNext(cur->getNext());
        delete(cur);
    }
    this->sizeList -= 1;
}

template <typename typeData>
List <typeData>::List() : sizeList(0)
{
    this->head = nullptr;
}

template <typename typeData>
List <typeData>::List(const typeData data, const size_t countData) : sizeList(0)
{
    this->head = initNode(data);
    ListNode <typeData> *cur = this->head;
    
    for (size_t i = 1; i < countData; ++i, cur = cur->getNext())
    {
        ListNode <typeData>* newNode = initNode(data);
        cur->setNext(newNode);
    }
}

template <typename typeData>
List <typeData>::List(const List <typeData>& someList) : sizeList(0)
{
    this->head = nullptr;
    this->extend(someList);
}

template <typename typeData>
List <typeData>::List(const typeData* arr, const size_t sizeArr) : sizeList(0)
{
    /*if (arr == nullptr)
        throw DataError();*/
    
    this->head = initNode(arr[0]);
    ListNode <typeData> *cur = this->head;
    
    for (size_t i = 1; i < sizeArr; ++i, cur = cur->getNext())
    {
        ListNode <typeData>* newNode = initNode(arr[i]);
        cur->setNext(newNode);
    }
}

template <typename typeData>
List <typeData>::~List()
{
    this->clear();
}

template <typename typeData>
size_t List <typeData>::size() const
{
    return sizeList;
}

template <typename typeData>
bool List <typeData>::isEmpty() const
{
    return (this->head == nullptr) ? true : false;
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
void List <typeData>::insert(typeData data, int posToAdd)
{
    if (posToAdd < 0)
        posToAdd = int (sizeList) + posToAdd;
    
    if (this->isEmpty() || posToAdd <= 0)
    {
        ListNode <typeData>* headNode = this->head;
        this->head = initNode(data, headNode);
    }
    else
    {
        ListNode <typeData> *cur = this->head;
        for (int i = 1; cur->getNext() && i < posToAdd; i++, cur = cur->getNext());
        ListNode <typeData>* nextNode = cur->getNext();
        ListNode <typeData>* newNode = initNode(data, nextNode);
        cur->setNext(newNode);
    }
}

template <typename typeData>
void List <typeData>::extend(const List& ListToAdd)
{
    if (ListToAdd.isEmpty())
        return;
    
    typeData data = ListToAdd.head->getData();
    ListNode <typeData>* nextNode = ListToAdd.head->getNext();
    ListNode <typeData>* nodeToAdd = initNode(data, nextNode);
    ListNode <typeData> *cur = this->head;
    
    if (this->isEmpty())
    {
        cur = nodeToAdd;
        this->head = cur;
    }
    else
    {
        for (; cur->getNext(); cur = cur->getNext());
        cur->setNext(nodeToAdd);
        cur = cur->getNext();
    }
    
    ListNode <typeData> *curToAdd = nextNode;
    
    for (; curToAdd; curToAdd = curToAdd->getNext(), cur = cur->getNext())
    {
        data = curToAdd->getData();
        nextNode = curToAdd->getNext();
        ListNode <typeData>* newNode = initNode(data, nextNode);
        cur->setNext(newNode);
    }
}

template <typename typeData>
void List <typeData>::remove(typeData dataToSearch)
{
    if (this->isEmpty())
        throw EmptyError();
    
    ListNode <typeData>* cur = this->head;
    ListNode <typeData>* tmp = this->head;
    
    for (; cur && cur->getData() != dataToSearch; tmp = cur, cur = cur->getNext());
    
    if (cur == nullptr)
        throw ValueError();
    
    deleteNode(cur, tmp);
}

template <typename typeData>
typeData List <typeData>::pop(int posToDel)
{
    if (this->isEmpty())
        throw EmptyError();
    
    if (std::abs(posToDel) >= int (sizeList))
        throw RangeError();
    
    ListNode <typeData>* cur = this->head;
    ListNode <typeData>* tmp = this->head;
    typeData retData;
    
    if (posToDel < 0)
        posToDel = int (sizeList) + posToDel;
    
    for (int i = 0; i != posToDel; tmp = cur, cur = cur->getNext(), ++i);
    retData = cur->getData();
    
    deleteNode(cur, tmp);
    
    return retData;
}

template <typename typeData>
void List <typeData>::clear()
{
    if (!this->isEmpty())
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
size_t List <typeData>::index(typeData dataToSearch) const
{
    if (this->isEmpty())
        throw EmptyError();
    
    ListNode <typeData>* cur = this->head;
    size_t index = 0;
    
    for (; cur && cur->getData() != dataToSearch; cur = cur->getNext(), ++index);
    
    if (cur == nullptr)
        throw ValueError();
    
    return index;
}

template <typename typeData>
size_t List <typeData>::count(typeData dataToSearch) const
{
    if (this->isEmpty())
        throw EmptyError();
    
    ListNode <typeData>* cur = this->head;
    size_t count = 0;
    
    for (; cur; cur = cur->getNext())
    {
        if (cur->getData() == dataToSearch)
            ++count;
    }
    
    return count;
}

template <typename typeData>
void List <typeData>::reverse()
{
    ListNode <typeData>* cur = this->head;
    ListNode <typeData>* curBack = nullptr;
    ListNode <typeData>* tmp;
    
    for (; cur; )
    {
        tmp = cur;
        cur = cur->getNext();
        tmp->setNext(curBack);
        curBack = tmp;
    }
    this->head = curBack;
}

template <typename typeData>
bool List <typeData>::increaseCmp(typeData lData, typeData rData) const
{
    return (lData > rData);
}

template <typename typeData>
bool List <typeData>::decreaseCmp(typeData lData, typeData rData) const
{
    return (lData < rData);
}

template <typename typeData>
void List <typeData>::sort(bool reverse)
{
    ListNode <typeData>* cur = this->head;
    ListNode <typeData>* curToFind;
    ListNode <typeData>* findPtr;
    typeData curData, findData;
    
    bool (List <typeData>::*cmpSort) (typeData lData, typeData rData) const;
    if (reverse)
        cmpSort = &List <typeData>::decreaseCmp;
    else
        cmpSort = &List <typeData>::increaseCmp;
    
    for (; cur; cur = cur->getNext())
    {
        findData = cur->getData();
        findPtr = cur;
        for (curToFind = cur; curToFind; curToFind = curToFind->getNext())
        {
            curData = curToFind->getData();
            if ((this->*cmpSort)(findData, curData))
            {
                findData = curData;
                findPtr = curToFind;
            }
        }
        if (cur != findPtr)
        {
            findPtr->setData(cur->getData());
            cur->setData(findData);
        }
    }
}
