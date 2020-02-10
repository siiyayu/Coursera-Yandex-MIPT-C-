#include "test_runner.h"
#include <string>
#include <vector>
#include <string_view>
#include <map>
#include <deque>




using namespace std;

class Translator {
public:
  void Add(string_view source, string_view target) {
      string_view source_view = GetCloneView(source);
      string_view target_view = GetCloneView(target);
      forward_dict[source_view] = target_view;
      backward_dict[target_view] = source_view;
  }
  string_view TranslateForward(string_view source) const {
      if (forward_dict.count(source) == 0) {
          return "";
      } else
      return forward_dict.at(source);
  }
  string_view TranslateBackward(string_view target) const {
      if (backward_dict.count(target) == 0) {
          return "";
      } else
          return backward_dict.at(target);  }

private:
    map<string_view, string_view> forward_dict;
    map<string_view, string_view> backward_dict;
    deque<string> data;

    string_view GetCloneView(string_view s) {
        for (const auto* map_ptr : {&forward_dict, &backward_dict}) {
            const auto it = map_ptr->find(s);
            if (it != map_ptr->end()) {
                return it->first;
            }
        }
        return data.emplace_back(s);
    }
};

void TestSimple() {
  Translator translator;
  translator.Add(string("okno"), string("window"));
  translator.Add(string("stol"), string("table"));

  ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
  ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
  ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSimple);
  return 0;
}