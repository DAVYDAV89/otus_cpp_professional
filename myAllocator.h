#include <iostream>
#include <memory>
#include <list>

template <typename T, size_t N>
class myAllocator {
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = size_t;

    template <typename U>
    struct rebind {
        using other = myAllocator<U, N>;
    };

    myAllocator() noexcept {}

    template <typename U>
    myAllocator(const myAllocator<U, N>&) noexcept {}

    T* allocate(size_t n) {
        if (n > N) {
            throw std::bad_alloc();
        }
        if (n == 1) {
            if (count == N) {
                throw std::bad_alloc();
            }
            return &data[count++];
        }
        throw std::bad_alloc();
    }

    void deallocate(T* p, size_t n) noexcept {}

private:
    static T data[N];
    static size_t count;
};

template <typename T, size_t N>
T myAllocator<T, N>::data[N];

template <typename T, size_t N>
size_t myAllocator<T, N>::count = 0;



//calss myAllocator
//Реализовать свой аллокатор памяти, который позволит выполнять операцию резервирования
//памяти. Далее использовать этот аллокатор с контейнером std::map. Аллокатор должен
//параметризоваться количеством выделяемых за раз элементов. Освобождение конкретного
//элемента не предполагается - аллокатор должен освобождать всю память самостоятельно.
//Аллокатор работает с фиксированным количеством элементов. Попытку выделить большее число
//элементов считать ошибкой.

//calss myMap
//Реализовать свой контейнер, который по аналогии с контейнерами stl параметризуется
//аллокатором. Контейнер должен иметь две возможности - добавить новый элемент и обойти
//контейнер в одном направлении.

//main
//Прикладной код должен содержать следующие вызовы:
//- создание экземпляра std::map<int, int>
//- заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
//- создание экземпляра std::map<int, int> с новым аллокатором, ограниченным 10
//элементами
//- заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
//- вывод на экран всех значений (ключ и значение разделены пробелом) хранящихся в контейнере
//- создание экземпляра своего контейнера для хранения значений типа int
//- заполнение 10 элементами от 0 до 9
//- создание экземпляра своего контейнера для хранения значений типа int с новым аллокатором,
//ограниченным 10 элементами
//- заполнение 10 элементами от 0 до 9
//- вывод на экран всех значений, хранящихся в контейнере
