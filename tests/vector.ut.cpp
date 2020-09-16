
#include <random>
#include <vector>

#include "../src/vector.hpp"
#include "catch.hpp"

TEST_CASE("Default ctor of Vector<int> should allocate give vectro.size() = 0 and vector.capacity() = 4.") {
    const Vector<int> vector;
    SECTION("Vector should has size equal to 0") {
        REQUIRE(vector.size() == 0);
    }
    SECTION("Vector should has capacity equal to 4") {
        REQUIRE(vector.capacity() == 4);
    }
}

TEST_CASE("Construct Vector with Vector<int>(random_number) vector size sholud be equal to random_number and contain only 0 values") {
    std::random_device rd;
    std::mt19937 e{rd()};

    std::uniform_int_distribution<std::size_t> dist{
        1, 10000};
    std::size_t random_number = dist(e);
    Vector<int> vector(random_number);
    std::vector<int> expected(random_number);
    SECTION("Vector size sholud be equal to random_number") {
        REQUIRE(vector.size() == random_number);
    }
    SECTION("Vector should has same size as std::vector") {
        REQUIRE(vector.size() == expected.size());
    }
    SECTION("Vector should has same capacity as std::vector") {
        REQUIRE(vector.capacity() == expected.capacity());
    }
    SECTION("Vector should contain only 0 as std::vector") {
        REQUIRE(std::equal(vector.begin(), vector.end(), expected.begin(), expected.end()));
    }
}
TEST_CASE("Contructed Vectro<int>(5, random_value) should match with std::vectro<int>(5,random_value).") {
    std::random_device rd;
    std::mt19937 e{rd()};

    std::uniform_int_distribution<int> dist{
        1, 100};
    int random_value = dist(e);

    Vector<int> vector(5, random_value);
    std::vector<int> expected(5, random_value);
    REQUIRE(std::equal(vector.begin(), vector.end(), expected.begin(), expected.end()));
}
TEST_CASE("Copy ctor, expression Vector<int> vec1(5,6) Vector<int> vec2(ve1) should give same values, size and capacity.") {
    Vector<int> vec1(5, 6);
    Vector<int> vec2(vec1);
    SECTION("Vectors should be equal on range.") {
        REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }
    SECTION("Vectors should be same size.") {
        REQUIRE(vec1.size() == vec2.size());
    }
    SECTION("Vectors should be same capacity") {
        REQUIRE(vec1.capacity() == vec2.capacity());
    }
}
