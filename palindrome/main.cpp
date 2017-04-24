#include <stdio.h>
#include <string>
using namespace std;

string longestPalindrome(string s) {
	int start = 0;
	int end = 0;

	int tmp_start = 0;
	int tmp_end = 0;
	bool bFind = false;
	bool bRepeat = false;

	for (int i = 1; i < s.size(); i++){
		if (bFind){
			if (bRepeat && s[i] == s[i-1]){
				tmp_end++;
				continue;
			}else{
				bRepeat = false;
			}
			if (tmp_start - 1 >= 0 && s[tmp_start-1] == s[i]){
				tmp_start--;
				tmp_end++;
			}else{
				bFind = false;
				if (tmp_end - tmp_start > end - start){
					start = tmp_start;
					end = tmp_end;
				}
				i = (tmp_start + tmp_end)/2 + 2;//此处i需要跳转到center+2的位置
			}
		}
		if (!bFind){
			if (s[i] == s[i-1]){
				tmp_start = i-1;
				tmp_end = i;
				bFind = true;
				bRepeat = true;
			}
			if (i-2 >= 0 && s[i] == s[i-2]){
				tmp_start = i-2;
				tmp_end = i;
				bFind = true;
			}
		}
	}

	if (tmp_end - tmp_start > end - start){
		start = tmp_start;
		end = tmp_end;
	}

	return s.substr(start,end-start+1);
}

int main(){
	string ret = longestPalindrome("cabababac");

	ret.append(1,'w');
	return 0;
}