//
//  listnode.hpp
//  lab_02
//
//  Created by Mac-HOME on 08/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#ifndef listnode_hpp
#define listnode_hpp

template <typename typeData>
class ListNode
{
public:
    template <typename typeList> friend class List;
    
    ListNode();
    explicit ListNode(const typeData data);
    ListNode(ListNode& nextNode);
    ListNode(const typeData data, ListNode& nextNode);
    ~ListNode();
    
    void setData(const typeData data);
    typeData getData() const;
    
    void setNext(ListNode& nextNode);
    ListNode* getNext();
    void delNext();
    
    bool operator ==(const ListNode& secondNode) const;
    bool operator !=(const ListNode& secondNode) const;
    bool operator >(const ListNode& secondNode) const;
    bool operator <(const ListNode& secondNode) const;
    bool operator >=(const ListNode& secondNode) const;
    bool operator <=(const ListNode& secondNode) const;
private:
    typeData data;
    ListNode* next;
protected:
};

#endif /* listnode_hpp */