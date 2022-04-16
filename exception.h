
#ifndef MDS2HW1_EXCEPTION_H
#define MDS2HW1_EXCEPTION_H

#include <stdexcept>

class SpielException : public std::runtime_error  {
public:
    using std::runtime_error::runtime_error;
};

class ArrayFullException : public SpielException  {
public:
    using SpielException::SpielException;
};

class InvalidIndexException : public SpielException {
public:
    using SpielException::SpielException;
};

class EmptyIndexException : public SpielException {
public:
    using SpielException::SpielException;
};

class NoLootException : public SpielException {
public:
    using SpielException::SpielException;
};

class NegativeNumberException : public SpielException {
public:
    using SpielException::SpielException;
};


#endif //MDS2HW1_EXCEPTION_H
