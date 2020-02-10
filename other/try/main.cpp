#include <iostream>
#include <list>
#include <string>
#include <set>
#include <vector>

using T = std::string;

struct MyStruct {
    using Id = typename std::list<T>::iterator/* тип, используемый для идентификаторов */;
    std::set<std::pair<int, Id>> p;
    std::list<T> data;

    Id Add(T object) {
        data.push_back(move(object));
        p.insert({ 0, prev(data.end()) });
        return prev(data.end());
    }

    template <typename ObjInputIt, typename IdOutputIt>
    void Add(ObjInputIt range_begin, ObjInputIt range_end,
             IdOutputIt ids_begin) {
        for (auto it = range_begin; it != range_end; it++) {
            *ids_begin = Add(move(*it));
        }
    }
};

int main()
{
    std::vector<T> strings{ "aa","bb","cc" };
    MyStruct test;
    auto it = strings.begin();
    test.Add(*it++);
    test.Add(*it++);
    test.Add(*it++);
    std::cout << test.data.size() << '\n';
    std::cout << test.p.size() << '\n';
}