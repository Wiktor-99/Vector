
#include "../src/vector.hpp"
#include "catch.hpp"
#include <iostream>
#include <random>
#include <vector>

// TEST_CASE("Default ctor of Vector<int> should allocate give vectro.size() = 0 and vector.capacity() = 4.") {
//     const Vector<int> vector;
//     SECTION("Vector should has size equal to 0") {
//         REQUIRE(vector.size() == 0);
//     }
//     SECTION("Vector should has capacity equal to 4") {
//         REQUIRE(vector.capacity() == 4);
//     }
// }

// TEST_CASE("Construct Vector with Vector<int>(random_number) vector size sholud be equal to random_number and contain only 0 values") {
//     std::random_device rd;
//     std::mt19937 e{rd()};

//     std::uniform_int_distribution<std::size_t> dist{
//         1, 10000};
//     std::size_t random_number = dist(e);
//     Vector<int> vector(random_number);
//     std::vector<int> expected(random_number);
//     SECTION("Vector size sholud be equal to random_number") {
//         REQUIRE(vector.size() == random_number);
//     }
//     SECTION("Vector should has same size as std::vector") {
//         REQUIRE(vector.size() == expected.size());
//     }
//     SECTION("Vector should has same capacity as std::vector") {
//         REQUIRE(vector.capacity() == expected.capacity());
//     }
//     SECTION("Vector should contain only 0 as std::vector") {
//         REQUIRE(std::equal(vector.begin(), vector.end(), expected.begin(), expected.end()));
//     }
// }
// TEST_CASE("Contructed Vectro<int>(5, random_value) should match with std::vectro<int>(5,random_value).") {
//     std::random_device rd;
//     std::mt19937 e{rd()};

//     std::uniform_int_distribution<int> dist{
//         1, 100};
//     int random_value = dist(e);

//     Vector<int> vector(5, random_value);
//     std::vector<int> expected(5, random_value);
//     REQUIRE(std::equal(vector.begin(), vector.end(), expected.begin(), expected.end()));
// }
// TEST_CASE("Copy ctor, expression Vector<int> vec1(5,6) Vector<int> vec2(ve1) should give same values, size and capacity.") {
//     Vector<int> vec1(5, 6);
//     Vector<int> vec2(vec1);
//     SECTION("Vectors should be equal on range.") {
//         REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
//     }
//     SECTION("Vectors should be same size.") {
//         REQUIRE(vec1.size() == vec2.size());
//     }
//     SECTION("Vectors should be same capacity") {
//         REQUIRE(vec1.capacity() == vec2.capacity());
//     }
// }

