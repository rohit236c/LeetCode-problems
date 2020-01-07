#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &digits) {
	reverse(digits.begin(), digits.end());
	vector<int> ans;
	int carry = 1;
	for (int i = 0; i < digits.size(); i++) {
		int sum = digits[i] + carry;
		ans.push_back(sum % 10);
		carry = sum / 10;
	}
	while (carry) {
		ans.push_back(carry % 10);
		carry /= 10;
	}
	while (ans[ans.size() - 1] == 0 && ans.size() > 1) {
		ans.pop_back();
	}
	reverse(ans.begin(), ans.end());
	reverse(digits.begin(), digits.end());
	return ans;
}
int pathSum(pair<int, int>p1, pair<int, int>p2) {

	if (p1.first - p2.first <= p1.second - p2.second) {
		return abs(p2.second - p1.second);
	} else {
		return abs(p1.first - p2.first);
	}
}

int minStepsToGrid(std::vector<int> &A, std::vector<int> &B) {

	pair<int, int>p1, p2;
	int sum = 0;
	for (int i = 0; i < A.size() - 1; i++) {
		p1.first = A[i];
		p1.second = B[i];

		p2.first = A[i + 1];
		p2.second = B[i + 1];
		sum += pathSum(p1, p2);
	}
	return sum;
}
int kadaneAlgorithm(std::vector<int> &Arr) {
	int sum = 0;
	int curSum = 0;
	int index = 0, start = 0, s = 0;
	for (int i = 0; i < Arr.size(); i++) {
		curSum += Arr[i];
		if (curSum < 0) {
			s = i + 1;
			curSum = 0;
		}
		if (curSum > sum) {
			sum = curSum;
			start = s;
			index = i;
		}
	}
	cout << sum << endl;

	return sum;
}
int maxArea(std::vector<int> &v) {
	int n = v.size();
	int i = 0 , j = v.size() - 1;

	int maxArea = 0;
	while (i <= j) {
		int maxHeight = min(v[i], v[j]);
		int maxWidth = j - i;
		int area = maxHeight * maxWidth;
		maxArea = max(maxArea, area);
		if (v[j] > v[i]) {
			i++;
		} else {
			j--;
		}
	}
	return maxArea;
}

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
	// [-1, 0, 1, 2, -1, -4]
	//   i  l             r

	std::vector<std::vector<int>> res;
	if (nums.size() < 2) return res;

	sort(nums.begin(), nums.end());
	int idx = 0;

	while (idx < nums.size() - 2) {
		int target  = -nums[idx];
		//Two Sum Problem....
		int l = idx + 1;
		int r = nums.size() - 1;
		while (l < r) {
			int sum = nums[l] + nums[r];
			if (sum < target) {
				l++;
			} else if (sum > target) {
				r--;
			} else {
				//target == sum
				std::vector<int> tripletFound = {nums[idx], nums[l], nums[r]};
				res.push_back(tripletFound);

				//now skip all same numbers....
				while (l < r && nums[l] == tripletFound[1])
					l++;

				while (l < r && nums[r] == tripletFound[2])
					r--;
			}
		}
		int curNum = nums[idx];
		while (idx < nums.size() - 2 && nums[idx] == curNum)
			idx++;
	}
	return res;
}
int threeSumClosest(vector<int>& nums, int target) {
	if (nums.size() < 2) return -1;
	sort(nums.begin(), nums.end());
	int idx = 0;
	int minDiff = 1e9, minSum = 1e9;

	while (idx < nums.size() - 2) {
		if (idx > 0 && nums[idx - 1] == nums[idx]) continue;
		int l = idx + 1;
		int r = nums.size() - 1;
		while (l < r) {
			int a = nums[idx];
			int b = nums[l];
			int c = nums[r];
			int sum = a + b + c;
			int diff = abs(target - sum);
			if (diff == 0) {
				return target;
			}
			if (diff < minDiff) {
				minDiff = diff;
				minSum = sum;
			}
			if (sum - target > 0) {
				int rNum = nums[r];
				while (r > 1 && nums[r] == nums[r - 1]) r--;
				r--;
			} else {
				int lNum = nums[l];
				while (l < nums.size() - 1 && nums[l] == nums[l + 1]) l++;

				l++;
			}
		}
		idx++;
	}
	return minSum;
}

