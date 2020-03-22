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
int maximalRectangleII(vector<vector<char>>& matrix) {
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
//-------------------------------Russian Doll------------------------------//

bool compare(VI p1, VI p2) {
	if (p1[0] == p2[0]) return p1[1] > p2[1];

	return p1[0] < p2[0];
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
	if (envelopes.size() == 0) return 0;
	sort(envelopes.begin(), envelopes.end(), compare);

	VI LIS;
	// LIS[0] = 1;

	LIS.push_back(envelopes[0][1]);
	int len = 1, max_ = 1;
	for (int i = 1; i < envelopes.size(); i++) {
		if (LIS.back() < envelopes[i][1]) {
			LIS.push_back(envelopes[i][1]);
			len++;
		}
		else {
			int num = envelopes[i][1];
			int low = 0;
			int high = len - 1;

			//find the exact position of the element......
			while (low < high) {
				int mid = (low + high) / 2;
				if (LIS[mid] < num) {
					low = mid + 1;
				} else {
					high = mid;
				}
			}
			LIS[high] = num;
		}
	}
	return len;
}
//----russian doll-- using inbuilt BS------------------------------//
int maxEnvelopes(vector<pair<int, int>>& envelopes)
{
	int size = envelopes.size();
	sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int>b) {
		return a.first < b.first || (a.first == b.first && a.second > b.second);
	});
	vector<int> collector;
	for (auto& pair : envelopes)
	{
		auto iter = lower_bound(collector.begin(), collector.end(), pair.second);
		if (iter == collector.end()) collector.push_back(pair.second);
		else if (*iter > pair.second) *iter = pair.second;
	}
	return collector.size();
}
//---------------find--Target--Sum--Ways-------------------------------//
int findTargetSumWays(VI nums, int  S, int idx, int c) {
	if (idx == nums.size()) {
		if (S == 0) {
			return 1;
		}
		return 0;
	}
	int cnt = 0;

	cnt += findTargetSumWays(nums, S + nums[idx], idx + 1, 0);
	cnt += findTargetSumWays(nums, S - nums[idx], idx + 1, 0);

	return cnt;
}
int findTargetSumWays(vector<int>& nums, int S) {
	return findTargetSumWays(nums, S, 0, 0);
}

//--------------find--Target--Sum--Ways-DP---------------------------//
int findTargetSumWaysII(std::vector<int> nums, int S, int idx) {
	int posSum = 0, negativeSum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		posSum += nums[i];
		negativeSum -= nums[i];
	}
	std::vector<int> dp(posSum * 2, 0);
	dp[posSum * 2] = 1;
	dp[0] = 1;
	for (int i = 0; i < nums.size(); i++) {

	}
}
int findTargetSumWaysII(vector<int>& nums, int S) {
	return findTargetSumWaysII(nums, S, 0);
}

//-----------------------------num-decodings-hard----------------------//
int M = 1000000007;
int numDecodings(string s) {
	string a;
	cin >> a;
	s += a;
	if (s.size() == 0) return 0;
	int n = s.size();
	std::vector<int> dp(s.size() + 1, 0);
	dp[n] = 1;

	for (int i = n - 1; i >= 0; i--)
	{	string num = "";
		if (s[i] == '0') {
			dp[i] = 0;
			continue;
		}
		if (s[i] == '*') {
			dp[i] = (dp[i + 1] * 9) % M;
			num += s[i];
			num += s[i + 1];
			if ( i + 1 < n && s[i + 1] == '*' ) {
				int ans = (dp[i + 2] * 15) % M;
				dp[i] = dp[i] + ans;
				continue;
			}
			if (s[i + 1] <= '6' && s[i + 1] >= '1') {
				dp[i] += (dp[i + 2] * 2) % M;
			} else if (s[i + 1] >= '7' && s[i + 1] <= '9') {
				dp[i] += (dp[i + 2] * 1) % M;
			} else if (s[i + 1] == '0') {
				dp[i] += (dp[i + 2] * 2) % M;
			}
		} else {
			string num = "";
			num += s[i];
			num += s[i + 1];
			if (s[i + 1] != '*') {
				if (num >= "10" && num <= "26" && i + 2 <= n) {
					//two-digit h...
					dp[i] = (dp[i + 1] + dp[i + 2]) % M;
				} else {
					dp[i] = dp[i + 1] % M;
				}
			} else {
				dp[i] = dp[i + 1] % M;
				if (s[i] == '1') {
					if (s[i + 1] == '*') {
						dp[i] =  (dp[i] + (9 * dp[i + 2])) % M;
					}
				}
				else if (s[i] == '2') {
					if (s[i + 1] == '*') {
						dp[i] =  (dp[i] + (6 * dp[i + 2])) % M;
					}
				}
			}
		}
	}
	printV(dp);
	return dp[0];

}
int burstBalloons(VI &nums) {
	int max_ = INT_MIN;


	return max_;
}
bool divisorGame(int N) {
	if (N == 0) return true;
	if (N == 1) return false;
	vector<bool>dp(N + 1);
	dp[0] = true;
	dp[1] = false;
	dp[2] = true;

	for (int i = 3; i <= N; i++) {
		bool ans = dp[1];
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				ans = ans | dp[j];
			}
		}
		dp[i] = ans;
	}
	PrintM<bool>(dp);
	return dp[N];
}
int maxProfit(vector<int>& prices) {

}
class NumArray {
	vector<int>prefix;
public:
	NumArray(vector<int>& nums) {
		prefix.resize(nums.size() + 1);
		prefix[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			prefix[i] = prefix[i - 1] + nums[i];
		}
	}

