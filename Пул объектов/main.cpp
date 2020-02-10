#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
    T* Allocate() {
        if (!deallocated.empty()) {
            T* to_allocate = deallocated.front();
            allocated.insert(to_allocate);
            deallocated.pop();
            return to_allocate;
        } else {
            T* to_allocate = new T;
            allocated.insert(to_allocate);
            return to_allocate;
        }
    }
    T* TryAllocate() {
        if (!deallocated.empty()) {
            T* to_allocate = deallocated.front();
            allocated.insert(to_allocate);
            deallocated.pop();
            return to_allocate;
        } else {
            return nullptr;
        }
    }

    void Deallocate(T* object) {
        if (allocated.count(object) == 0) {
            throw invalid_argument("");
        } else {
            deallocated.push(object);
            allocated.erase(object);
        }
    }

    ~ObjectPool() {
        for (auto item : allocated) {
            delete item;
        }
        while (!deallocated.empty()) {
            delete deallocated.front();
            deallocated.pop();
        }
//        allocated.erase(allocated.begin(), allocated.end());     // -- incorrect
//        while (!deallocated.empty()) {
//            deallocated.pop();
//        }
    }

private:
    set<T*> allocated;
    queue<T*> deallocated;
};

void TestObjectPool() {
    ObjectPool<string> pool;

    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();

    *p1 = "first";
    *p2 = "second";
    *p3 = "third";

    pool.Deallocate(p2);
    ASSERT_EQUAL(*pool.Allocate(), "second");

    pool.Deallocate(p3);
    pool.Deallocate(p1);
    ASSERT_EQUAL(*pool.Allocate(), "third");
    ASSERT_EQUAL(*pool.Allocate(), "first");

    pool.Deallocate(p1);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    return 0;
}



//#include "test_runner.h"
//
//#include <algorithm>
//#include <string>
//#include <queue>
//#include <stdexcept>
//#include <set>
//using namespace std;
//
//template <class T>
//class ObjectPool {
//public:
//    T* Allocate();
//    T* TryAllocate();
//
//    void Deallocate(T* object);
//
//    ~ObjectPool();
//
//private:
//    queue<T*> free;
//    set<T*> allocated;
//};
//
//template <typename T>
//T* ObjectPool<T>::Allocate() {
//    if (free.empty()) {
//        free.push(new T);
//    }
//    auto ret = free.front();
//    free.pop();
//    allocated.insert(ret);
//    return ret;
//}
//
//template <typename T>
//T* ObjectPool<T>::TryAllocate() {
//    if (free.empty()) {
//        return nullptr;
//    }
//    return Allocate();
//}
//
//template <typename T>
//void ObjectPool<T>::Deallocate(T* object) {
//    if (allocated.find(object) == allocated.end()) {
//        throw invalid_argument("");
//    }
//    allocated.erase(object);
//    free.push(object);
//}
//
//template <typename T>
//ObjectPool<T>::~ObjectPool() {
//    for (auto x : allocated) {
//        delete x;
//    }
//    while (!free.empty()) {
//        auto x = free.front();
//        free.pop();
//        delete x;
//    }
//}