// TEST_CASE("Move ctor should move all meber values(pointers) to resul vector. Moved vector should be clear (size = 0 and capacity = 0 ).") {
//     Vector<int> vector(4, 8);
//     Vector<int> result(std::move(vector));
//     Vector<int> expected(4, 8);
//     SECTION("Vectors should not be equal.") {
//         REQUIRE_FALSE(std::equal(vector.begin(), vector.end(), result.begin(), result.end()));
//     }
//     SECTION("Moved vector should has size eqaul to 0") {
//         REQUIRE(vector.size() == 0);
//     }
//     SECTION("Moved vector should has capacity equal to 0") {
//         REQUIRE(vector.capacity() == 0);
//     }
//     SECTION("New vector should be equal to vectro<int>(4,8)") {
//         REQUIRE(std::equal(result.begin(), result.end(), expected.begin(), expected.end()));
//     }
// }
// TEST_CASE("Copy assignment operator, expression Vector<int> vec1(5,6) Vector<int> vec2(ve1) should give same values, size and capacity.") {
//     Vector<int> vec1(5, 6);
//     Vector<int> vec2;
//     vec2 = vec1;
//     SECTION("Vectors should be equal on range.") {
//         REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
//     }
//     SECTION("Vectors should be same size.") {
//         REQUIRE(vec1.size() == vec2.size());
//     }
//     SECTION("Vectors should be same capacity") {
//         REQUIRE(vec1.capacity() == vec2.capacity());
//     }
// }
// TEST_CASE("Move assignment operator should move all meber values(pointers) to resul vector. Moved vector should be clear (size = 0 and capacity = 0 ).") {
//     Vector<int> vector(4, 8);
//     Vector<int> result;
//     Vector<int> expected(4, 8);
//     result = std::move(vector);
//     SECTION("Vectors should not be equal.") {
//         REQUIRE_FALSE(std::equal(vector.begin(), vector.end(), result.begin(), result.end()));
//     }
//     SECTION("Moved vector should has size eqaul to 0") {
//         REQUIRE(vector.size() == 0);
//     }
//     SECTION("Moved vector should has capacity equal to 0") {
//         REQUIRE(vector.capacity() == 0);
//     }
//     SECTION("New vector should be equal to vectro<int>(4,8)") {
//         REQUIRE(std::equal(result.begin(), result.end(), expected.begin(), expected.end()));
//     }
// }
// TEST_CASE("Vector push_back method test, for default ctor and push_back method size shuld be equal  1 and capacity 4") {
//     Vector<int> vector;
//     int x = 1;
//     vector.push_back(x);
//     SECTION("Vector size sholud be equal 1") {
//         REQUIRE(vector.size() == 1);
//     }
//     SECTION("Vector capacity sholud be equal 4") {
//         REQUIRE(vector.capacity() == 4);
//     }
// }
// TEST_CASE("Vector push_back when size(5) is equal capacity(5) should resize to size+1(6) and capcity x 2(10) ") {
//     Vector<int> vector;
//     int x = 1;
//     vector.push_back(x);
//     SECTION("Vector size sholud be equal 1") {
//         REQUIRE(vector.size() == 1);
//     }
//     SECTION("Vector capacity sholud be equal 4") {
//         REQUIRE(vector.capacity() == 4);
//     }
// }
// TEST_CASE("Vector push_back(for r-value) method test, for default ctor and push_back method size shuld be equal  1 and capacity 4") {
//     Vector<int> vector;
//     vector.push_back(1);
//     SECTION("Vector size sholud be equal 1") {
//         REQUIRE(vector.size() == 1);
//     }
//     SECTION("Vector capacity sholud be equal 4") {
//         REQUIRE(vector.capacity() == 4);
//     }
// }
// TEST_CASE("Vector push_back(for r-value) when size(5) is equal capacity(5) should resize to size+1(6) and capcity x 2(10)") {
//     Vector<int> vector(5, 1);
//     vector.push_back(1);
//     SECTION("Vector size sholud be equal 1") {
//         REQUIRE(vector.size() == 6);
//     }
//     SECTION("Vector capacity sholud be equal 4") {
//         REQUIRE(vector.capacity() == 10);
//     }
// }

