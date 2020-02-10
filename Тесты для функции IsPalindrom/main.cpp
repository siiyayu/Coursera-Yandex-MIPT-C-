#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};


void TestIsPalindrom() {
        AssertEqual(IsPalindrom(""),true, "empty");
        AssertEqual(IsPalindrom(""),true, "empty");
        AssertEqual(IsPalindrom("777778"),false, "777778");
        AssertEqual(IsPalindrom("777777"),true, "777777");
        AssertEqual(IsPalindrom("777778 "),false, "777778 ");
        AssertEqual(IsPalindrom(" 777778 "),false, " 777778 ");
        AssertEqual(IsPalindrom(" 777778"),false, " 777778");
        AssertEqual(IsPalindrom("777777 "),false, "777777 ");
        AssertEqual(IsPalindrom(" 777777"),false, " 777777");
        AssertEqual(IsPalindrom(" 777777 "),true, " 777777 ");
        AssertEqual(IsPalindrom("7777 77"),false, "7777 77");
        AssertEqual(IsPalindrom("77 7777"),false, "77 7777");
        AssertEqual(IsPalindrom("777 777"),true, "777 777");
        AssertEqual(IsPalindrom("77777 7"),false, "77777 7");
        AssertEqual(IsPalindrom("abcderdcba"),0);
        AssertEqual(IsPalindrom("abcdeedcbaz"),0);
        AssertEqual(IsPalindrom("zabcdeedcba"),0);
        AssertEqual(IsPalindrom(" - - "),true, " - - ");
        AssertEqual(IsPalindrom("s"),true, "s");
        AssertEqual(IsPalindrom("ccbbaamomaabbcc"),true, "ccbbaamomaabbcc");
        AssertEqual(IsPalindrom("ccbbaaMoMaabbcc"),true, "ccbbaaMoMaabbcc");
        AssertEqual(IsPalindrom("mOm"),true, "mOm");
        AssertEqual(IsPalindrom("level"),true, "level");
        AssertEqual(IsPalindrom("ccbbaawasitacaroracatisawaabbcc"),true, "ccbbaawasitacaroracatisawaabbcc");
        AssertEqual(IsPalindrom("madam"),true, "madam");
        AssertEqual(IsPalindrom("ccbbaamadamaabbcc"),true, "ccbbaamadamaabbcc");
        AssertEqual(IsPalindrom("ma d am"),true, "ma d am");
        AssertEqual(IsPalindrom("maasdsaam"),true, "maasdsaam");
        AssertEqual(IsPalindrom("asa"),true, "asa");
        AssertEqual(IsPalindrom("moM"),false, "moM");
        AssertEqual(IsPalindrom("ccbbaamoMaabbcc"),false, "ccbbaamoMaabbcc");
        AssertEqual(IsPalindrom("ccbbaamOmaabbcc"),true), "ccbbaamOmaabbcc";
        AssertEqual(IsPalindrom("ma dam"),false, "ma dam");
        AssertEqual(IsPalindrom(" ccbbaaasaaabbcc"),false, " ccbbaaasaaabbcc");
        AssertEqual(IsPalindrom("sa"),false, "sa");
        AssertEqual(IsPalindrom("as"),false, "as");
        AssertEqual(IsPalindrom("s "),false, "s ");
        AssertEqual(IsPalindrom("ccbbaaasaaabbcc "),false, "ccbbaaasaaabbcc ");
        AssertEqual(IsPalindrom(" s"),false, " s");
}
//bool IsPalindrom(const string& str) {
//    // Вы можете вставлять сюда различные реализации функции,
//    // чтобы проверить, что ваши тесты пропускают корректный код
//    // и ловят некорректный
//}

int main() {
    TestRunner runner;
    runner.RunTest(TestIsPalindrom, "TestIsPalindrom");
    return 0;
}
