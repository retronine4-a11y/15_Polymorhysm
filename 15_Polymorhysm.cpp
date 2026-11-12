#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape
{
protected:
    string name;
    string type;

public:
    Shape(string n, string t)
    {
        name = n;
        type = t;
    }

    virtual void Show()
    {
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
    }

    virtual double GetArea() = 0;

    virtual ~Shape() {}
};

class Rectangle : public Shape
{
private:
    double a, b;

public:
    Rectangle(double x, double y)
        : Shape("Rectangle", "Quadrilateral")
    {
        a = x;
        b = y;
    }

    void Show() override
    {
        Shape::Show();
        cout << "Sides: " << a << " and " << b << endl;
    }

    double GetArea() override
    {
        return a * b;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r)
        : Shape("Circle", "Round shape")
    {
        radius = r;
    }

    void Show() override
    {
        Shape::Show();
        cout << "Radius: " << radius << endl;
    }

    double GetArea() override
    {
        return 3.14 * radius * radius;
    }
};

class RightTriangle : public Shape
{
private:
    double a, b;

public:
    RightTriangle(double x, double y)
        : Shape("Right Triangle", "Triangle")
    {
        a = x;
        b = y;
    }

    void Show() override
    {
        Shape::Show();
        cout << "Cathetus A: " << a << endl;
        cout << "Cathetus B: " << b << endl;
    }

    double GetArea() override
    {
        return (a * b) / 2;
    }
};

class Triangle : public Shape
{
private:
    double a, b, c;

public:
    Triangle(double x, double y, double z)
        : Shape("Triangle", "Triangle")
    {
        a = x;
        b = y;
        c = z;
    }

    void Show() override
    {
        Shape::Show();
        cout << "Side A: " << a << endl;
        cout << "Side B: " << b << endl;
        cout << "Side C: " << c << endl;
    }

    double GetArea() override
    {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Trapezoid : public Shape
{
private:
    double a, b, h;

public:
    Trapezoid(double x, double y, double height)
        : Shape("Trapezoid", "Quadrilateral")
    {
        a = x;
        b = y;
        h = height;
    }

    void Show() override
    {
        Shape::Show();
        cout << "Base A: " << a << endl;
        cout << "Base B: " << b << endl;
        cout << "Height: " << h << endl;
    }

    double GetArea() override
    {
        return ((a + b) * h) / 2;
    }
};

void TestShape(Shape& shape)
{
    shape.Show();
    cout << "Area: " << shape.GetArea() << endl;
    cout << "------------------------" << endl;
}

int main()
{
    Rectangle r(5, 4);
    Circle c(3);
    RightTriangle rt(3, 4);
    Triangle t(3, 4, 5);
    Trapezoid tr(6, 4, 3);

    TestShape(r);
    TestShape(c);
    TestShape(rt);
    TestShape(t);
    TestShape(tr);
}
