#include<bits/stdc++.h>
using namespace std;

// double myPow(double x, int n) {
// 	double ans = 1;
// 	int t = 0;
// 	if(n < 0) {
// 		t = n;
// 		n = abs(n);
// 	}
// 	while (n) {
// 		ans *= x;
// 		n--;
// 	}
// 	int h = n, l = 1;

// 	if(t != 0) {
// 		return (1/ans);
// 	}
// 	return ans;

// }
double myPow(double x, int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return x;
	} else if (n == -1) {
		return (1 / x);
	}

	double ans = myPow(x, n / 2);
	double extra = n > 0 ? x : (1 / x);

	if (!(n & 1)) {
		return ans * ans;
	}
	else {
		return ans * ans * extra;
	}
}
string getPermutationUtil(string n, int k, string ans, int idx) {
	if(ans.size() == n.size()) {
		k--;
		cout<<ans<<endl;
		return ans;
	}
	ans = ans + n[0];
	getPermutationUtil(n, k, ans, idx++);
	ans.pop_back();
	getPermutationUtil(n, k, ans, idx++);
}

string getPermutation(int n, int k) {
	string ans = to_string(n);
	getPermutationUtil(ans, k, "", 0);
}
void solve() {
	// cout << fixed << std::setprecision(5) << myPow(2, -2) ;
	// cout<<getPermutation(123, 3);
	int i = 200, n = 80;
	int cnt = 0;
	while(i >= n) {
		i = i-2;
		cnt++;
		n++;
	}
	cout<<cnt;
}

int main() {
	solve();

	return 0;
}