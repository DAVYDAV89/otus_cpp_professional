#include "Circle.h"
#include <vector>
#include <cmath>

void Circle::draw() {
//    std::cout << __PRETTY_FUNCTION__ << std::endl;

    int radius{15};
    int height{7};
    char drawChar{'*'};
    char emptyChar{' '};

    // реализация отрисовки круга
    double x, y;

    std::vector<std::vector<char>> drawBuffer(
                (radius) * 2 + 2,
                std::vector<char>(radius * 2 + 7, emptyChar));

    for (double t = 0.0; t < height; t += 0.1) {
        x = 0.5 * radius * sin(t) + radius + 1;
        y = radius * cos(t) + radius + 1;
        drawBuffer[x][y] = drawChar;
    }

    for (const auto& row : drawBuffer) {
        bool isEmptyLine = true;
        std::string line;
        for (auto cell : row){
            line += cell;
            if (cell != emptyChar)
                isEmptyLine = false;
        }
        if (!isEmptyLine)
            std::cout << line << std::endl;
    }
}
