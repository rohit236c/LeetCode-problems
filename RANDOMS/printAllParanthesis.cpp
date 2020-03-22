#include<bits/stdc++.h>

using namespace std;

void printParathensisUtil(int numOfOpenBrackets, int numOfCloseBrackets, string ans, std::vector<string> &result) {
	if (numOfOpenBrackets == 0 && numOfCloseBrackets == 0) {
		result.push_back(ans);
		return;
	}
	if (numOfOpenBrackets > 0) {
		printParathensisUtil(numOfOpenBrackets - 1, numOfCloseBrackets, ans + '(', result);
	}
	if (numOfOpenBrackets < numOfCloseBrackets) {
		printParathensisUtil(numOfOpenBrackets, numOfCloseBrackets - 1, ans + ')', result);
	}
}


void printParathensis(int n) {

	std::vector<string> result;

	printParathensisUtil(n, n, "", result);

	for (auto str : result) {
		cout << str << endl;
	}

}

void generateHelper(string &current, int numOpenBrackets, int numClosedBrackets, int n, vector<string> &ans) {
	if (numOpenBrackets == numClosedBrackets && numOpenBrackets == n) {
		ans.push_back(current);
		return;
	}
	if (numOpenBrackets > n || numClosedBrackets > n) {
		// Invalid.
		return;
	}

	// Now we have 2 options. We can either add '(' to the string or add ')' to the string.
	// Option 1. Add '('
	if (numOpenBrackets < n) {
		current.push_back('(');
		generateHelper(current, numOpenBrackets + 1, numClosedBrackets, n, ans);
		current.pop_back();
	}
	// Option 2. Add ')'
	if (numClosedBrackets < numOpenBrackets) {
		current.push_back(')');
		generateHelper(current, numOpenBrackets, numClosedBrackets + 1, n, ans);
		current.pop_back();
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> ans;
	string current = "";
	int numOpenBrackets = 0, numClosedBrackets = 0;
	generateHelper(current, numOpenBrackets, numClosedBrackets, n, ans);
	return ans;
}

int main() {

	int n;
	n = 2;
	// std::vector<string> v = generateParenthesis(3);
	// printParathensis(n);
	return 0;
}