	int sumRange(int i, int j) {
		// find 0, j then...
		if (i == 0) return prefix[j];
		else {
			int ans = prefix[j] - prefix[i - 1];
			return ans;
		}
	}
};

int maxProduct(vector<int>& nums) {
	if (nums.size() == 0) return 0;

	int maxProduct = nums[0], minProduct = nums[0];
	int prevMax = nums[0], prevMin = nums[0];
	int ans = INT_MIN;
	ans = nums[0];

	for (int i = 1; i < nums.size(); i++) {

		maxProduct = max(maxProduct, max(prevMax * nums[i], prevMin * nums[i]));
		minProduct = min(minProduct, min(prevMax * nums[i], prevMin * nums[i]));
		ans = max(ans, maxProduct);
		prevMax = maxProduct;
		prevMin = minProduct;

	}
	return ans;
}
//----------------------------Triangle---------------------------------------------------------------//
int minimumTotal(vector<vector<int>>& triangle) {
	int row = triangle.size();
	if (row == 0) return 0;
	int col = triangle[row - 1].size();
	VVI dp(triangle.size(), VI(col, 0));

	for (int i = row - 1; i >= 0; i--) {
		int colSize = triangle[i].size();
		for (int j = colSize - 1; j >= 0; j--) {
			if (i == row - 1) {
				dp[i][j] = triangle[i][j];
			} else {
				dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
			}
		}
	}
	// print2D(dp);
	return dp[0][0];

}
int rob(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) return 0;
	if (n == 1) return nums[0];

	VI dp(n , 0);
	VI dp2(n, 0);
	if (n == 2) return max(nums[0], nums[1]);
	int ans = INT_MIN;
	dp[0] = nums[0];
	dp2[0] = 0;
	dp[1] = nums[1];
	dp2[1] = nums[1];
	dp[2] = nums[2] + dp[0];
	dp2[2] = nums[2];
	if (n == 3)
		ans = max(nums[2], max(nums[1], nums[0]));
	else {
		ans = max(dp[2], max(dp[1], dp[0]));
	}
	for (int i = 3; i < n; i++) {
		if (i == n - 1) {
			dp2[i] = max(dp2[i - 2], dp2[i - 3]) + nums[i];
			ans = max(ans, dp2[i]);
		} else {
			dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
			dp2[i] = max(dp2[i - 2], dp2[i - 3]) + nums[i];
			ans = max(ans, max(dp[i], dp2[i]));
		}
	}
	printV(dp);
	printV(dp2);
	return ans;
}
int nthUglyNumber(int n) {
	vector<int>dp(n);
	dp[0] = 1;
	int p2 = 0, p3 = 0, p5 = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
		if (dp[i] == dp[p2] * 2) p2++;
		if (dp[i] == dp[p3] * 3) p3++;
		if (dp[i] == dp[p5] * 5) p5++;
	}
	return dp[n - 1];
}

