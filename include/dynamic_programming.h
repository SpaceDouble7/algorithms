//
// Created by Admin on 2015/11/20.
//

#ifndef ALGORITHMS_DYNAMIC_PROGRAMMING_H
#define ALGORITHMS_DYNAMIC_PROGRAMMING_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
namespace zy_d_p {
    std::vector<int> longestIncreasingSubsequence(std::vector<int> sequence);
    void test_longestIncreasingSubsequence();

    int editDistance(std::string s1, std::string s2);
    void test_editDistance();
}
#endif //ALGORITHMS_DYNAMIC_PROGRAMMING_H
