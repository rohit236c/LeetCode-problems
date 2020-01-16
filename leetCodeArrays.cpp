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

//----------------------------------------------------------------------//

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size(), i = 0, temp, j;
	if (n & 1) {
		for (; i <= n / 2; i++) {
			for (j = 0; j < n / 2; j++) {
				temp = matrix[n - j - 1][i];

				matrix[n - j - 1][i] = matrix[n - 1 - i][n - j - 1];
				matrix[n - 1 - i][n - j - 1] = matrix[j][n - i - 1];
				matrix[j][n - i - 1] = matrix[i][j];
				matrix[i][j] = temp;
			}
		}
	}
	else {
		for (; i < n / 2; i++) {
			for (j = 0; j < n / 2; j++) {
				temp = matrix[n - j - 1][i];
				matrix[n - j - 1][i] = matrix[n - 1 - i][n - j - 1];
				matrix[n - 1 - i][n - j - 1] = matrix[j][n - i - 1];
				matrix[j][n - i - 1] = matrix[i][j];
				matrix[i][j] = temp;
			}
		}
	}
}
//---------------------------------------------------------------------//

int maxSubArray(vector<int>& nums) {
	int curSum = 0, sum = 0, cnt = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		curSum += nums[i];
		if (curSum >= 0) {
			cnt++;
		}

		sum = max(curSum, sum);
		if (curSum < 0) {
			curSum = 0;
		}
	}
	if (cnt == 0) {
		int maxNum = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			maxNum = max(nums[i], maxNum);
		}
		sum = maxNum;
	}
	return sum;
}
//----------------------------------------------------------------------//

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
bool canJump(vector<int>& nums) {
	//greedy approach......
	int n = nums.size();
	if (nums[0] == 0) return false;
	if (nums.size() == 1) return true;


	int isPossible = n - 1;
	for (int i = n - 1; i >= 0 ; i--) {
		if (i + nums[i] >= isPossible) {
			isPossible = i;
		}
	}

	return (isPossible == 0);

}
//-------------------------------------------------------------------//
vector<vector<int>> merge(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end());
	std::vector<std::vector<int>> res;
	pair<int, int> p1, p2;
	// auto itr = res.back();
	int itr = 0 ;
	for (int i = 0; i < intervals.size(); ++i)
	{
		std::vector<int> ans;
		p1.first = intervals[i][0];
		p1.second = intervals[i][1];
		if (res.size() > 0) {
			itr = res.size() - 1;
		}
		if (res.size() == 0 || (res.size() > 0 && (res[itr][1] < p1.first))) {
			ans.push_back(p1.first);
			ans.push_back(p1.second);
			res.push_back(ans);
		} else {
			res[itr][1] = max(res[itr][1], p1.second);
		}

	}
	return res;
}
//-------------------------------------------------------------------//
vector<int> spiralOrder(vector<vector<int>>& A) {
	int i = 0, k = 0, l = 0;
	int m = A.size();
	int n = A[i].size();

	vector<int>v;
	while (k < m && l < n) {
		//push row inside the matrix...
		for (i = l; i < n; ++i) {
			v.push_back(A[k][i]);
		}
		k++;

		//push last colm.. inside matrix..
		for (i = k; i < m; ++i) {
			v.push_back(A[i][n - 1]);
		}
		n--;

		//push last row if left inside matrix
		if (k < m) {
			for (i = n - 1; i >= l; --i) {
				v.push_back(A[m - 1][i]);
			}
			m--;
		}

		//push first col inside matrix
		if (l < n) {
			for (i = m - 1; i >= k; --i) {
				v.push_back(A[i][l]);
			}
			l++;
		}
	}
	return v;

}
vector<vector<int>> generateMatrix(int n) {
	std::vector<std::vector<int>> matrix(n, std::vector<int> (n, 0));
	int totalNum = (n * n);
	int k = 0, l = 0, i = 0, t = 0, dir = 0;
	int num = 1;
	int r = n - 1;
	int b = n - 1;
	int elem = 1;
	std::vector<int> v;

	if (!n) return matrix;

	while (t <= b && l <= r) {
		if (dir == 0) {
			for (int i = l; i <= r; i++) {
				matrix[t][i] = elem;
				elem++;
			}
			t++;
			dir = 1;
		} else if (dir == 1) {
			for (int i = t; i <= b; i++) {
				matrix[i][r] = elem;
				elem++;
			}
			r--;
			dir = 2;
		} else if (dir == 2) {
			for (int i = r; i >= l ; i--) {
				matrix[b][i] = elem;
				elem++;
			}
			b--;
			dir = 3;
		} else if (dir == 3) {
			for (int i = b; i >= t; i--) {
				matrix[i][l] = elem;
				elem++;
			}
			l++;
			dir = 0;
		}
	}


	return matrix;
}
//-------------------------------------------------------------------//
/*
*unique path - I
*unique path- II
*Minimum pathSum - III
*/

