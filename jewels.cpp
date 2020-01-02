#include<bits/stdc++.h>
using namespace std;
int numJewelsInStones(string J, string S) {
	unsigned long long int mask = 0;
	for (int i = 0; i < J.size(); i++) {
		unsigned long long int bit = J[i] - 'A';
		cout << bit << endl;

		mask = mask | (1 << bit);
	}
	int cnt = 0;
	cout << mask << endl;
	for (int i = 0; i < S.size(); i++) {
		unsigned long long int bit = S[i] - 'A';
		if (mask & (1 << bit)) {
			cnt++;
		}
	}
	return cnt;
}
string defangIPaddr(string address) {
	string ans = "";
	int k = 0;
	for (int i = 0; i < address.size(); i++) {
		if (address[i] == '.') {
			char p = '[';
			ans.push_back(p);
			p = '.';
			ans.push_back(p);
			p = ']';
			ans.push_back(p);
		} else {
			ans.push_back(address[i]);
		}

	}
	return ans;
}
int subtractProductAndSum(int n) {
	int product = 1;
	int sum = 0;
	int ans = 0;
	while (n > 0) {
		int temp = n % 10;
		product *= temp;
		sum += temp;
		n = n / 10;
	}
	ans = product - sum;
	return ans;
}
string toLower(string str) {
	string ans = "";
	for (int i = 0; i < str.size(); ++i)
	{
		char ch;
		if (((int)str[i]) < 97 && ((int)str[i]) >= 65) {
			ch = (char)(str[i] + 32);
			ans += ch;
		} else {
			ans += str[i];
		}
	}
	return ans;
}

vector<int> replaceElements(vector<int>& arr) {
	int n = arr.size() - 1;
	std::vector<int> v(n, 0);
	if (arr.size() > 1) {
		int f = arr[n];
		int s = arr[n - 1];
		int maxElement = max(f, s);
		for (int i = n - 2; i >= 0; i--) {
			int e = arr[i + 1];
			maxElement = max(e , maxElement);
			if (e <= maxElement) {
				v[i] = maxElement;
			} 
		}
		v[n] = -1;
		v[n - 1] = arr[n];
	} else {
		v[0] = -1;
	}
	return v;
}

int main() {

	// cout << numJewelsInStones("zZ", "aAAzZbbbbb");
	// cout<<defangIPaddr("255.100.50.0");
	// cout<<subtractProductAndSum(4421);
	std::vector<int> arr = {17, 18, 5, 4, 6, 1};
	std::vector<int> ans = replaceElements(arr);
	for (int i = 0; i < arr.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}