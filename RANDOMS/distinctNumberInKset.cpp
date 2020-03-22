#include<bits/stdc++.h>
using namespace std;

void printDistinctElementsInKSet(std::vector<int> arr, int k) {
	int n = arr.size();
	std::map<int, int> mp;
	int distinct_count = 0;
	int i ;

	for (i = 0; i < k; i++) {
		if (mp[arr[i]] == 0) {
			distinct_count++;
		}
		mp[arr[i]]++;
	}
	cout << distinct_count << " " ;

	for (; i < n; i++) {
		
		// delete the element that is not required
		if (mp[arr[i - k]] == 1) {
			distinct_count--;
		}
		//decrement the count here..
		mp[arr[i - k]]--;

		//insert new element & increment the distinct_count
		if (mp[arr[i]] == 0) {
			distinct_count++;
		}
		//increment the count here....
		mp[arr[i]]++;
		cout << distinct_count << " ";
	}

}


int main() {
	int n;
	n = 6;
	std::vector<int> v(n);
	// 1 2 1 3 4 3
	int k = 3;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	printDistinctElementsInKSet(v, k);
	//o/p == 2 3 3 2
	return 0;
}