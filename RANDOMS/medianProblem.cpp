#include<bits/stdc++.h>
using namespace std;

double bineary_search_ans(std::vector<int> A, std::vector<int> B) {
	//call the array on the smaller size....
	if (A.size() > B.size()) return bineary_search_ans(B, A);

	int x = A.size();
	int y = B.size();

	int low = 0;
	int high = x;
	double ans;
	while (low <= high) {

		int pX = (low + high) / 2;
		int pY = (x + y + 1) / 2 - pX;

		int maxLeftX = (pX == 0) ? -1e9 : A[pX - 1];
		int minRightX = (pX == x) ? 1e9 : A[pX];

		int maxLeftY = (pY == 0) ? -1e9 : A[pY - 1];
		int minRightY = (pY == y) ? 1e9 : A[pY];

		if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
			if ((x + y) & 1) {
				ans = (double) max(maxLeftX, maxLeftY);
				break;
			}
			else{
				ans = (double) (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
				break;
			}
		}
		else if (maxLeftX > minRightY) {
			high = pX - 1;
		}
		else {
			low = pX + 1;
		}
	}
	return ans;
}


int main() {

	int n;
	cin >> n;
	int m;
	cin >> m;
	std::vector<int> A(n);
	std::vector<int> B(m);
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> B[i];
	}
	cout << bineary_search_ans(A, B);


	return 0;
}