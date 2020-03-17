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

int main() {
	Tree*root = NULL;
	// root = buildTree();
	// 4,9,0,5,1]
	buildLevelTree(root);
	printByLevelQueue(root);
	// pathSum(root, -5);
	// cout << hasPathSum(root, 22);
	cout << pathSum01(root, 8) << endl;
	cout << ans;
	return 0;
}