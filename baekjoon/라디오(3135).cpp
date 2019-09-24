#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A, B, N;

int findAns(vector<int> &v) {
	int mn = 2e9;

	for (int val : v) {
		int diff = abs(B - val);
		mn = diff < mn ? diff : mn;
	}
	mn++;

	return mn < abs(A - B) ? mn : abs(A - B);
}

int main() {
	int input;
	vector<int> v;

	cin >> A >> B >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}
	cout << findAns(v);
	return 0;
}