#pragma once

#include <cstddef>

#include <algorithm>
#include <iterator>

template <typename T, typename Allocator = std::allocator<T>>
class Vector {
    using value_type = T;

  public:
    explicit Vector(std::size_t size, const value_type &value = T()) {
        first_ = allocator_.allocate(size);
        realEnd_ = end_ = first_ + size;
        rangeConstructor(first_, end_, value);
    }
    ~Vector() {
        rangeDestructor(first_, end_);
        allocator_.deallocate(first_, realSize());
    }
    std::size_t size() const { return end_ - first_; }
    auto begin() { return first_; }
    auto end() { return end_; }

  private:
    void rangeConstructor(T *first, T *end, const value_type &value = T()) {
        for (; first != end; ++first) {
            new (first) value_type(value);
        }
    }
    void rangeDestructor(T *first, T *end) {
        for (; first != end; ++first) {
            first->~value_type();
        }
    }
    std::size_t realSize() const { return realEnd_ - first_; }

  private:
    Allocator allocator_ = {};
    value_type *first_ = {};
    value_type *end_ = {};
    value_type *realEnd_ = {};
};
