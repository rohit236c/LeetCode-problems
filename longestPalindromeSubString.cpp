#include<bits/stdc++.h>

using namespace std;


int longestPalindromeSubstring(string str) {

	std::vector<std::vector<int>> table(str.length(), std::vector<int>(str.length()));

	int maxLength = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		table[i][i] = true;
	}
	for (int i = 0; i < str.length() - 1; ++i)
	{
		if (str[i] == str[i + 1]) {
			table[i][i + 1] = true;
			maxLength = 2;
		}
	}

	for (int k = 3; k <= str.length(); k++) {
		for (int i = 0; i < str.length() - k + 1; i++) {
			int j = i + k - 1;

			if (table[i + 1][j - 1] && str[i] == str[j]) {
				table[i][j] = true;
				maxLength = max(k, maxLength);
			}
		}
	}
	return maxLength;
}

int main() {

	cout<<longestPalindromeSubstring("abacdfgdcaba");

	return 0;
}