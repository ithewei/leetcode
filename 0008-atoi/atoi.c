#include <stdio.h>
#include <limits.h>

int myAtoi(char * str) {
    if (!str || !*str) return 0;
    char* p = str;
    int ret = 0;
    int sign = 1;
    char ch;
    while (*p == ' ') {++p;}
    if (*p == '+') {
        sign = 1;
        ++p;
    }
    else if (*p == '-') {
        sign = -1;
        ++p;
    }
    while ((ch = *p++) != '\0') {
        if (ch >= '0' && ch <= '9') {
            int num = (ch-'0')*sign;
            if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && num > 7)) return INT_MAX;
            if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && num < -8)) return INT_MIN;
            ret = ret * 10 + num;
        }
        else {
            break;
        }
    }
    return ret;
}

int main() {
    char str[] = "   -123hello";
    printf("%d\n", myAtoi(str));
    return 0;
}
