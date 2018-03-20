
#include "catch.hpp"

#include "../simple_vector.hpp"

TEST_CASE("vector_iterator<T> has a pre-decrement operator")
{
    simple_vector<int> vec{1, 2, 3, 4};
    auto it = vec.end();
    --it;
    REQUIRE(*it == 4);
}

TEST_CASE("vector_iterator_<T> has a post-decrement operator")
{
    simple_vector<int> vec{1, 2, 3, 4};
    auto it = vec.end();
    --it;
    REQUIRE(*it-- == 4);
}

TEST_CASE("vector_iterator<T>::iterator_category is set appropriately")
{
    using category = typename std::iterator_traits<simple_vector<int>::iterator>::iterator_category;
    constexpr bool has_bidir_iterator_tag = std::is_base_of<std::bidirectional_iterator_tag, category>::value;
    REQUIRE(has_bidir_iterator_tag);
}