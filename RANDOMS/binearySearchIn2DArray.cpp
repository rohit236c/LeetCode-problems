#include<bits/stdc++.h>
using namespace std;


pair<int, int> binearySearchInto2DArray(int arr[][100], int key, int m, int n) {
	int start = 0;
	int high = (m * n) - 1;
	pair<int, int>p;
	while (start <= high) {
		// int middle = left + (right - left) / 2;
		int mid = (start + high) / 2;
		int r = mid / n;
		int c = mid % n;
		if (key == arr[r][c]) {
			pair<int, int>p;
			p.first = r;
			p.second = c;
			return p;
		}
		else if (key > arr[r][c]) {
			start = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	if (start > high) {
		p.first = -1;
		p.second = -1;
		return p;
	}
}

int main() {
	int arr[100][100];
	int m = 3, n = 4;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}

	pair<int, int> p = binearySearchInto2DArray(arr, 7, m, n);
	cout << arr[p.first][p.second] << endl;
	
	//convert 2D into 1D using c = i % (no of columns) && r = i/(number of columns)

	// for (int i = 0; i < m * n; ++i)
	// {
	// 	int r = i / n;
	// 	int c = i % n;
	// 	cout << arr[r][c] << endl;
	// }

	return 0;
}