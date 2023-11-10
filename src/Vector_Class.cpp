#include"include/Vector.h"

template <class U>
Vector_Class<U>::Vector_Class() : data(nullptr), size(0), capacity(0) {}

template <class U>
Vector_Class<U>::~Vector_Class() { delete[] data; }

template <class U>
int Vector_Class<U>::getSize() const {
    return size;
}

template <class U>
bool Vector_Class<U>::isEmpty() const {
    return size == 0;
}

template <class U>
void Vector_Class<U>::clear() {
    size = 0;
}

template <class U>
void Vector_Class<U>::pushBack(const U &obj) {
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = obj;
}

template <class U>
void Vector_Class<U>::popBack() {
    if (size > 0) {
        size--;
    }
}

template <class U>
U Vector_Class<U>::at(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <class U>
void Vector_Class<U>::remove(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }

    for (int i = index + 1; i < size; i++) {
        data[i - 1] = data[i];
    }

    size--;
}

template <class U>
void Vector_Class<U>::resize(int newCapacity) {
    U *newData = new U[newCapacity];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <class U>
U Vector_Class<U>::operator[](int index) const {
    return at(index);
}

template <class U>
void Vector_Class<U>::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template <class U>
Vector_Class<U>::Vector_Class(const Vector_Class<U> &other) : size(other.size), capacity(other.capacity) {
    data = new U[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template <class U>
Vector_Class<U> &Vector_Class<U>::operator=(const Vector_Class<U> &other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new U[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

// Overloaded << operator for Vector_Class
template <class V>
std::ostream &operator<<(std::ostream &os, const Vector_Class<V> &vec) {
    for (int i = 0; i < vec.getSize(); i++) {
        os << vec.at(i) << " ";
    }
    return os;
}
