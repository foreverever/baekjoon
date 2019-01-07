#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> a, b;

void input() {
	cin >> N;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < N; i++) {
		cin >> x;
		b.push_back(x);
	}
}

bool desc(int x, int y) {
	return x > y;
}

int findAns() {
	sort(a.begin(), a.end(),desc);
	sort(b.begin(), b.end());
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += a[i] * b[i];
	}
	return sum;
}

int main() {
	input();
	cout << findAns();
	return 0;
}