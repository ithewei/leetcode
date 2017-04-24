#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;
using namespace std::tr1;

//vector<int> twoSum(vector<int>& vecNums, int target){
//	vector<int> vecRet;
//	for (unsigned int i = 0; i < vecNums.size() - 1; i++){
//		int nFind = target - vecNums[i];
//		for (unsigned int j = i + 1; j < vecNums.size(); j++){
//			if (vecNums[j] == nFind){
//				vecRet.push_back(i);
//				vecRet.push_back(j);
//				return vecRet;
//			}
//		}
//	}
//	return vecRet;
//}

vector<int> twoSum(vector<int>& vecNums, int target){
	unordered_map<int, int> hashNums;
	vector<int> vecRet;
	for (int i = 0; i < vecNums.size(); i++){
		int nFind = target - vecNums[i];
		if (hashNums.find(nFind) != hashNums.end()){
			vecRet.push_back(hashNums[nFind]);
			vecRet.push_back(i);
			return vecRet;
		}
		hashNums[vecNums[i]] = i;
	}

	return vecRet;
}

int main(){
	vector<int> vecNums;
	vecNums.push_back(1);
	vecNums.push_back(2);
	vecNums.push_back(3);
	vecNums.push_back(4);
	vector<int> vecRet = twoSum(vecNums, 3);
	if (vecRet.empty()){
		printf("No result!\n");
	}else{
		printf("num1:%d, num2:%d\n", vecRet[0], vecRet[1]);
	}
	getchar();
	return 0;
}