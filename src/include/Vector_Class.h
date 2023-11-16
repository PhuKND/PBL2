#pragma once
#include <iostream>

template <class U>
class Vector_Class {
private:
    U *data;
    int size;
    int capacity;

public:
    Vector_Class();
    ~Vector_Class();
    int getSize() const;
    bool isEmpty() const;
    void clear();
    void pushBack(const U &obj);
    void popBack();
    U& at(int index) const;
    void remove(int index);
    void resize(int newCapacity);
    U operator[](int index) const;
    U getLast();
 
    // void print() const;

    Vector_Class(const Vector_Class<U> &other);

    Vector_Class<U> &operator=(const Vector_Class<U>&);
    template <class V>
    friend std::ostream &operator<<(std::ostream&, const Vector_Class<V>&);
};

