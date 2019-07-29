/*
There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume A and B cannot be both empty.

Example 1:

A = [1, 3]
B = [2]

The median is 2.0
Example 2:

A = [1, 2]
B = [3, 4]

The median is (2 + 3)/2 = 2.5
*/


#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
// T(n) = O(log(min(m, n)))
// A[0,i-1] => A[i, m-1]
// B[0,j-1] => A[j, n-1]
double findMedianSortedArrays(int* A, int m, int* B, int n) {
    // ensure m >= n
    if (n > m) {
        return findMedianSortedArrays(B, n, A, m);
    }

    if (n == 0) {
        return (A[(m-1)/2] + A[m/2]) / 2.0f;
    }

    int left = 0;
    int right = n;
    int i,j;
    while (left <= right) {
        j = (left+right)/2;
        i = (m + n + 1) / 2 - j;
        if (j > 0 && B[j-1] > A[i]) {
            // [left, j-1]
            right = j-1;
        }
        else if (j < n && A[i-1] > B[j]) {
            // [j+1, right]
            left = j+1;
        }
        else {
            // j == 0 || j == n || (A[i-1] <= B[j] && B[j-1] <= A[i]
            break;
        }
    }

    // Boundary judgments carefull
    int lmax = j == 0 ? A[i-1] : (i == 0 ? B[j-1] : MAX(A[i-1], B[j-1]));
    if ((m + n) % 2 == 1) {
        return lmax;
    }
    int rmin = j == n ? A[i] : (i == m ? B[j] : MIN(A[i], B[j]));
    return (lmax + rmin) / 2.0;
}

#include <stdio.h>
int main() {
    int m = 2;
    int A[2] = {1, 2};
    int n = 2;
    int B[2] = {3, 4};
    double median = findMedianSortedArrays(A, m, B, n);
    printf("median=%lf\n", median);
    return median;
}

