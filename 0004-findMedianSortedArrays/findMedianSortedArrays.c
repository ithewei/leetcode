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
    // ensure m <= n
    if (m > n) {
        return findMedianSortedArrays(B, n, A, m);
    }

    int left = 0;
    int right = m;
    int i = (left+right)/2;
    int j = (m + n) / 2 - i;
    while (left <= right) {
        i = (left+right)/2;
        j = (m + n) / 2 - i;
        if (i > 0 && A[i-1] > B[j]) {
            right = i-1;
        }
        else if (i < m && B[j-1] > A[i]) {
            left = i+1;
        }
        else {
            // i == 0 || i == m || (B[j-1] <= A[i] && A[i-1] <= B[j])
            break;
        }
    }

    // Boundary judgments carefull
    int rmin = i == n ? B[j] : (j == n ? A[i] : MIN(A[i], B[j]));
    if ((m + n) % 2 == 1) {
        return rmin;
    }
    int lmax = i == 0 ? B[j-1] : (j == 0 ? A[i-1] : MAX(A[i-1], B[j-1]));
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

