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

VVI groupThePeopleII(VI groupSizes) {
	VVI ans;
	int n = (int)groupSizes.size();
	unordered_set<int>set;
	for (int i = 0; i < groupSizes.size(); i++) {
		int cnt = 1;
		VI g;
		g.PB(i);
		if(set.find(i) != set.end()) {
			continue;
		}
		set.insert(i);
		for (int j = i + 1; j < n; j++) {
			if (groupSizes[i] == groupSizes[j] && cnt < groupSizes[i] && set.find(j) == set.end()) {
				g.PB(j);
				set.insert(j);
				cnt++;
			}
		}
		ans.PB(g);
	}
	return ans;
}
void printV(VI v) {
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
void solve() {
	VI g{2,1,3,3,3,2};
	// VVI ans = groupThePeople(g);
	VVI ans = groupThePeopleII(g);
	cout << ans.size() << endl;
	for (VI k : ans) {
		printV(k);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}