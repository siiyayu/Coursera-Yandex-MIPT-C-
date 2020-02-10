#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <memory>


using namespace std;


class Figure {
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

shared_ptr<Figure> CreateFigure(istringstream& ss);

class Rect : public Figure {
public:
    Rect(const string& name, const int& width, const int& height) : _name(name), _width(width), _height(height) {}
    string Name() const override {
        return _name;
    }
    double Perimeter() const override {
        return (_width + _height) * 2;
    }
    double Area() const override {
        return _width * _height;
    }

private:
    string _name;
    int _width, _height;
};

class Triangle : public Figure {
public:
    Triangle(const string& name, const int& a, const int& b, const int& c) : _name(name), _a(a), _b(b), _c(c) {}
    string Name() const override {
        return _name;
    }
    double Perimeter() const override {
        return _a + _b + _c;
    }
    double Area() const override {
        double p = Perimeter()/2;
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));
    }
private:
    string _name;
    int _a, _b, _c;
};

class Circle : public Figure {
public:
    Circle(const string& name, const int& r) : _name(name), _r(r) {}
    string Name() const override {
        return _name;
    }
    double Perimeter() const override {
        return 2 * 3.14 * _r;
    }
    double Area() const override {
        return 3.14 * _r * _r;
    }
private:
    string _name;
    int _r;
};

shared_ptr<Figure> CreateFigure(istringstream& ss) {
    string figure;
    ss >> figure;
    shared_ptr<Figure> result;
    if (figure == "RECT") {
        int w, h;
        ss >> w;
        ss >> h;
        return make_shared<Rect>(figure, w, h); /////
    } else if (figure == "TRIANGLE") {
        int a, b, c;
        ss >> a >> b >> c;
        return make_shared<Triangle>(figure, a, b, c);
    } else {
        int r;
        ss >> r;
        return make_shared<Circle>(figure, r);
    }
}

int main() {
vector<shared_ptr<Figure>> figures;
for (string line; getline(cin, line); ) {
istringstream is(line);
string command;
is >> command;
if (command == "ADD") {
figures.push_back(CreateFigure(is));
} else if (command == "PRINT") {
for (const auto& current_figure : figures) {
cout << fixed << setprecision(3)
<< current_figure->Name() << " "
<< current_figure->Perimeter() << " "
<< current_figure->Area() << endl;
}
}
}
return 0;
}