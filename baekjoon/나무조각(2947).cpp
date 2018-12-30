#include <iostream>
#include <algorithm>

using namespace std;
int arr[5];

void input() {
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
}

void print() {
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

void findAns() {
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 5 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				print();
			}
		}
	}
}

int main() {
	input();
	findAns();
	return 0;
}