// TEST_CASE("Non const front, back method should change values first and last values") {
//     Vector<int> vector(5, 1);
//     vector.front() = 98;
//     vector.back() = 10001;
//     SECTION("Vector size sholud be equal 1") {
//         REQUIRE(vector.front() == 98);
//     }
//     SECTION("Vector capacity sholud be equal 4") {
//         REQUIRE(vector.back() == 10001);
//     }
// }
// TEST_CASE("Vector operator[] with index control for Vector<int> vector(1,2,3,5) should give vector[0] = 1, vector[2] = 3 and for vector[4] should throw expetion") {
//     Vector<int> vector;
//     vector.push_back(1);
//     vector.push_back(2);
//     vector.push_back(3);
//     vector.push_back(5);
//     SECTION("Vector[0] should give 1") {
//         REQUIRE(vector[0] == 1);
//     }
//     SECTION("Vector[2] should give 3") {
//         REQUIRE(vector[2] == 3);
//     }
//     SECTION("Vector[5] should throw exeption") {
//         REQUIRE_THROWS(vector[5]);
//     }
//     SECTION("Vector[-1] should throw exeption") {
//         REQUIRE_THROWS(vector[5]);
//     }
// }
// TEST_CASE("Vector ctor initializer_list{1,2,3} should construct vector that contains {1,2,3,4}") {
//     std::initializer_list<int> list{1, 2, 3};
//     std::vector<int> expected(list);
//     Vector<int> vector(list);
//     SECTION("vector[0] should be equal 1") {
//         REQUIRE(vector[0] == 1);
//     }
//     SECTION("vector[0] should be equal 2") {
//         REQUIRE(vector[1] == 2);
//     }
//     SECTION("vector[0] should be equal 3") {
//         REQUIRE(vector[2] == 3);
//     }
// }
// TEST_CASE("Using pop_back method for should change Vector<int>{1,2,3,4} to Vector<int>{1,2,3} and return 4. If vector is empty should return std:nullopt") {
//     Vector<int> vector{1, 2, 3, 4};
//     std::vector<int> expected{1, 2, 3};
//     auto result = vector.pop_back();
//     SECTION("Vector<int>{1,2,3,4} after pop_back should be equal to Vector<int>{1,2,3}") {
//         REQUIRE(*result == 4);
//     }
//     SECTION("Vector<int>{1,2,3,4} after pop_back should be equal to Vector<int>{1,2,3}") {
//         REQUIRE(std::equal(expected.begin(), expected.end(), vector.begin(), vector.end()));
//     }
//     vector.pop_back();
//     expected.pop_back();
//     SECTION("Vector<int>{1,2,3} after pop_back should be equal to Vector<int>{1,2}") {
//         REQUIRE(std::equal(expected.begin(), expected.end(), vector.begin(), vector.end()));
//     }
//     vector.pop_back();
//     expected.pop_back();
//     SECTION("Vector<int>{1,2} after pop_back should be equal to Vector<int>{1}") {
//         REQUIRE(std::equal(expected.begin(), expected.end(), vector.begin(), vector.end()));
//     }
//     vector.pop_back();
//     expected.pop_back();
//     SECTION("Vector<int>{1} after pop_back should be equal to Vector<int>{}") {
//         REQUIRE(std::equal(expected.begin(), expected.end(), vector.begin(), vector.end()));
//     }
//     SECTION("Vector<int>{} after pop_back should retrun std::nullopt") {
//         auto result = vector.pop_back();
//         REQUIRE(!result.has_value());
//     }
// }
 TEST_CASE("Iterator to begin of vector after using * opeartor should show first element of vector. Iterator++ and ++Iteratot should move iterator forward."){
    Vector<int> vec{1,2,3,4,5,6};
    Vector<int>::iterator it = vec.begin();
    Vector<int>::const_iterator cit = vec.cbegin();
    SECTION("Iterator *to begin shoud be equal 1"){
        REQUIRE(*it == 1);
    } 
    SECTION("Const_iterator *to begin shoud be equal 1"){
        REQUIRE(*cit == 1);
    }   
    SECTION("Preincrementation  iterator and use operator *to begin shoud be equal 2"){
        ++it;
        REQUIRE(*it == 2);
    } 
    SECTION("Preincrementation  const_iterator and use operator *to begin shoud be equal 2"){
        ++cit;
        REQUIRE(*cit == 2);
    }
    SECTION("Postincrementation  iterator and use operator *to begin shoud be equal 2"){
        it++;
        REQUIRE(*it == 2);
    } 
    SECTION("Postincrementation  const_iterator and use operator *to begin shoud be equal 2"){
        cit++;
        REQUIRE(*cit == 2);
    }  
 }
 TEST_CASE("Iterator to end and --Iterator and Iterator-- should give last element of given vector"){
    Vector<int> vec{1,2,3,4,5,6};
    Vector<int>::iterator it = vec.end();
    Vector<int>::const_iterator cit = vec.cend();
   
  
    SECTION("Predecrementation  iterator and use operator *to begin shoud be equal 6"){
        --it;
        REQUIRE(*it == 6);
    } 
    SECTION("Predecrementation  const_iterator and use operator *to begin shoud be equal 6"){
        --cit;
        REQUIRE(*cit == 6);
    }
   
 }