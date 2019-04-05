#include <iostream>
#include <string>
#define ADDITION 26
using namespace std;

int N;
string first, second;

void findAns() {
	int diff = 0;
	for (int i = 0; i < first.size(); i++) {
		diff = second[i] - first[i];
		if (first[i] <= second[i]) cout << diff << ' ';
		else cout << diff + ADDITION << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> first >> second;
		cout << "Distances: ";  findAns(); cout << '\n';
	}
	return 0;
}