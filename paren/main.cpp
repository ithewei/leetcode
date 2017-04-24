#include <string>
using namespace std;

int main(){
	string str = "abc";
	int len = str.size();
	str[str.size()-1] = '\0';
	len = str.size();
	str.erase(str.end()-1);
	len = str.size();
	return len;
}