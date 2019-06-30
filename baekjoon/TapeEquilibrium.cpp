#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
int mn = 2e9;

int solution(vector<int> &A) {
	int front = 0, back = 0;

	for (int i = 0; i < A.size(); i++) back += A[i];
	for (int i = 0; i < A.size()-1; i++) {
		front += A[i]; back -= A[i];
		mn = mn > abs(back - front) ? abs(back - front) : mn;
	}
	return mn;
}

int main() {
	vector<int> v = { -1000,1000 };
	cout << solution(v);
	return 0;
}