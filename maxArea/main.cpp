int maxArea(int* height, int heightSize) {
	long long max = 0;
	int s = 0;
	int e = heightSize - 1;
	int ss,ee;
	while (s < e){
		int area = (e-s)*(height[s] < height[e] ? height[s] : height[e]);
		if (area > max){
			max = area;
			ss = s;
			ee = e;
		}
		if (height[s] < height[e]){
			while (height[++s] <= height[ss]) {}
		}else{
			while (height[--e] < height[ee]) {}
		}
	}

	return max;
}

int main(){
	int height[2] = {1,2};
	int ret = maxArea(height,2);
	return ret;
}