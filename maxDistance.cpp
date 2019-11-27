#include<bits/stdc++.h>
using namespace std;

int maxDistance(std::vector<int> arr) {

	std::vector <pair<int, int>> index;
	for (int i = 0; i < arr.size(); i++) {
		pair<int, int>p;
		p.first = arr[i];
		p.second = i;
		index.push_back(p);
	}
	sort(index.begin(), index.end());
	std::vector<int> rightIndex(arr.size());
	int maxAns = -1e9;

	for (int i = arr.size()-1; i >=0; --i)
	{
		maxAns = max(maxAns,index[i].second);
		rightIndex[i] = maxAns;
	}

	int finalAns = -1;
	
	for(int i = 0; i < arr.size(); i++) {
		finalAns = max(finalAns,rightIndex[i]-index[i].second);
	}
	return finalAns;

}


int main() {
	int n;
	n = 4;
	std::vector<int> v(n);
	// 1 2 1 3 4 3
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}	
	cout<<maxDistance(v);
	return 0;
}