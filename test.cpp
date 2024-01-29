// Copyright 2023 Bikash Shrestha
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EDistanceTest
#include <boost/test/unit_test.hpp>
#include "EDistance.hpp"

// Test the min3 function
BOOST_AUTO_TEST_CASE(testEditDistance1) {
    EDistance test("AGCT", "AGC");
    BOOST_CHECK_EQUAL(test.optDistance(), 2);
}

BOOST_AUTO_TEST_CASE(testEditDistance2) {
    EDistance test("A", "A");
    BOOST_CHECK_EQUAL(test.optDistance(), 0);
}


BOOST_AUTO_TEST_CASE(testEditDistance3) {
    EDistance test("AGCT", "AGCT");
    BOOST_CHECK_EQUAL(test.optDistance(), 0);
}


BOOST_AUTO_TEST_CASE(testEditDistance5) {
    EDistance test("ACGT", "AGCT");
    BOOST_CHECK_EQUAL(test.optDistance(), 2);
}

