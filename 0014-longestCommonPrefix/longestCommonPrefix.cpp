/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

#include "stdio.h"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        int size = strs[0].size();
        char ch;
        int i = 0;
        for (; i < size; ++i) {
            ch = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != ch) return strs[0].substr(0, i); 
            }
        }
        return strs[0];
    }
};

int main() {
    vector<string> strs{"abcd", "abc", "abcdefg"};
    Solution sln;
    string ret = sln.longestCommonPrefix(strs);
    printf("%s\n", ret.c_str());
    return 0;
}
