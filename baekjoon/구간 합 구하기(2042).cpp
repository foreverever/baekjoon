#include <iostream>
#define MAX 1000000
using namespace std;

int n, m, k;
long long tree[MAX * 3];

int initTree() {
	for (int i = 1; i < 3 * n; i++) {
		tree[i] = 0;
	}
	int s = 1;
	while (s < n) s *= 2;
	return s;
}

void update(int node, long long newVal) {
	while (node > 0) {
		tree[node] += newVal;
		node /= 2;	//�θ��� ������Ʈ
	}
}

long long sum(int start, int end) {
	long long r = 0;
	while (start <= end) {
		if (start % 2 == 1) r += tree[start];	//������ ù ��尡 Ȧ���� °(������ �����)
		if (end % 2 == 0) r += tree[end];	//������ ������ ��尡 ¦���� °(���� �����) 
		start = (start + 1) / 2;
		end = (end - 1) / 2;
	}
	return r;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	int firstidx = initTree();	//Ʈ�� �ʱ�ȭ

	for (int i = 0; i < n; i++) {
		scanf("%lld", &tree[firstidx + i]);
	}
	//Ʈ�� ����
	for (int i = firstidx - 1; i > 0; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			update(firstidx + b - 1, c - tree[firstidx + b - 1]);
		}
		else {
			printf("%lld\n", sum(firstidx + b - 1, firstidx + c - 1));
		}
	}
	return 0;
}