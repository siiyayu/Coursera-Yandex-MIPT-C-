#include <iostream>
#include <deque>


using namespace std;

void GetExpression(deque<string>& exp,const string& query,const string& k, bool flag) {
    if (flag == false) {
        exp.push_back(" ");
        exp.push_back(query);
        exp.push_back(" ");
        exp.push_back(k);
    } else {
        exp.push_front("(");
        exp.push_back(") ");
        exp.push_back(query);
        exp.push_back(" ");
        exp.push_back(k);
    }
}

int main() {
    int x, n;
    cin >> x >> n;
    deque<string> exp;
    exp.push_front(to_string(x));
    bool qp;
    bool prev_qp = true;
    for (int i = 0; i < n; i++) {
        string query;
        int k;
        cin >> query;
        cin >> k;
        if (query == "+" or query == "-") {
            qp = false;
        } else {
            qp = true;
        }
        if (prev_qp == false and qp == true) {
            GetExpression(exp, query, to_string(k), 1);
        } else {
            GetExpression(exp, query, to_string(k), 0);
        }
        prev_qp = qp;
    }
    for (int i = 0; i < exp.size(); i++) {
        cout << exp[i];
    }

    return 0;
}

