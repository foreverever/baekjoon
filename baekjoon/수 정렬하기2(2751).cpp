#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000001];

void input() {
	cin >> N;
	int x;

	for (int i = 0; i < N; i++) cin >> arr[i];
}

void findAns() {
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) cout << arr[i] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	input();
	findAns();

	return 0;
}