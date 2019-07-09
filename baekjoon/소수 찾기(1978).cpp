#include <iostream>
using	namespace std;

int N;
bool isNotPrime[1001];

void eraseMultiple(int n) {
	for (int i = n * 2; i < 1001; i += n) {
		if(!isNotPrime[i]) isNotPrime[i] = true;
	}
}

void getPrime() {
	isNotPrime[1] = true;

	for (int i = 2; i < 1001; i++) {
		if (!isNotPrime[i]) {
			eraseMultiple(i);
		}
	}
}

int findAns() {
	int cnt = 0, x;
	getPrime();

	for (int i = 0; i < N; i++) {
		cin >> x;
		if (!isNotPrime[x]) cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	cout << findAns();
	return 0;
}