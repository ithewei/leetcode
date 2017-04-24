#include <string>
using namespace std;

string convert(string s, int numRows) {
	if (numRows == 1)
		return s;
	string ret;
	int colSpan = 2*(numRows-1);
	for (int i = 0; i < numRows; i++){
		int span = 2*(numRows-(i+1));
		int index = i;
		while (index < s.size()){
			ret.append(1,s[index]);
			if (span == 0){
				span = colSpan;
			}
			index += span;
			span = colSpan - span;
		}
	} 
	return ret;
}

int main(){
	string ret = convert("0123456789", 4);
	return 0;
}