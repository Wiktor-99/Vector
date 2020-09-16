
#include <random>
#include <vector>

#include "../src/vector.hpp"
#include "catch.hpp"

TEST_CASE("Construct Vector with Vector<int>(random_number) should give vectro.size() = random_number ") {
    std::random_device rd;
    std::mt19937 e{rd()};

    std::uniform_int_distribution<std::size_t> dist{
        1, 10000000};
    std::size_t random_number = dist(e);

    Vector<int> vector(random_number);
    REQUIRE(vector.size() == random_number);
}

TEST_CASE("Constructed Vector<int>(5) should contain only 0 values{0,0,0,0,0}") {
    std::vector<int> expected(5);
    Vector<int> vector(5);
    REQUIRE(std::equal(vector.begin(), vector.end(), expected.begin(), expected.end()));
}
TEST_CASE("Contructed Vectro<int>(5, random_value) should match with std::vectro<int>(5,random_value)") {
    std::random_device rd;
    std::mt19937 e{rd()};

    std::uniform_int_distribution<int> dist{
        1, 100};
    int random_value = dist(e);

    Vector<int> vector(5, random_value);
    std::vector<int> expected(5, random_value);
    REQUIRE(std::equal(vector.begin(), vector.end(), expected.begin(), expected.end()));
}
TEST_CASE("Default ctor of Vector<int> should allocate give vectro.size() = 0") {
    Vector<int> vector;
    REQUIRE(vector.size() == 0);
}
