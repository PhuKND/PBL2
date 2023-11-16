#include <iostream>
#include"include/Vector.h"
template class Vector_Class<Order>;

template<typename T>
Vector<T>::Vector() {
    size = 0;
    capacity = 10;
    data = new T[capacity];
}

template<typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template<typename T>
int Vector<T>::getSize() const {
    return size;
}

template<typename T>
bool Vector<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
void Vector<T>::clear() {
    size = 0;
}

template<typename T>
void Vector<T>::pushBack(int value) {
    if (size == capacity) {
        // Nếu vector đã đầy, thay đổi dung lượng bằng cách gấp đôi nó
        resize(2 * capacity);
    }
    data[size++] = value;
}

template<typename T>
void Vector<T>::popBack() {
    if (!isEmpty()) {
        size--;
    }
}

template<typename T>
int Vector<T>::at(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    // Trả về một giá trị mặc định nếu index nằm ngoài phạm vi
    return -1;
}

template<typename T>
void Vector<T>::insert(int index, int value) {
    if (index < 0 || index > size) {
        return;
    }
    if (size == capacity) {
        // Nếu vector đã đầy, thay đổi dung lượng bằng cách gấp đôi nó
        resize(2 * capacity);
    }
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}

template<typename T>
void Vector<T>::remove(int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }
}

template<typename T>
void Vector<T>::resize(int newCapacity) {
    T* newData = new T[newCapacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template<typename T>
int Vector<T>::operator[](int index) const {
    return at(index);
}

template<typename T>
void Vector<T>::print() const {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) {
        std::cout << data[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " ]" << std::endl;
}

template<typename T>
Vector<T>::Vector(const Vector& other) {
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }
    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    return *this;
}
