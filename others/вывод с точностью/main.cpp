#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt"); //чтение и вывод таблицы
    int n, m;
    input >> n;
    input >> m;
    for (int i = 0; i < n; i++) {
        for (int i1 = 0; i1 < m; i1++){
            int a;
            input >> a;
            input.ignore(1);
            cout << setw(10) << a;
            if (i1 != m - 1) {
                cout << " ";
            }
        }
        if (i != n - 1){
            cout << endl;
        }
    }
//    ifstream input("input.txt"); // вывод с точностью
//    double a;
//    cout << fixed << setprecision(3);
//    while (input >> a) {
//        cout << a << endl;
//    }
    return 0;
}