#pragma once

#include <algorithm>
using namespace std;

template <typename T>
class SimpleVector {
public:
    SimpleVector() = default;
    explicit SimpleVector(size_t size);
    ~SimpleVector();
    SimpleVector(const SimpleVector& rhs) :
    data(new T[rhs.capacity]), size(rhs.size), capacity(rhs.capacity) {
        copy(rhs.begin(), rhs.end(), begin());
    }


    T& operator[](size_t index);
    //Compile error: b"/tmp/submissionu6r_aqv_/tmp_eb_9_m9.cpp:2:9: warning: #pragma once in main file [-Wpragma-once-outside-header]\n#pragma once\n        ^\n/tmp/submissionu6r_aqv_/tmp_eb_9_m9.cpp:19:18: fatal error: 'this' argument to member function 'begin' has type 'const SimpleVector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >', but function is not marked const\n            copy(rhs.begin(), rhs.end(), begin());\n                 ^~~\n/tmp/submissionu6r_aqv_/tmp_eb_9_m9.cpp:170:10: note: in instantiation of member function 'SimpleVector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::operator=' requested here\n    dest = source;\n         ^\n/tmp/submissionu6r_aqv_/tmp_eb_9_m9.cpp:37:8: note: 'begin' declared here\n    T* begin();\n       ^\n1 warning and 1 error generated.\n"
    void operator=(const SimpleVector& rhs) {
        if (rhs.size <= capacity) {
            // У нас достаточно памяти - просто копируем элементы
            copy(rhs.begin(), rhs.end(), begin());
            size = rhs.size;
        } else {
            // Это так называемая идиома copy-and-swap.
            // Мы создаём временный вектор с помощью
            // конструктора копирования, а затем обмениваем его поля со своими.
            // Так мы достигаем двух целей:
            //  - избегаем дублирования кода в конструкторе копирования
            //    и операторе присваивания
            //  - обеспечиваем согласованное поведение конструктора копирования
            //    и оператора присваивания
            SimpleVector<T> tmp(rhs);
            swap(tmp.data, data);
            swap(tmp.size, size);swap(tmp.capacity, capacity);
        }
    }

    T* begin();
    T* end();


    const T* begin() const;
    const T* end() const;

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



template <typename T>
const T* SimpleVector<T>::begin() const{
    return data;
}

template <typename T>
const T* SimpleVector<T>::end() const{
    return data + size;
}


