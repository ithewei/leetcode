/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

int maxArea(int* height, int heightSize) {
    int maxarea = 0;
    int left = 0;
    int right = heightSize - 1;
    int w, h, area;
    while (left < right) {
        w = right - left;
        h = height[left];
        if (height[left] < height[right]) {
            ++left;
        }
        else if (height[left] > height[right]) {
            h = height[right];
            --right;
        }
        else {
            ++left; --right;
        }
        area = w * h;
        if (area > maxarea) maxarea = area;
    }
    return maxarea;
}

#include <stdio.h>
int main() {
    int heights[] = {1,8,6,2,5,4,8,3,7};
    int maxarea = maxArea(heights, sizeof(heights)/sizeof(*heights));
    printf("maxarea=%d\n", maxarea);
}
