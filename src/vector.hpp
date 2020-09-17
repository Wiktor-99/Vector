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
    explicit Vector(std::size_t size, const value_type &value = T()) {
        first_ = allocator_.allocate(size);
        realEnd_ = end_ = first_ + size;
        rangeConstructor(first_, end_, value);
    }
    Vector(const Vector<value_type> &other) {
        changeSize(other.size(),other.capacity());
        auto first = first_;
        for (auto it = other.begin(); it != other.end(); ++it) {
            *first = *it;
            ++first;
        }
    }
    Vector(Vector<value_type> &&other) {
        first_ = other.first_;
        end_ = other.end_;
        realEnd_ = other.realEnd_;
        other.first_ = other.realEnd_ = other.end_ = nullptr;
    }
    Vector<T> &operator=(const Vector<value_type> &other) {
        changeSize(other.size(),other.capacity());
        auto first = first_;
        for (auto it = other.begin(); it != other.end(); ++it) {
            *first = *it;
            ++first;
        }
        return *this;
    }
    Vector<T> &operator=( Vector<value_type> &&other) {
         first_ = other.first_;
        end_ = other.end_;
        realEnd_ = other.realEnd_;
        other.first_ = other.realEnd_ = other.end_ = nullptr;
        return *this;
    }
    ~Vector() {
        rangeDestructor(first_, end_);
        allocator_.deallocate(first_, capacity());
    }
    void push_back(const value_type& value){
        if(end_ == realEnd_){
            makeBigger();
        }
        new(end_) T(value);
        end_++;
    }
    void push_back(value_type&& value){
        if(end_ == realEnd_){
            makeBigger();
        }
        new(end_) T(std::move(value));
        end_++;
    }
    value_type& front() { return *first_; }
    value_type& back() { return *(end_ - 1); }

    const value_type& front() const { return *first_; }
    const value_type& back() const { return *(end_ - 1); }


    
    std::size_t size() const { return end_ - first_; }
    std::size_t capacity() const { return realEnd_ - first_; }
    auto begin() const { return first_; }
    auto end() const { return end_; }

  private:
     void changeSize(std::size_t newSize, std::size_t newCapacity) {
        auto oldSize = size();
        auto newFirst = allocator_.allocate(newCapacity);
         for (size_t i = 0; i < oldSize; ++i)
            new(newFirst + i) T(std::move(first_[i]));
        rangeDestructor(first_, end_);
        allocator_.deallocate(first_, capacity());
        first_ = newFirst;
        end_ = first_ + newSize;
        realEnd_ = first_ + newCapacity;
    }
    void rangeConstructor(value_type *first, value_type *end, const value_type &value = T()) {
        for (; first != end; ++first) {
            new (first) T(value);
        }
    }
    void rangeDestructor(T *first, T *end) {
        for (; first != end; ++first) {
            first->~T();
        }
    }
    void makeBigger(){
        auto oldSize = size();
        auto newSize = (oldSize == 0) ? 1 : 2 * oldSize;
        changeSize(oldSize,newSize);
    }

  private:
    constexpr static std::size_t defaultSize = 4;
    Allocator allocator_ = {};
    value_type *first_ = {};
    value_type *end_ = {};
    value_type *realEnd_ = {};
};
