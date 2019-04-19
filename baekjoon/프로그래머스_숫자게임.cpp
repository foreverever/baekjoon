#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int &a, int &b) {
	return a > b;
}

int solution(vector<int> A, vector<int> B) {
	int answer = 0;

	sort(A.begin(), A.end(), cmp);
	sort(B.begin(), B.end());

	for (int val : B) {
		if (A.back() >= val) continue;
		answer++;
		A.pop_back();
	}

	return answer;
}