
#include "catch.hpp"

#include "../simple_vector.hpp"

#include <iostream>
#include <cassert>
#include <iterator>

TEST_CASE("vector_iterator is an input iterator")
{
    using category = typename std::iterator_traits<simple_vector<int>::iterator>::iterator_category;
    constexpr bool has_input_iterator_tag = std::is_base_of<std::input_iterator_tag, category>::value;
    REQUIRE(has_input_iterator_tag);
}

TEST_CASE("vector_iterator<T> can be dereferenced")
{
    simple_vector<int> vec{1, 2, 3, 4};
    auto begin = vec.begin();
    REQUIRE(*begin == 1);
}

TEST_CASE("vector_iterator<T> can be dereferenced using operator->()")
{
    struct foo { int i = 0; };
    simple_vector<foo> vec(3);
    auto iter = vec.begin();
    REQUIRE(iter->i == 0);
}

TEST_CASE("vector_iterator<T> can be pre-incremented")
{
    simple_vector<int> vec{1, 2, 3, 4};
    auto iter = vec.begin();
    ++iter;
    REQUIRE(*iter == 2);
}

TEST_CASE("vector_iterator<T> can be post-incremented")
{
    simple_vector<int> vec{1, 2, 3, 4};
    auto iter = vec.begin();
    REQUIRE(*iter++ == 1);
}

TEST_CASE("vector_iterator<T> can be compared for (in)equality")
{
    simple_vector<int> vec{1, 2, 3, 4};
    auto iter1 = vec.begin();
    auto iter2 = vec.begin();
    REQUIRE(iter1 == iter2);
    ++iter1;
    REQUIRE(iter1 != iter2);
}