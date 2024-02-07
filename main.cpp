#include <iostream>
#include <map>
#include <algorithm>
#include "myAllocator.h"
#include "myMap.h"

// Функция для вычисления факториала
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    // Создание экземпляра std::map<int, int>
    std::map<int, int> map1;

    // Заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    for (int i = 0; i < 10; ++i) {
        map1[i] = factorial(i);
    }

    // Создание экземпляра std::map<int, int> с новым аллокатором, ограниченным 10 элементами
    std::map<int, int, std::less<int>, myAllocator<std::pair<const int, int>, 10>> map2;

    // Заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    for (int i = 0; i < 10; ++i) {
        map2[i] = factorial(i);
    }

    // Вывод на экран всех значений (ключ и значение разделены пробелом) хранящихся в контейнере
    std::cout << "map1: ";
    for (const auto& pair : map1) {
        std::cout << pair.first << " " << pair.second << " ";
    }
    std::cout << std::endl;

    std::cout << "map2: ";
    for (const auto& pair : map2) {
        std::cout << pair.first << " " << pair.second << " ";
    }
    std::cout << std::endl;

    // Создание экземпляра своего контейнера для хранения значений типа int
    myMap<int, int> myMap1;

    // Заполнение 10 элементами от 0 до 9
    for (int i = 0; i < 10; ++i) {
        myMap1.emplace(i, i);
    }

    // Создание экземпляра своего контейнера для хранения значений типа int с новым аллокатором, ограниченным 10 элементами
    myMap<int, int, std::less<int>, myAllocator<std::pair<const int, int>, 10>> myMap2;

    // Заполнение 10 элементами от 0 до 9
    for (int i = 0; i < 10; ++i) {
        myMap2.emplace(i, i);
    }

    // Вывод на экран всех значений, хранящихся в контейнере
    std::cout << "myMap1: ";
    for (const auto& pair : myMap1) {
        std::cout << pair.first << " " << pair.second << " ";
    }
    std::cout << std::endl;

    std::cout << "myMap2: ";
    for (const auto& pair : myMap2) {
        std::cout << pair.first << " " << pair.second << " ";
    }
    std::cout << std::endl;

    return 0;
}
