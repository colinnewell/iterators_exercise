
#include "catch.hpp"

#include "../simple_vector.hpp"

#include <type_traits>

using iterator_t = typename simple_vector<int>::iterator;
using const_iterator_t = typename simple_vector<int>::const_iterator;

TEST_CASE("vector_iterator<T> is copy-constructible")
{
    REQUIRE(std::is_copy_constructible<iterator_t>::value);
    REQUIRE(std::is_copy_constructible<const_iterator_t>::value);
}

TEST_CASE("vector_iterator<T> is copy-assignable")
{
    REQUIRE(std::is_copy_assignable<iterator_t>::value);
    REQUIRE(std::is_copy_assignable<const_iterator_t>::value);
}

TEST_CASE("vector_iterator<T> is destructible")
{
    REQUIRE(std::is_destructible<iterator_t>::value);
    REQUIRE(std::is_destructible<const_iterator_t>::value);
}

TEST_CASE("vector_iterator<T> is swappable")
{
    // FIXME: Implement this properly
}

template <typename...> using void_t = void;

template <typename, typename = void>
struct has_iterator_typedefs : std::false_type {};

template <typename I>
using traits = std::iterator_traits<I>;


template <typename T>
struct has_iterator_typedefs<T, void_t<
        typename traits<T>::value_type,
        typename traits<T>::difference_type,
        typename traits<T>::reference,
        typename traits<T>::pointer,
        typename traits<T>::iterator_category>>
    : std::true_type {};

TEST_CASE("vector_iterator<T> has the required typedefs")
{
    REQUIRE(has_iterator_typedefs<iterator_t>::value);
    REQUIRE(has_iterator_typedefs<const_iterator_t>::value);
}

template <typename, typename = void>
struct has_pre_increment : std::false_type {};

template <typename T>
struct has_pre_increment<T, std::enable_if_t<
        std::is_same<decltype(++(std::declval<T>())), T&>::value
                >>
    : std::true_type {};


TEST_CASE("vector_iterator<T> has a pre-increment operator")
{
    REQUIRE(has_pre_increment<iterator_t>::value);
    REQUIRE(has_pre_increment<const_iterator_t>::value);
}

template <typename, typename = void>
struct has_dereference : std::false_type {};

template <typename T>
struct has_dereference<T, void_t<decltype(*std::declval<T>())>>
    : std::true_type {};

TEST_CASE("vector_iterator<T> has a dereference operator")
{
    REQUIRE(has_dereference<iterator_t>::value);
    REQUIRE(has_dereference<const_iterator_t>::value);
}

