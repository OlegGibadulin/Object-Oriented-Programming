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
    ListNode();
    explicit ListNode(const typeData data);
    ListNode(ListNode& node);
    ListNode(const typeData data, ListNode& nextNode);
    virtual ~ListNode();
    
    void setData(const typeData data);
    typeData getData() const;
    
    void setNext(ListNode* nextNode);
    ListNode* getNext();
    
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
