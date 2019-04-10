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

template <typename typeData>
class List
{
private:
    size_t sizeList;
    ListNode <typeData>* head;
    
    ListNode <typeData>* initNode(typeData data, ListNode <typeData>* ptrNode = nullptr);
    
public:
    List();
    List(const typeData data, const size_t countData = 1);
    explicit List(const List& someList);
    List(const typeData* arr, const size_t sizeArr);
    virtual ~List();
    
    size_t size() const;
    bool isEmpty() const;
    
    void append(typeData data);
    void insert(typeData data, size_t position = 0);
    void extend(const List& ListToAdd);
    
    void remove(typeData dataToSearch);
    typeData pop(size_t position = 0);
    void clear();
    
    void index(typeData dataToSearch) const;
    size_t count(typeData dataToSearch) const;
    
    void reverse();
    void sort(bool reverse = false); // pointer to function
    List* copy() const;
protected:
};

#endif /* list_hpp */
