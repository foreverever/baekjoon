#include <iostream>
using namespace std;

int n, m, ans;
int arr[51][51];


int CompareSize(int n, int m) {
	if (n > m) return m;
	else return n;
}
int CheckSquare(int length) {
	int result = 0;
	for (int len = length; len > 0; len--) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i + (len - 1) >= n || j + (len - 1) >= m) continue;
				if (arr[i][j] == arr[i + (len - 1)][j] && arr[i][j] == arr[i][j + (len - 1)] && arr[i][j] == arr[i + (len - 1)][j + (len - 1)]) {
					result = len * len;
					return result;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	ans = CheckSquare(CompareSize(n, m));
	cout << ans;
	return 0;
}
