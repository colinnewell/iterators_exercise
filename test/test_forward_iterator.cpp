
#include "catch.hpp"

#include "../simple_vector.hpp"

using iterator_t = typename simple_vector<int>::iterator;
using const_iterator_t = typename simple_vector<int>::const_iterator;

TEST_CASE("vector_iterator<T> is default constructible")
{
    REQUIRE(std::is_default_constructible<iterator_t>::value);
    REQUIRE(std::is_default_constructible<const_iterator_t>::value);
}

TEST_CASE("vector_iterator<T>::reference is set appropriately")
{
    using reference_t = std::iterator_traits<iterator_t>::reference;
    REQUIRE(std::is_same<reference_t, int&>::value);

    using const_ref_t = std::iterator_traits<const_iterator_t>::reference;
    REQUIRE(std::is_same<const_ref_t, const int&>::value);
}

TEST_CASE("vector_iterator<T>::iterator_category is set appropraitely")
{
    using category = typename std::iterator_traits<simple_vector<int>::iterator>::iterator_category;
    constexpr bool has_forward_iterator_tag = std::is_base_of<std::forward_iterator_tag, category>::value;
    REQUIRE(has_forward_iterator_tag);
}