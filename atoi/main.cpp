#include <string>
using namespace std;

int myAtoi(string str) {
	long long ret = 0;
	int sign = 1;
	bool bCheckSign = true;
	for (int i = 0; i < str.size(); i++){
		if (bCheckSign){
			if (str[i] == ' '){
				continue;
			}
			if (str[i] == '-'){
				sign = -1;
				bCheckSign = false;
				continue;
			}
			if (str[i] == '+'){
				sign = 1;
				bCheckSign = false;
				continue;
			}
		}
		if (str[i] < '0' || str[i] > '9'){
			return 0;
		}
		ret = ret*10 + str[i]- '0';
		bCheckSign = false;
		if ((int)ret != ret){
			return 0;
		}
	}  
	return ret*sign;
}

int main(){
	int ret = myAtoi("   +95");
	return ret;
}