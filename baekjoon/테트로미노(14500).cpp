#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans = -2e9;
int arr[501][501];
int range[5] = { 3,1,2,1,2 };	//긴 축의 범위

void calcMax(int sum) {
	ans = ans < sum ? sum : ans;
}

void update(int type) {
	int ny, nx, sum = 0;

	if (type == 0) {
		//가로
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sum = 0;
				nx = j + range[type];
				if (nx < 0 || nx >= M) continue;
				for (int k = j; k <= nx; k++) {
					sum += arr[i][k];
				}
				calcMax(sum);
			}
		}
		//세로
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sum = 0;
				ny = i + range[type];
				if (ny < 0 || ny >= N) continue;
				for (int k = i; k <= ny; k++) {
					sum += arr[k][j];
				}
				calcMax(sum);
			}
		}
	}
	else if (type == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sum = 0;
				ny = i + range[type];
				nx = j + range[type];
				if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
				sum = arr[i][j] + arr[i][nx] + arr[ny][j] + arr[ny][nx];
				calcMax(sum);
			}
		}
	}
	else if (type == 2) {
		//가로
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sum = 0;
				nx = j + range[type];
				if (nx < 0 || nx >= M) continue;
				for (int k = j; k <= nx; k++) {
					sum += arr[i][k];
				}
				int dum = 0;
				if (i - 1 >= 0) dum = max(arr[i - 1][j], arr[i - 1][nx]);
				if (i + 1 < N) {
					dum = max(arr[i + 1][j], dum);
					dum = max(arr[i + 1][nx], dum);
				}
				sum += dum;
				calcMax(sum);
			}
		}
		//세로
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sum = 0;
				ny = i + range[type];
				if (ny < 0 || ny >= N) continue;
				for (int k = i; k <= ny; k++) {
					sum += arr[k][j];
				}
				int dum = 0;
				if (j - 1 >= 0) dum = max(arr[i][j - 1], arr[ny][j - 1]);
				if (j + 1 < M) {
					dum = max(arr[i][j + 1], dum);
					dum = max(arr[ny][j + 1], dum);
				}
				sum += dum;
				calcMax(sum);
			}
		}
	}
	else if (type == 3) {
		//가로
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sum = 0;
				nx = j + range[type];
				if (i - 1 < 0 || i + 1 >= N) continue;
				for (int k = j; k <= nx; k++) {
					sum += arr[i][k];
				}
				int first = arr[i - 1][j] + arr[i+1][j+1];
				int second = arr[i + 1][j] + arr[i - 1][j + 1];
				sum += max(first, second);
				calcMax(sum);
			}
		}
		//세로
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sum = 0;
				ny = i + range[type];
				if (j - 1 < 0 || j + 1 >= M) continue;
				for (int k = i; k <= ny; k++) {
					sum += arr[k][j];
				}
				int first = arr[i][j-1] + arr[i + 1][j+1];
				int second = arr[i + 1][j - 1] + arr[i][j + 1];
				sum += max(first, second);
				calcMax(sum);
			}
		}
	}
	else if (type == 4) {
		//가로
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sum = 0;
				nx = j + range[type];
				if (nx < 0 || nx >= M) continue;
				for (int k = j; k <= nx; k++) {
					sum += arr[i][k];
				}
				int dum = 0;
				if (i - 1 >= 0) dum = arr[i - 1][j + 1];
				if (i + 1 < N) dum = max(arr[i + 1][j + 1], dum);
				sum += dum;
				calcMax(sum);
			}
		}
		//세로
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sum = 0;
				ny = i + range[type];
				if (ny < 0 || ny >= N) continue;
				for (int k = i; k <= ny; k++) {
					sum += arr[k][j];
				}
				int dum = 0;
				if (j - 1 >= 0) dum = arr[i + 1][j - 1];
				if (j + 1 < M) dum = max(arr[i + 1][j + 1], dum);
				sum += dum;
				calcMax(sum);
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	//찾기
	for (int type = 0; type < 5; type++) {
		update(type);
	}
	printf("%d", ans);
	return 0;
}