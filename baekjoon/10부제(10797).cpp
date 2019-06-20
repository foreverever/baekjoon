#include <iostream>
using namespace std;

int N;

int findAns() {
	int x, cnt = 0;

	for (int i = 0; i < 5; i++) {
		cin >> x;
		if (x==N) cnt++;
	}
	return cnt;
}

int main() {
	cin >> N;
	cout << findAns();
	return 0;
}