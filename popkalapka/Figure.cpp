#include "Figure.h"

Rectangle::Rectangle() : CVector2D(), a{0, 0}, b{0, 0}, c{0, 0}, d{0, 0}, a_side(0), b_side(0), c_side(0), d_side(0) {}

void Rectangle::initFromDialog() {
    std::cout << "Введите координаты точек прямоугольника:\na: ";
    std::cin >> a.x >> a.y;
    std::cout << "b: ";
    std::cin >> b.x >> b.y;
    std::cout << "c: ";
    std::cin >> c.x >> b.y;
    std::cout << "d: ";
    std::cin >> d.x >> d.y;
    a_side = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    b_side = sqrt(pow(c.x - b.x, 2) + pow(c.y - b.y, 2));
    c_side = sqrt(pow(d.x - c.x, 2) + pow(d.y - c.y, 2));
    d_side = sqrt(pow(a.x - d.x, 2) + pow(a.y - d.y, 2));
}

void Rectangle::draw() {
    std::cout << "Стороны прямоугольника:\na = " << a_side << ", b = " << b_side << ", c = " << c_side << ", d = "
              << d_side << std::endl;
}

const char *Rectangle::classname() {
    return "Rectangle";
}

unsigned int Rectangle::size() {
    return sizeof(Rectangle);
}

double Rectangle::square() {
    return a_side * b_side;
}

double Rectangle::perimeter() {
    return a_side + b_side + c_side + d_side;
}

Ellipse::Ellipse() : CVector2D(), a{0, 0}, b{0, 0}, c{0, 0}, d{0, 0}, a_axis(0), b_axis(0) {}

void Ellipse::initFromDialog() {
    std::cout << "Введите координаты концов осей эллипса:\na: ";
    std::cin >> a.x >> a.y >> b.x >> b.y;
    std::cout << "b: ";
    std::cin >> c.x >> c.y >> d.x >> d.y;
    a_axis = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    b_axis = sqrt(pow(c.x - d.x, 2) + pow(c.y - d.y, 2));
}

void Ellipse::draw() {
    std::cout << "Значение длинны осей:\na = " << a_axis << "\nb = " << b_axis << std::endl;
}

const char *Ellipse::classname() {
    return "Ellipse";
}

unsigned int Ellipse::size() {
    return sizeof(Ellipse);
}

double Ellipse::square() {
    return M_PI * a_axis * b_axis / 2;
}

double Ellipse::perimeter() {
    return 2 * M_PI * sqrt((pow(a_axis / 2, 2) + pow(b_axis / 2, 2)) / 2);
}

