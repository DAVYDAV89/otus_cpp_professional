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
        } else {
            T* ptr = static_cast<T*>(::operator new(n * sizeof(T)));
            return ptr;
        }
    }

    void deallocate(T* p, size_t n) noexcept {
        if (n == 1) {
            // No need to deallocate for single element allocation
        } else {
            ::operator delete(p);
        }
    }

private:
    T data[N];
    size_t count = 0;
};
