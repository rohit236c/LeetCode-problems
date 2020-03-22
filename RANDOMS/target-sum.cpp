#include<bits/stdc++.h>

using namespace std;

std::vector<int> twoSum(std::vector<int> nums, int target) {
	
	multimap<int, int>m;

	for (int i = 0; i < nums.size(); i++) {
		m.insert(pair<int, int>(nums[i], i));
	}

	vector<int>v;
	
	for (int i = 0; i < nums.size(); i++) {
		int curNum = nums[i];
		auto it1 = m.find(target - curNum);
		if (m.find(target - curNum) != m.end() && it1->second != i) {
			v.push_back(i);
			auto it = m.find(target - curNum);
			v.push_back(it->second);
			break;
		}
	}

	return v;
}

int main() {
	int n;
	cin >> n;
	std::vector<int> v(n);
	int target;
	cin >> target;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	std::vector<int> ans = twoSum(v, target);

	for (auto i : ans) {
		cout << i << " ";
	}

	return 0;
}