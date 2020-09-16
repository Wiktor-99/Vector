
#include <random>
#include <vector>

#include "../src/vector.hpp"
#include "catch.hpp"

TEST_CASE("Construct Vector with Vector<int>(random_number) shuld give vectro.size() = random_number ") {
    std::random_device rd;
    std::mt19937 e{rd()};

    std::uniform_int_distribution<int> dist{
        1, 10000000};
    std::size_t random_number = dist(e);

    Vector<int> vector(random_number);
    REQUIRE(vector.size() == random_number);
}

TEST_CASE("Constructed Vector<int>(5) should contain only 0 values{0,0,0,0,0}"){
    int expected[5]  = {0,0,0,0,0};
    Vector<int> vector(5);
    REQUIRE(std::equal(vector.begin(),vector.end(),expected,expected+5));
}