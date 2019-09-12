#include <iostream>
#include <algorithm>

using namespace std;

int A[20001], B[20001];
int tc, N, M;

void input() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < M; i++) scanf("%d", &B[i]);
}

int findAns() {
	sort(B, B + M);
	
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += lower_bound(B, B + M, A[i]) - B;
	}
	return ans;
}

int main() {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		input();
		printf("%d\n", findAns());
	}
	return 0;
}

//반례 찾고 모든 케이스 통과했으나, 실패 (직접 이분탐색 구현해서)
//int binarySearch(int &val) {
//	int s = 0, e = M - 1;
//
//	if (val > B[e]) return M;
//	if (val <= B[s]) return 0;
//
//	int mid;
//	while (1) {
//		mid = (s + e) / 2;
//		//if (val == B[mid]) return mid;	//잘못된 로직 (만약 조건이 맞는 B[mid]값이 여러개라면 맨 앞의 값의 인덱스를 줘야함)
//		/*
//		반례
//		1
//		4 6
//		2 11 7 104
//		7 11 11 11 103 290
//		답은 6인데 7나옴
//		*/
//		//같은 값이 여러 개인 경우 해당 값들 중 맨 앞값의 인덱스를 반환
//		if (val == B[mid]) {
//			for (int i = mid - 1; i >= 0; i--) {
//				if (B[i] != B[mid]) return i + 1;
//			}
//		}
//		if (val > B[mid]) {
//			s = mid + 1;
//			if (s >= e) return e;
//		}
//		else {
//			e = mid - 1;
//			if (s >= e) return e + 1;
//		}
//	}
//}