#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include <list>
#include <tuple>

// Вспомогательная структура для определения, является ли тип контейнером
template<typename T>
struct is_container : std::false_type {};

template<typename... Args>
struct is_container<std::vector<Args...>> : std::true_type {};

template<typename... Args>
struct is_container<std::list<Args...>> : std::true_type {};

template <typename Tuple, size_t... Is>
void print_tuple(const Tuple& tuple, std::index_sequence<Is...>) {
    ((std::cout << (Is == 0 ? "" : ".") << std::get<Is>(tuple)), ...);
}

// Функция для печати элемента
template<typename T>
typename std::enable_if<std::is_integral<T>::value && !std::is_same<T, bool>::value, void>::type
print_ip(const T& ip) {
    const unsigned char* bytes = reinterpret_cast<const unsigned char*>(&ip);
    std::cout << static_cast<int>(bytes[0]);
    for (int i = 1; i < sizeof(T); ++i) {
        std::cout << "." << static_cast<int>(bytes[i]);
    }
    std::cout << std::endl;
}

template<typename T>
typename std::enable_if<std::is_same<T, std::string>::value, void>::type
print_ip(const T& ip) {
    std::cout << ip << std::endl;
}

template<typename T>
typename std::enable_if<is_container<T>::value, void>::type
print_ip(const T& ip) {
    auto it = ip.begin();
    std::cout << *it;
    ++it;
    while (it != ip.end()) {
        std::cout << "." << *it;
        ++it;
    }
    std::cout << std::endl;
}


template <typename... Args>
void print_ip(const std::tuple<Args...>& ip) {
    print_tuple(ip, std::index_sequence_for<Args...>{});
    std::cout << std::endl;
}

int main() {
    print_ip(int8_t{-1}); // 255
    print_ip(int16_t{0}); // 0.0
    print_ip(int32_t{2130706433}); // 127.0.0.1
    print_ip(int64_t{8875824491850138409}); // 123.45.67.89.101.112.131.41
    print_ip(std::string{"Hello, World!"}); // Hello, World!
    print_ip(std::vector<int>{100, 200, 300, 400}); // 100.200.300.400
    print_ip(std::list<short>{400, 300, 200, 100}); // 400.300.200.100
    print_ip(std::make_tuple(123, 456, 789, 0)); // 123.456.789.0

    return 0;
}
