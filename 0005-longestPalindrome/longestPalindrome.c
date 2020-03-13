/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

#include <stdio.h>
int isPalindrome(char* b, char* e) {
    while (b < e && *b == *e) {
        ++b;
        --e;
    }
    return b >= e;
}

char * longestPalindrome(char * s) {
    if (!s || !*s) return s;
    char* e = s;
    while (*e) {++e;}
    --e;
    char* maxpos = s;
    int maxlen = 1;
    char* pb = s;
    char* pe = e;
    while (e - pb >= maxlen) {
        pe = e;
        while (pe - pb >= maxlen) {
            if (*pe == *pb && isPalindrome(pb, pe)) {
                int len = pe - pb + 1;
                if (len > maxlen) {
                    maxpos = pb;
                    maxlen = len;
                }
                break;
            }
            --pe;
        }
        ++pb;
    }
    maxpos[maxlen] = '\0';
    return maxpos;
}

int main() {
    char str[] = "babad";
    printf("%s\n", longestPalindrome(str));
    return 0;
}
