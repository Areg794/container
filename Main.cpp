#include <iostream>

template<typename T>
class Vector {
private:
    T* ptr;
    int size;
    int capacity;

public:
    Vector(int size) : size(size), capacity(size) {
        ptr = new T[capacity];
    }

    virtual ~Vector() {
        delete[] ptr;
    }


    Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
        ptr = new T[capacity];
        for (int i = 0; i < size; ++i) {
            ptr[i] = other.ptr[i];
        }
    }


    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }
        delete[] ptr;
        size = other.size;
        capacity = other.capacity;
        ptr = new T[capacity];
        for (int i = 0; i < size; ++i) {
            ptr[i] = other.ptr[i];
        }
        return *this;
    }

    Vector(Vector&& other) : ptr(other.ptr), size(other.size), capacity(other.capacity) {
        other.ptr = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    Vector& operator=(Vector&& other) {
        if (this == &other) {
            return *this;
        }
        delete[] ptr;
        ptr = other.ptr;
        size = other.size;
        capacity = other.capacity;
        other.ptr = nullptr;
        other.size = 0;
        other.capacity = 0;
        return *this;
    }
    T& operator[](int index) {
        if (index >= size) {
            throw "Index out of range";
        }
        return ptr[index];
    }
public:
    int getSize() const {
        return size;
    }
    int getCapacity()const {
        return capacity;
    }
    bool empty()const {
        return size == 0;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            capacity *= 2;
            T* newPtr = new T[capacity];
            for (int i = 0; i < size; ++i) {
                newPtr[i] = ptr[i];
            }
            delete[] ptr;
            ptr = newPtr;
        }
        ptr[size++] = value;
    }

    void pop_back() {
        if (size > 0) {
            --size;
        }
    }
};
int main() {
    Vector<int> intVec(3);
  
    intVec.push_back(1);
    intVec.push_back(2);
    intVec.push_back(3);
    intVec.pop_back();
    intVec.empty();
    
        for (int i = 0; i < intVec.getSize(); ++i) {
            std::cout << intVec[i] << " ";
        }
        std::cout << std::endl;

    return 0;
}