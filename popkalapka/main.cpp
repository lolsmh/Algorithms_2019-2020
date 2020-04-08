#include <iostream>
#include "Figure.h"

int main() {
    Rectangle r;
    Ellipse e;
    r.initFromDialog();
    e.initFromDialog();
    r.draw();
    e.draw();
    std::cout << "Периметр прямоугольника: " << r.perimeter() << std::endl;
    std::cout << "Периметр эллипса: " << e.perimeter() << std::endl;
    std::cout << "Площадь прямоугольника: " << r.square() << std::endl;
    std::cout << "Площадь эллипса: " << e.square() << std::endl;
    std::cout << "Имя класса прямоугольник: " << r.classname() << std::endl;
    std::cout << "Имя класса эллипс: " << e.classname() << std::endl;
    std::cout << "Память, занимаемая всеми экземплярами класса прямоугольник: " << r.size() << std::endl;
    std::cout << "Память, занимаемая всеми экземплярами класса эллипс: " << e.size() << std::endl;
    return 0;
}
