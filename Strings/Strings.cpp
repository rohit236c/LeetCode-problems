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
int minSteps(string s, string t) {
	int t1[26] = {0};
	int ans = 0;
	for (int i = 0; i < t.size(); i++) {
		t1[t[i] - 'a']++;
	}
	for (int i = 0; i < s.size(); i++) {
		int val = t1[s[i] - 'a'];
		if (val == 0) ans ++;
		else {
			t1[s[i] - 'a']--;
		}
	}
	return ans;
}

bool isPermute(string s, string p) {
	unordered_map<char, char>mp;
	unordered_map<char, char> pm;

	// for (int i = 0; i < s.size(); i++) {
	// 	char s1 = s[i];
	// 	char p1 = p[i];
	// 	if (mp.find(s1) == mp.end()) {
	// 		m[s1] = p1;
	// 	}
	// 	if (pm.find(p1) == pm.end()) {
	// 		m[p1] = s1;
	// 	}
	// 	if ((mp[s1] != p1) || (pm[p1] != s1)) return false;
	// }
	return true;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
	int n = (int)words.size();
	int m = (int)pattern.size();

	std::vector<string> ans;

	for (int i = 0; i < n; i++) {
		string curr = words[i];
		if (curr.size() == pattern.size() && isPermute(curr, pattern)) {
			ans.push_back(curr);
		}

	}
	return ans;
}

class node {
public:
	char ch;
	unordered_map<char, node*>map;
	bool end;

	node(char c) {
		ch = c;
		end = false;
	}
};
class Trie {
	node*head;
public:
	Trie() {
		head = new node('1');
	}

	void insert(string word) {
		node* temp = head;

		for (char c : word) {
			if (temp->map.find(c) != temp->map.end()) {
				temp = temp->map[c];
			} else {
				node* n = new node(c);
				temp->map[c] = n;
				temp = temp->map[c];
			}
		}
		temp->end = true;
	}

	bool search(string word) {
		node*temp = head;

		for (int i = 0; i < word.size(); i++) {
			if (temp->map.find(word[i]) != temp->map.end()) {
				temp = temp->map[word[i]];
			} else {
				return false;
			}
		}
		return temp->end;
	}

	bool startsWith(string prefix, std::vector<VS> &ans) {
		node*temp = head;
		node* st = head;
		for (char c : prefix) {
			if (temp->map.find(c) != temp->map.end()) {
				temp = temp->map[c];
			} else {
				return false;
			}
		}
		int idx = 0;
		while (idx < 3) {

		}
		return true;
	}

};
std::vector<bool> visited;
VVI adj;
int final;
void dfs(int v) {
	final = v;
	if (visited[v]) return;

	visited[v] = true;
	for (int u : adj[v]) {
		if (!visited[u]) {
			dfs(u);
		}
	}

}
string destCity(vector<vector<string>>& paths) {
	int n = paths.size();

	unordered_map<string, int>map;

	int idx = 0;

	for (VS str : paths) {
		string u = str[0];
		string v = str[1];
		if (map.find(u) == map.end()) {
			map[u] = idx++;
		}
		if (map.find(v) == map.end()) {
			map[v] = idx++;
		}
	}
	int size = map.size();
	adj.resize(size);
	visited.resize(size);
	final = -1;

	for (VS str : paths) {
		string u1 = str[0];
		string v1 = str[1];
		int u = map[u1];
		int v = map[v1];
		adj[u].push_back(v);
	}

	dfs(0);
	for (auto itr : map) {
		if (itr.second == final) {
			return itr.first;
		}
	}

}
int ans;
std::vector<std::vector<bool>> isPalidrome(string s) {
	int n = (int)(s.size());

	std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
	for (int gap = 0; gap < n; gap++) {
		for (int i = 0, j = gap; j < n; j++, i++) {
			if (gap == 0) {
				dp[i][j] = true;
			} else if(gap == 1) {
				dp[i][j] = (s[i] == s[j]);
			} 
			else if (s[i] == s[j] && dp[i + 1][j - 1]) {
				dp[i][j] = true;
			}
			if(dp[i][j]) {
				ans++;
			}
		}
	}
	return dp;
}
int countSubstrings(string s) {
	int n = (int)(s.size());
	if(n < 1) return 0;

	
	ans = 0;
	std::vector<std::vector<bool>> isPali = isPalidrome(s);

	return ans;	
}


void solve() {
	// std::vector<VS> paths = {{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
	// cout << destCity(paths);
	cout << countSubstrings("abc") << endl;

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}