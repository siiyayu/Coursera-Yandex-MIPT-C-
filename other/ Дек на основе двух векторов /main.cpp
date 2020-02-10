#include <iostream>
#include <vector>


using namespace std;

template <typename T>
class Deque {
public:
    bool Empty() const {
        if (v_back.empty() && v_front.empty())
            return true;
        else
            return false;
    }

    size_t Size() const {
        return v_back.size() + v_front.size();
    }

    T& operator[](size_t index) {
        if (index >= v_front.size())
            return v_back[index - v_front.size()];
        else
            return v_front[v_front.size() - index - 1];
    }

    const T& operator[](size_t index) const {
        if (index >= v_front.size())
            return v_back[index - v_front.size()];
        else
            return v_front[v_front.size() - index - 1];
    }

    T& At(size_t index) {
        size_t push_front_size = v_front.size();
        size_t push_back_size = v_back.size();
        if (index >= push_back_size + push_front_size)
            throw out_of_range("Index is larger than the size of deque");
        if (index >= push_front_size)
            return v_back.at(index - push_front_size);
        else
            return v_front.at(push_front_size - index - 1);
    }

    const T& At(size_t index) const {
        size_t push_front_size = v_front.size();
        size_t push_back_size = v_back.size();
        if (index >= push_back_size + push_front_size)
            throw out_of_range("Index is larger than the size of deque");
        if (index >= push_front_size)
            return v_back.at(index - push_front_size);
        else
            return v_front.at(push_front_size - index - 1);
    }

    T& Front() {
        if (v_front.empty())
            return v_back.front();
        else
            return v_front.back(); //
    }

    const T& Front() const {
        if (v_front.empty())
            return v_back.front();
        else
            return v_front.back(); //
    };

    T& Back() {
        if (v_back.empty())
            return v_front.front();
        else
            return v_back.back(); //
    }

    const T& Back() const {
        if (v_back.empty())
            return v_front.front();
        else
            return v_back.back(); //
    };

    void PushFront(const T& item) {
        v_front.push_back(item);
    }

    void PushBack(const T& item) {
        v_back.push_back(item);
    }

private:
    vector<T> v_front;
    vector<T> v_back;
};
int main() {
    Deque<string> d;
    d.PushBack("A");
    cout << d.Front() << " " << d.Back();

    return 0;
}

//
//#include <cstddef>
//#include <stdexcept>
//#include <utility>
//#include <vector>
//
//using namespace std;
//
//template <typename T>
//class Deque {
//private:
//    vector<T> head, tail;
//
//    void CheckIndex(size_t i) const {
//        if (i >= Size())
//            throw out_of_range("Index is out of range");
//    }
//
//public:
//    Deque() = default;
//
//    bool Empty() const {
//        return head.empty() && tail.empty();
//    }
//
//    size_t Size() const {
//        return head.size() + tail.size();
//    }
//
//    void Clear() {
//        head.clear();
//        tail.clear();
//    }
//
//    const T& operator [] (size_t i) const {
//        return i < head.size() ? head[head.size() - i - 1] : tail[i - head.size()];
//    }
//
//    T& operator [] (size_t i) {
//        return i < head.size() ? head[head.size() - i - 1] : tail[i - head.size()];
//    }
//
//    const T& At(size_t i) const {
//        CheckIndex(i);
//        return (*this)[i];
//    }
//
//    T& At(size_t i) {
//        CheckIndex(i);
//        return (*this)[i];
//    }
//
//    const T& Front() const {
//        return head.empty() ? tail.front() : head.back();
//    }
//
//    T& Front() {
//        return head.empty() ? tail.front() : head.back();
//    }
//
//    const T& Back() const {
//        return tail.empty() ? head.front() : tail.back();
//    }
//
//    T& Back() {
//        return tail.empty() ? head.front() : tail.back();
//    }
//
//    void PushFront(const T& elem) {
//        head.push_back(elem);
//    }
//
//    void PushBack(const T& elem) {
//        tail.push_back(elem);
//    }
//};