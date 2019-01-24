#include <iostream>
#define MAX 101

using namespace std;

char arr[MAX][MAX];
int N, K;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}
	cin >> K;
}

void findAns() {
	if (K == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << arr[i][j];
			}
			cout << '\n';
		}
		return;
	}
	if (K == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				cout << arr[i][j];
			}
			cout << '\n';
		}
		return;
	}
	if (K == 3) {
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				cout << arr[i][j];
			}
			cout << '\n';
		}
		return;
	}
}

int main() {
	input();
	findAns();
	return 0;
}