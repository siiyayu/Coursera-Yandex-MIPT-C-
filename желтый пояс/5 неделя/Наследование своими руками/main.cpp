#include <iostream>

using namespace std;

class Animal {
public:
    Animal(const string& t) : Name(t) {
        //cout << "Animal name" << endl;
    }

    const string Name;
};


class Dog : public Animal {
public:
    Dog(const string& t) : Animal(t) {
        //cout << "Dog name" << endl;

    }
    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};


int main() {
    Dog d("Bim");
    return 0;
}