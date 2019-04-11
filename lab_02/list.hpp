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
#include <iostream>

template <typename typeData>
class List
{
private:
    size_t sizeList;
    ListNode <typeData>* head;
    
    ListNode <typeData>* initNode(typeData data, ListNode <typeData>* ptrNode = nullptr);
    void deleteNode(ListNode <typeData>* cur, ListNode <typeData>* tmp);
    bool increaseCmp(typeData lData, typeData rData) const;
    bool decreaseCmp(typeData lData, typeData rData) const;
    
public:
    List();
    List(const typeData data, const size_t countData = 1);
    explicit List(const List& someList);
    List(const typeData* arr, const size_t sizeArr);
    virtual ~List();
    
    void showList()
    {
        if (this->head == nullptr)
        {
            std::cout << "nullptr" << std::endl;
            return;
        }
        ListNode <typeData>* cur = this->head;
        for (; cur; cur = cur->getNext())
            std::cout << cur->getData() << " ";
        std::cout << "\n";
    }
    
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
protected:
};

#endif /* list_hpp */