void easySet() {
	// cout << divisorGame(5);
	// VI nums{0, 2};
	// NumArray* obj = new NumArray(nums);
	// cout << obj->sumRange(3, 5);


}
vector<int> countBits(int num) {
	VI dp(num + 1, 0);
	if (num == 0) return dp;

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= num; i++) {
		dp[i] = (i & 1) + dp[i / 2];
	}
	return dp;
}
bool isPerfectSquare(long double x)
{
	long double sr = sqrt(x);

	return ((sr - floor(sr)) == 0);
}
int numSquares(int n) {
	VI dp(n + 1, 0);
	dp[0] = 0;
	dp[1] = 1;
	if (isPerfectSquare(n)) return 1;

	for (int i = 2; i <= n; i++) {
		if (isPerfectSquare(i)) {
			dp[i] = 1;
		} else {
			int ans = INT_MAX;
			for (int j = 1; j * j <= i; j++) {
				ans = min(ans, dp[i - (j * j)] + dp[j * j]);
			}
			dp[i] = ans;
		}
	}
	return dp[n];
}
int integerBreak(int n) {
	VI dp(n + 1, 0);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int ans = INT_MIN;
		for (int j = 1; j < i; j++) {
			int ans1 = (i - j) * dp[j];
			int ans2 = dp[i - j] * dp[j];
			int ans3 = dp[i - j] * (j);
			int ans5 = (i - j) * j;
			int ans4 = max(ans1, max(ans2, ans3));

			ans4 = max(ans4, ans5);
			ans = max(ans, ans4);
		}
		dp[i] = ans;
	}
	return dp[n];
}
int countNumbersWithUniqueDigits(int n) {
	std::vector<signed int> dp(n + 1, 0);
	dp[1] = 10;
	if (n == 1) return 10;
	for (int i = 2; i <= n; i++) {
		signed int ans = 1;
		int cnt = 1;
		int num = 9;
		//optimized soln........
		// ans = ans * (9-i+2);
		while (cnt < i) {
			ans = ans * num;
			num--;
			cnt++;
		}
		ans = ans * 9;
		dp[i] = ans + dp[i - 1];
	}
	return dp[n];
}
int histogram(VI arr) {
	int n = arr.size();
	if (n == 0) return 0;
	if (n == 1) return arr[0];
	stack <int> s ;
	int area = 0;
	int maxArea = 0;
	int i = 0;
	int top;
	while (i < n)
	{
		if (s.empty() || arr[s.top()] <= arr[i]) {
			s.push(i++);
		}
		else {
			top = s.top();
			s.pop();
			area = arr[top] * (s.empty() ? i : i - s.top() - 1);
			maxArea = max(maxArea, area);
		}
	}
	// cout<<s.size() <<endl;
	while (!s.empty()) {
		top = s.top();
		s.pop();
		area = arr[top] * (s.empty() ? i : i - s.top() - 1);
		maxArea = max(maxArea, area);
	}
	return maxArea;
}
int maximalRectangle(vector<vector<char>>& nums) {
	int n = nums.size();
	if (n == 0) return 0;
	int m = nums[0].size();
	VI dp(m + 1, 0);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0) {
				if (nums[i][j] == '1') {
					dp[j] = 1;
				} else {
					dp[j] = 0;
				}
			} else {
				if (nums[i][j] == '1') {
					dp[j] += 1;
				} else {
					dp[j] = 0;
				}
			}
		}
		ans = max(ans, histogram(dp));
	}
	return ans;
}
int superEggDrop(int K, int N) {
	if (K == 1) return 1;
	if (N == 1) return 1;

	VVI dp(K + 1, VI(N + 1, 0));

	for (int i = 1; i <= K; ++i)
	{
		for (int j = 1; j <= N; j++) {
			if (i == 1) {
				dp[i][j] = j;
			}
			else if (j == 1) {
				dp[i][j] = 1;
			}
			else {
				int ans = INT_MAX;
				dp[i][j] = ans;
				for (int x = 1; x <= j; x++) {
					ans = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
					dp[i][j] = min(dp[i][j], ans);
				}
			}
		}
	}
	return dp[K][N];
}
VVI dp(100, VI(100, -1));
bool equalSubset(VI nums, int sum1, int sum2, int idx) {
	if (sum1 == sum2 && idx == nums.size()) return true;
	else if (sum1 != sum2 && idx == nums.size()) return false;

	if (dp[idx][sum1] != -1) {
		return (bool)dp[idx][sum1];
	}
	bool ansOne = equalSubset(nums, sum1 + nums[idx], sum2, idx + 1);
	bool ansTwo = equalSubset(nums, sum1, sum2 + nums[idx], idx + 1);



	dp[idx][sum2] = (int)(ansOne || ansTwo);

	return (ansOne || ansTwo);
}
bool equalSubsetII(VI nums) {
	if (nums.size() == 0) return true;
	if (nums.size() == 1) return false;
	int sum = 0;
	for (int n : nums) sum += n;

	if (sum % 2 != 0) return false;


	VVB dp2(nums.size(), VB((sum / 2) + 1, false));

	dp2[0][0] = true;
	// we try to find the half sum using all elements if yeh possible h toh return true nhi toh return false
	for (int i = 1; i < nums.size(); i++) {
		for (int j = 0; j <= (sum / 2) ; j++) {
			//don't include the number || include the number and bta                          baaki sum bnana possible hai
			dp2[i][j] = (dp2[i - 1][j]) || (j >= nums[i] ? dp2[i - 1][j - nums[i]] : false);
		}
	}
	return dp2[nums.size() - 1][sum / 2];
}

