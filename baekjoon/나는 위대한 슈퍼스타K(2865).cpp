#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

double participant[MAX];
int N, M, K;

void input() {
	scanf("%d %d %d", &N, &M, &K);
}

bool cmp(double &first, double &second) {
	return first > second;
}

double findAns() {
	int num = 0;
	double score = 0, total = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d %lf", &num, &score);
			participant[num] = participant[num] < score ? score : participant[num];
		}
	}

	sort(participant + 1, participant + N + 1, cmp);

	for (int i = 1; i <= K; i++) {
		total += participant[i];
	}
	return total;
}

int main() {
	input();
	printf("%.1f", findAns());
	return 0;
}

//배열의 인덱스 : 참가자 번호, 인덱스 값 : 현재까지 최대 점수
//하나씩 입력받으면서, 해당 번호(인덱스)의 기존 점수(인덱스값)보다 클 경우 값 갱신
//모든 입력을 다 받았다면, 참가자 번호별 최대 점수를 구한 것
//내림차순 정렬
//배열의 맨 앞 부터 K번 째 값까지의 합이 정답
