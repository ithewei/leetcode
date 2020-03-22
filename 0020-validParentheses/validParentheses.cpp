/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

#include <stdio.h>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isLeftParenthesis(char c) {
        return c == '(' || c == '[' || c == '{';
    }

    bool isRightParenthesis(char c) {
        return c == ')' || c == ']' || c == '}';
    }

    bool isPairs(char c1, char c2) {
        switch(c1) {
        case '(': return c2 == ')';
        case '[': return c2 == ']';
        case '{': return c2 == '}';
        }
        return false;
    }

    bool isValid(string s) {
        stack<char> chars;
        for (auto& c : s) {
            if (isLeftParenthesis(c)) {
                chars.push(c);
            }
            else if (isRightParenthesis(c)) {
                if (chars.empty() || !isPairs(chars.top(), c)) return false;
                chars.pop();
            }
        }
        return chars.empty();
    }
};

int main() {
    Solution sln;
    bool b = sln.isValid("{{[[(())]]}}");
    printf("%d\n", (int)b);
    return 0;
}
