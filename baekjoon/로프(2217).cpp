#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> v;

void input() {
	cin >> N;
	int x;

	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
}

int findAns() {
	sort(v.begin(), v.end());
	int size = v.size();
	int mx = -2e9;

	for (int i = 0; i < v.size(); i++) {
		int tmp = v[i] * (size - i);
		mx = tmp > mx ? tmp : mx;
	}
	return mx;
}

int main() {
	input();
	cout << findAns();
	return 0;
}
//작은 숫자는 자신보다(자신 포함) 큰 모든 로프를 사용해야 자체 최대값이 나옴
//그 다음 작은 숫자를 선택할때 자신보다(자신 포함) 큰 모든 로프를 사용해야 자체 최대값이 나옴
//위를 반복하며, 자체 최대값들 중 가장 큰 값이 정답