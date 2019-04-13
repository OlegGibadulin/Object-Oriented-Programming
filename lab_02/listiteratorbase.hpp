//
//  listiteratorbase.hpp
//  lab_02
//
//  Created by Mac-HOME on 13/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#ifndef listiteratorbase_hpp
#define listiteratorbase_hpp

template <typename typeData>
class ListIterBase
{
public:
    ListIterBase();
    ListIterBase(const ListIterBase& listIter);
    ListIterBase(const typeData* ptr);
    ~ListIterBase();
    
    void begin();
    void end();
    void next();
    void isInRange();
    
    ListIterBase& operator = (const ListIterBase& listIter);
    ListIterBase& operator ++ ();
    ListIterBase& operator ++ (int);
    ListIterBase& operator -- ();
    ListIterBase& operator -- (int);
    
    bool operator == (const ListIterBase& listIter) const;
    bool operator != (const ListIterBase& listIter) const;
private:
protected:
    typeData* ptr;
};

#endif /* listiteratorbase_hpp */
