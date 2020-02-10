#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
  Person(const string &name, const string &type) :
    name_(name), type_(type)
  {}

  virtual void Walk(const string &destination) const {
    cout << type_ << ": " << name_ <<  " walks to: " << destination << endl;
  }
  
  string get_name() const {
    return name_;
  }

  string get_type() const {
    return type_;
  }

private:
  string name_;
  string type_;
};

void common_log(const Person &p, const string &action, const string &item) {
  cout << p.get_type() << ": " << p.get_name() << ' ' << action << ": " << item << endl;;
}

class Student : public Person {
public:
  Student(string name, string favourite_song) :
    Person(name, "Student"), fav_song_(favourite_song) {
  }

  void Learn() {
    cout << "Student: " << get_name() << " learns" << endl;
  }

  void Walk(const string &destination) const override {
    Person::Walk(destination);
    SingSong();
  }

  void SingSong() const {
    common_log(*this, "sings a song", fav_song_);
  }

private:
  string fav_song_;
};


class Teacher : public Person {
public:
  Teacher(string name, string subject) : 
    Person(name, "Teacher"),
    subject_(subject) 
  { }

  void Teach() {
    common_log(*this, "teaches", subject_);
  }

private:
  string subject_;
};


class Policeman : public Person {
public:
  Policeman(string name) : Person(name, "Policeman")
  {}

  void Check(const Person &t) {
    cout << "Policeman: " << get_name() << ' ' 
         << "checks " << t.get_type() << ". "
         << t.get_type() << "'s name is: " << t.get_name() 
         << endl;
  }
};


void VisitPlaces(const Person &person, const vector<string>& places) {
  for (auto place : places) {
    person.Walk(place);
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
