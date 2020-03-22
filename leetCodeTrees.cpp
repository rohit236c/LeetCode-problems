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


class Tree
{
public:
	int val;
	Tree * left;
	Tree * right;
	Tree(int data) {
		this->val = data;
		this->left = NULL;
		this->right = NULL;
	}
};
void buildLevelTree(Tree * &root) {
	int data;
	cin >> data;
	root = new Tree(data);
	queue<Tree *>q;
	q.push(root);
	while (!q.empty()) {
		Tree * n = q.front();
		q.pop();
		int d1, d2;
		cin >> d1 >> d2;
		if (d1 != -1) {
			n -> left = new Tree(d1);
			q.push(n->left);
		}
		if (d2 != -1) {
			n -> right = new Tree(d2);
			q.push(n->right);
		}
	}
}
void printByLevelQueue(Tree * root) {
	queue<Tree *>q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		Tree * front = q.front();
		cout << front->val << " ";
		q.pop();

		if (front->left != NULL) {
			q.push(front->left);
		}
		if (front->right != NULL)
		{
			q.push(front->right);
		}
		if (q.front() == NULL) {
			q.pop();
			if (!q.empty())
				q.push(NULL);

			cout << endl;
		}
	}
}
void printV(VI v) {
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void pathSumUtil(Tree* root, VVI &ans, int sum, VI tk) {
	if (sum == 0 && root && root->left == NULL && root->right == NULL) {
		ans.push_back(tk);
		return;
	}

	if (root == NULL) return;



	int val = 0;
	if (root->left != NULL) {
		tk.push_back(root->left->val);
		val = root->left->val;
	}
	pathSumUtil(root->left, ans, sum - val, tk);

	if (root->left != NULL) tk.pop_back();

	if (root->right != NULL) {
		tk.push_back(root->right->val);
		val = root->right->val;
	}
	pathSumUtil(root->right, ans, sum - val, tk);

}
void print2D(VVI matrix) {
	for (auto K : matrix) {
		for (int i : K) {
			cout << i << " ";
		}
		cout << endl;
	}
}

vector<vector<int>> pathSum(Tree* root, int sum) {
	VVI ans;
	VI tk;
	if (root == NULL) return ans;
	tk.push_back(root->val);
	pathSumUtil(root, ans, sum - root->val, tk);
	print2D(ans);
}
void found(Tree* root, int sum, vector<vector<int>>& result, vector<int> each) {
	if (root == NULL) {
		return;
	}
	sum -= root->val;
	each.push_back(root->val);
	if ((root->left == NULL && root->right == NULL) && (sum == 0)) {
		result.push_back(each);
	}
	found(root->left, sum, result, each);
	found(root->right, sum, result, each);
}
vector<vector<int>> pathSum02(Tree* root, int sum) {
	vector<vector<int>> result;
	if (root == NULL) {
		return result;
	}
	found(root, sum, result, vector<int>());
	return result;
}
bool haspth(Tree* root, int sum) {
	if (root == NULL) return false;
	sum = sum - root->val;

	if ((root->left == NULL && root->right == NULL) && sum == 0) {
		return true;
	}


	bool ans = haspth(root->left, sum);
	if (ans) return true;
	bool ans2 = haspth(root->right, sum);
	if (ans2) return true;

	return (ans || ans2);

}
bool hasPathSum(Tree* root, int sum) {
	if (root == NULL) return false;
	return haspth(root, sum);
}
int ans = 0;
void pathSumIII(Tree *root, int sum, int& k) {
	if (root == NULL) return ;
	sum = sum - root->val;
	if (sum == 0) {
		ans++;
		k++;
	}

	pathSumIII(root->left, sum, k);
	pathSumIII(root->right, sum, k);
}
// 	      10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1

int pathSum01(Tree *root, int sum) {
	if (root == NULL) return 0;
	queue<Tree*>q;
	q.push(root);
	int ans = 0;
	while (!q.empty()) {
		Tree *head = q.front();
		q.pop();
		pathSumIII(head, sum, ans);
		if (head->left) {
			q.push(head->left);
		}
		if (head->right) {
			q.push(head->right);
		}
	}
	return ans;
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

std::vector<Tree*> generateTreesUtil(int lo, int hi) {
	int n = hi - lo + 1;

	if (n == 0) {
		std::vector<Tree*> v;
		v.push_back(NULL);
		return v;
	}

	std::vector<Tree*> ans ;
	for (int i = lo; i <= hi; i++) {
		std::vector<Tree*>leftTree = generateTreesUtil(lo, i - 1);
		std::vector<Tree*> rightTree = generateTreesUtil(i + 1, hi);
		for (Tree* left : leftTree) {
			for (Tree* right : rightTree) {
				Tree* root = new Tree(i);
				root->left = left;
				root->right = right;
				ans.push_back(root);
			}
		}
	}
	return ans;
}

void testRun(int n) {
	for (int k = 1; k < n; k++) {
		for (int i = 1; i <= n - k; i++) {
			int j = i + k;
			for (int root = i; root <= j; root++) {
				cout << j << " <-j@ " << root << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
	for (int gap = 0; gap < n; gap++) {
		for (int i = 0, j = gap; j < n; j++, i++) {
			for (int k = i; k <= j; k++) {
				cout << k << " @ ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

std::vector<Tree*> generateTreesUtilDP(int n) {
	std::vector<Tree*> ans;
	if (n == 0) return ans;
	std::vector<std::vector<Tree*> > dp(n + 1, vector<Tree*>(n + 1, NULL));

	// for (int gap = 0; gap < n; gap++) {
	// 	for (int i = 0; i <= n - k; i++) {

	// 		if (gap == 0) {
	// 			dp[i][j] = new Tree(i);
	// 		} else {
	// 			for (int root = i; root <= j; root++) {
	// 				int eL = root - 1;
	// 				int eR = root + 1;
	// 				std::vector<Tree*> left, right;
	// 				if (eL < i) {
	// 					left.push_back(NULL);
	// 				} else {
	// 					left.push_back(dp[i][eL]);
	// 				}
	// 				if (eR < j) {
	// 					right.push_back(NULL);
	// 				} else {
	// 					right.push_back(dp[eR][j]);
	// 				}
	// 				for (Tree*leftSub : left) {
	// 					for (Tree* rightSub : right) {
	// 						Tree* node = new Tree(root);
	// 						node->left = leftSub;
	// 						node->right = rightSub;
	// 						ans.push_back(node);
	// 					}
	// 				}
	// 			}
	// 		}

	// 	}
	// }
	// return ans;
}


vector<Tree*> generateTrees(int n) {
	std::vector<Tree*> ans;
	if (n == 0) return ans;

	return generateTreesUtil(1, n);

}
int findLongestChain(vector<vector<int>>& pairs) {
	if (pairs.size() == 0) return 0;
	VI dp(pairs.size(), 0);
	sort(pairs.begin(), pairs.end());

	VI LIS;
	LIS.push_back(pairs[0][1]);
	int maxLen = 1, len = 1;
	print2D(pairs);
	for (int i = 1; i < pairs.size(); ++i)
	{
		int low = 0;
		int high = len - 1;
		if (pairs[i][1] > LIS[high] && pairs[i][0] > LIS[high]) {
			LIS.push_back(pairs[i][1]);
			len++;
		} else if(pairs[i][1] < LIS[high]) {
			while (low < high) {
				int mid = (low + high) / 2;
				if (LIS[mid] < pairs[i][1]) {
					low = mid + 1;
				} else {
					high = mid;
				}
			}
			LIS[high] = pairs[i][1];
		}
	}
	return LIS.size();
}
void solve2() {
	VVI pairs{{1,2},{2,3},{3,4}};
	// {{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}};
	cout << findLongestChain(pairs);
}
int main() {
	// Tree*root = NULL;
	// root = buildTree();
	// 4,9,0,5,1]
	// buildLevelTree(root);
	// printByLevelQueue(root);
	// pathSum(root, -5);
	// cout << hasPathSum(root, 22);
	// cout << pathSum01(root, 8) << endl;
	// cout << ans;
	// std::vector<Tree*> v =  generateTreesUtilDP(3);
	// for (Tree*node : v) {
	// printByLevelQueue(node);
	solve2();
	// cout << "------" << endl;
	// }
	// testRun(3);

	return 0;
}