#include<bits/stdc++.h>
using namespace std;

int oddCells(int n, int m, vector<vector<int>>& indices) {
	std::vector<int> row(n, 0);
	std::vector<int> column(m, 0);

	for (int i = 0; i < indices.size(); i++) {
		row[indices[i][0]]++;
		column[indices[i][1]]++;
	}
	int matrixSize = n * m;
	int oddNumbers = 0;
	//Now the fun part - interpreting which numbers we have in result.
	//Starting from rows array. As you remember, it shows which rows were incremented and how many times.
	//e.g. [2, 1] would say `first row was incremented twice so we now have all dueces there and
	// the second one we've incremented only once - so all the elements will be 1s`
	for (int i = 0; i < matrixSize; i++) {
		int rowIndex = i / m;
		int columnIndex = i % m;
		//then we'll be iterating through n*m numbers in total
		//the rows[0] would display how we should update our first `n` numbers
		//the cols[0] - how we additionally should update every `m`-th number
		//so in order to get the information on how to update this particular number by its index
		//we can use such calculations (notice how we don't really need n value there):
		//if i is the current index, then `i/m` would let us get the value from rows array
		//and the `i%m` - for the columns. Then we just sum those 2 values to get the current number in
		//the matrix which, in turn, we don't really need to put anything and just increment our oddNumbers
		//if it is actuall odd.
		//
		//e.g. let's go over some example iterations
		//     consider our rows are [2, 1] and columns are [1,0,1]
		//i=0  ->  row_index = i/3 = 0;  col_index = i%3 =0; -> 2 + 1 = 3; -> oddNumbers++
		//i=1  ->  row_index = i/3 = 0;  col_index = i%3 =1; -> 2 + 0 = 2;
		//i=2  ->  row_index = i/3 = 0;  col_index = i%3 =2; -> 2 + 1 = 3; -> oddNumbers++
		//i=3  ->  row_index = i/3 = 1;  col_index = i%3 =0; -> 1 + 1 = 2;
		//i=4  ->  row_index = i/3 = 1;  col_index = i%3 =1; -> 1 + 2 = 1; -> oddNumbers++
		//i=5  ->  row_index = i/3 = 1;  col_index = i%3 =2; -> 1 + 1 = 2;
		//
		//and the result: oddNumbers==3

		if ((row[rowIndex] + column[columnIndex]) & 1) {
			oddNumbers++;
		}
	}
	return oddNumbers;
}

int main() {

	int n, m;
	cin >> n >> m;
	std::vector<std::vector<int>> indices;



	return 0;
}