#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& name, const string& type) : Name(name), Type(type) {}
    string GetName() const {
        return Name;
    }
    string GetType() const {
        return Type;
    }
    virtual void Walk(const string& destination) const {
        cout << Type << ": " << Name << " walks to: " << destination << endl;
    }

private:
    string Name;
    string Type;
};
class Student : public Person {
public:
    Student(const string& name, const string& favouriteSong) : Person(name, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() {
        cout << GetType() << ": " << GetName() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << GetType() << ": " << GetName() << " walks to: " << destination << endl;
        cout << GetType() << ": " << GetName() << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() {
        cout << GetType() << ": " << GetName() << " sings a song: " << FavouriteSong << endl;
    }

private:
    string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string& name, const string& subject) : Person(name, "Teacher"), Subject(subject) {}

    void Teach() {
        cout << GetType() << ": " << GetName() << " teaches: " << Subject << endl;
    }

private:
    string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name) : Person(name, "Policeman") {}

    void Check(const Person& t) {
        string type_lower = t.GetType();
        char first = tolower(type_lower[0]);
        type_lower[0] = first;
        cout << GetType() << ": " << GetName() << " checks " << type_lower
        << ". " << t.GetType() << " name is: " << t.GetName() << endl;
    }
};


void VisitPlaces(const Person& p, const vector<string>& places) {
    for (auto item : places) {
        p.Walk(item);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
