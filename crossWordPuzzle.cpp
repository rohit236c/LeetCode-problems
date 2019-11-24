#include<bits/stdc++.h>
using namespace std;

std::vector<string> dic = {"PUNJAB", "JHARKHAND", "MIZORAM", "MUMBAI"};

bool isValidToPutHorizontal(int x, int y, std::vector<string> board, string curWord) {
	int n = curWord.length();
	for (int i = 0; i < n; i++) {
		if (board[x + i][y] == '#' ||
		        board[x + i][y] == curWord[i]) {
			board[x + i][y] = curWord[i];
		}
		else {
			return false;
		}
	}
	return true;
}
bool isValidToPutVertical(int x, int y, std::vector<string> &board, string curWord) {
	int n = curWord.length();

	for (int i = 0; i < n; i++) {
		if (board[x][y + i] == '#' ||
		        board[x][y + i] == curWord[i]) {
			board[x][y + i] = curWord[i];
		}
		else {
			return false;
		}
	}
	return true;
}
bool crossWord(std::vector<string> &board, int vidx, int m) {
	if (vidx >= dic.size()) {
		//print board..
		for (auto str : board) {
			for (auto ch : str) {
				cout << ch << "";
			}
			cout << endl;
		}
		return true;
	}

	string curWord = dic[vidx];
	int maxLen = m - curWord.length();
	bool res = false;

	//check for horizontal position
	if (!res) {
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j <= maxLen; j++) {
				if (isValidToPutHorizontal(j, i, board, curWord)) {
					res = res || crossWord(board, vidx + 1, m);
					//print board..
				}
			}
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j <= maxLen; j++) {
				if (isValidToPutVertical(i, j, board, curWord)) {
					res = res || crossWord(board, vidx + 1, m);
				}
			}
		}
	}
	return res;
}


int main() {

	int n1 = 10;

	// board to hold the grid of puzzle
	vector<string> board;

	// take input of puzzle in board
	// input of grid of size n1 x n1
	board.push_back("*#********");
	board.push_back("*#********");
	board.push_back("*#****#***");
	board.push_back("*##***##**");
	board.push_back("*#****#***");
	board.push_back("*#****#***");
	board.push_back("*#****#***");
	board.push_back("*#*######*");
	board.push_back("*#********");
	board.push_back("***#######");
	cout<<crossWord(board, 0, n1);
	return 0;
}