#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0) return "";
	string ret;
	char c;
	for (int s = 0;; s++) {
		for (int v = 0; v < strs.size(); v++){
			if (s >= strs[v].size())
				return ret; 
			if (v == 0){
				c = strs[v][s];  
			}else{
				if (strs[v][s] != c)
					return ret;
			} 
		} 
		ret+=c;
	}
	return ret;
}

int main(){
	vector<string> param;
	param.push_back("a");
	param.push_back("ab");
	param.push_back("abc");
	string ret = longestCommonPrefix(param);
	return 0;
}