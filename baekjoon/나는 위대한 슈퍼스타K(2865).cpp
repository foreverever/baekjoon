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

//�迭�� �ε��� : ������ ��ȣ, �ε��� �� : ������� �ִ� ����
//�ϳ��� �Է¹����鼭, �ش� ��ȣ(�ε���)�� ���� ����(�ε�����)���� Ŭ ��� �� ����
//��� �Է��� �� �޾Ҵٸ�, ������ ��ȣ�� �ִ� ������ ���� ��
//�������� ����
//�迭�� �� �� ���� K�� ° �������� ���� ����
