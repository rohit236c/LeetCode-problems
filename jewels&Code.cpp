#include<bits/stdc++.h>
using namespace std;
int numJewelsInStones(string J, string S) {
        long long int mask = 0;
        for(int i = 0; i < J.size(); i++) {
        	int bit = J[i] - 'A';
        	cout<<bit<<endl;
        }
        int cnt = 0;
        // for(int i = 0; i < S.size(); i++) {
        //     if(s.find(S[i]) != s.end()) {
        //         cnt++;
        //     }
        // }
        return cnt;
   }

int main() {
	
	numJewelsInStones("aA","aAAbbbbb");
	return 0;
}