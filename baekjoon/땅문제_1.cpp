#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> v, int size) {
	int cnt = 0, sum = 0;

	for (int i = 0; i < size; i++) {
		if (v[i]) {
			cnt++;
			sum += (i + 1)*cnt;
		}
		else cnt = 0;
	}
	return sum;
}

int main() {
	vector<int> v = { 0,1,1,0,1,1,1,0 };
	cout << solution(v, v.size());
	return 0;
}