/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Could you solve it without converting the integer to a string?
*/

#include <stdbool.h>
bool isPalindrome(int x){
    if (x < 0) return false;
    if (x < 10) return true;
    if (x % 10 == 0) return false;
    int a = 0;
    while (x > a) {
        a = a * 10 + x % 10;
        x /= 10;
    }
    return x == a || x == a / 10;
}

#include <stdio.h>
int main() {
    int x = 123454321;
    if (isPalindrome(x)) {
        printf("%d is a palindrome number\n", x);
    }
    else {
        printf("%d is not a palindrome number\n", x);
    }
    return 0;
}
