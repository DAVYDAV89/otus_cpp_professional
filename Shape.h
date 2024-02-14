#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape {
public:
    virtual ~Shape() {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    virtual void draw() = 0;
};

#endif
