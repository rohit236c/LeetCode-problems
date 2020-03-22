#include<bits/stdc++.h>
using namespace std;


int lengthOfSubstring(string s) {
	set<char>set;
	int n = s.length();
	int i = 0, j = 0, ans = 0;
	while (i < n && j < n) {
		if (set.find(s[j]) == set.end()) {
			set.insert(s[j]);
			j++;
			ans = max(ans, j - i);
		}
		else {
			set.erase(s[i]);
			i++;
		}
	}
	return ans;
}

int main() {

	int ans = lengthOfSubstring("adddababb");
	cout << ans;
	return 0;
}