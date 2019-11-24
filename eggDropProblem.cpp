/*
	author of this code is rohit sharma
*/
#include<bits/stdc++.h>
using namespace std;

// //top down appproach
// int eggDropProblemRecursion(int totalEggs, int totalFloors, std::vector<std::vector<int>> &v) {

// 	if (totalFloors == 1 || totalFloors == 0) {
// 		return totalFloors;
// 	}
// 	if (totalEggs == 1) {
// 		return totalFloors;
// 	}
// 	if (v[totalEggs][totalFloors] != 1e9) {
// 		return v[totalEggs][totalFloors];
// 	}

// 	for (int floors = 1; floors <= totalFloors ; floors++) {

// 		int withoutEggBreakTry = eggDropProblemRecursion(totalEggs, totalFloors - floors, v);
// 		int withEggBreakTry = eggDropProblemRecursion(totalEggs - 1, floors - 1, v);

// 		int numberOfTries = max(withEggBreakTry, withEggBreakTry) + 1;
// 		v[totalEggs][totalFloors] = min(v[totalEggs][totalFloors], numberOfTries);
// 	}
// 	return v[totalEggs][totalFloors];
// }


// void topDownSolution() {
// 	int totalFloors = 4;
// 	int totalEggs = 3;
// 	std::vector<std::vector<int>> v(totalEggs + 1, std::vector<int>(totalFloors + 1));
// 	for (int i = 2; i <= totalEggs; ++i)
// 	{
// 		for (int j = 2; j <= totalFloors; j++) {
// 			v[i][j] = 1e9;
// 		}
// 	}

// 	cout << eggDropProblemRecursion(totalEggs, totalFloors, v);
// }


int eggDropProblemBottomUp(int totalEggs, int totalFloors, std::vector<std::vector<int>> &cache) {

	for (int i = 0; i <= totalFloors; i++) {
		cache[0][i] = 0;
	}
	/*
	 If we have 0 floors we need 0 trials, no matter the egg amount given
	 If we have 1 floor we need 1 trial, no matter the egg amount given
	*/

	for (int i = 1; i <= totalEggs; i++) {
		cache[i][0] = 0;
		cache[i][1] = 1;
	}

	/*
	  If we have 1 egg...no matter what floors we get, our approach will
	  be to do 'floorAmount' drops...this is because we want to start from
	  floor 1, drop...then go to floor 2, drop...and so on until we get to
	  in the worst case 'floorAmount'
	  Remember, we want to know the minimum amount of drops that will always
	  work. So we want to MINIMIZE...to the absolute LEAST...worst...amount
	  of drops so that our drop count ALWAYS works
	  Any worse then the MINIMIZED WORST will be suboptimal
	*/
	for (int floor = 1; floor <= totalFloors; floor++) {
		cache[1][floor] = floor;
	}
	for (int i = 2; i <= totalEggs; i++) {
		for (int j = 2; j <= totalFloors; j++)
		{
			cache[i][j] = 1e9;
			for(int floor = 1; floor <= j; floor++) {
				int cacheAns = max(cache[i][j-floor],cache[i-1][floor-1]);
				int ansToPut  = cacheAns + 1;
				cache[i][j] = min(ansToPut,cache[i][j]); 
			}
		}
	}

	return cache[totalEggs][totalFloors];
}

void bottomUpSolution() {
	int totalFloors = 4;
	int totalEggs = 3;
	std::vector<std::vector<int>> cache(totalEggs + 1, std::vector<int>(totalFloors + 1, 1e9));
	
	cout << eggDropProblemBottomUp(totalEggs, totalFloors, cache)<<endl;
}

int main() {


	// topDownSolution();
	bottomUpSolution();
	return 0;
}