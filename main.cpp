#include "Document.h"
#include "Rectangle.h"
#include "Circle.h"
#include <memory>

int main() {
    Document document;
    int figure;

    std::cout << "Выберите фигуру: " << std::endl;
    std::cout << "Прямоугольник - 1 " << std::endl;
    std::cout << "Круг - 2 " << std::endl;
    std::cout << "Для выхода нажмите 3" << std::endl;

    std::cin >> figure;

    std::unique_ptr<Shape> _figure;
    while (figure != 3) {
        if (figure == 1) {
            _figure = std::make_unique<Rectangle>();
            break;
        }
        if (figure == 2) {
            _figure = std::make_unique<Circle>();
            break;
        }
    }
    document.createShape(_figure.get());
    _figure->draw();

    std::cout << "Спасибо, приходите еще!!!" << std::endl;

    document.exportToFile("output.txt");

    return 0;
}
