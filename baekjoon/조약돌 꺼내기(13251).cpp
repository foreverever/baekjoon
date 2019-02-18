#include <iostream>

using namespace std;
int M, K, total;
int stone[51];
double probability[51];
double ans;

void findAns(){
	for (int i = 0; i < M; i++) {	//�� ���濡 ����
		if (stone[i] >= K) {	//��� �� ������ ������ ������ �����Ϸ��� ����(K)���� ũ�ų� ���� ��쿡��
			probability[i] = 1.0;
			for (int j = 0; j < K; j++) {
				probability[i] *= (double)(stone[i] - j) / (total - j);	//�� ������ ���游 �� Ȯ��
			}
			ans += probability[i];	//��� ���� ������ ���� �ش� ���游 �� Ȯ���� �� �����ش�.
		}
	}
	printf("%.16f", ans);
}

int main() {
	cin >> M;
	int x;
	for (int i = 0; i < M; i++) {
		scanf("%d", &x);
		stone[i] = x;
		total += x;
	}
	scanf("%d", &K);
	findAns();
	return 0;
}