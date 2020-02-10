#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ReadAll(const string& path) {
    ifstream input(path);
    string line;
    while (getline(input, line)) {
        cout << line << endl;
    }
}
void WriteAll(const string& input_path, const string& output_path ) {
    ifstream input(input_path);
    ofstream output(output_path);
    string line;
    while (getline(input, line)) {
        output << line << endl;
    }


}

int main() {
    string input_path = "input.txt";
    string output_path = "output.txt";
    ReadAll(input_path);
    WriteAll(input_path, output_path);
    return 0;
}