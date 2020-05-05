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
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n = s1.size();
        sort(s1.begin(), s1.end());
        sort(s2.begin(),s2.end());
        
        bool ans_1 = true;
        bool ans_2 = true;
         for(int i = 0; i < n; i++) {
            if(s1[i] < s2[i]) {
                ans_1 = false;
            }
             if(s1[i] > s2[i]) {
                 ans_2 = false;
             }
             if(!ans_1 && !ans_2) return false;
        }
        return ans_1 || ans_2;
    }
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	return 0;
}