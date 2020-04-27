#include<bits/stdc++.h>
using namespace std;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9	
#define MOD 1000000007
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

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
	if (ans.size() == n.size()) {
		k--;
		cout << ans << endl;
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
string fractionToDecimal(int numerator, int denominator) {
	if (numerator == 0) return "0";
	if (numerator % denominator == 0) {
		int ans = (double)(numerator) / (double)(denominator);
		return to_string(ans);
	}

	string ans = "";
	double num = 0.0;
	int curNum = numerator;
	return ans;
}
vector<int> diStringMatch(string S) {
	int n = S.size();
	VI ans(n+1, 0);
	if(n == 0) {
		return ans;
	}
	int start = 0, end = n;
	for(int i = 0; i < n; i++) {
		if(S[i] == 'I') {
			ans[i] = start++;
		} else {
			ans[i] = end--;
		}
	}
	if(S[n-1] == 'I') {
		ans[n] = start;
	} else {
		ans[n] = end;
	}
	return ans;
}
void solve() {
	// cout << fixed << std::setprecision(5) << myPow(2, -2) ;
	// // cout<<getPermutation(123, 3);
	// int i = 200, n = 80;
	// int cnt = 0;
	// while (i >= n) {
	// 	i = i - 2;
	// 	cnt++;
	// 	n++;
	// }
	// cout << cnt;
	// cout << fractionToDecimal(2, 2);
	VI ans = diStringMatch("III");

	for(int i: ans) cout << i << " ";
}

int main() {
	solve();

	return 0;
}