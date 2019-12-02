#include<bits/stdc++.h>
using namespace std;


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
	// multimap<int,int>map;
	// set<int>s;
	// for (int i = 0; i < n; ++i)
	// {
	// 	map.insert(pair<int,int>(v[i],i));
	// }
	
	//convert 2D into 1D using c = i % (no of columns) && r = i/(number of columns)
	// for (int i = 0; i < m * n; ++i)
	// {
	// 	int r = i / n;
	// 	int c = i % n;
	// 	cout << arr[r][c] << endl;
	// }

	return 0;
}