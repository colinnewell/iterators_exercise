
#ifndef CPP_LONDON_UNI_SIMPLE_VECTOR_HPP
#define CPP_LONDON_UNI_SIMPLE_VECTOR_HPP

#include <algorithm>

template <typename>
class vector_iterator;

template <typename T>
class simple_vector {
public:
    // Type aliases required by the STL Container concept
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using difference_type = std::ptrdiff_t;
    using size_type = std::size_t;

    //using iterator = T*;
    //using const_iterator = const T*;

    using iterator = vector_iterator<T>;
    using const_iterator = vector_iterator<const T>;

    // Constructor/destruct/assignment
    simple_vector() = default;

    simple_vector(size_type s, const T& value = T{})
        : elements_(new T[s]),
          size_(s)
    {
        std::fill(elements_, elements_ + s, value);
    }

    simple_vector(std::initializer_list<T> ilist)
        : elements_(new T[ilist.size()]),
          size_(ilist.size())
    {
        std::copy(ilist.begin(), ilist.end(), elements_);
    }

    simple_vector(const simple_vector& other)
         : elements_(new T[other.size_]),
           size_(other.size_)
    {
        std::copy(other.elements_, other.elements + other.size_, elements_);
    }

    simple_vector(simple_vector&& other)
        : elements_(other.elements_),
          size_(other.size_)
    {
        other.elements_ = nullptr;
        other.size_ = nullptr;
    }

    simple_vector& operator=(simple_vector other)
    {
        std::swap(elements_, other.elements_);
        std::swap(size_, other.size_);
        return *this;
    }

    ~simple_vector()
    {
        delete[] elements_;
    }

    T& operator[](size_type idx) { return elements_[idx]; }
    const T& operator[](size_type idx) const { return elements_[idx]; }

    T* data()  { return elements_; }
    const T* data() const { return elements_; }


    //
    iterator begin() { return iterator{elements_}; }
    const_iterator begin() const { return const_iterator{elements_}; }

    iterator end() { return iterator{elements_ + size_}; }
    const_iterator end() const { return const_iterator{elements_ + size_}; }


    bool empty() const { return size_ == 0; }

    size_type size() const { return size_; }

private:
    T* elements_ = nullptr;
    std::size_t size_ = 0;
};


template <typename T>
class vector_iterator {
public:

private:
    T* element_ = nullptr;
};


#endif
