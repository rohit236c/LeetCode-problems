#include<bits/stdc++.h>
using namespace std;
int numJewelsInStones(string J, string S) {
	long long int mask = 0;
	for (int i = 0; i < J.size(); i++) {
		int bit = J[i] - 'A';
		mask = mask | (1 << bit);
	}
	int cnt = 0;
	for (int i = 0; i < S.size(); i++) {
		int bit = S[i] - 'A';
		if (mask & (1 << bit)) {
			cnt++;
		}
	}
	return cnt;
}
string defangIPaddr(string address) {
	string ans = "";
	int k = 0;
	for (int i = 0; i < address.size(); i++) {
		if(address[i] == '.') {
			char p = '[';
			ans.push_back(p);
			p = '.';
			ans.push_back(p);
			p = ']';
			ans.push_back(p);
		} else {
			ans.push_back(address[i]);
		}
		
	}
	return ans;
}

int main() {

	// cout << numJewelsInStones("aAz", "aAAzbbbbb");
	cout<<defangIPaddr("255.100.50.0");
	return 0;
}