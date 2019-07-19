#include <iostream>

using namespace std;

int N;
bool isReserved[101];

int findAns() {
	int cnt = 0, x;

	for (int i = 0; i < N; i++) {
		cin >> x;
		if (!isReserved[x]) {
			isReserved[x] = true;
			continue;
		}
		cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	cout << findAns();
	return 0;
}