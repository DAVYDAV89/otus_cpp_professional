#include "Document.h"

Document::Document() {
    // конструктор
}

Document::~Document() {
    // деструктор
}

void Document::importFromFile(const std::string& filename) {
    // импорт документа из файла
}

void Document::exportToFile(const std::string& filename) {
    // экспорт документа в файл
}

void Document::createShape(Shape* shape) {
    shapes.push_back(shape);
}

void Document::deleteShape(Shape* shape) {
    // удаление графического примитива
    // ...
}
