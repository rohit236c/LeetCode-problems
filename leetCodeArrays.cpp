#include<bits/stdc++.h>
using namespace std;
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

//-------------------------------------------------------------//
void printV(VI v) {
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
*unique path - 1
*unique path- II
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


//------------------------------///-------------//-------------------//
void solve() {

	VVI matrix = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	int n, m;
	cin >> m >> n;
	cout << uniquePaths(m, n);
	// VVI intervals(n, std::vector<int> (m, 0));
	// input2D(intervals, n, m);
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