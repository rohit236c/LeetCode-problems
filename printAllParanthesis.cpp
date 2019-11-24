#include<bits/stdc++.h>

using namespace std;

void printParathensisUtil(int numOfOpenBrackets, int numOfCloseBrackets, string ans, std::vector<string> &result) {
	if(numOfOpenBrackets == 0 && numOfCloseBrackets == 0) {
		result.push_back(ans);
		return;
	}
	if(numOfOpenBrackets > 0) {
		printParathensisUtil(numOfOpenBrackets-1,numOfCloseBrackets,ans+'(',result);
	}
	if(numOfOpenBrackets < numOfCloseBrackets) {
		printParathensisUtil(numOfOpenBrackets,numOfCloseBrackets-1,ans+')',result);
	}
}


void printParathensis(int n) {

	std::vector<string> result;

	printParathensisUtil(n, n, "", result);

	for(auto str: result) {
		cout<<str<<endl;
	}

}

int main() {

	int n;
	n = 2;

	printParathensis(n);
	return 0;
}