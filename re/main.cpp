#include <string.h>
#include <vector>
using namespace std;

//bool isMatch(char* s, char* p) {
//	int m = strlen(s);
//	int n = strlen(p);
//	vector<vector<bool>> dp(m+1, vector<bool> (n+1,false));
//	dp[0][0] = true;//s为空p为空时匹配,s非空p空时不比配即dp[i][0] = false
//	for (int i = 0; i <= m; i++){
//		for (int j = 1; j <= n; j++){
//			if (p[j])
//		}
//	}
//	for (int i = -1; i < m ; i++){
//		for (int j = 0; j < n; j++){
//			int x = i+1;
//			int y = j+1;
//			if (p[j] == '*')
//				dp[x][y] = dp[x][y-1] || dp[x-1][y-1] && (p[j-1] == '.' || p[j-1] = s[i]);
//			else
//				dp[x][y] = dp[x-1][y-1] && (p[j] == '.' || p[j] == s[i]);
//		}
//	}
//	return dp[m][n];
//}

bool isMatch(string s, string p) {
	int m = s.size();
	int n = p.size();
	vector<vector<bool>> dp(m+1, vector<bool> (n+1,false));
	dp[0][0] = true;
	for (int i = 0; i <= m; i++)
		for (int j = 1; j <= n; j++){
			if (p[j-1] == '*')
				dp[i][j] = dp[i][j-2] || (i>0 && dp[i-1][j] && (p[j-2] == '.' || p[j-2] == s[i-1]));
			else
				dp[i][j] = i>0 && dp[i-1][j-1] && (p[j-1] == '.' || p[j-1] == s[i-1]);
		}

		return dp[m][n];
}

int main(){
	bool ret = isMatch("abc", "a*");
	return ret;
}