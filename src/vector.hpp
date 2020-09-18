#pragma once

#include <cstddef>

#include <algorithm>
#include <initializer_list>
#include <iterator>
#include <stdexcept>
#include <type_traits>

template <typename T, typename Allocator = std::allocator<T>>
class Vector {
  public:
    template <bool isConst>
    class myIteratorImpl {
      public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using reference = typename std::conditional_t<isConst, T const &, T &>;
        using pointer = typename std::conditional_t<isConst, T const *, T *>;

      public:
        explicit myIteratorImpl(pointer ptr) : ptr_(ptr) {}
        myIteratorImpl() : ptr_(nullptr) {}
        reference operator*() const {
            return *ptr_;
        }
        pointer operator->() const {
            return ptr_;
        }
        myIteratorImpl &operator++() {
            ptr_++;
            return *this;
        }
        myIteratorImpl operator++(int) {
            myIteratorImpl result(ptr_);
            ptr_++;
            return result;
        }
        myIteratorImpl &operator--() {
            ptr_--;
            return *this;
        }

      private:
        pointer ptr_;
    };

  public:
    using value_type = T;
    using iterator = myIteratorImpl<false>;
    using const_iterator = myIteratorImpl<true>;

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
        changeSize(other.size(), other.capacity());
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
        changeSize(other.size(), other.capacity());
        auto first = first_;
        for (auto it = other.begin(); it != other.end(); ++it) {
            *first = *it;
            ++first;
        }
        return *this;
    }
    Vector<T> &operator=(Vector<value_type> &&other) {
        first_ = other.first_;
        end_ = other.end_;
        realEnd_ = other.realEnd_;
        other.first_ = other.realEnd_ = other.end_ = nullptr;
        return *this;
    }
    Vector(const std::initializer_list<value_type> &list) {
        changeSize(list.size(), list.size());
        auto first = first_;
        for (auto it = list.begin(); it != list.end(); ++it) {
            *first = *it;
            ++first;
        }
    }
    ~Vector() {
        rangeDestructor(first_, end_);
        allocator_.deallocate(first_, capacity());
    }
    void push_back(const value_type &value) {
        if (end_ == realEnd_) {
            makeBigger();
        }
        new (end_) T(value);
        end_++;
    }
    void push_back(value_type &&value) {
        if (end_ == realEnd_) {
            makeBigger();
        }
        new (end_) T(std::move(value));
        end_++;
    }
    std::optional<value_type> pop_back() {
        if (size() > 0) {
            end_ -= 1;
            value_type temp = *end_;
            return temp;
        }
        return std::nullopt;
    }
    value_type &front() { return *first_; }
    value_type &back() { return *(end_ - 1); }

    const value_type &front() const { return *first_; }
    const value_type &back() const { return *(end_ - 1); }

    const value_type &operator[](std::size_t index) const {
        if (index >= size() || index < 0) {
            throw std::out_of_range("Index is out of range.");
        }
        return *(first_ + index);
    }
    std::size_t size() const { return end_ - first_; }
    std::size_t capacity() const { return realEnd_ - first_; }

    iterator begin() const { return iterator(first_); }
    iterator end() const { return iterator(end_); }

    const_iterator cbegin() const {
        return const_iterator(first_);
    }
    const_iterator cend() const { return const_iterator(end_); }

  private:
    void changeSize(std::size_t newSize, std::size_t newCapacity) {
        auto oldSize = size();
        auto newFirst = allocator_.allocate(newCapacity);
        for (size_t i = 0; i < oldSize; ++i)
            new (newFirst + i) T(std::move(first_[i]));
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
    void makeBigger() {
        auto oldSize = size();
        auto newSize = (oldSize == 0) ? 1 : 2 * oldSize;
        changeSize(oldSize, newSize);
    }

  private:
    constexpr static std::size_t defaultSize = 4;
    Allocator allocator_ = {};
    value_type *first_ = {};
    value_type *end_ = {};
    value_type *realEnd_ = {};
};
