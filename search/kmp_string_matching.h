#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

/**Knuth-Morris-Pratt algorithm**
*  Time complexity: O(m + n)    *
*  Auxiliary space: O(m)        *
*********************************/

vector<int> make_lps_array(const string& pattern);

vector<int> kmp_search(const string& pattern, const string& text)
{
    vector<int> res;
    auto lps_array = make_lps_array(pattern);
    for(int i(0), j(0); i < text.length(); )
    {
        if(pattern[j] == text[i])
        {
            ++j;
            ++i;
        }

        if(j == pattern.length())
        {
            res.push_back(i-j);
            j = 0;
        }
        else if(i < text.length() && pattern[j] != text[i])
        {
            if(j != 0)
                j = lps_array[j-1];
            else
                ++i;
        }
    }

    return res;
}

vector<int> make_lps_array(const string& pattern)
{
    vector<int> res(pattern.length());
    for(int i(1), j(0); i < pattern.length(); )
    {
        if(pattern[i] == pattern[j])
        {
            res[i] = ++j;
            ++i;
        }
        else
        {
            if(j != 0)
                j = res[j-1];
            else
            {
                res[i] = 0;
                ++i;
            }
        }

    }

    return res;
}