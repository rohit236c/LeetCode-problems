#include<bits/stdc++.h>
using namespace std;
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

//--------------------------------------------------------//
void combinationSumUtilII(std::vector<int> &nums, int target, int idx, std::vector<std::vector<int>> &res, std::vector<int> ans) {

	if (nums.size() == idx || target == 0) {
		if (target == 0) {
			res.push_back(ans);
			return ;
		}
		return ;
	}
	set<int>s;

	for (int i = idx; i < nums.size(); ++i)
	{
		if (target - nums[i] >= 0 && s.find(nums[i]) == s.end()) {
			ans.push_back(nums[i]);
			s.insert(nums[i]);
			combinationSumUtilII(nums, target - nums[i], i + 1, res, ans);
			ans.pop_back();
		}
	}
}

std::vector<std::vector<int>> combinationSumII(std::vector<int> &nums, int target) {
	std::vector<std::vector<int>> res;
	std::vector<int> ans;
	sort(nums.begin(), nums.end());
	combinationSumUtilII(nums, target, 0, res, ans);
	return res;
	// return ans;
}

//------------------------------------------------//
void combinationSumUtil(std::vector<int> &nums, int target, int idx,    std::vector<std::vector<int>> &res, std::vector<int> ans) {

	if (nums.size() == idx || target == 0) {
		if (target == 0) {
			res.push_back(ans);
			return ;
		}
		return ;
	}


	for (int i = idx; i < nums.size(); ++i)
	{
		if (target - nums[i] >= 0) {
			ans.push_back(nums[i]);
			combinationSumUtil(nums, target - nums[i], i, res, ans);
			ans.pop_back();
		}
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	std::vector<std::vector<int>> res;
	std::vector<int> ans;
	combinationSumUtil(candidates, target, 0, res, ans);
	return res;
}













//------------------------------///-------------//-------------------//
void solve() {
	int n, target;
	cin >> n >> target;
	vector <int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	VVI ans  = combinationSumII(nums, target);
	// int ans = combinationSum01(nums, target, 0, "");
	std::vector<int> v(2, 0);
	// for (int i : v) {
	// 	cout << i << " ";
	// }
	for (auto K : ans) {
		for (int i : K) {
			cout << i << " ";
		}
		cout << endl;
	}
	// cout << ans;
}


int main() {

	solve();

	return 0;
}