int uniquePaths(int m, int n) {
	if (m == 0 && n == 0) return 1;
	//this is dp
	vector<vector<int>>dp(m, std::vector<int>(n, 0));
	int er = m - 1, ec = n - 1;
	for (int i = er; i >= 0; i--) {
		for (int j = ec; j >= 0; j--) {
			if (i == er && j == ec) {
				dp[i][j] = 1;
				continue;
			}
			int count = 0;
			if (i + 1 <= er) {
				count += dp[i + 1][j];
			}
			if (j + 1 <= ec) {
				count += dp[i][j + 1];
			}
			dp[i][j] = count;
		}
	}
	return dp[0][0];
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size() - 1 , n = obstacleGrid[0].size() - 1;

	if (m == 0 && n == 0 && obstacleGrid[0][0] != 1) return 1;
	else if (m == 0 && n == 0 && obstacleGrid[0][0] == 1) return 0;
	//this is dp
	vector<vector<unsigned int>>dp(m + 1, std::vector<unsigned int>(n + 1, 0));
	int er = m, ec = n;
	for (int i = er; i >= 0; i--) {
		for (int j = ec; j >= 0; j--) {
			if (i == er && j == ec && obstacleGrid[i][j] != 1) {
				dp[i][j] = 1;
				continue;
			}
			if (obstacleGrid[i][j] != 1) {
				unsigned int count = 0;
				if (i + 1 <= er) {
					count += dp[i + 1][j];
				}
				if (j + 1 <= ec) {
					count += dp[i][j + 1];
				}
				dp[i][j] = count;
			}
		}
	}
	return dp[0][0];
}
int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size() - 1, n = grid[0].size() - 1;

	if (m == 0 && n == 0) return grid[0][0];

	vector<vector<unsigned int>>dp(m + 1, std::vector<unsigned int>(n + 1, -1));
	int er = m, ec = n;
	for (int i = er; i >= 0; i--) {
		for (int j = ec; j >= 0; j--) {
			if (i == er && j == ec) {
				dp[i][j] = grid[i][j];
				continue;
			}
			unsigned int cost = 1e6;
			unsigned int costR = 1e6;
			unsigned int costD = 1e6;
			if (i + 1 <= er) {
				costR = dp[i + 1][j];
			}
			if (j + 1 <= ec) {
				costD = dp[i][j + 1];
			}
			dp[i][j] = min(costR, costD) + grid[i][j];
		}
	}
	return dp[0][0];
}
//---------------------------------------------------------------------//
void setZeroes(vector<vector<int>>& matrix) {
	//(m+n) soln...

	//O(1) soln...
	int R = matrix.size();
	int C = matrix[0].size();
	bool isCol = false;

	// intutiton:- use first row & column as boolean to see whether the row/column should have 0 or not.Check for first row could be seen if matrix[0][0], then set all the ele of row_one as zero and if isCol is true set matrix[i][0] = 0;

	for (int i = 0; i < matrix.size(); i++) {

		if (matrix[i][0] == 0) {
			isCol = true;
		}
		for (int j = 1; j < matrix[0].size(); j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	// Iterate over the array once again and using the first row and first column, update the elements.
	for (int i = 1; i < R; i++) {
		for (int j = 1; j < C; j++) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}

	if (matrix[0][0] == 0) {
		for (int j = 0; j < matrix[0].size(); j++) {
			matrix[0][j] = 0;
		}
	}
	if (isCol) {
		for (int i = 0; i < matrix.size(); ++i)
		{
			matrix[i][0] = 0;
		}
	}
}

//-------------------------------------------------------------------//
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0 || matrix[0].size() == 0) return false;
	int n = matrix.size();
	int m = matrix[0].size();
	int s = n * m;

	int start = 0, high = s - 1;
	bool flag = false;

	while (start <= high) {
		int mid = (start + (high - start) / 2);
		int r = mid / m;
		int c = mid % m;
		if (matrix[r][c] == target) {
			return true;
		}
		else if (target > matrix[r][c]) {
			start = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return false;
}
//---------------------------------------------------------------------//
void sortColors(vector<int>& nums) {
	if (nums.size() == 0) return ;
	int itr = 0;
	int ptr = 0;
	int ptr1 = nums.size() - 1;

	while (itr <= ptr1) {
		if (nums[itr] == 0) {
			swap(nums[itr], nums[ptr]);
			ptr++;
		}
		else if (nums[itr] == 2) {
			swap(nums[itr], nums[ptr1]);
			ptr1--;
			continue;
		}
		itr++;
	}
}
//----------------------------------------------------------------------//

void subsetsUtil(VI nums, std::vector<int> ans, int idx, VVI &res) {
	if (idx == nums.size()) {
		res.push_back(ans);
		return;
	}
	int curN = nums[idx];
	ans.push_back(curN);
	subsetsUtil(nums, ans, idx + 1, res);
	ans.pop_back();
	subsetsUtil(nums, ans, idx + 1, res);
}

vector<vector<int>> subsets(vector<int>& nums) {
	std::vector<std::vector<int>> res;
	std::vector<int> ans;

	subsetsUtil(nums, ans, 0, res);

	return res;
}
//------------more optimized----------------------------------//
void subsetsUtil2(VI nums, std::vector<int> ans, int idx, VVI &res) {
	if (idx > nums.size()) {
		return;
	}
	res.push_back(ans);
	for (int i = idx; i < nums.size(); ++i)
	{
		ans.push_back(nums[i]);
		subsetsUtil2(nums, ans, i + 1, res);
		ans.pop_back();
	}
}
vector<vector<int>> subsets2(vector<int>& nums) {
	std::vector<std::vector<int>> res;
	std::vector<int> ans;

	subsetsUtil2(nums, ans, 0, res);

	return res;
}
//--------------------------------------------------------------------//
bool dfs(vector<vector<char>>& board, vector<vector<bool>>& used, string word, int cur, int row, int col) {
	if (!used[row][col] and board[row][col] == word[cur]) {

		used[row][col] = true;
		if (cur == word.size() - 1)
			return true;
		if (row > 0 and dfs(board, used, word, cur + 1, row - 1, col)) {
			return true;
		}
		if (row < board.size() - 1 and dfs(board, used, word, cur + 1, row + 1, col)) {
			return true;
		}
		if (col > 0 and dfs(board, used, word, cur + 1, row, col - 1)) {
			return true;
		}
		if (col < board[0].size() - 1 and dfs(board, used, word, cur + 1, row, col + 1)) {
			return true;
		}
		used[row][col] = false;
	}
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	int row = board.size();
	int col = board[0].size();
	vector<vector<bool>> used(row, vector<bool>(col, false));
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == word[0]) {
				if (dfs(board, used, word, 0, i, j))
					return true;
			}
		}
	}
	return false;
}

