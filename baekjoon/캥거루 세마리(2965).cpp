#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

void input() {
	int x;
	for (int i = 0; i < 3; i++) {
		cin >> x;
		v.push_back(x);
	}
}

int findAns() {
	sort(v.begin(), v.end());
	int front = v[1] - v[0], back = v[2] - v[1];

	return front > back ? front - 1 : back - 1;
}

int main() {
	input();
	cout << findAns();
	return 0;
}