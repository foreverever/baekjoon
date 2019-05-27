//정수 배열(int array)이 주어지면 0이 아닌 정수 순서를 유지하며 모든 0을 배열 오른쪽 끝으로 옮기시오. 
//단, 시간복잡도는 O(n), 공간복잡도는 O(1)여야 합니다.

#include <iostream>
#define MAX 10000
using namespace std;

int arr[MAX];
int n, idx;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void findAns() {
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) arr[idx++] = arr[i];
	}
	for (int i = idx; i < n; i++) arr[i] = 0;
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
}

int main() {
	input();
	findAns();
	return 0;
}