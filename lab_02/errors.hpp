//
//  errors.hpp
//  lab_02
//
//  Created by Mac-HOME on 08/04/2019.
//  Copyright © 2019 Mac-HOME. All rights reserved.
//

#ifndef errors_h
#define errors_h

#include <exception>

class ErrorBase : public std::exception
{
public:
    virtual const char* what() const throw() = 0;
};

class MemoryError : public ErrorBase
{
    const char* what() const throw()
    {
        return "Allocation error";
    }
};

class EmptyError : public ErrorBase
{
    const char* what() const throw()
    {
        return "List is empty";
    }
};

class RangeError : public ErrorBase
{
    const char* what() const throw()
    {
        return "Index out of range";
    }
};

class CompareError : public ErrorBase
{
    const char* what() const throw()
    {
        return "Elements of list are incomparable";
    }
};

class ValueError : public ErrorBase
{
    const char* what() const throw()
    {
        return "Value not in list";
    }
};

class Error : public ErrorBase
{
    const char* what() const noexcept
    {
        return "Some error";
    }
};

#endif /* errors_h */
