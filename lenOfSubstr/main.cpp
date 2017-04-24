#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
	int pos[256];
	memset(pos, -1, sizeof(int)*256);
	int start = -1;
	int maxlen = 0;
	for (int i = 0; i < strlen(s); i++){
		if (pos[s[i]] > start)
			start = pos[s[i]];
		maxlen = maxlen > (i - start) ? maxlen : (i - start);
		pos[s[i]] = i;
	}
	return maxlen;
}

int main(){
	int ret = lengthOfLongestSubstring("tmmzuxt");
	return 0;
}