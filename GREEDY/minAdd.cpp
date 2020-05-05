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
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int minAddToMakeValid(string S) {
	if(S.size() == 0) return 0;
	int n = S.size();
	stack<char>s;
	int64 ans = 0;
	for(int i = 0; i < n; i++) {
		if(S[i] == '(') {
			s.push(S[i]);
		} else {
			if(s.empty()) ans++;
			else {
				s.pop();
			}
		}
	}
	while(!s.empty()) {
		s.pop();
		ans++;
	}
	return ans;
}

void solve() {
	cout << minAddToMakeValid("(((");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}