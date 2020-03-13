/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

#include <stdio.h>
#include <string>
#include <vector>
using std::string;
using std::vector;

/*
class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if (numRows == 1 || size <= numRows) return s;
        string ret;
        ret.reserve(size + 1);
        char* src = (char*)s.data();
        char* dst = (char*)ret.data();
        dst[size] = '\0';
        for (int i = 0; i < numRows; ++i) {
            int a = (numRows - 1 - i) * 2;
            int b = i * 2;
            int idx = i;
            *dst++ = src[idx];
            while (idx < size) {
                if (a) {
                    idx += a;
                    if (idx < size) *dst++ = src[idx]; 
                }
                if (b) {
                    idx += b;
                    if (idx < size) *dst++ = src[idx];
                }
            }
        }
        return ret;
    }
};
*/


class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if (numRows == 1 || size <= numRows) return s;
        vector<string> rows(size);
        int flag = -1;
        int r = 0;
        for (char c : s) {
            rows[r] += c;
            if (r == 0 || r == numRows - 1) flag = -flag;
            r += flag;
        }
        string ret;
        for (auto& row : rows) {
            ret += row;
        }
        return ret;
    }
};

int main() {
    string src = "PAYPALISHIRING";
    Solution sln;
    string dst = sln.convert(src, 4);
    printf("%s\n", dst.c_str());
    return 0;
}
