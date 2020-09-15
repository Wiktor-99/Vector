#include "catch.hpp"
#include "../src/vector.hpp"


TEST_CASE("Construct Vector with Vector<int>(2) shuld give vectro.size() = 2 "){
    Vector<int> vector(2);
    
    REQUIRE(vector.size() == 2);
}