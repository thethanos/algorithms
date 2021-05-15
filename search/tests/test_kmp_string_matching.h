#include <gtest/gtest.h>

#include "kmp_string_matching.h"

TEST(KMPAlgorithmTest, KMPAlgorithmTest)
{
    vector<int> answer1{0, 7};
    vector<int> result1 = kmp_search("abcd", "abcdefgabcd");
    ASSERT_TRUE(std::equal(result1.begin(), result1.end(), answer1.begin()));

    vector<int> answer2{10, 19};
    vector<int> result2 = kmp_search("ABABCABAB", "ABABDABACDABABCABABABABCABAB");
    ASSERT_TRUE(std::equal(result2.begin(), result2.end(), answer2.begin()));

    vector<int> answer3{14};
    vector<int> result3 = kmp_search("aaaabc", "Adhfglhmsflflkaaaabcfdsldkgmslfgm");
    ASSERT_TRUE(std::equal(result3.begin(), result3.end(), answer3.begin()));
}   