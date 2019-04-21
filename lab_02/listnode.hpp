//
//  listnode.cpp
//  lab_02
//
//  Created by Mac-HOME on 08/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#ifndef listnode_hpp
#define listnode_hpp

#include "listnode.h"

template <typename typeData>
ListNode<typeData>::ListNode() : data(0), next(nullptr) {}

template <typename typeData>
ListNode<typeData>::ListNode(const typeData data) : data(data), next(nullptr) {}

template <typename typeData>
ListNode<typeData>::ListNode(const ListNode& node) : data(node.data)
{
    this->next = node.getNext();
}

template <typename typeData>
ListNode<typeData>::ListNode(const typeData data, ListNode<typeData>* nextNode) : data(data), next(nextNode) {}

template <typename typeData>
ListNode<typeData>::~ListNode() {}

template <typename typeData>
void ListNode<typeData>::setData(const typeData data)
{
    this->data = data;
}

template <typename typeData>
typeData ListNode<typeData>::getData() const
{
    return this->data;
}

template <typename typeData>
void ListNode<typeData>::setNext(ListNode<typeData>* nextNode)
{
    this->next = nextNode;
}

template <typename typeData>
std::shared_ptr<ListNode<typeData>> ListNode<typeData>::getNext() const
{
    return this->next;
}

template <typename typeData>
bool ListNode<typeData>::operator==(const ListNode& secondNode) const
{
    return (this->data == secondNode.data) ? true : false;
}

template <typename typeData>
bool ListNode<typeData>::operator!=(const ListNode& secondNode) const
{
    return (this->data != secondNode.data) ? true : false;
}

template <typename typeData>
bool ListNode<typeData>::operator>(const ListNode& secondNode) const
{
    return (this->data > secondNode.data) ? true : false;
}

template <typename typeData>
bool ListNode<typeData>::operator<(const ListNode& secondNode) const
{
    return (this->data < secondNode.data) ? true : false;
}

template <typename typeData>
bool ListNode<typeData>::operator>=(const ListNode& secondNode) const
{
    return (this->data >= secondNode.data) ? true : false;
}

template <typename typeData>
bool ListNode<typeData>::operator<=(const ListNode& secondNode) const
{
    return (this->data <= secondNode.data) ? true : false;
}

#endif /* listnode_hpp */
