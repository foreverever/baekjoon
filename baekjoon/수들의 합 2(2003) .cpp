#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int N, M;

int findAns() {
	int s = 1, e = 1, sum = 0, ans = 0;
	while (1) {
		if (sum == M) {	//���� M�� ������ ans 1 ���� �� üũ���� �� ù��° ��� ���ֱ�
			ans++;
			sum -= v[s];
			s++;
		}
		else if (sum > M) {	//sum�� M���� ũ�� üũ���� �� ù��° ��� ���ְ� continue
			sum -= v[s];
			s++;
			continue;
		}
		if (e <= N) {	//e ��ü�������� �۰ų� ������, �ش� ��ġ�� ��Ҹ� ���� �� �� �ִ�
			sum += v[e];
			e++;
		}
		else if (sum < M) return ans;	//e�� ��ü ������ �����, sum�� ã���� �ϴ� M���� ������ �� �̻� ���� �������� �����Ƿ� �Լ� ����
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