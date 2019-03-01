#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int N, M;

int findAns() {
	int s = 1, e = 1, sum = 0, ans = 0;
	while (1) {
		if (sum == M) {	//합이 M과 같으면 ans 1 증가 및 체크범위 내 첫번째 요소 빼주기
			ans++;
			sum -= v[s];
			s++;
		}
		else if (sum > M) {	//sum이 M보다 크면 체크범위 내 첫번째 요소 빼주고 continue
			sum -= v[s];
			s++;
			continue;
		}
		if (e <= N) {	//e 전체범위보다 작거나 같을때, 해당 위치의 요소를 더해 줄 수 있다
			sum += v[e];
			e++;
		}
		else if (sum < M) return ans;	//e가 전체 범위를 벗어나고, sum이 찾고자 하는 M보다 작으면 더 이상 답은 존재하지 않으므로 함수 종료
	}
}

int main() {
	scanf("%d %d", &N, &M);
	v.resize(N + 1);
	int x = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &x);
		v[i] = x;
	}
	printf("%d", findAns());
	return 0;
}