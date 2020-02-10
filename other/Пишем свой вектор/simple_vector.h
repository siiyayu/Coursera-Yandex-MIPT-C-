//#pragma once
//
//#include <algorithm>
//
//// Реализуйте шаблон SimpleVector
//template <typename T>
//class SimpleVector {
//public:
//    SimpleVector() : data(nullptr), capacity(0), size_(0) {}
//    explicit SimpleVector(size_t size) {
//        data = new T[size];
//        capacity = size;
//        size_ = size;
//
//    }
//    ~SimpleVector() {
//        delete[] data;
//    }
//
//    T& operator[](size_t index) {
//        return data[index];
//    }
//
//    T* begin();
//
//    T* end();
//
//    size_t Size() const {
//        return size_;
//    }
//    size_t Capacity() const {
//        return capacity;
//    }
//    void PushBack(const T& value);
//
//private:
//    T* data;
//    size_t capacity = 0;
//    size_t size_ = 0;
//};
//
//template <typename T>
//void SimpleVector<T>::PushBack(const T& value) {
//    if (size_ >= capacity) {
//        auto new_capacity = capacity == 0 ? 1 : 2 * capacity;
//        T* data_new = new T[new_capacity];
////        copy(begin(), end(), data_new);
//            for (int i = 0; i < size_; i++) {
//                data_new[i] = data[i];
//            }
//        delete[] data;
//        data = data_new;
//        capacity = new_capacity;
//    }
//    data[size_++] = value;
//}
//
//template <typename T>
//T* SimpleVector<T>::begin() {
//    return data;
//}
//
//template <typename T>
//T* SimpleVector<T>::end() {
//    return data + size_;
//}


#pragma once

#include <algorithm>
using namespace std;

template <typename T>
class SimpleVector {
public:
    SimpleVector() = default;
    explicit SimpleVector(size_t size);
    ~SimpleVector();

    T& operator[](size_t index);

    T* begin();
    T* end();

    size_t Size() const;
    size_t Capacity() const;
    void PushBack(const T& value);

private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
};

template <typename T>
SimpleVector<T>::SimpleVector(size_t size)
        : data(new T[size])
        , size(size)
        , capacity(size)
{
}

template <typename T>
SimpleVector<T>::~SimpleVector() {
    delete[] data;
}

template <typename T>
T& SimpleVector<T>::operator[](size_t index) {
    return data[index];
}

template <typename T>
size_t SimpleVector<T>::Size() const {
    return size;
}

template <typename T>
size_t SimpleVector<T>::Capacity() const {
    return capacity;
}

template <typename T>
void SimpleVector<T>::PushBack(const T& value) {
    if (size >= capacity) {
        auto new_cap = capacity == 0 ? 1 : 2 * capacity;
        auto new_data = new T[new_cap];
        copy(begin(), end(), new_data);
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }
    data[size++] = value;
}

template <typename T>
T* SimpleVector<T>::begin() {
    return data;
}

template <typename T>
T* SimpleVector<T>::end() {
    return data + size;
}
