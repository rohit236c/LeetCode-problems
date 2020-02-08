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


int numOfSubarrays(vector<int>& arr, int k, int threshold) {
	int n = arr.size();
	if (n == 1 && arr[0] == threshold) return 1;
	VI prefix(n + 1, 0);
	int cnt = 0;
	int avg = 0;
	prefix[0] = arr[0];
	int i;
	for (i = 1; i < k; i++) {
		prefix[i] += prefix[i - 1] + arr[i];
	}
	if ((prefix[i - 1] / k ) >= threshold) cnt++;

	for (; i < n; i++) {
		prefix[i] = arr[i] + prefix[i - 1] - arr[i - k];
		if ((prefix[i] / k >= threshold)) {
			cnt++;
		}
	}
	return cnt;
}
int numberOfSteps (int num) {
	if (num == 0) return 0;

	VI dp(num + 1, 0);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= num; i++) {
		if (i % 2 == 0) {
			dp[i] = 1 + dp[i / 2];
		} else {
			dp[i] = 1 + dp[i - 1];
		}
	}
	return dp[num];
}
double angleClock(int hour, int minutes) {

	if (hour == 12) hour = 0;
	if (minutes == 60) minutes = 0;


	double hour_angle = 0.5 * (hour * 60 + minutes);
	double minute_angle = 6 * minutes;

	double angle = abs(hour_angle - minute_angle);

	angle = min(360 - angle, angle);

	return angle;
}
void printV(VI v) {
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
int minJumps(vector<int>& arr) {
	int n = arr.size();
	if (n == 1) return 0;
	if (arr[0] == arr[n - 1]) return 1;
	VI dp(n + 1, 1e8);
	VI dp2(n + 1, 1e8);
	dp[n - 1] = 0;
	dp[n - 2] = 1;
	dp2[n-1] = 0;
	dp2[n-2] = 1;

	for (int i = n-3; i >= 0; i--) {
		int ans = 1e8;
		for (int j = i + 1; j < n; j++) {
			if (arr[i] == arr[j]) {
				dp2[i] = 1 + dp2[j];
			}
		}
		// int j = i - 1;
		// dp2[i] = min(dp2[i], 1 + dp2[j]);
	}
	// printV(dp2);
	for (int i = n - 3; i >= 0 ; i--) {
		int ans = 1e8;
		for (int j = i + 1; j < n; j++) {
			if (arr[i] == arr[j]) {
				dp[i] = 1 + dp[j];
			}
		}
		int j = i + 1;
		dp[i] = min(dp[i], 1 + dp[j]);
		j = i - 1;
		dp[i] = min(dp[i], 1 + dp2[j]);
	}
	// printV(dp);
	return dp[0];

}


int main() {

	// cout << numberOfSteps(123);
	VI nums{11,22,7,7,7,7,7,7,7,22,13};
	int k = 3, threshold = 5;
	// cout << numOfSubarrays(nums, k, threshold);
	// cout << angleClock(4, 50);
	cout << minJumps(nums);


	return 0;
}