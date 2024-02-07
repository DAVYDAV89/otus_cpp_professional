#include <iostream>
#include <map>

template <typename Key, typename Value, typename Compare = std::less<Key>, typename Allocator = std::allocator<std::pair<const Key, Value>>>
class myMap {
public:
    using key_type = Key;
    using mapped_type = Value;
    using value_type = std::pair<const Key, Value>;
    using key_compare = Compare;
    using allocator_type = Allocator;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = typename std::allocator_traits<Allocator>::pointer;
    using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
    using iterator = typename std::map<Key, Value, Compare, Allocator>::iterator;
    using const_iterator = typename std::map<Key, Value, Compare, Allocator>::const_iterator;
    using reverse_iterator = typename std::map<Key, Value, Compare, Allocator>::reverse_iterator;
    using const_reverse_iterator = typename std::map<Key, Value, Compare, Allocator>::const_reverse_iterator;
    using difference_type = typename std::map<Key, Value, Compare, Allocator>::difference_type;
    using size_type = typename std::map<Key, Value, Compare, Allocator>::size_type;

    myMap() : map(Allocator()) {}

    explicit myMap(const Allocator& alloc) : map(alloc) {}

    template <typename InputIterator>
    myMap(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& alloc = Allocator())
        : map(first, last, comp, alloc) {}

    myMap(const myMap& other) : map(other.map) {}

    myMap(const myMap& other, const Allocator& alloc) : map(other.map, alloc) {}

    myMap(myMap&& other) noexcept : map(std::move(other.map)) {}

    myMap(myMap&& other, const Allocator& alloc) noexcept : map(std::move(other.map), alloc) {}

    myMap(std::initializer_list<value_type> init, const Compare& comp = Compare(), const Allocator& alloc = Allocator())
        : map(init, comp, alloc) {}

    ~myMap() = default;

    myMap& operator=(const myMap& other) {
        map = other.map;
        return *this;
    }

    myMap& operator=(myMap&& other) noexcept {
        map = std::move(other.map);
        return *this;
    }

    myMap& operator=(std::initializer_list<value_type> init) {
        map = init;
        return *this;
    }

    allocator_type get_allocator() const noexcept {
        return map.get_allocator();
    }

    iterator begin() noexcept {
        return map.begin();
    }

    const_iterator begin() const noexcept {
        return map.begin();
    }

    iterator end() noexcept {
        return map.end();
    }

    const_iterator end() const noexcept {
        return map.end();
    }

    reverse_iterator rbegin() noexcept {
        return map.rbegin();
    }

    const_reverse_iterator rbegin() const noexcept {
        return map.rbegin();
    }

    reverse_iterator rend() noexcept {
        return map.rend();
    }

    const_reverse_iterator rend() const noexcept {
        return map.rend();
    }

    const_iterator cbegin() const noexcept {
        return map.cbegin();
    }

    const_iterator cend() const noexcept {
        return map.cend();
    }

    const_reverse_iterator crbegin() const noexcept {
        return map.crbegin();
    }

    const_reverse_iterator crend() const noexcept {
        return map.crend();
    }

    bool empty() const noexcept {
        return map.empty();
    }

    size_type size() const noexcept {
        return map.size();
    }

    size_type max_size() const noexcept {
        return map.max_size();
    }

    void clear() noexcept {
        map.clear();
    }

    std::pair<iterator, bool> insert(const value_type& value) {
        return map.insert(value);
    }

    template <typename P>
    std::pair<iterator, bool> insert(P&& value) {
        return map.insert(std::forward<P>(value));
    }

    iterator insert(const_iterator hint, const value_type& value) {
        return map.insert(hint, value);
    }

    template <typename P>
    iterator insert(const_iterator hint, P&& value) {
        return map.insert(hint, std::forward<P>(value));
    }

    template <typename InputIterator>
    void insert(InputIterator first, InputIterator last) {
        map.insert(first, last);
    }

    void insert(std::initializer_list<value_type> init) {
        map.insert(init);
    }

    template <typename... Args>
    std::pair<iterator, bool> emplace(Args&&... args) {
        return map.emplace(std::forward<Args>(args)...);
    }

    template <typename... Args>
    iterator emplace_hint(const_iterator hint, Args&&... args) {
        return map.emplace_hint(hint, std::forward<Args>(args)...);
    }

    iterator erase(const_iterator pos) {
        return map.erase(pos);
    }

    iterator erase(const_iterator first, const_iterator last) {
        return map.erase(first, last);
    }

    size_type erase(const key_type& key) {
        return map.erase(key);
    }

    void swap(myMap& other) noexcept {
        map.swap(other.map);
    }

    mapped_type& operator[](const key_type& key) {
        return map[key];
    }

    mapped_type& operator[](key_type&& key) {
        return map[std::move(key)];
    }

    mapped_type& at(const key_type& key) {
        return map.at(key);
    }

    const mapped_type& at(const key_type& key) const {
        return map.at(key);
    }

    iterator find(const key_type& key) {
        return map.find(key);
    }

    const_iterator find(const key_type& key) const {
        return map.find(key);
    }

    size_type count(const key_type& key) const {
        return map.count(key);
    }

    iterator lower_bound(const key_type& key) {
        return map.lower_bound(key);
    }

    const_iterator lower_bound(const key_type& key) const {
        return map.lower_bound(key);
    }

    iterator upper_bound(const key_type& key) {
        return map.upper_bound(key);
    }

    const_iterator upper_bound(const key_type& key) const {
        return map.upper_bound(key);
    }

    std::pair<iterator, iterator> equal_range(const key_type& key) {
        return map.equal_range(key);
    }

    std::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
        return map.equal_range(key);
    }

private:
    std::map<Key, Value, Compare, Allocator> map;
};




