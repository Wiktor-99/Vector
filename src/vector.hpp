#pragma once

#include <cstddef>

#include <algorithm>
#include <iterator>

template <typename T, typename Allocator = std::allocator<T>>
class Vector {
    using value_type = T;

  public:
    explicit Vector(std::size_t size){
        first_ = allocator_.allocate(size);
        realEnd_ = end_ = first_ + size;
        auto first = first_;
        auto end = end_;
        for(; first != end; ++first)
            new(first) T();
    }
    std::size_t size()const{return end_-first_;}


  private:
    Allocator allocator_;
    T *first_ = {};
    T *end_ = {};
    T *realEnd_ = {};
};
