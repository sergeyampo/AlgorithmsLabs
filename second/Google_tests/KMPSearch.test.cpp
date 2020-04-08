//
// Created by sergeyampo on 08.04.2020.
//
#include "gtest/gtest.h"
#include "../KMPSearch.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

TEST(KMPSearch, makePrefixFunctionCorrectWork){
    vector<wstring::size_type> expected_vec = { 0, 0, 0, 1, 2, 0 };
    vector<wstring::size_type> got_vec = makePrefixFunction(L"abcabd");

    EXPECT_TRUE(equal(begin(expected_vec), end(expected_vec), begin(got_vec)));
}

TEST(KMPSearch, KMPSearchTest){
    optional<wstring::size_type> FoundPos = KMPSearch(L"abcabeabcabcabd", L"abcabd");
    EXPECT_EQ(*FoundPos, 9);
}

TEST(KMPSearch, KMPSearchTestFail){
    optional<wstring::size_type> FoundPos = KMPSearch(L"abcabeabcabcabd", L"abcabdf");
    EXPECT_FALSE(FoundPos);
}