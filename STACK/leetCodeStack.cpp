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
void printStack(stack<T> s) {
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << endl;
}

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

bool isValid(string s) {
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			st.push(s[i]);
		}
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
			if (st.empty()) {
				return false;
			}
			char stack_top = st.top();
			st.pop();
			if ((stack_top == '{' && s[i] != '}') || (stack_top == '(' && s[i] != ')') || (stack_top == '[' && s[i] != ']')) {
				return false;
			}
		}
	}
	return st.empty() ;
}
///-----------------------------------------------------------------------------///
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
int histogramII(VI nums) {

	stack<int>s;
	s.push(-1);
	int i = 0;
	int n = nums.size();
	int maxArea = 0;
	while (i < n) {
		if (s.size() == 1 || nums[s.top()] <= nums[i]) {
			s.push(nums[i]);
			i++;
		} else {
			int top = s.top();
			s.pop();
			int h = nums[h];
			int wid = s.top() == -1 ? i : i - s.top() - 1;
			int area = h * wid;
			maxArea = max(area, maxArea);
		}
	}
	while (s.size() != -1) {
		int top = s.top();
		s.pop();
		int area = nums[top] * (s.top() == -1 ? i : i - s.top() - 1);
		maxArea = max(maxArea, area);
	}
	return maxArea;
}
void solve() {
	// string ans = removeOuterParentheses("");
	// cout << ans << endl;
}

int main() {
	solve();

	return 0;
}