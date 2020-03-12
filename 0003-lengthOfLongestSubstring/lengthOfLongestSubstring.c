/*
Given a string, find the length of the longest substring without repeating characters.
Example 1:
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

#include <stdio.h>
#include <string.h>
// slide window
// look-up table
// T(n) = O(n)
// S(n) = O(1)
int lengthOfLongestSubstring(char * s) {
    int table[0xFF];
    memset(table, -1, sizeof(table));
    int maxlen = 0;
    int begin = 0;
    int end = 0;
    int findidx = 0;
    int ch;
    while ((ch = s[end]) != '\0') {
        findidx = table[ch];
        if (findidx >= begin) {
            int len = end - begin;
            maxlen = len > maxlen ? len : maxlen;
            begin = findidx + 1;
        }
        table[ch] = end;
        ++end;
    }
    int len = end - begin;
    maxlen = len > maxlen ? len : maxlen;
    return maxlen;
}

int main() {
    const char* s = "abcabcbb";
    int len = lengthOfLongestSubstring((char*)s);
    printf("len=%d\n", len);
    return 0;
}