//-------------------------------------------------------------------//
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
//--------------------------------------------------------------------//
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
//------------------------------///-------------//-------------------//

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
///---------------------------------------------------------------------///
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
//-----------------------------------------------------------------------//
bool isSubsequence(string s, string t) {
	if (s.length() > t.length())
		return false;
	if (s.empty() || t.empty())
		return true;
	int sIndex = 0;
	for (int i = 0; i < t.size(); ++i)
	{
		if(sIndex == s.size()) {
			return true;
		}
		if(s[sIndex] == t[i]) sIndex++;
	}
	return false;
}

void solve() {


	// string str;
	// cin >> str;
	// cout << longestPalindromicSubstring(str);
	int n = 2;
	cout<<isSubsequence("B","C");
	// cout << climbStairs(4);
	// cout << minDistance("intention", "execution");
	// int n, m, target;
	// VI nums = {1, 2, 3};
	// VVI ans = subsets(nums);
	// std::vector<string> v;
	// VI ans;
	// subseq("123","", v);
	// printVS(v);
	// VVI res = subsets2(nums);
	// cout << exist(board, "ABCD");
	// printV(ans);
	// print2D(res);
	// cin >> m >> n >> target;
	// cout << uniquePaths(m, n);
	// VVI intervals(m, std::vector<int> (n, 0));
	// input2D(intervals, m, n);
	// std::vector<string> v =  printSub("abc");
	// subset("123","");
	// printVS(v);
	// print2D(intervals);
	// cout << minPathSum(intervals);
	// cout << searchMatrix(intervals, target);
	// cout << uniquePathsWithObstacles(intervals);
	// VI ans = spiralOrder(intervals);
	// VVI ans = generateMatrix(3);
	// print2D(ans);
	// VVI ans = merge(intervals);
	// print2D(ans);
	// printV(ans);
	// VVI ans ;
	// VI k = {1,2};
	// ans.push_back(k);
	// auto itr = ans.back();
	// cout<<itr[1];
	// VVI ans  = combinationSumII(nums, target);
	// cout << maxSubArray(nums);
	// cout << jumpII(nums);
	// int ans = combinationSum01(nums, target, 0, "");
	// print2D(matrix);
	// rotate(matrix);
	// cout << endl;
	// print2D(matrix);


	// cout << ans;
}


int main() {

	solve();

	return 0;
}