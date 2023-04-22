#include <iostream>
#include <cmath>

using namespace std;

class Quadrilateral {
protected:
    double m_side1;
    double m_side2;
    double m_side3;
    double m_side4;

public:
    Quadrilateral(double side1 = 0, double side2 = 0, double side3 = 0, double side4 = 0)
        : m_side1(side1), m_side2(side2), m_side3(side3), m_side4(side4) {}

    virtual ~Quadrilateral() {}

    virtual double area() const = 0;

    friend ostream& operator<<(ostream& os, const Quadrilateral& q) {
        os << "Side 1: " << q.m_side1 << endl;
        os << "Side 2: " << q.m_side2 << endl;
        os << "Side 3: " << q.m_side3 << endl;
        os << "Side 4: " << q.m_side4 << endl;
        os << "Area: " << q.area() << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Quadrilateral& q) {
        cout << "Enter side 1: ";
        is >> q.m_side1;
        cout << "Enter side 2: ";
        is >> q.m_side2;
        cout << "Enter side 3: ";
        is >> q.m_side3;
        cout << "Enter side 4: ";
        is >> q.m_side4;
        return is;
    }

    Quadrilateral(const Quadrilateral& other)
        : m_side1(other.m_side1), m_side2(other.m_side2), m_side3(other.m_side3), m_side4(other.m_side4) {}

    Quadrilateral& operator=(const Quadrilateral& other) {
        if (this != &other) {
            m_side1 = other.m_side1;
            m_side2 = other.m_side2;
            m_side3 = other.m_side3;
            m_side4 = other.m_side4;
        }
        return *this;
    }
};

class Square : public Quadrilateral {
public:
    Square(double side = 0) : Quadrilateral(side, side, side, side) {}

    double area() const {
        return m_side1 * m_side1;
    }
};

int main() {
    Square s1(5);
    Square s2(s1);
    Square s3 = s2;
    cin >> s1;
    cout << s1;
    return 0;
}
