#include<iostream>
#include <stack>
#include <vector>
using namespace std;

void ans2() {
	int n;
	cin >> n;
	std::vector<int> v(n + 1);
	std::vector<bool> c(n + 1,false);
	v.push_back(-1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	// sort(v.begin(),v.end());
	for (int i = 1; i <= n; i++) {
		if (v[i] != 0) {
			c[v[i]] = true;
		} 
	}
	
	stack<int>s;
	for (int i = 1; i <= n; i++) {
		if (c[i] == false) {
			s.push(i);
		}
	}
	int temp = -1;
	for (int i = 1; i <= n; i++) {
		if(v[i] == 0) {
			if(s.top() == i) {
				temp = s.top();
				s.pop();
				v[i] = s.top();
				s.pop();
				s.push(temp);
			} else {
				v[i] = s.top();	
				s.pop();
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << v[i] << " ";
	}
}

int main() {
	ans2();

	return 0;
}