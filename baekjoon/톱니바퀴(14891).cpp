#include <iostream>
#include <math.h>
#define LEFT 6
#define RIGHT 2

using namespace std;

struct Rotation {
	bool canRotate = false;
	int dir = 1;
};

int arr[5][8];	//톱니바퀴
int temp[8];
int N, num, rot, ans;
Rotation rt[5];

void findAns() {
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &num, &rot);
		rt[num].canRotate = true;
		rt[num].dir = rot;
		//회전 유무 판단
		if (num == 1) {
			if (arr[1][RIGHT] != arr[2][LEFT]) {
				rt[2].canRotate = true;
				rt[2].dir = rt[1].dir * (-1);
			}
			if (arr[2][RIGHT] != arr[3][LEFT] && rt[2].canRotate) {
				rt[3].canRotate = true;
				rt[3].dir = rt[2].dir * (-1);
			}
			if (arr[3][RIGHT] != arr[4][LEFT] && rt[3].canRotate) {
				rt[4].canRotate = true;
				rt[4].dir = rt[3].dir * (-1);
			}
		}
		else if (num == 2) {
			if (arr[2][RIGHT] != arr[3][LEFT]) {
				rt[3].canRotate = true;
				rt[3].dir = rt[2].dir * (-1);
			}
			if (arr[1][RIGHT] != arr[2][LEFT]) {
				rt[1].canRotate = true;
				rt[1].dir = rt[2].dir * (-1);
			}
			if (arr[3][RIGHT] != arr[4][LEFT] && rt[3].canRotate) {
				rt[4].canRotate = true;
				rt[4].dir = rt[3].dir * (-1);
			}
		}
		else if (num == 3) {
			if (arr[3][RIGHT] != arr[4][LEFT]) {
				rt[4].canRotate = true;
				rt[4].dir = rt[3].dir * (-1);
			}
			if (arr[2][RIGHT] != arr[3][LEFT]) {
				rt[2].canRotate = true;
				rt[2].dir = rt[3].dir * (-1);
			}
			if (arr[1][RIGHT] != arr[2][LEFT] && rt[2].canRotate) {
				rt[1].canRotate = true;
				rt[1].dir = rt[2].dir * (-1);
			}
		}
		else if (num == 4) {
			if (arr[3][RIGHT] != arr[4][LEFT]) {
				rt[3].canRotate = true;
				rt[3].dir = rt[4].dir * (-1);
			}
			if (arr[2][RIGHT] != arr[3][LEFT] && rt[3].canRotate) {
				rt[2].canRotate = true;
				rt[2].dir = rt[3].dir * (-1);
			}
			if (arr[1][RIGHT] != arr[2][LEFT] && rt[2].canRotate) {
				rt[1].canRotate = true;
				rt[1].dir = rt[2].dir * (-1);
			}
		}
		//회전 시키기
		for (int k = 1; k <= 4; k++) {
			if (rt[k].canRotate) {
				for (int j = 0; j < 8; j++) temp[j] = arr[k][j];
				//시계
				if (rt[k].dir == 1) {
					for (int j = 0; j < 8; j++) {
						arr[k][(j + 1) % 8] = temp[j];
					}
				}
				//반시계
				else {
					for (int j = 0; j < 8; j++) {
						arr[k][j] = temp[(j + 1) % 8];
					}
				}
			}
			//초기화
			rt[k].canRotate = false;
			rt[k].dir = 1;
		}
	}

	for (int i = 1; i <= 4; i++) {
		ans += arr[i][0] * pow(2, i - 1);
	}
}

int main() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	scanf("%d", &N);
	findAns();
	printf("%d", ans);
	return 0;
}