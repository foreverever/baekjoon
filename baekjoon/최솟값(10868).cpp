#include <iostream>
#define MAX 100000
using namespace std;
int tree[MAX * 3];
int N, M;

int initTree() {
	int s = 1;
	while (s < N) s *= 2;
	return s;
}

void findMin(int start, int end) {
	int minVal = 2e9;
	while (start <= end) {
		if (start % 2 == 1) minVal = tree[start] < minVal ? tree[start] : minVal;
		if (end % 2 == 0) minVal = tree[end] < minVal ? tree[end] : minVal;
		start = (start + 1) / 2;
		end = (end - 1) / 2;
	}
	printf("%d\n", minVal);
}

int main() {
	int val, start, end;
	scanf("%d %d", &N, &M);
	int firstIdx = initTree();

	for (int i = 0; i < N; i++) {
		scanf("%d", &val);
		tree[firstIdx + i] = val;
	}
	//트리구성
	for (int i = firstIdx - 1; i > 0; i--) {
		tree[i] = tree[i * 2] < tree[i * 2 + 1] ? tree[i * 2] : tree[i * 2 + 1];
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &start, &end);
		findMin(firstIdx + start - 1, firstIdx + end - 1);
	}
	return 0;
}