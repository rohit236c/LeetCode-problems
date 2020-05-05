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


int minSetSize(vector<int>& arr) {
	unordered_map<int,int>m;
	int size = arr.size();
	for(int n: arr) {
		m[n]++;
	}
	int ans = 0;
	priority_queue<PII>pq;
	for(auto i: m) {
		pq.push({i.second,i.first});
	}
	int f = 0;
	while(ans < (size/2)) {
		int top = pq.top().first;
		ans += top;
		f++;
		pq.pop();
	}
	return f;
}
int minSetSizeII(vector<int>& arr) {
	VI nums(1e5,0);
	int size = arr.size();
	for(int n: arr) {
		nums[n]++;
	}
	sort(nums.begin(), nums.end(), greater<int>());
	int ans = 0;
	int idx = 0;
	while(ans < (size/2)) {
		ans += nums[idx];
		idx++;
	}
	
	return idx;
}

void solve() {
	VI arr{2,28,92,30,100,52,28,48,91,27,66,19,11,53,91,95,74,51,65,65,96,81,21,55,98,3,2,89,99,57,78,34,50,2,57,76,23,90,89,36,53,22,73,59,95,45};

	cout << minSetSizeII(arr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}