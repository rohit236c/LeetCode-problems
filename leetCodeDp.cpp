#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef std::vector<bool> VB;
typedef std::vector<VB> VVB;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


//-------------------------------------------------------------//
template<class T>
void PrintM(std::vector<T> v) {
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
void printV(VI v) {
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
void printVS(std::vector<string> v) {
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void print2D(VVI matrix) {
	for (auto K : matrix) {
		for (int i : K) {
			cout << i << " ";
		}
		cout << endl;
	}
}
void input2D(VVI &intervals, int n, int m) {
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> intervals[i][j];
		}
	}
}
void targetQues(VI &nums, int n) {
	int target;
	cin >> target;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
}
//---------------------------jump to last position---------------------------//
int jumpII(vector<int>& nums) {
	int n = nums.size();
	vector<int>dp(n, 1e6);
	dp[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {

		int toGo = nums[i];
		int ans = (int)1e6;
		for (int j = 1; j <= toGo && i + j < n; j++) {
			ans = min(dp[i + j], ans);
		}
		dp[i] = 1 + ans;
	}
	printV(dp);
	return dp[0];
}
//-----------------------longest Palindromic substring--------------------//
VVB lpsDp(string str) {
	VVB dp(str.size(), std::vector<bool> (str.size(), false));
	int maxLen = 1, begin = 0, end = 0;
	for (int gap = 0; gap < str.size(); gap++) {
		for (int i = 0, j = gap; j < str.size(); j++, i++) {
			if (gap == 0) {
				dp[i][j] = true;
			} else if (gap == 1 && str[i] == str[j]) {
				dp[i][j] = true;

			} else if (str[i] == str[j] && dp[i + 1] == dp[j - 1]) {
				dp[i][j] = dp[i + 1][j - 1];
			}
			if (dp[i][j] && maxLen < j - i + 1) {
				maxLen = j - i + 1;
				begin = i;
			}
		}
	}
	cout << str.substr(begin, maxLen) << endl;
	return dp;
}
int longestPalindromicSubstring(string str) {
	VVI dp(str.size(), std::vector<int> (str.size(), 0));

	VVB isPali = lpsDp(str);
	int maxLen = 1, begin = 0, end = 0;
	for (int gap = 0; gap < str.size(); gap++) {
		for (int i = 0, j = gap; j < str.size(); j++, i++) {
			if (gap == 0) {
				dp[i][j] = 1;
			} else if (gap == 1 && str[i] == str[j]) {
				dp[i][j] = 2;
				maxLen = 2;
				begin = i;
				end = j;
			} else if (str[i] == str[j] && isPali[i + 1][j - 1]) {
				dp[i][j] = dp[i + 1][j - 1] + 2; // j - i + 1
				if (maxLen < dp[i][j]) {
					maxLen = dp[i][j];
					begin = i;
					end = j;
				}

			} else {
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << str.substr(begin, maxLen) << endl;
	return dp[0][str.size() - 1];
}
//------------------------------climb stairs fibonacci series type--------------------------------------//
int climbStairs(int n) {
	vector<int>dp(n + 1, 0);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		if (i - 2 >= 0) dp[i] += dp[i - 2];
		if (i - 1 >= 0) dp[i] += dp[i - 1];
	}
	// printV(dp);
	return dp[n];
}
//-----------------------Min distance to reach-------///-------------//-------------------//

int minDistance(string word1, string word2) {
	VVI dp(word1.size() + 1, VI(word2.size() + 1, 0));

	for (int i = 0; i <= word1.size(); i++) {
		for (int j = 0; j <= word2.size(); j++)
		{
			if (i == 0 && j == 0) {
				dp[i][j] = 0;
				continue;
			}
			if (i == 0) {
				dp[i][j] = 1 + dp[i][j - 1];
				continue;
			}
			if (j == 0) {
				dp[i][j] = 1 + dp[i - 1][j];
				continue;
			}
			if (word1[i - 1] == word2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
		}
	}
	return dp[word1.size()][word2.size()];
}
///--------------------------Longest Increasing subsequence-------------------------------------------///
int LIS(std::vector<int> &num) {
	if (num.size() <= 0) return 0;
	VI dp(num.size(), 1);
	int maxVal = 1;
	for (int i = 1; i < num.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (num[j] < num[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		maxVal = max(maxVal, dp[i]);
	}
	printV(dp);
	return maxVal;
}
int LIS_II(std::vector<int> &num) {
	int n = num.size();
	if (num.size() <= 0) return 0;
	VI LIS;
	LIS.push_back(num[0]);
	int maxVal = 1;
	int len = 1;
	for (int i = 1; i < n; ++i)
	{
		int low = 0;
		int high = len - 1;
		
		if (num[i] > LIS[high]) {
			LIS.push_back(num[i]);
			len++;
			continue;
		}
		//find the exact position of the element......
		while (low < high) {
			int mid = (low + high) / 2;
			if (LIS[mid] < num[i]) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		LIS[high] = num[i];
		// parent[i] = LIS[low - 1];

	}
	// printV(LIS);
	return LIS.size();
}
//---------------------Is a pattern subsequence of the string---------------------------------------//
bool isSubsequence(string s, string t) {
	if (s.length() > t.length())
		return false;
	if (s.empty() || t.empty())
		return true;
	int sIndex = 0;
	for (int i = 0; i < t.size(); ++i)
	{
		if (sIndex == s.size()) {
			return true;
		}
		if (s[sIndex] == t[i]) sIndex++;
	}
	return false;
}

void solve() {
	VI nums  = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	cout << LIS_II(nums);
}
int main() {
	solve();
}