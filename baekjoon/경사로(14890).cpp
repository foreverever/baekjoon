#include <iostream>
#include <string.h>

using namespace std;

int N, L, arr[101][101], ans, tc;
int w[101], h[101];
bool rUp[101], rDown[101];

void findAns(int road[101]) {
	memset(rUp, false, sizeof(rUp));
	memset(rDown, false, sizeof(rDown));

	int cnt = 0;
	//��� ������ ���� �Ǻ�
	for (int i = 0; i < N - 1; i++) {
		if (road[i] == road[i + 1]) cnt++;
	}
	if (cnt == N - 1) {
		ans++;
		return;
	}

	//rUp
	for (int i = 0; i < N - 1; i++) {
		if (road[i] + 1 < road[i + 1]) return;
		if (road[i] + 1 == road[i + 1]) {
			//���� ������ ��� �������� üũ
			for (int j = i - (L - 1); j <= i; j++) {
				if (j < 0) 	return;
				if (road[j] != road[i]) return;
			}
			//��ġ �����ϸ�
			for (int j = i - (L - 1); j <= i; j++) {
				rUp[j] = true;
			}
		}
	}

	//rDown
	for (int i = 0; i < N - 1; i++) {
		if (road[i] - 1 > road[i + 1]) return;
		if (road[i] == road[i + 1] + 1) {
			//���� ������ ��� �������� üũ
			for (int j = i + 1; j <= i + L; j++) {
				if (j >= N) 	return;
				if (road[j] != road[i + 1]) return;
			}
			//��ġ �����ϸ�
			for (int j = i + 1; j <= i + L; j++) {
				rDown[j] = true;
			}
		}
	}
	//rUp�� rDown �Ѵ� true�� �ε����� �����ϸ� ��ġX (�ٸ� ��ġ �ߺ�)
	for (int i = 0; i < N; i++) {
		if (rUp[i] == true && rDown[i] == true) return;
	}
	ans++;
}
int main() {

	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d %d", &N, &L);
		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				w[j] = arr[i][j];
				h[j] = arr[j][i];
			}
			findAns(w);
			findAns(h);
		}
		printf("#%d %d\n", t, ans);
	}
	return 0;
}