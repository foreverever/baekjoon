#include <iostream>
#include <memory.h>
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4

using namespace std;

int N, M, y, x, K;
int arr[21][21];
int direction[1001];
int face[7], before[7];

void findAns() {
	for (int i = 0; i < K; i++) {
		memcpy(before, face, sizeof(face));

		if (direction[i] == EAST) {
			x++;
			if (x >= M) {
				x--;
				continue;
			}
			face[3] = before[1];
			face[6] = before[3];
			face[4] = before[6];
			face[1] = before[4];
		}

		else if (direction[i] == WEST) {
			x--;
			if (x < 0) {
				x++;
				continue;
			}
			face[4] = before[1];
			face[6] = before[4];
			face[3] = before[6];
			face[1] = before[3];
		}
		else if (direction[i] == SOUTH) {
			y++;
			if (y >= N) {
				y--;
				continue;
			}
			face[1] = before[2];
			face[5] = before[1];
			face[6] = before[5];
			face[2] = before[6];
		}
		else if (direction[i] == NORTH) {
			y--;
			if (y < 0) {
				y++;
				continue;
			}
			face[2] = before[1];
			face[1] = before[5];
			face[5] = before[6];
			face[6] = before[2];
		}
		if (arr[y][x] == 0) arr[y][x] = face[6];
		else {
			face[6] = arr[y][x];
			arr[y][x] = 0;
		}
		printf("%d\n", face[1]);
	}
}

int main() {
	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		scanf("%d", &direction[i]);
	}
	findAns();
	return 0;
}