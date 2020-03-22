/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> letterMap(char ch) {
        switch(ch) {
        case '2': return {"a", "b", "c"};
        case '3': return {"d", "e", "f"};
        case '4': return {"g", "h", "i"};
        case '5': return {"j", "k", "l"}; 
        case '6': return {"m", "n", "o"};
        case '7': return {"p", "q", "r", "s"};
        case '8': return {"t", "u", "v"};
        case '9': return {"w", "x", "y", "z"};
        default: return {};
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        if (digits.size() == 1) return letterMap(digits[0]);
        vector<string> f1 = letterMap(digits[0]);
        vector<string> fn_1 = letterCombinations(digits.substr(1));
        vector<string> ret;
        for (auto& c : f1)
            for (auto& str : fn_1) {
                ret.push_back(c + str);
            }
        return ret;
    }
};

int main() {
    Solution sln;
    auto strs = sln.letterCombinations("23");
    for (auto& str : strs) {
        printf("%s,", str.c_str());
    }
    return 0;
}
