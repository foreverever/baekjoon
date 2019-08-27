#include <iostream>
#define MAX 21

using namespace std;
int team[MAX][MAX];
int TC, N, K;

void calc(int &tc) {
	int sum;

	printf("#%d ", tc);

	for (int i = 0; i < K; i++) {
		sum = 0;
		for (int j = 0; j < N; j++) {
			sum += team[i][j];
		}
		printf("%d ", sum);
	}
}

void findAns(int &tc) {
	scanf("%d %d", &N, &K);
	int total = N * K, val = 1;

	while (total > val) {
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) {
				for (int j = 0; j < K; j++) {
					team[j][i] = val++;
				}
			}
			else {
				for (int j = K - 1; j >= 0; j--) {
					team[j][i] = val++;
				}
			}
		}
	}
	calc(tc);
}

int main() {
	scanf("%d", &TC);
	for (int t = 1; t <= TC; t++) {
		findAns(t);
		printf("\n");
	}
	return 0;
}