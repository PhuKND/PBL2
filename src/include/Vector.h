#pragma once
template<typename T>   
class Vector {
private:
    int* data;        
    int size;         
    int capacity;

public:
    Vector();                         // Constructor
    ~Vector();                        // Destructor
    int getSize() const;              // Lấy kích thước của vector
    bool isEmpty() const;            // Kiểm tra vector có rỗng không
    void clear();                    // Xóa toàn bộ phần tử trong vector
    void pushBack(int value);        // Thêm một phần tử vào cuối vector
    void popBack();                  // Xóa phần tử cuối cùng của vector
    int at(int index) const;         // Truy cập phần tử tại vị trí index
    void insert(int index, int value);  // Chèn một phần tử vào vị trí index
    void remove(int index);            // Xóa phần tử tại vị trí index
    void resize(int newCapacity);     
    int operator[](int index) const;   

    void print() const;            

    Vector(const Vector& other);

    Vector& operator=(const Vector& other);
};
