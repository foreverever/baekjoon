#include <iostream>
#define MAX 14

using namespace std;
int k, n;
int arr[MAX+1][MAX+1];

void initArr() {
	for (int i = 1; i <= MAX; i++) {
		arr[0][i] = i;
		arr[i][1] = 1;
	}
	for (int i = 1; i <= MAX; i++) {
		for (int j = 2; j <= MAX; j++) {
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
		}
	}
}

int main() {
	int tc;
	initArr();
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> k >> n;
		cout << arr[k][n] <<'\n';
	}
	return 0;
}