//���� �迭(int array)�� �־����� 0�� �ƴ� ���� ������ �����ϸ� ��� 0�� �迭 ������ ������ �ű�ÿ�. 
//��, �ð����⵵�� O(n), �������⵵�� O(1)���� �մϴ�.

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