#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

void input() {
	cin >> N;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
}

bool cmp(int &a, int &b) {
	return a > b;
}

int findAns() {
	if (v.size() == 1) return v.front();

	sort(v.begin(), v.end(), cmp);
	int sum = v.front();
	
	for (int i = 1; i < v.size(); i++) {
		sum+=v[i]-1;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	input();
	cout << findAns();
	return 0;
}