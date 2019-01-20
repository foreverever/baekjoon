#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int N, x;
long long sum;

bool cmp(int x, int y) {
	return x > y;
}

void findAns() {
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			sum += v[i] - v[j];
		}
	}
	cout << 2*sum;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
	findAns();
	return 0;
}