int removeDuplicates(std::vector<int> &nums) {

	int itr = 0;
	int ptr = 1;
	int cnt = 1;
	while (itr < ptr && ptr < nums.size()) {
		if (nums[itr] == nums[ptr]) {
			ptr++;
			continue;
		}
		if (nums[itr] != nums[ptr]) {
			nums[itr + 1] = nums[ptr];
			itr++;
			cnt++;
			ptr++;
		}
	}
	return cnt;
}
int removeElement(vector<int>& nums, int val) {
	int itr = 0, i = nums.size() - 1, cnt = 0;
	while (itr < i) {
		if (nums[itr] == val) {
			swap(nums[i], nums[itr]);
			i--;
			continue;
		}
		itr++;
		cnt++;
	}
	return itr + 1;
}
void nextPermutation(vector<int>& nums) {
	int n = nums.size();
	int i = n - 2;
	while (i >= 0 && nums[i] >= nums[i + 1]) i--;

	if (i >= 0) {
		int j = n - 1;
		while (j >= 0 && nums[i] >= nums[j]) j--;

		swap(nums[i], nums[j]);
	}
	//reverse the elements from i+1 to n
	int k = i + 1;
	int m = n - 1;
	while (k < m) {
		swap(nums[k], nums[m]);
		k++;
		m--;
	}
}
int search(vector<int>& nums, int target) {
	int beg = 0, end = nums.size() - 1, mid;
	while (beg <= end)
	{
		mid = (beg + end) / 2;
		if (nums[mid] == target)
			return mid;
		if (nums[beg] <= nums[mid])
		{
			if (target <= nums[mid] && target >= nums[beg])
				end = mid - 1;
			else {
				beg = mid + 1;
			}
		}
		else
		{
			if (target >= nums[mid] && target <= nums[end])
				beg = mid + 1;
			else
				end = mid - 1;
		}
	}
	return -1;
}
vector<int> searchRange(vector<int>& nums, int target) {
	int high = nums.size() - 1, start = 0;
	//           .... 1 1 1 2 2 2 3 4 5
	//						l   u
	std::vector<int> range;
	// lowerbound
	int lowerbound = -1, upperbound = -1;
	while (start <= high) {
		int mid = (start + high) / 2;

		if (nums[mid] == target) {
			lowerbound = mid;
			high = mid - 1;
		}
		else if (target > nums[mid]) {
			start = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	high = nums.size() - 1;
	start = 0;
	while (start <= high) {
		int mid = (start + high) / 2;

		if (nums[mid] == target) {
			upperbound = mid;
			start = mid + 1;
		}
		else if (target > nums[mid]) {
			start = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	range.push_back(lowerbound);
	range.push_back(upperbound);

	return range;
}
int searchInsert(vector<int>& nums, int target) {
	int high = nums.size() - 1, start = 0;
	int index = -1;
	while (start <= high) {
		int mid = (start + high) / 2;
		if (nums[mid] == target) {
			index = mid;
			break;
		}
		else if (target >= nums[mid]) {
			start = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	if(index == -1) return start;

	return index;
}

int main() {
	int n, target;
	cin >> n >> target;
	vector<int>nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	// std::vector<int> k = plusOne(v);
	// for (int i : k) {
	// cout << i << endl;
	// }
	// cout << kadaneAlgorithm(v);
	// cout << maxArea(v);
	// std::vector<std::vector<int>> ans = threeSum(v);
	// for (auto K : ans) {
	// 	for (int i : K) {
	// 		cout << i << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << threeSumClosest(v, target);
	// cout << removeDuplicates(nums) << endl;
	// cout << removeElement(nums, target) << endl;

	// std::vector<int> v = searchRange(nums, target);
	cout<<searchInsert(nums, target);
	// for (int i : v) {
		// cout << i << " ";
	// }
	// int i = 0;
	// cout << ++i;
	// cout << i + 1;
	// map<pair<int, int>, int>m;
	// pair<int, int>p ;
	// p.first = 1;
	// p.second = 2;
	// m.insert(pair<pair<int, int>, int>(p, 0));
	// pair<int, int> k;
	// k.first = 1;
	// k.second = 2;
	// if (m.find(k) != m.end()) {
	// 	cout << "a";
	// } else {
	// 	cout << "m";
	// }

	return 0;
}