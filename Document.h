#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <vector>
#include <string>

#include "Shape.h"

class Document {
private:
    std::vector<Shape*> shapes;

public:
    Document();
    ~Document();

    void importFromFile(const std::string& filename);
    void exportToFile(const std::string& filename);
    void createShape(Shape* shape);
    void deleteShape(Shape* shape);
};

#endif
