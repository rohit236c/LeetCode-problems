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
template<typename T>
void Print2DT(std::vector<T> v) {
	for (auto K : v) {
		for (auto i : K) {
			cout << i << " ";
		}
		cout << endl;
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
void input2DChar(std::vector<std::vector<char>> &intervals, int n, int m) {
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
//----------------------------------Gold Mine------------------------------------------------//
const int directions[] = {0, 1, 0, -1, 0};
int getMaximumGoldUtil(VVI grid, int idx, int jidx) {
	if (idx < 0 || jidx < 0 || idx >= grid.size() || jidx >= grid[0].size() || grid[idx][jidx] == 0) return 0;
	int maxGold = 0;
	int val = grid[idx][jidx];
	grid[idx][jidx] = 0;
	for (int i = 0; i < 4; i++) {
		maxGold = max(maxGold, getMaximumGoldUtil(grid, directions[i] + idx, directions[i + 1] + jidx));
	}
	grid[idx][jidx] = val;

	return val + maxGold;

}

int getMaximumGold(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	int maxVal = -1e8;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] > 0)
				maxVal = max(maxVal, getMaximumGoldUtil(grid, i, j));
		}
	}
	return maxVal;
}
class Rectangle {
public:
	int squareVal;
	int horizRect;
	int verticalRect;
	Rectangle(int s, int h, int v) {
		squareVal = s;
		horizRect = h;
		verticalRect = v;
	}
	Rectangle() {

	}
};
int maximalRectangle(vector<vector<char>>& matrix) {
	int n = matrix.size(), m = matrix[0].size();
	Rectangle r = Rectangle(0, 0, 0);
	std::vector<std::vector<Rectangle>> dp(matrix.size(), std::vector<Rectangle> (matrix[0].size(), r));

	//------------dp is initialised here-----------------------\\

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (matrix[i][j] == '0') {
				Rectangle r = Rectangle(0, 0, 0);
				dp[i][j] = r;
			} else {
				Rectangle r = Rectangle(1, 1, 1);
				dp[i][j] = r;
			}
		}
	}
	//-------------main calls---------------------------------\\

	int maxiRectangle = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (matrix[i][j] == '0') {
				Rectangle r = Rectangle(0, 0, 0);
				dp[i][j] = r;
			} else {
				// check for square length---
				int upVal = 0;
				int leftVal = 0;
				int diag = 0;
				if (i - 1 >= 0) {
					upVal = dp[i - 1][j].squareVal;
				}
				if (j - 1 >= 0) {
					leftVal = dp[i][j - 1].squareVal;
				}
				if (i - 1 >= 0 && j - 1 >= 0) {
					diag = dp[i - 1][j - 1].squareVal;
				}
				int sqVal = min(upVal, min(leftVal, diag)) + 1;
				//--------------------------------------------//
				int horizRect = 1;
				int verticalRect = 1;
				// rectangle Val
				if (i - 1 >= 0) {
					verticalRect = dp[i - 1][j].verticalRect + 1;
				}
				if (j - 1 >= 0) {
					horizRect = dp[i][j - 1].horizRect + 1;
				}
				Rectangle r = Rectangle(sqVal, horizRect, verticalRect);
				dp[i][j] = r;
				int val = max(sqVal, max(horizRect, verticalRect));
				maxiRectangle = max(maxiRectangle, val);
			}
		}
	}

	// for (auto K : dp) {
	// 	for (auto i : K) {
	// 		cout << i.squareVal << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout<<endl;
	for (auto K : dp) {
		for (auto i : K) {
			cout << i.verticalRect << " ";
		}
		cout << endl;
	}

	return maxiRectangle;

}
unsigned int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.size() == 0) return 0;
	int n = matrix.size(), m = matrix[0].size();

	if (n == 0 && m == 0) return 0;
	if (n == 1 && m == 1 && matrix[0][0] == '1') return 1;
	else if (n == 1 && m == 1 && matrix[0][0] == '0') return 0;


	std::vector<std::vector<int>> dp(matrix.size(), std::vector<int> (matrix[0].size(), 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (matrix[i][j] == '0') {
				dp[i][j] = 0;
			} else {
				dp[i][j] = 1;
			}
		}
	}
	unsigned int maximalSquare_ = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (matrix[i][j] != '0') {
				int upVal = 0;
				int leftVal = 0;
				int diag = 0;
				if (i - 1 >= 0) {
					upVal = dp[i - 1][j];
				}
				if (j - 1 >= 0) {
					leftVal = dp[i][j - 1];
				}
				if (i - 1 >= 0 && j - 1 >= 0) {
					diag = dp[i - 1][j - 1];
				}
				unsigned int sqVal = min(upVal, min(leftVal, diag)) + 1;
				dp[i][j] = sqVal;
				maximalSquare_  = max(maximalSquare_, sqVal);
			}
		}
	}

	return (maximalSquare_ * maximalSquare_);

}


//----------------------------------coin Change---------------------------------------------//
int coinChangePermu(std::vector<int> coins, int target) {
	if (coins.size() == 0) return 0;

	if (target == 0) return 1;

	std::vector<int> dp(target + 1, 0);
	dp[0] = 1;
	for (int t = 1; t <= target; t++) {
		for (int i = 0; i < coins.size(); ++i)
		{
			if (t - coins[i] >= 0) {
				dp[t] += dp[t - coins[i]];
			}
		}
	}
	return dp[target];
}
int coinChange(std::vector<int> coins, int target) {
	if (target == 0) return 0;
	if (coins.size() == 0) return 0;


	std::vector<int> toReach(target + 1, INT_MAX / 2);
	toReach[0] = 0;

	for (int i = 0; i < coins.size(); ++i) {
		int val = INT_MAX / 2;
		for (int t = 1; t <= target; t++) {
			if (t - coins[i] >= 0) {
				val = (1 + toReach[t - coins[i]]);
			}

			toReach[t] = min(toReach[t], val);

		}
	}
	if (toReach[target] == INT_MAX / 2) return -1;
	return toReach[target];
}
int cnt = 0;
int recursionCoinChangeCombi(std::vector<int> coins, int target, int &minCoin, int idx) {

	if (target == 0) {
		return 1;
	}

	int ans = 0;
	for (int i = idx; i < coins.size(); i++) {
		if (target - coins[i] >= 0) {
			cnt++;
			if (target - coins[i] == 0) {
				cout << cnt << " @ " << coins[i] << endl;
				minCoin = min(minCoin, cnt);
			}

			ans += recursionCoinChangeCombi(coins, target - coins[i], minCoin, i);
			cnt--;
		}
	}
	return ans;
}


void solve() {
	// VI nums  = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int m = 4, n = 5;
	// char ch = '5';
	// char ch2 = '1';
	// cout<<((ch + ch2) - 'a' + 1);

	// std::vector<std::vector<char>> grid(m, std::vector<char>(n));
	// input2DChar(grid, 4, 5);
	// // cout << getMaximumGold(grid);
	// // print2D(grid);
	// // cout << maximalRectangle(grid);
	// cout << maximalSquare(grid);
	// cout << endl;
	// Print2DT<std::vector<char>>(grid);
	VI coins = {1,2,5};
	int target = 1;
	// cout << coinChangeCombi(coins, 10);
	int minCoin = 1e7;
	// cout << recursionCoinChangeCombi(coins, 11, minCoin, 0) << endl;
	cout << coinChange(coins, 11);
	// cout << minCoin;
	// cout << LIS_II(nums);
}
int main() {
	solve();
}