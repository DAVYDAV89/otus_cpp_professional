// Файл Rectangle.cpp
#include "Rectangle.h"

void Rectangle::draw() {
//    std::cout << __PRETTY_FUNCTION__ << std::endl;

    // реализация отрисовки прямоугольника
    int width{35};
    int height{20};
    char drawChar{'#'};
    char emptyChar{' '};

    const std::string firstRow(width, drawChar);

    std::cout << firstRow << std::endl;
    for (int row = 1; row < height - 1; ++row) {
        std::string nextRow(width, emptyChar);
        nextRow[0] = drawChar;
        nextRow[width - 1] = drawChar;
        std::cout << nextRow << std::endl;
    }
    std::cout << firstRow << std::endl;
}
