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
    ErrorBase();
    explicit ErrorBase(const char* message) : message(message) {}
    explicit ErrorBase(const std::string& message) : message(message) {}
    
    virtual const char* what() const noexcept override
    {
        return message.c_str();
    }
protected:
    std::string message;
};

class MemoryError : public ErrorBase
{
private:
    static constexpr const char* ErrorMsg = "Allocation error";
public:
    explicit MemoryError() : ErrorBase(ErrorMsg) {}
    explicit MemoryError(const std::string& message) : ErrorBase(ErrorMsg + message) {}
};

class EmptyError : public ErrorBase
{
private:
    static constexpr const char* ErrorMsg = "List is empty";
public:
    explicit EmptyError() : ErrorBase(ErrorMsg) {}
    explicit EmptyError(const std::string& message) : ErrorBase(ErrorMsg + message) {}
};

class RangeError : public ErrorBase
{
private:
    static constexpr const char* ErrorMsg = "Index out of range";
public:
    explicit RangeError() : ErrorBase(ErrorMsg) {}
    explicit RangeError(const std::string& message) : ErrorBase(ErrorMsg + message) {}
};

#endif /* errors_h */
