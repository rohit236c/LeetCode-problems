#include<bits/stdc++.h>
using namespace std;
//code from backTobackSwe..
class KadaneResult {
public:
	int maxSum;
	int maxRegionStart;
	int maxRegionEnd;
};

class MaxRectangleSum {
public:
	int maxInteriorSum;
	int rectangleTopIndex;
	int rectangleBottomIndex;
	int rectangleLeftIndex;
	int rectangleRightIndex;
};

MaxRectangleSum rectangleMaxSum(std::vector<std::vector<int>> matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();

	std::vector<int> runningRowLength(rows, 0);
	MaxRectangleSum rectangle;
	for (int left = 0; left < cols; left++) {

		//initialise the running row matrix
		for (int i = 0; i < rows; i++) {
			runningRowLength[i] = 0;
		}

		//move the right pointer now..
		for (int right = left; right < cols; right++) {
			for (int i = 0; i < rows; i++) {
				runningRowLength[i] += matrix[i][right];
			}
		}
	}

}
KadaneResult kadaneSum (std::vector<int> array) {
	KadaneResult rowMaxSum;
	int maxSum = 0;
	int curSum = 0;
	for (int i = 0; i < array.size(); i++) {

	}
}

int main() {
	// int matrix[][] = {
	// 	{   6, -5,  -7,  4, -4 },
	// 	{  -9,  3,  -6,  5,  2 },
	// 	{ -10,  4,   7, -6,  3 },
	// 	{  -8,  9,  -3,  3, -7 }
	// };

	return 0;
}