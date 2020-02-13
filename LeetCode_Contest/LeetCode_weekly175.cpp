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

void print2D(VVI matrix) {
	for (auto K : matrix) {
		for (int i : K) {
			cout << i << " ";
		}
		cout << endl;
	}
}
void printV(VI v) {
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
class TweetCounts {
	 map<string,VI>m;
public:
    TweetCounts() {
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].push_back(time);
        sort(m[tweetName].begin(), m[tweetName].end());
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int range;
        if(freq.comare("hour") == 0) {
        	range = 3600;
        } else if(freq.comare("minutes") == 0) {
        	range = 60;
        } else {
        	range = 0;
        }
        int high = endTime - startTime;
        VI ans;
        
        for (int i = startTime; i < endTime; ++i)
        {
        	
        }

    }
};
bool checkIfExist(vector<int>& arr) {
	int n = arr.size();
	if (n == 1) return false;
	if (n == 0) return false;
	map<int, int>s;
	int idx = 0;
	for (int i = 0; i < n; ++i)
	{
		s[arr[i]] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		if (s.find(arr[i] * 2) != s.end() && s[arr[i] * 2] != i) {

			return true;
		}
	}

	return false;
}
int minSteps(string s, string t) {
	if (s.size() == 0 && t.size() == 0) return 0;
	if (s.size() == 0 && t.size() != 0) return t.size();
	if (t.size() == 0 && s.size() != 0) return s.size();

	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	VI freq(27, 0);
	if(s.compare(t) == 0) return 0;

	for (int i = 0; i < s.size(); ++i)
	{
		freq[s[i] - 'a']++;
	}
	for (int i = 0; i < t.size(); ++i)
	{
		freq[t[i] - 'a']--;
	}
	int cnt = 0;
	for (int i : freq) {
		if (i > 0) {
			cnt += i;
		}
	}
	return cnt;
}

int main() {

	// cout << numberOfSteps(123);
	VI nums{10, 2, 5, 3};
	// cout << checkIfExist(nums);
	cout << minSteps("xxyyzz","xxyyzz");
	return 0;
}