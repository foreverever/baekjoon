#include <iostream>
#include <queue>

using namespace std;

int n;

int findAns() {
	priority_queue<int, vector<int>, greater<int> > q;
	int x = 0, sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);
	}

	while (!q.empty()) {
		sum += q.top()*q.size();
		q.pop();
	}
	return sum;
}

int main() {
	cin >> n;
	cout << findAns();
	return 0;
}