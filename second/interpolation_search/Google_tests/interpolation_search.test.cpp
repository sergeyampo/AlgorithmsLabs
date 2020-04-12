//
// Created by sergeyampo on 08.04.2020.
//
#include "gtest/gtest.h"
#include <vector>
#include <list>
#include "../interpolation_search.h"

using namespace std;

TEST(InterpolationSearch, FirstVec){
    vector<int> vec = { 2, 7, 30, 40, 80, 82, 90, 110, 112, 123, 130, 150 };

    EXPECT_EQ(interpolation_search(begin(vec), end(vec), 123).value_or(-1), 9);
}

TEST(InterpolationSearch, SecondVec){
    vector<int> vec = {10, 12, 13, 16, 18, 19, 20, 21,
                        22, 23, 24, 33, 35, 42, 47};
    EXPECT_EQ(interpolation_search(begin(vec), end(vec), 18).value_or(-1), 4);
}

TEST(InterpolationSearch, FirstList){
    list<int> lst = { 2, 7, 30, 40, 80, 82, 90, 110, 112, 123, 130, 150 };

    EXPECT_EQ(interpolation_search(begin(lst), end(lst), 123).value_or(-1), 9);
}