int numTrees(int n) {
	if (n == 0) return 1;

	VI dp(n + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}

	return dp[n];
}

bool checkWord(string word, VS &wordDict) {
	for (string s : wordDict)
	{
		if (s.compare(word) == 0)
			return true;
	}

	return false;
}

bool wordBreakUtil(string s, set<string>set, int idx, VI &dp) {

	// if (s.length() == 0) return true;

	if (idx == s.length()) return true;
	if (dp[idx] != -1) return (bool)dp[idx];

	bool res = false;
	for (int i = idx; i < s.size(); i++) {
		string str = s.substr(idx, i + 1);
		cout << str << endl;
		if (set.find(str) != set.end()) {
			cout << "here " << str << endl;
			res = wordBreakUtil(s, set, i + 1, dp);
			if (res) {
				dp[idx] = true;
				return true;
			}
		}
	}
	dp[idx] = (bool)res;
	return res;
}
bool wordBreak(string s, vector<string>& wordDict) {
	if (s.size() == 0) return true;

	set<string>set;
	for (string str : wordDict) {
		set.insert(str);
	}
	std::vector<int> memo(s.size(), -1);
	bool ans = wordBreakUtil(s, set, 0, memo);
	printV(memo);
	return ans;
}



void hardSet() {
	std::vector<std::vector<char>> v = {
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'}
	};
	// cout << maximalRectangle(v);
	// cout<< superEggDrop(1,2);
	// leftRecur(8);

}
void mediumSet() {
	// cout << maxProduct(nums) << endl;
	// VVI nums = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	// cout << minimumTotal(nums);
	// VI num{2, 7, 9, 3, 1};
	// cout << rob(num) << endl;
	// VI ans = countBits(5);
	// printV(ans);
	// cout << nthUglyNumber(2);
	// int number = 13;
	// VI nums{3, 3, 3, 3};
	string s = "applepenapple";
	VS dic{"apple", "pen"};
	// {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};

	cout << wordBreak(s, dic);
	// cout << (bool)(0);
	// cout << s.substr(0,3);
	// sort(nums.begin(), nums.end());
	// cout << equalSubsetII(nums);
	// cout << "@" << equalSubset(nums, 0, 0, 0) << endl;
	// int h = 9;
	// int b = 5 * 2 + 2 * 3 < (h * 2 ? 5 : 3);
	// cout << "@ = " << b << endl;
	// cout << endl;
	// Print2DT(dp);

	// VVI nums{{2, 0, 1}, {1, 0, 2}, {1, 1, 1}};
	// cout << countNumbersWithUniqueDigits(3);
	// cout << numSquares(13);
	// cout << integerBreak(8);
}
void solve() {
	// VI nums  = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	// int m = 4, n = 5;
	// VVI v;
	// for (int i = 0; i < m; i++) {
	// 	int p, k;
	// 	cin >> p >> k;
	// 	VI p1(2);
	// 	p1[0] = p;
	// 	p1[1] = k;
	// 	v.push_back(p1);
	// }
	// cout << maxEnvelopes(v);
	// VI nums = {1, 1, 1, 1, 1};
	// int target = 3;
	// // cout << findTargetSumWays(nums, 3);
	// cout << numDecodings("");
	//-------------------------------//
	// VII k;
	// for (int i = 0; i < m; i++) {
	// 	int p, k;
	// 	cin >> p >> k;
	// 	VI p1(2);
	// 	p1[0] = p;
	// 	p1[1] = k;
	// 	v.push_back(p1);
	// }
	// cout<< maxEnvelopes(v);

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
	// VI coins = {1, 2, 5};
	// int target = 1;
	// // cout << coinChangeCombi(coins, 10);
	// int minCoin = 1e7;
	// // cout << recursionCoinChangeCombi(coins, 11, minCoin, 0) << endl;
	// cout << coinChange(coins, 11);
	// cout << minCoin;
	// cout << LIS_II(nums);
}
int main() {
	// solve();
	// easySet();
	mediumSet();
	// hardSet();
}