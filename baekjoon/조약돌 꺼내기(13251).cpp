#include <iostream>

using namespace std;
int M, K, total;
int stone[51];
double probability[51];
double ans;

void findAns(){
	for (int i = 0; i < M; i++) {	//각 스톤에 대해
		if (stone[i] >= K) {	//어느 한 종류의 스톤의 개수가 선택하려는 개수(K)보다 크거나 같을 경우에만
			probability[i] = 1.0;
			for (int j = 0; j < K; j++) {
				probability[i] *= (double)(stone[i] - j) / (total - j);	//한 종류의 스톤만 고를 확률
			}
			ans += probability[i];	//모든 스톤 각각에 대해 해당 스톤만 고를 확률을 다 더해준다.
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