#define CATCH_CONFIG_MAIN


#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

/**
 * Factorial Test Case
 */
TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}

/**
 * AddN Test Case
 */
TEST_CASE("AddN adds n to each element of the vector", "[AddN]") {

    SECTION("Adding 5 to each element of the vector") {
        std::vector<int> input = {1, 2, 3};
        std::vector<int> expected = {6, 7, 8};
        REQUIRE(AddN(input, 5) == expected);
    }

    SECTION("Adding 0 to each element of the vector") {
        std::vector<int> input = {1, 2, 3};
        std::vector<int> expected = {1, 2, 3};
        REQUIRE(AddN(input, 0) == expected);
    }

    SECTION("Adding negative number to each element of the vector") {
        std::vector<int> input = {1, 2, 3};
        std::vector<int> expected = {-4, -3, -2};
        REQUIRE(AddN(input, -5) == expected);
    }

    SECTION("Empty vector remains empty") {
        std::vector<int> input = {};
        std::vector<int> expected = {};
        REQUIRE(AddN(input, 5) == expected);
    }

    SECTION("Adding to a single-element vector") {
        std::vector<int> input = {10};
        std::vector<int> expected = {15};
        REQUIRE(AddN(input, 5) == expected);
    }

    SECTION("Adding large numbers") {
        std::vector<int> input = {1000000, 2000000, 3000000};
        std::vector<int> expected = {1000050, 2000050, 3000050};
        REQUIRE(AddN(input, 50) == expected);
    }
}

/**
 * Sign Test Case
 */
TEST_CASE("Sign returns correct result based on number", "[Sign]") {

    SECTION("Positive number returns 1") {
        REQUIRE(Sign(10) == 1);
        REQUIRE(Sign(100) == 1);
        REQUIRE(Sign(9999) == 1);
    }

    SECTION("Negative number returns -1") {
        REQUIRE(Sign(-10) == -1);
        REQUIRE(Sign(-100) == -1);
        REQUIRE(Sign(-9999) == -1);
    }

    SECTION("Zero returns 1") {
        REQUIRE(Sign(0) == 1);
    }
}
