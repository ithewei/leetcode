#include <stdio.h>
#include <limits.h>

//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//	int *pA,*pB;
//	int m,n;
//	if (nums1Size < nums2Size){
//		pA = nums1;
//		pB = nums2;
//		m = nums1Size;
//		n = nums2Size;
//	}else{
//		pA = nums2;
//		pB = nums1;
//		m = nums2Size;
//		n = nums1Size;
//	}
//
//	for (int i = 0; i <= m; i++){
//		int j = (m+n)/2 - i;
//		int aL,ar,bL,br;
//		if (i > 0){
//			aL = pA[i-1];
//		}else{
//			aL = INT_MIN;
//		}
//		if (j > 0){
//			bL = pB[j-1];
//		}else{
//			bL = INT_MIN;
//		}
//		if (i < m){
//			ar = pA[i]; 
//		}else{
//			ar = INT_MAX;
//		}
//		if (j < n){
//			br = pB[j];
//		}else{
//			br = INT_MAX;
//		}
//		if (aL <= br && bL <= ar){
//			if ((m+n)%2 == 1){
//				return ar < br ? ar : br;
//			}else{
//				return ((aL > bL ? aL : bL) + (ar < br ? ar : br)) / (double)2.0;
//			}
//		}
//	} 
//	return 0;
//}

//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//	int m = (nums1Size-1)/2;
//	int n = nums1Size/2;
//	int x = (nums2Size-1)/2;
//	int y = nums2Size/2;
//	while (m <= nums1Size && n >= 0 && x <= nums2Size && y >= 0){
//		int L1 = (m >= 0 && m < nums1Size) ? nums1[m] : INT_MIN;
//		int R1 = (n >= 0 && n < nums1Size) ? nums1[n] : INT_MAX;
//		int L2 = (x >= 0 && x < nums2Size) ? nums2[x] : INT_MIN;
//		int R2 = (y >= 0 && y < nums2Size) ? nums2[y] : INT_MAX;
//		if (L1 > R2){
//			m--;n--;
//			x++;y++;
//		}else if(L2 > R1){
//			m++;n++;
//			x--;y--;
//		}else{
//			return ((L1 > L2 ? L1 : L2) + (R1 < R2 ? R1 : R2)) / (double)2.0;
//		}
//	}
//
//	return 0;
//}

//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//	int *pA,*pB;
//	int m,n;
//	if (nums1Size < nums2Size){
//		pA = nums1;
//		pB = nums2;
//		m = nums1Size;
//		n = nums2Size;
//	}else{
//		pA = nums2;
//		pB = nums1;
//		m = nums2Size;
//		n = nums1Size;
//	}
//
//	for (int i = 0; i <= m; i++){
//		int j = (m+n)/2 - i;
//		int L1 = i > 0 ? pA[i-1] : INT_MIN;
//		int R1 = i < m ? pA[i] : INT_MAX;
//		int L2 = j > 0 ? pB[j-1] : INT_MIN;
//		int R2 = j < n ? pB[j] : INT_MAX;
//		if (L1 <= R2 && L2 <= R1){
//			if ((m+n)%2 == 1){
//				return R1 < R2 ? R1 : R2;
//			}else{
//				return ((L1 > L2 ? L1 : L2) + (R1 < R2 ? R1 : R2)) / (double)2.0;
//			}
//		}
//	} 
//	return 0;
//}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	if (nums1Size > nums2Size){
		return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
	}

	int start = 0;
	int end = nums1Size;
	while (start <= end){
		int i = (start + end)/2;
		int j = (nums1Size+nums2Size)/2 - i;
		int L1 = i > 0 ? nums1[i-1] : INT_MIN;
		int R1 = i < nums1Size ? nums1[i] : INT_MAX;
		int L2 = j > 0 ? nums2[j-1] : INT_MIN;
		int R2 = j < nums2Size ? nums2[j] : INT_MAX;
		if (L1 > R2){
			end = i-1;
		}else if (R1 < L2){
			start = i+1;
		}else{
			if ((nums1Size+nums2Size)%2 == 1){
				return R1 < R2 ? R1 : R2;
			}else{
				return ((L1 > L2 ? L1 : L2) + (R1 < R2 ? R1 : R2)) / (double)2.0;
			}	    
		}
	} 
	return 0;
}

int main(){
	int *a = NULL;
	int b[1] = {1};
	double c = findMedianSortedArrays(a,0,b,1);
	return c;
}