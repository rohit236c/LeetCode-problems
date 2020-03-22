#include<bits/stdc++.h>
using namespace std;


int reverse(int x) {
	int n = 0;
	while (x) {
		int r = x % 10;
		x = x / 10;
		if (n > INT_MAX / 10 || (n == INT_MAX / 10 && r > 7))
			return 0;
		if (n < INT_MIN / 10 || (n == INT_MIN / 10 && r < -8))
			return 0;

		n = n * 10 + r;
	}

	return n;
}



int main() {

	int x = 1900876;
	cout << reverse(x);

	return 0;
}