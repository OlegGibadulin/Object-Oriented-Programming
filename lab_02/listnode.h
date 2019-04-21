//
//  listnode.hpp
//  lab_02
//
//  Created by Mac-HOME on 08/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#ifndef listnode_h
#define listnode_h

template <typename typeData>
class ListNode
{
public:
    ListNode();
    explicit ListNode(const typeData dataToAdd);
    ListNode(ListNode<typeData>& node);
    ListNode(const typeData data, ListNode<typeData>& nextNode);
    virtual ~ListNode();
    
    void setData(const typeData data);
    typeData getData() const;
    
    void setNext(ListNode<typeData>* nextNode);
    ListNode* getNext();
    
    bool operator==(const ListNode<typeData>& secondNode) const;
    bool operator!=(const ListNode<typeData>& secondNode) const;
    bool operator>(const ListNode<typeData>& secondNode) const;
    bool operator<(const ListNode<typeData>& secondNode) const;
    bool operator>=(const ListNode<typeData>& secondNode) const;
    bool operator<=(const ListNode<typeData>& secondNode) const;
private:
    typeData data;
    ListNode* next;
protected:
};

#endif /* listnode_h */
