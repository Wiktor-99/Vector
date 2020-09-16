#pragma once

#include <cstddef>

#include <algorithm>
#include <iterator>

template <typename T, typename Allocator = std::allocator<T>>
class Vector {
  public:
    using value_type = T;

  public:
    Vector() {
        first_ = end_ = allocator_.allocate(defaultSize);
        realEnd_ = first_ + defaultSize;
    }
    explicit Vector(std::size_t size, const T &value = T()) {
        first_ = allocator_.allocate(size);
        realEnd_ = end_ = first_ + size;
        rangeConstructor(first_, end_, value);
    }
    Vector(const Vector<T> &other) {
        changeSizeAndClear(other);
        auto first = first_;
        for (auto it = other.begin(); it != other.end(); ++it) {
            *first = *it;
            ++first;
        }
    }
    ~Vector() {
        rangeDestructor(first_, end_);
        allocator_.deallocate(first_, capacity());
    }
    std::size_t size() const { return end_ - first_; }
    std::size_t capacity() const { return realEnd_ - first_; }
    auto begin() const { return first_; }
    auto end() const { return end_; }

  private:
    void changeSizeAndClear(const Vector<T> &other) {
        auto newFirst = allocator_.allocate(other.capacity());
        rangeDestructor(first_, end_);
        allocator_.deallocate(first_, capacity());
        first_ = newFirst;
        end_ = first_ + other.size();
        realEnd_ = first_ + other.capacity();
    }
    void rangeConstructor(T *first, T *end, const value_type &value = T()) {
        for (; first != end; ++first) {
            new (first) T(value);
        }
    }
    void rangeDestructor(T *first, T *end) {
        for (; first != end; ++first) {
            first->~T();
        }
    }

  private:
    constexpr static std::size_t defaultSize = 4;
    Allocator allocator_ = {};
    value_type *first_ = {};
    value_type *end_ = {};
    value_type *realEnd_ = {};
};
