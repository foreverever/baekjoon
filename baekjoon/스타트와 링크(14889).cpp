#include <iostream>
#include <math.h>
using namespace std;

int N, half, ans = 2e9;
int arr[21][21], a[11], b[11];
bool used[21];

void divide(int cnt, int idx) {
	if (cnt == half) {
		int aSum = 0, bSum = 0, aSize = 0, bSize=0;
		for (int i = 1; i <= N; i++) {
			if (used[i] == true) {
				a[aSize++] = i;
			}
			else b[bSize++] = i;
		}
		for (int i = 0; i < half; i++) {
			for (int j = 0; j < half; j++) {
				if (i == j) continue;
				aSum += arr[a[i]][a[j]];
				bSum += arr[b[i]][b[j]];
			}
		}
		int diff = abs(aSum - bSum);
		ans = ans > diff ? diff : ans;
		return;
	}
	for (int i = idx; i <= N; i++) {
		if (used[i] == false) {
			used[i] = true;
			divide(cnt + 1, i + 1);
			used[i] = false;
		}
	}
}

int main() {
	scanf("%d", &N);
	half = N / 2;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	used[1] = true;	//1을 먼저 선택하고, 나머지 경우의 수만 구하면 전체 경우의 수의 절반이 된다.
	divide(1, 2);
	printf("%d", ans);
	return 0;
}